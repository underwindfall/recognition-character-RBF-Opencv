/// Autor : Xilong WU, Qifan Yang
#include "opencv2/opencv.hpp"
#include <raspicam/raspicam_cv.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <GST/classifiers/neuroRBF.h>

//les taille de capture image depuis le caméra
#define taille_w 640
#define taille_h 480

//les taille à resize avant de le donner au réseux neuroRBF 
#define taille_w_resize 64
#define taille_h_resize 48
using namespace std;
using namespace cv;
using namespace gst;
//-------------------------------variable globale--------------------------------------------------------------------
// matrice origine capturé par caméra, il est en 1 channel
Mat frame;
// matrice normalisé en 0 et 1
Mat normalized_frame;
// matrice avec la taille compressé
Mat resized_frame;
//Mat src_gray;

//le réseuxRBF à entrainer
neuroRBF rbf;
 //--------------------------------------------------------------------------------------------------------------------

 /// Function header
void learn_image();               // fonction principale pour recevoir les commande de utilisateur depuis les touche clavier
void add_to_categorie(int IDcat); // ajoute d'un vector dans une catégorie donnée
int recognise();                  // fonction de reconnaissance sur l'image actuelle sur l'écran
void print_base2txt(vector<int>); // fonction de débuggage permettnt de sorie les valeurs du vector donné à fichier base_learning.txt 
Mat cut_caractere(Mat);			  // fonction permet de trouver le caractère dans l'image puis retourner seulement une Mat avec le zone d'intérêt



//------------------------------------------fonction principale---------------------------------------------------------
int main(int narg, char *argv[]) {
	
    raspicam::RaspiCam_Cv Camera;
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
    Camera.set ( CV_CAP_PROP_FRAME_WIDTH,  taille_w);
    Camera.set ( CV_CAP_PROP_FRAME_HEIGHT, taille_h);
    Camera.set ( CV_CAP_PROP_BRIGHTNESS,50 );
    Camera.set ( CV_CAP_PROP_CONTRAST ,50);
    Camera.set ( CV_CAP_PROP_SATURATION, 50);
    Camera.set ( CV_CAP_PROP_GAIN, 50 );
    Camera.set ( CV_CAP_PROP_EXPOSURE, 50 );   
    //rbf.restoreneuroRBF("networkBase.txt"); 
    if (!Camera.open()) {
		  cerr<<"Error opening the camera"<<endl;
		  return -1;
	}
	//initialisation de RBF
	//rbf.setnumCat(16);
    printf("Are you ready? Press entre to begin ");
    char str[8];
	cin.getline(str,8);
	printf("\n ---------------------If you'd like to use the network saved before please tape 'l'");
	printf("\n\n\nTape 'shift' + a number --- adding a caracter of number to the network");
	printf("\nTape a alphaber 'a-f'   --- adding a caracter of alphaber to the network");
	printf("\nTape 'l' ------------------ trainning the network");
	printf("\nTape 'r' ------------------ recongizing the actuel image");
	printf("\n\n ---------------------If you'd like to save the network trained please tape 's'");
	//rbf.setvSize(76800); 
	if(strcasecmp("1",str) ==0)
	{
		cout << "OK" << endl;
	}
    for(;;) {
		Camera.grab();
        Camera.retrieve ( frame);
		blur( frame, frame, Size(3,3) ); 			// lisser l'image et élimiler les bruite
	     /// Canny detector
	   //Canny( frame, frame, 10,45, 3 );			// tracer le contour de l'image
	   imshow("camera2",frame);		 				// afficher l'image actuelle
	   normalize(frame,normalized_frame,0,1,NORM_MINMAX); // normaliser le matrice en 0 et 1
	   learn_image();										// attendre les commandes de utilisateur
    }
    Camera.release();
    cout << "that's all folk" << endl;
    // the camera will be deinitialized automatically in VideoCapture destructor   
    return 0;
}


void learn_image()
{
	char key = (char)waitKey(10);
	if(key == (char)'1'){
		if(rbf.neuroRBFCatExists(1) == 0){
			rbf.addNeuroRBFCat(1);
			cout << "creat cat 1" << endl;
		}
		else{
			add_to_categorie(1);
			}
			int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb << endl;
		
	}
	if(key == (char)'0'){
			if(rbf.neuroRBFCatExists(20) == 0){
			rbf.addNeuroRBFCat(20);
			cout << "creat cat 0" << endl;
		}
		else
			add_to_categorie(20);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb << endl;
	}
	if(key == (char)'2'){
			//cout << "2" << endl;
			if(rbf.neuroRBFCatExists(2) == 0){
			rbf.addNeuroRBFCat(2);
			cout << "creat cat 2" << endl;
		}
		else
			add_to_categorie(2);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'3'){
			
			if(rbf.neuroRBFCatExists(3) == 0){
			rbf.addNeuroRBFCat(3);
			cout << "creat cat 3" << endl;
		}
		else
			add_to_categorie(3);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'4'){
			
			if(rbf.neuroRBFCatExists(4) == 0){
			rbf.addNeuroRBFCat(4);
			cout << "creat cat 4" << endl;
		}
		else
			add_to_categorie(4);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'5'){
			
			if(rbf.neuroRBFCatExists(5) == 0){
			rbf.addNeuroRBFCat(5);
			cout << "creat cat 5" << endl;
		}
		else
			add_to_categorie(5);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'6'){
			
			if(rbf.neuroRBFCatExists(6) == 0){
			rbf.addNeuroRBFCat(6);
			cout << "creat cat 6" << endl;
		}
		else
			add_to_categorie(6);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'7'){
			
			if(rbf.neuroRBFCatExists(7) == 0){
			rbf.addNeuroRBFCat(7);
			cout << "creat cat 7" << endl;
		}
		else
			add_to_categorie(7);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'8'){
			if(rbf.neuroRBFCatExists(8) == 0){
			rbf.addNeuroRBFCat(8);
			cout << "creat cat 8" << endl;
		}
		else
			add_to_categorie(8);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'9'){
			
			if(rbf.neuroRBFCatExists(9) == 0){
			rbf.addNeuroRBFCat(9);
			cout << "creat cat 9" << endl;
		}
		else
			add_to_categorie(9);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'a'){
			if(rbf.neuroRBFCatExists(10) == 0){
			rbf.addNeuroRBFCat(10);
			cout << "creat cat A" << endl;
		}
		else{
			add_to_categorie(10);
			int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
		}
	}
	if(key == (char)'b'){
			if(rbf.neuroRBFCatExists(11) == 0){
			rbf.addNeuroRBFCat(11);
			cout << "creat cat B" << endl;
		}
		else
			add_to_categorie(11);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'c'){
			if(rbf.neuroRBFCatExists(12) == 0){
			rbf.addNeuroRBFCat(12);
			cout << "creat cat C" << endl;
		}
		else
			add_to_categorie(12);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'d'){
			if(rbf.neuroRBFCatExists(13) == 0){
			rbf.addNeuroRBFCat(13);
			cout << "creat cat D" << endl;
		}
		else
			add_to_categorie(13);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'e'){
			if(rbf.neuroRBFCatExists(14) == 0){
			rbf.addNeuroRBFCat(14);
			cout << "creat cat E" << endl;
		}
		else
			add_to_categorie(14);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'f'){
			if(rbf.neuroRBFCatExists(15) == 0){
			rbf.addNeuroRBFCat(15);
			cout << "creat cat F" << endl;
		}
		else
			add_to_categorie(15);
		int nb = rbf.getnumCat();
			cout << "Nbr of cat :"<<nb  << endl;
	}
	if(key == (char)'r'){
		int resultat = recognise();
		if(resultat >= 10){
			const char* resu_char;
			if(resultat ==10)
				resu_char= "A";
			if(resultat ==11)
				resu_char= "B";
			if(resultat ==12)
				resu_char= "C";
			if(resultat ==13)
				resu_char= "D";
			if(resultat ==14)
				resu_char= "E";
			if(resultat ==15)
				resu_char= "F";
			if(resultat ==20)
				resu_char= "0";
			cout << "It seem to be one of categorie : "<<resu_char<< endl;
		}			
		else
		cout << "It seem to be one of categorie : "<<resultat << endl;
	}
	if(key == (char)'l'){
		rbf.learnneuroRBF();
		cout << "learnneuroRBF processed"<< endl;
	}
	if(key == (char)'s'){
		rbf.save2neuroRBF("networkBase.txt");
		cout << "Network Rbf was saved to networkBase.txt"<< endl;
	}
	if(key == (char)'g'){
		rbf.restoreneuroRBF("networkBase.txt"); 
		cout << "\nrebuild the network from networkBase.txt"<< endl;
	}
	if(key == (char)'t'){
		cut_caractere(resized_frame);
	}
}
void add_to_categorie(int IDcat){
	neuroRBFCat cat_now = rbf.getnetCat(IDcat);
	resized_frame = cut_caractere(normalized_frame);
	resize(resized_frame,resized_frame,Size(taille_w_resize,taille_h_resize),0,0,CV_INTER_LINEAR);
	std::vector<int> vec;
	if(resized_frame.isContinuous()){
		cout << "add vector to categorie"<< IDcat << endl;
		vec.assign(resized_frame.datastart,resized_frame.dataend); 
	}
	print_base2txt(vec);
	rbf.addVectToCat(vec,IDcat);  
	cout<<"number of vectors learned for the class : "<<cat_now.cSize<<endl;
}
int recognise(){
	std::vector<int> f_vec;
	resized_frame = cut_caractere(normalized_frame);
	resize(resized_frame,resized_frame,Size(taille_w_resize,taille_h_resize),0,0,CV_INTER_LINEAR);
	if(resized_frame.isContinuous()){
		f_vec.assign(resized_frame.datastart,resized_frame.dataend);
	}
	print_base2txt(f_vec);
    return rbf.legacyRecallneuroRBF(f_vec);//rbf.fastRecallneuroRBF(f_vec);////rbf.recallneuroRBF(f_vec);// rbf.recallneuroRBF(f_vec);
}
void print_base2txt(vector<int> vec){
ofstream file;
	file.open("base_learning.txt");
	int nbr=0;
	int line =taille_w_resize;
	for(std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i){
		//std::cout<<*i<<' ';
		file<<*i;
		line--;
		if(line == 0){
			file<<" \n";
			line = taille_w_resize;
		}
		 nbr++;
	 }
	std::cout<<"size vector"<<nbr<< endl;
	file.close();
}
Mat cut_caractere(Mat mat){
	int nbr_begin_line;
	int nbr_begin_col;
	int nbr_fin_line;
	int nbr_fin_col;
	int num_line = 0;
	int nbr_cols =taille_w;
	int nbr_line =taille_h;
	int find=0;
for (int i=1; i<=nbr_line; ++i){
	for(int j=1; j<=nbr_cols; ++j){
		if(mat.at<int>(i,j) == 1){
			//~ cout<<"line : "<<i<<endl;
			//~ cout<<mat.at<int>(i,j)<<endl;
			nbr_begin_line = i-1;
			find = 1;
			break;
		}
	}
		if(find ==1){
			find = 0;
		break;
	}
}
for (int i=1; i<=nbr_cols; ++i){
	for(int j=1; j<=nbr_line; ++j){
		if(mat.at<int>(j,i) == 1){
			//~ cout<<mat.at<int>(j,i)<<endl;
			nbr_begin_col =(int)(i*4);
			//~ cout<<"cols : "<<nbr_begin_col<<endl;
			find = 1;
			break;
		}
	}
		if(find ==1){
			find = 0;
		break;
}
}
for (int i=nbr_cols; i>1; --i){
	for(int j=nbr_line; j>1; --j){
		if(mat.at<int>(j,i) == 1){
			nbr_fin_col =(int)(640-((640-i)*3.3));
			//~ cout<<"nbr_fin_col : "<<nbr_fin_col<<endl;
			find = 1;
			break;
		}
	}
		if(find ==1){
			find = 0;
		break;
}
}
for (int i=nbr_line; i>1; --i){
	for(int j=nbr_cols; j>1; --j){
		if(mat.at<int>(i,j) == 1){
			//~ cout<<"line_fin : "<<i<<endl;
			nbr_fin_line = i+1;
			find = 1;
			break;
		}
	}
		if(find ==1){
			find = 0;
		break;
	}
}
// Rectangle à couper après le détection
Rect carac(nbr_begin_col,nbr_begin_line,nbr_fin_col-nbr_begin_col,nbr_fin_line-nbr_begin_line);
Mat image_roi = mat(carac);
return image_roi;
}
