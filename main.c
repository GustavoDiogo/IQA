#include<stdio.h>
#include<math.h>

#define e 2.71828182845904523536
#define pi 3.14159265358979323846

double calculo_OD(double ODinput)
{
	double Cs,T,CCI,H,qs;
	printf("Digite a Temperatura(ºC)\n");
	scanf("%lf\n",&T);
	printf("Digite a Concentração de Cloreto(mg/L)\n");
	scanf("%lf\n",&CCI);
	printf("Digite a Altitude(m)\n");
	scanf("%lf\n",&H);
	Cs =((14.2)*pow(e,-0.0212*T)-(0.0016*CCI)*pow(e,-0.0264*T))*(0.994-(0.0001042*H));
	printf("A concentração de saturação de oxigênio é %lf\n",Cs);

	double porcentagem_OD = (ODinput/Cs)*100;
	printf("A porcentagem de oxigênio é %lf\n", porcentagem_OD);

	if(porcentagem_OD<= 100)
	{
		double y[5];
		y[0] = 0.01396 * porcentagem_OD + 0.0873;
		y[1] = (pi/56.0) * (porcentagem_OD - 27.0);
		y[2] = (pi/85.0)- (porcentagem_OD - 15.0);
		y[3] = (porcentagem_OD - 65)/10.0;
		y[4] = (65.0 - porcentagem_OD)/10.0;

		qs = 100 * pow(sin(y[0]),2) - ((2.5 * sin (y[1]) - 0.018 * porcentagem_OD + 6.86) * sin (y[2])) + (12 / (pow(e, y[3]) + pow(e, y[4])));
	}
	else if(porcentagem_OD<=140)
	{
		qs = (-0.00777142857142832 * pow(porcentagem_OD,2)) + (1.27854285714278 * porcentagem_OD) + 49.8817148572;
	}
	else
		qs = 47.0;

	return(qs<0) ? 0.1 : qs;
}
double calculo_CF(double CFinput)
{
	double qs=0;
	if(CFinput <= pow(10, 5))
	{
		qs = 98.24034 - 34.7145 * (log10(CFinput)) + 2.614267 * pow(log(CFinput),2) + 0.107821 * pow(log10(CFinput),3);
	}
	else
		qs = 3.0;

	return qs;
}
double calculo_PH(double PHinput)
{
	double qs = 0;
	if(PHinput <= 2)
			qs = 2.0;
	else if(PHinput <= 6.9)
			qs = -37.1085 + 41.91277 * PHinput - 15.7043 * pow(PHinput, 2) + 2.417486 * pow(PHinput, 3) - 0.091252 * pow(PHinput, 4);
	else if(PHinput <= 7.1)
			qs = -4.69365 - (21.4593 * PHinput) - (68.4561 * pow(PHinput,2)) + (21.638886 * pow(PHinput,3)) - (1.59165 * pow(PHinput,4));
	else if(PHinput <= 12)
			qs = -7698.19 + 3262.031 * PHinput - 499.494 * pow(PHinput,2) + 33.1551 * pow(PHinput,3) - 0.810613 * pow(PHinput,4);
	else
			qs = 3.0;

	return qs;								
}
double calculo_DBO(double DBOinput)
{
	double qs = 0;

	if(DBOinput<=30)
		qs = 100.9571 - 10.7121 * DBOinput + 0.49544 * pow(DBOinput, 2) - 0.011167 * pow(DBOinput, 3) + .0001 * pow(DBOinput, 4);
	else 
		qs = 30.0;
	return qs;

}

double calculo_VT(double VTinput)
{
double qs = 93; 
return qs;
}

double calculo_NO3(double NO3input)
{
	double qs = 0;
	if(NO3input <=10)
		qs = -5.1 * NO3input + 100.17;
	else if (NO3input <=60)
		qs = -22.853 * log(NO3input)+101.18;
	else if(NO3input <=90)
		qs = pow(10, 9)* pow(NO3input, -5.1161);
	else
		qs = 1.0;
	return qs;
}
double calculo_PO4(double POinput)
{
	double qs = 0;
	if (POinput <= 10)
		qs = 79.7 * pow(POinput + 0.821, -1.15);
	else if(POinput > 10)
		qs = 5;
	return qs;
}
double calculo_TU(double TUinput){
	double qs = 0;
	if (TUinput<=100)
		qs = 90.37*pow(e, -0.0169 * TUinput) - 15* cos(0.0571 * (TUinput-30)) + 10.22 * pow(e, -0.231 * TUinput)-0.8;
	else
		qs=5;
	return qs;

}
double calculo_ST(double STinput)
{
	double qs = 0;
	if(STinput<=500)
		qs = 133.17 * pow(e, - 0.0027 * STinput) - 53.17 * pow(e,-0.0141 *STinput)+((-6.2*pow(e, - 0.00462*STinput)) * sin(0.0146 * STinput));
	else
		qs = 30.0;
	return qs;
}

int main()
{
	double x[9];
	printf("Digite a quantidade de oxigênio dissolvido\n");
	scanf("%lf\n", &x[0]);
	calculo_OD(x[0]);
	printf("Digite a concentração de Coliformes Fecais\n");
	scanf("%lf\n", &x[1]);
	calculo_CF(x[1]);
	printf("Digite a concentração do pH\n");
	scanf("%lf\n", &x[2]);
	calculo_PH(x[2]);
	printf("Digite a concentração da Demanda Bioquímica de Oxigênio\n");
	scanf("%lf\n", &x[3]);
	calculo_DBO(x[3]);
	printf("Digite a variação da Temperatura\n");
	scanf("%lf\n",&x[4]);
	calculo_VT(x[4]);
	printf("Digite a concentração de Nitratos\n");
	scanf("%lf\n",&x[5]);
	calculo_NO3(x[5]);
	printf("Digite a concentração de Fosfatos\n");
	scanf("%lf\n",&x[6]);
	calculo_PO4(x[6]);
	printf("Digite a Turbidez\n");
	scanf("%lf\n",&x[7]);
	calculo_TU(x[7]);
	printf("Digite a concentração de sólidos totais\n");
	scanf("%lf\n",&x[8]);
	calculo_ST(x[8]);



	return 0;
}
