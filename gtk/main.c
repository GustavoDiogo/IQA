#include <gtk/gtk.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define e 2.71828182845904523536
#define pi 3.14159265358979323846

double x[9];
double z[3];

    GtkBuilder      *builder; 
    GtkWidget       *window;
    GtkWidget       *t;
    GtkWidget       *cs;
    GtkWidget       *h;
    GtkWidget       *od;
    GtkWidget       *cf;
    GtkWidget       *ph;
    GtkWidget       *dbo;
    GtkWidget       *vt;
    GtkWidget       *no3;
    GtkWidget       *po4;
    GtkWidget       *tu;
    GtkWidget       *st;
    GtkWidget       *result;

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
	char s[100];


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
	char resultado[100];
  	sprintf(resultado, "%.2lf - %s", Qinput, s);
  	gtk_label_set_text(GTK_LABEL(result), resultado);
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
  char s[1000];
  //strod transfoma string em double
  	
	z[0] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(t)));
	z[0] = strtod(s, NULL);
	
	z[1] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(cs)));
	z[1] = strtod(s, NULL);
	
	z[2] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(h)));
	z[2] = strtod(s, NULL);

	x[0] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(od)));
	x[0] = strtod(s, NULL);
	calculo_OD(x[0]);

	x[1] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(cf)));
	x[1] = strtod(s, NULL);
	calculo_CF(x[1]);

	x[2] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(ph)));
	x[2] = strtod(s, NULL);
	calculo_PH(x[2]);
	
	x[3] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(dbo)));
	x[3] = strtod(s, NULL);
	calculo_DBO(x[3]);

	x[4] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(vt)));
	x[4] = strtod(s, NULL);
	calculo_VT(x[4]);

	x[5] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(no3)));
	x[5] = strtod(s, NULL);
	calculo_NO3(x[5]);

	x[6] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(po4)));
	x[6] = strtod(s, NULL);
	calculo_PO4(x[6]);

	x[7] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(tu)));
	x[7] = strtod(s, NULL);
	calculo_TU(x[7]);

	x[8] = sprintf(s, "%s", gtk_entry_get_text(GTK_ENTRY(st)));
	x[8] = strtod(s, NULL);
	calculo_ST(x[8]);
	

	IQA();

}

int main(int argc, char *argv[])
{
	printf("Os valores padrões para seguir a planilha são:\n Variação da Temperatura(Coluna F) = Temperatura atual\n Concentração de Cloreto = 9.09\n Altitude = 852 metros\n ");
	printf("\n");

	GObject *button_calculate;
    

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    gtk_builder_add_from_file (builder, "mainui.glade", NULL);

    button_calculate = gtk_builder_get_object (builder, "button1");
    g_signal_connect (button_calculate, "clicked", G_CALLBACK (on_button1_clicked), NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Calculadora IQA"));
    gtk_builder_connect_signals(builder, NULL);

    t = GTK_WIDGET(gtk_builder_get_object(builder, "entry1"));
    cs = GTK_WIDGET(gtk_builder_get_object(builder, "entry2"));
    h = GTK_WIDGET(gtk_builder_get_object(builder, "entry3"));
    od = GTK_WIDGET(gtk_builder_get_object(builder, "entry4"));
    cf = GTK_WIDGET(gtk_builder_get_object(builder, "entry5"));
    ph = GTK_WIDGET(gtk_builder_get_object(builder, "entry6"));
    dbo = GTK_WIDGET(gtk_builder_get_object(builder, "entry7"));
    vt = GTK_WIDGET(gtk_builder_get_object(builder, "entry8"));
    no3 = GTK_WIDGET(gtk_builder_get_object(builder, "entry9"));
    po4 = GTK_WIDGET(gtk_builder_get_object(builder, "entry10"));
    tu = GTK_WIDGET(gtk_builder_get_object(builder, "entry11"));
    st = GTK_WIDGET(gtk_builder_get_object(builder, "entry12"));
    result = GTK_WIDGET(gtk_builder_get_object(builder, "resultado"));

    g_object_unref( G_OBJECT( builder ) );

    gtk_widget_show(window);                
    gtk_main();

    return 0;
}

void on_window_main_destroy()
{
    gtk_main_quit();
}
