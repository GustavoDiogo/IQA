#include <gtk/gtk.h>

#include<stdio.h>
#include<math.h>

#define e 2.71828182845904523536
#define pi 3.14159265358979323846

double x[9];
double z[3];

    GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkWidget       *entry1;
    GtkWidget       *entry2;
    GtkWidget       *entry3;
    GtkWidget       *entry4;
    GtkWidget       *entry5;
    GtkWidget       *entry6;
    GtkWidget       *entry7;
    GtkWidget       *entry8;
    GtkWidget       *entry9;
    GtkWidget       *entry10;
    GtkWidget       *entry11;
    GtkWidget       *entry12;
    GtkWidget       *textview1;


double calculo_OD(double ODinput)
{

	double cs,qs;
	cs = (14.2 * pow(e,-0.0212 * z[0]) - (0.0016*z[1]*pow(e, -0.0264 * z[0]))) * (0.994 - (0.0001042 * z[2]));
	double porcentagem_OD = (ODinput/cs)*100;
	

	if(porcentagem_OD<= 100)
	{
		double y[5];
		y[0] = 0.01396 * porcentagem_OD + 0.0873;
		y[1] = (pi/56) * (porcentagem_OD - 27);
		y[2] = (pi/85)- (porcentagem_OD - 15);
		y[3] = (porcentagem_OD - 65)/10;
		y[4] = (65 - porcentagem_OD)/10;

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
		qs = 98.24034 - 34.7145 * (log10(CFinput)) + 2.614267 * pow(log10(CFinput),2) + 0.107821 * pow(log10(CFinput),3);
	}
	else

		qs = 3.0;

	return qs;
}
double calculo_PH(double pHinput)
{
	double qs = 0;
	
	if(pHinput <= 2)
		qs = 2.0;
	else if(pHinput <= 6.9)
		qs =  -37.1085 + 41.91277 * pHinput - 15.7043 * pow(pHinput, 2) + 2.417486 * pow(pHinput, 3) - 0.091252 * pow(pHinput, 4);
	else if(pHinput <= 7.1)
		qs = -4.69365 - (21.4593 * pHinput) - (68.4561 * pow(pHinput,2)) + (21.638886 * pow(pHinput,3)) - (1.59165 * pow(pHinput,4));
	else if(pHinput <= 12)
		qs =  -7698.19 + 3262.031 * pHinput - 499.494 * pow(pHinput,2) + 33.1551 * pow(pHinput,3) - 0.810613 * pow(pHinput,4);
	else
		qs = 3.0;

	return qs;								
}
double calculo_DBO(double DBOinput)
{
	double qs = 0;

	if(DBOinput <= 30)
		qs = 100.9571 - 10.7121 * DBOinput + 0.49544 * pow(DBOinput,2) - 0.011167 * pow(DBOinput,3) + 0.0001 * pow(DBOinput,4);
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
	
	if(NO3input <= 10)
		qs = -5.1 * NO3input + 100.17;
	else if(NO3input <= 60)
		qs = -22.853 * log(NO3input) + 101.18;
	else if(NO3input <= 90)
		qs = pow(10, 10) * pow(NO3input, -5.1161);
	else
		qs = 1.0;
	return qs;
}
double calculo_PO4(double POinput)
{
	double qs = 0;
	if(POinput <= 10)
		qs = 79.7 * pow(POinput + 0.821, -1.15);
	else if(POinput > 10)
		qs = 5;
	return qs;
}
double calculo_TU(double TUinput){
	double qs = 0;
	if(TUinput <= 100)
		qs = 90.37 * pow(e, -0.0169 * TUinput) - 15 * cos(0.0571 * (TUinput - 30)) + 10.22 * pow(e, -0.231 * TUinput) - 0.8;
	else
		qs = 5;
	return qs;

}
double calculo_ST(double STinput)
{
	double qs = 0;
	if(STinput <= 500)
		qs = 133.17 * pow(e, -0.0027 * STinput) - 53.17 * pow(e,- 0.0141 * STinput) + ((- 6.2 * pow(e, - 0.00462 * STinput)) * sin(0.0146 * STinput));
	else
		qs = 30.0;
	return qs;
}
double resultados(int cont)
{
	double resultados = 0;

	if(cont == 0)
	{
	resultados = calculo_OD(x[cont]);
	}
	else if(cont == 1)
	{
	resultados = calculo_CF(x[cont]);
	}
	else if (cont == 2)
	{
	resultados = calculo_PH(x[cont]);
	}
	else if (cont == 3)
	{
	resultados = calculo_DBO(x[cont]);
	}
	else if (cont == 4)
	{
	resultados = calculo_VT(x[cont]);
	}
	else if (cont == 5)
	{
	resultados = calculo_NO3(x[cont]);
	}
	else if (cont == 6)
	{
	resultados = calculo_PO4(x[cont]);
	}
	else if (cont == 7)
	{
	resultados = calculo_TU(x[cont]);
	}
	else if (cont == 8)
	{
	resultados = calculo_ST(x[cont]);
	}
	return resultados;
}
void qualidade(double Qinput)
{
	char s[30];

	if(Qinput<=19)
	{
		sprintf(s, "%s", "Pessima");
		printf("IQA = %.2lf - Péssima\n", Qinput);
	}
	else if(Qinput<=36)
	{
		sprintf(s, "%s", "Ruim");
		printf("IQA = %.2lf - Ruim\n", Qinput);
	}
	else if(Qinput<=51)
	{
		sprintf(s, "%s", "Regular");
		printf("IQA = %.2lf - Regular\n", Qinput);
	}
	else if (Qinput<=79)
	{
		sprintf(s, "%s", "Boa");
		printf("IQA = %.2lf - Boa\n", Qinput);
	}
	else
	{
		sprintf(s, "%s", "Otima");
		printf("IQA = %.2lf - Ótima\n", Qinput);
	}
	char result[20];
  	sprintf(result, "%.2lf - %s", Qinput, s);
  	gtk_label_set_text(GTK_LABEL(textview1), result);
}
void IQA()
{
	double iqa2 = 1, produtorio;
	double pesos[9] = {0.17, 0.15, 0.12, 0.1, 0.1, 0.1, 0.1, 0.08, 0.08};
	int i;

	for (i = 0; i < 9; i++)
	{
		produtorio = pow(resultados(i), pesos[i]);
		iqa2 *= produtorio;
	}
	qualidade(iqa2);
}

void on_button1_clicked (GtkButton *button, gpointer data)
{
  char s[100];
  

  int i=0;
  	printf("Iniciando o cálculo de concentração de saturação de oxigênio:\n Os valores padrões para seguir a planilha são:\n Variação da Temperatura(Coluna F) = Temperatura atual\n Concentração de Cloreto = 9.09\n Altitude = 852 metros\n ");
	printf("\n");
	printf("Digite a Temperatura atual da água(ºC)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry1)));
	printf("Digite a Concentração de Cloreto(mg/L)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry2)));
	printf("Digite a Altitude(m)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry3)));
  for(i=0;i<9;i++)
  {
	if(x[i]=0)
	{
	printf("Digite a quantidade de Oxigênio Dissolvido(mg/L)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry4)));
	calculo_OD(x[0]);
	}
	else if(x[i]=1)
	{
	printf("Digite a concentração de Coliformes Fecais(NMP/100mL)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry5)));
	calculo_CF(x[1]);
	}
	else if(x[i]=2)
	{
	printf("Digite a concentração do pH\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry6)));
	calculo_PH(x[2]);
	}
	else if(x[i]=3)
	{
	printf("Digite a concentração da Demanda Bioquímica de Oxigênio(mg/L)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry7)));
	calculo_DBO(x[3]);
	}
	else if(x[i]=4)
	{
	printf("Digite a variação da Temperatura(ºC)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry8)));
	calculo_VT(x[4]);
	}	
	else if(x[i]=5)
	{
	printf("Digite a concentração de Nitratos(mg/L)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry9)));
	calculo_NO3(x[5]);
	}
	else if(x[i]=6)
	{
	printf("Digite a concentração de Fosfatos(mg/L)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry10)));
	calculo_PO4(x[6]);
	}
	else if(x[i]=7)
	{
	printf("Digite a Turbidez(NTU)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry11)));
	calculo_TU(x[7]);
	}
	else if(x[i]=8)
	{
	printf("Digite a concentração de Sólidos Totais(mg/L)\n");
	sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(entry12)));
	calculo_ST(x[8]);
	}
}

	x[i] = strtod(s, NULL);

	IQA();

}

int main(int argc, char *argv[])
{
    //ARRUMAR ISSO
	labelTxt = GTK_WIDGET(gtk_builder_get_object(builder, "resposta"));
    labelOD = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    labelCF = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    labelPH = GTK_WIDGET(gtk_builder_get_object(builder, "entry3"));
    labelDBO = GTK_WIDGET(gtk_builder_get_object(builder, "entry4"));
    labelTemp = GTK_WIDGET(gtk_builder_get_object(builder, "entry5"));
    labelNitrogenio = GTK_WIDGET(gtk_builder_get_object(builder, "entry6"));
    labelFosforo = GTK_WIDGET(gtk_builder_get_object(builder, "entry7"));
    labelTurbidez = GTK_WIDGET(gtk_builder_get_object(builder, "entry8"));
    labelResiduos = GTK_WIDGET(gtk_builder_get_object(builder, "entry9"));

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainui.glade", NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(builder);

    gtk_widget_show(window);                
    gtk_main();

     

    return 0;
}

// called when window is closed
void on_window_main_destroy()
{
    gtk_main_quit();
}
