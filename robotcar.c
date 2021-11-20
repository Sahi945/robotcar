#include<reg51.h>
// motor input connection//
sbit m1p=P2^0;
sbit m1n=P2^1;
sbit m2p=P2^2;
sbit m2n=P2^3;
sbit l1p=P1^0;
sbit ln=P1^1;
sbit l2p=P1^2;
sbit left=P1^3;
sbit right=P1^4;
sbit b1p=P1^5;
sbit m3p=P2^4;
sbit m3n=P2^5;
sbit m4p=P2^6;
sbit m4n=P2^7;
void txdata(unsigned char);
void main()
{
	unsigned char x;
	unsigned char msg1[]={"Car is moving forward \n"};
unsigned char msg2[]={"Car is moving backward \n"};
unsigned char msg3[]={"Car is moving right \n"};
unsigned char msg4[]={"Car is moving left \n"};
unsigned char msg5[]={"Car is stopped \n"};
	SCON=0X50;
	TMOD=0X20;
	TH1=-3;
	TR1=1; //INITIALISE SERIAL COMMUNICATION
	while(1)
	{
		while (RI==0);
		x=SBUF;
		RI=0;
		SBUF=x;
		while(TI==0);
		TI=0;
		if(x=='F')
		{
			//robot moves forward
			l1p=1;
			ln=0;
			l2p=0;
			m1p=1;
			m1n=0;
			m2p=1;
			m2n=0;
			b1p=0;
			m3p=1;
			m3n=0;
			m4p=1;
			m4n=0;
			left=1;
			right=0;
			for(x=0;msg1[x]!='\0';x++)
{
    txdata(msg1[x]);
} 
		}
		if(x=='B')
		{
			l1p=1;
			ln=0;
			l2p=1;
			//robot moves backbard
			m1p=0;
			m1n=1;
			m2p=0;
			m2n=1;
			b1p=1; 
			m3p=0;
			m3n=1;
			m4p=0;
			m4n=1;
			left=1;
		  right=1;
			for(x=0;msg2[x]!='\0';x++)
{
    txdata(msg2[x]);
} 
		}
		if(x=='R')
		{
			//robot moves right
			l1p=0;
			l2p=0;
			ln=0;
			m1p=0;
			m1n=1;
			m2p=1;
			m2n=0;
			b1p=0;
			m3p=0;
			m3n=0;
			m4p=0;
			m4n=0;
		  right=1;
			left=1;
			for(x=0;msg3[x]!='\0';x++)
{
    txdata(msg3[x]);
} 
		}
		if(x=='L')
		{
			l1p=1;
			l2p=1;
			ln=0;
			//robot moves left
			m1p=1;
			m1n=0;
			m2p=0;
			m2n=1;
			b1p=0; 
			m3p=0;
			m3n=0;
			m4p=0;
			m4n=0;
			left=0;
			right=0;
			for(x=0;msg4[x]!='\0';x++)
{
    txdata(msg4[x]);
} 
		}
		if(x=='S')
		{
			l1p=0;
			ln=0;
			l2p=0;
			m1p=0;
			m1n=0;
			m2p=0;
			m2n=0;
			b1p=0; 
			m3p=0;
			m3n=0;
			m4p=0;
			m4n=0;
			left=right=1;
			for(x=0;msg5[x]!='\0';x++)
				{
						txdata(msg5[x]);
				} 
		}
		if(x=='V')
		{
			l1p=1;
			ln=0;
			l2p=1;
			m1p=0;
			m1n=0;
			m2p=0;
			m2n=0;
			b1p=1;
			m3p=0;
			m3n=0;
			m4p=0;
			m4n=0;
			left=right=1;
		}
		if(x=='v')
		{
			l1p=1;
			ln=0;
			l2p=0;
			m1p=0;
			m1n=0;
			m2p=0;
			m2n=0;
			b1p=0;
			m3p=0;
			m3n=0;
			m4p=0;
			m4n=0;
			left=1;
			right=0;
		}
	}
}
void txdata(unsigned char x)
{
   SBUF=x; //copy data to be transmitted to SBUF
   while(TI==0); //wait till TI becomes high
   TI=0; //mae TI low for next transmission
}