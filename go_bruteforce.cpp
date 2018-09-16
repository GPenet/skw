// skwgoa.cpp : general routines and tests

extern ZHOU  zhou[50];
extern void  rowminlex(char *in, char *out);

void M0_testzhou(char *finput_name){
	int nbon=0;
	finput.SetName(finput_name);
	if(finput.OpenFI()){   
		cerr << "error open file "<<finput_name
			<< " finp " << finput.namex << endl;		return ;	}

	char zpuz[82],zout[82]; zout[81]=zpuz[81]=0;
	int lim=100; //100000;
	cout << "test brute force"<<endl;
	while(finput.GetPuzzle(zpuz))  {
		long tdeb=GetTimeMillis();
		// First find the solution 
		int ir=(zhou[0].CheckValidityQuick(zpuz)-1);
		cout << zpuz<<"a traiter ir=" <<ir<<endl;	
		GINT tgint[81];
		int ntgint=0;
		for(int i=0;i<81;i++) 	if(zpuz[i]>'0' && zpuz[i]<= '9')
			tgint[ntgint++].u32=i+((zpuz[i]-'1')<<8);
		int ir2=zhou[0].StatusValid(tgint,ntgint,4)-1;

		long tfin=GetTimeMillis();
		cout <<"retour zhouquickest ir=" <<ir<< "ir2=" <<ir2<<" durée="<<(int)(tfin-tdeb)<<endl;
		tdeb=tfin;
//		if(!ir) nbon++;
//		else cout <<zpuz<<endl;
	}
//	cerr<< "nbon=" << nbon<<endl;
}

/*

void M0_testzhou(char *finput_name){ // le etst de comparatif
	int nbon=0;
	finput.SetName(finput_name);
	if(finput.OpenFI()){   
		cerr << "error open file "<<finput_name
			<< " finp " << finput.namex << endl;		return ;	}

	char zpuz[82],zout[82]; zout[81]=zpuz[81]=0;
	int lim=100; //100000;
	while(finput.GetPuzzle(zpuz))  {
		cout << zpuz<<"a traiter"<<endl;		
		long tdeb=GetTimeMillis();
		// First find the solution 
		int ir=(zhou[0].CheckValidityQuick(zpuz)-1);
		for(int i=0;i<lim;i++)zhou[0].CheckValidityQuick(zpuz);
		long tfin=GetTimeMillis();
		cout <<"retour zhou ir=" <<ir<< " durée="<<(int)(tfin-tdeb)<<endl;
		tdeb=tfin;
		ir=(zhou[0].CheckValidityQuickest(zpuz)-1);
		for(int i=0;i<lim;i++)zhou[0].CheckValidityQuickest(zpuz);
		tfin=GetTimeMillis();
		cout <<"retour zhouquickest ir=" <<ir<< " durée="<<(int)(tfin-tdeb)<<endl;
		tdeb=tfin;
		ir=(zhou[0].CheckValidityQuickest(zpuz,50)-1);
		for(int i=0;i<lim;i++)zhou[0].CheckValidityQuickest(zpuz,50);
		tfin=GetTimeMillis();
		cout <<"retour zhouquickest no sym ir=" <<ir<< " durée="<<(int)(tfin-tdeb)<<endl;
		tdeb=tfin;
//		if(!ir) nbon++;
//		else cout <<zpuz<<endl;
	}
//	cerr<< "nbon=" << nbon<<endl;
}


*/