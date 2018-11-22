/* meiolpb.h	�̎ߎێĎ��پ���̎�����						  */
/* 1994.12.19	�����ԡ�������						  */
/* 1995.5.18    dummy����ѹ� 					  M01 */
/* 1995.6.29    ST2866 �Х�����				      M02 */
/* 1995.7.24    ST2866 me_cget��LICP�؎��ĎޤΥХ�������  */
/*												  M03 */
/* 1995.7.25    ST2772   4w on X.25�Ύ��Î������ɲ�	  M04 */
/* 1995.11.09   SSCY0124 4w on X.25iread��rd����  M05 */
/* 1995.11.09   SSCY0124 4w on X.25iread��rd����  M05 */
/* 1995.11.30   SSCY0121 4W-NTMonX.25���ɲä���	  M06 */
/* 1995.11.30   SSCY0121 4W-NTMonX.25�Υ꡼��Ĺ��	  */
/*					�饤��Ĺ�򥻥åȤ���		  M07 */
/* 1996.01.30   SSCY0121 4W on X.25�׎��Ď؎Ďײ��	  M08 */
/* 1996.01.30   ST3972       dummy���ɲä���	  M09 */
/* 1996.02.27   ST4087   4W ���������Î��������ɲ�	  M10 */
/* 1997.04.30   ST4666   4W-NTMonX.25���ێ����ގ̎׎����ɲ�M11 */
/* 1997.08.18   ST4873   ���ێ����ގ̎׎��ޢ������Ď̎׎��ޤ��ѹ� M12 */

#define uchar  unsigned char
#define ushort unsigned short
#define ulong  unsigned long
#define MELDRV   0x01
#define ME4DRV   0x02
#define MELONX25 0x03
#define MELONLAN 0x04
#define ME4ONX25 0x05
#define ME4NONX25 0x06	/* 4W-NTM on X.25�ɲ�					    M06 */

/* M03�ɲá�LICP�؎��ĎޤΥإå���size */
#define	MELONXHEAD	7					/*                          M03 */
#define MELONLHEAD	23					/*                          M03 */

struct meiolpb {
	char	bname[4];	/* ���"MEIO"�Ȥ��롣							*/
	uchar	bottom;		/* {MELDRV|ME4DRV|MELONX25|MELONLAN|ME4ONX25}	*/
	char	dummy1[2];	/* ͽ���� 										*/
	char	setflg;		/* �����Ď̎׎���(s4op�ˎ����Ĥ�����0x10) 			 M12*/
	long	fd;			/* �ե����뵭�һҡ��̣ɣãл��ѻ��ѥ��ɣ�		*/
	ulong	licpid;		/* �̣ɣãХץ����ɣ�							*/
	uchar	ddten;		/* ���ģԣť��ɥ쥹���						*/
	uchar	ddteadr[8];	/* ���ģԣť��ɥ쥹							*/
	uchar	ipksiz;		/* ȯ�Ƽ������ѥ��åȥ�����						*/
	uchar	rpksiz;		/* ��Ƽ������ѥ��åȥ�����						*/
	uchar	iwdsiz;		/* ȯ�Ƽԥ�����ɥ�������						*/
	uchar	rwdsiz;		/* ��Ƽԥ�����ɥ�������						*/
	uchar	fstslct;	/* �ե����ȥ��쥯���׵�							*/
	uchar	account;	/* �忮�ݶ�										*/
	uchar	irtpclas;	/* ȯ����˸Ƽԥ��롼�ץåȥ��饹				*/
	uchar	iexadn;		/* ȯ���ɥ쥹��ĥ���							*/
	uchar	iexadr[20];	/* ȯ���ɥ쥹��ĥ								*/
	uchar	rexadn;		/* �奢�ɥ쥹��ĥ���							*/
	uchar	rexadr[20];	/* �奢�ɥ쥹��ĥ								*/
	uchar	gwproto;	/* �����̎ߎێĎ��� {GW���׎��ʎގ�/TCPIP/HDLC�َ��̎�/4W}	*/
	uchar	gwlno;		/* �ǣ�������ֹ�								*/
	ulong	portnum;	/* ü���ێ����َ��Ďގڎ�(TCP�Ύߎ����ֹ�) �� DL���Ďގڎ�		*/
	char	lpn;		/* �����ѥ��ֹ�									*/
	uchar	prefix;		/* 4WI/O�ץ�ե�����						M01	*/
	ushort	lgln;		/* LCGN+LCN�ֹ�								M01	*/
	long	aplopt;		/* ���ѥ����ƥ४�ץ����						*/
	uchar	ccdctm;		/* ���Ȏ���/�Îގ������Ȏ��ĤΎڎ��Ύߎݎ��Ԥ������� (op/cl)			*/
	char	st_4wX25;	/* 4W on X.25�Ύ��Î�����						M04 */
	short	seglen;		/* ����ʬ��ǡ���Ĺ								*/
	char	l4wsiz;		/* �������楦����ɥ�������						*/
	char	x25hc;		/* X25�λ���ȯ��(0x01)�����(0x02)��			*/
	short	lpteno;		/* TLPT����ȥ��ֹ�			                M02 */
	long	poolid;		/* �ס��뼱�̻�									*/
	long	us4wread;	/* 4WonX.25�ξ���osiread��rd				M05 */
	long	us4wrdad;	/* 4WonX.25�ξ���osiread�Ύ̎ߎ��َʎގ��̎����Ďގڎ�  M05 */
	long	rewrcnt;	/* 4W-NTM on X.25�Υ꡼��Ĺ���饤��Ĺ��Ǽ	M07 */
	short	retry;		/* 4W-NTM on X.25�Υ饤�ȤΥ�ȥ饤���		M08 */
	char	rs4w;		/* 4WonX.25�؎��Ďގ��ώݎĎޤ����������Î�����			M10 */
	char	ws4w;		/* 4WonX.25�׎��Ď��ώݎĎޤ����������Î�����			M10 */
#ifdef OLD
	short	dumm2;		/* dammy									M10 */
#endif
};
typedef struct meiolpb MEIOLPB;
