#include <stdio.h>
int main(){
    int nf, a;
    double s1, d1, d2;
    d2=0;
    
    printf("Ingrese el numero de facturas a calcular\n");
    scanf("%d", &nf);
    if (nf>0){
        for (a=1; a<=nf; a++){
            printf("Ingrese el gasto anual de la factura: %d\n", a);
            scanf("%lf", &s1);
            if (s1>=0){
                d1=.02*s1;
                d2=d1+d2;
                if(s1>=400000){
                    s1=.20*s1;
                    printf("El impuesto a pagar es de: %.2f\n", s1);
                }
                else{
                    s1=.16*s1;
                    printf("El impuesto a pagar es de: %.2f\n", s1);
                }
            }
        }
        if (d2>=0 && d2<=5000) printf("Usted tiene un reembolso de: %.2lf\n", d2);
    }
    getchar();
}
