#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void middle(double x1, double y1, double x2, double y2, int ind, double *X, double *Y);
double d(double x1, double y1, double x2, double y2);
void count_axes(double *X, double *Y, int *answ, int n, int ind);

int main(void){
    int t, n;
    int answer[10];
    double *X = malloc(200000*(sizeof(double)));
    double *Y = malloc(200000*(sizeof(double)));
    scanf("%d", &t);

    for (int i = 0; i < 10; i++)
        answer[i] = 0;
    for (int j = 0; j < t; j++){
        scanf("%d",&n);
        for (int l = 0; l < n; l++)
            scanf("%lf %lf",&X[2*l],&Y[2*l]);
        count_axes(X, Y, answer, n, j);
    }
    for (int a = 0; a < t; a++)
        printf("%d \n", answer[a]);
    free(X);
    free(Y);
    return 0;
}

void middle(double x1, double y1, double x2, double y2, int ind, double *X, double *Y){
    X[ind] = (x1 + x2) / 2;
    Y[ind] = (y1 + y2) / 2;
}

double d(double x1, double y1, double x2, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void count_axes(double *X, double *Y, int *answ, int n, int ind){
    middle(X[0], Y[0],X[2*n - 2], Y[2*n - 2], 2*n -1 , X, Y);

    for(int i = 1; i < 2*n -1; i += 2){
        middle(X[i - 1], Y[i - 1], X[i + 1], Y[i + 1],i, X, Y);
    }
    int res = 0;
    for (int k = 0; k < n; k++){
        int tmp = 1;
        double xp = X[k];
        double yp = Y[k];
        double xq = X[k + n];
        double yq = Y[k + n];
        for ( int m = 1; m < n; m++){
            int w1 = (k + m) % (2*n);
            int w2 = (k - m);
            if (w2 < 0) w2 = 2*n + w2;
            double w1x = X[w1];
            double w1y = Y[w1];
            double w2x = X[w2];
            double w2y = Y[w2];
            if (d(w1x,w1y,xp,yp) != d(w2x,w2y, xp, yp) || d(w1x,w1y,xq,yq) != d(w2x,w2y,xq,yq)){
                tmp = 0;
                break;
            }
        }
        res += tmp;
    }
    answ[ind] = res;
}