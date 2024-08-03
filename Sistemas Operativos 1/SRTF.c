#include<stdio.h>
#define ejecutado 1
#define no_eje 0
//structure for a process
typedef struct proceso
{
	int tll;        //arrival time
	int tc;         //burst time
	int te;		//waiting time
	int ts;		//finish time
	int status;
} proceso;

void srtf(proceso *pr,int n,float *awt,float *atat);
int procesoCorto(proceso *pr,int n,int ct);
int sumaArray(int *tll,int n);
void mostrarArray(int *tll,int n);

int main()
{
	int n,i;
	float awt,atat;
	proceso pr[20];
	printf("\nIngrese el numero de procesos:");
	scanf("%d",&n);
	
	for(i=0; i<n; i++)
	{
		printf("\nIngrese el tiempo de llegada y de ejecucion %d: ",i+1);
		scanf("%d %d",&pr[i].tll,&pr[i].tc);
	}
	srtf(pr,n,&awt,&atat);
	printf("\nTiempo promedio de espera=%.2f",awt);
	printf("\nTiempo en que se tardo al completar los procesos=%.2f\n",atat);
	return 0;
}
void srtf(proceso *pr,int n,float *awt,float *atat)
{
	int i,ct=0,spi;	//ct->current time,spi->indice del proceso mas corto
	//Se inicializan los procesos
	for(i=0;i<n;i++)
	{
		pr[i].status=no_eje;
		pr[i].te=0;
	}
	do
	{
		//printf("spi=%d",spi);
		spi=procesoCorto(pr,n,ct);
		if(spi==-1)
			break;
		
		//aumenta el tiempo de espera de los procesos que han llegado pero no se están ejecutando
		for(i=0;i<n;i++)
		{
			if(i!=spi && pr[i].status!=ejecutado && ct>=pr[i].tll)
				pr[i].te++;
		}
		//printf("te=%d",pr[spi].te);
		ct++;		//updating current time
		pr[spi].te=ct-pr[spi].tll;		//finish time of the executed process
		pr[spi].tc--;
		if(pr[spi].tc<=0)
		{
			pr[spi].status=ejecutado;
			pr[spi].ts=ct-pr[spi].tll;
		}
	}while(ct);
	
	for(i=0;i<n;i++)
	{
		(*awt)+=pr[i].te;
		(*atat)+=pr[i].ts;
	}
	*awt=*awt/n;
	*atat=*atat/n;
	
	printf("\nWaiting Times:");
	for(i=0;i<n;i++)
	{
		printf("\t%d",pr[i].te);
	}
	
	printf("\nturnaround Times:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",pr[i].ts);
	}
	
}
//returns the index of shortest process arrived beore the current time ct
int procesoCorto(proceso *pr,int n,int ct)
{
	int i,min_tc=99999,min_index=-1;
	for(i=0;i<n;i++)
	{
		if(pr[i].status==no_eje && pr[i].tll<=ct)
		{
			if(pr[i].tc<min_tc)
			{
				min_tc=pr[i].tc;
				min_index=i;
			}
		}
	}
	return min_index;
}

//to give the sum of the array
int sumArray(int *tll,int n)
{
	int sum=0,i;
	for(i=0; i<n; i++)
	{
		sum+=tll[i];
	}
	return sum;
}

//Muestra el array
void mostrarArray(int *tll,int n)
{
	int i=0;
	for(i=0; i<n; i++)
	{
		printf("%d",tll[i]);
	}
}
