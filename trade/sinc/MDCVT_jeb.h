/****************************************************************************/
/*	���	��������														*/
/*			��������ңΣԣԥǡ���											*/
/*				��ͻ�ӥ��ͥ���������										*/
/*--------------------------------------------------------------------------*/
/* �㳫ȯô��̾��					 �ӥ��ͥ����ô��						*/
/* �������ֹ��						 148-1457(03-5437-1457)					*/
/*--------------------------------------------------------------------------*/
/* ���߷׼�̾��						 ��������								*/
/* ���߷�ǯ������					 ��������ǯ���������					*/
/*--------------------------------------------------------------------------*/
/* �㵡ǽ���ס�		�ʣɣӢ��ţ£ãģɣáʣ��Х��ȡ��Ѵ��ơ��֥�			*/
/****************************************************************************/
struct MDCVT_jeb{
	char umu;
	char value;
}MDCVT_jeb[256]={
/*--------------------------------------------------------------------------*/
/* ���/̤�������		�Ѵ���						�ʣɣӥ�����			*/
/*--------------------------------------------------------------------------*/
		{0x01,			0x00},			/*		0x00		NUL				*/
		{0x01,			0x01},			/*		0x01		SOH				*/
		{0x01,			0x02},			/*		0x02		STX				*/
		{0x01,			0x03},			/*		0x03		ETX				*/
		{0x01,			0x37},			/*		0x04		EOT 			*/
		{0x01,			0x2d},			/*		0x05		ENQ				*/
		{0x01,			0x2e},			/*		0x06		ACK 			*/
		{0x01,			0x2f},			/*		0x07		BEL				*/
		{0x01,			0x16},			/*		0x08		BS  			*/
		{0x01,			0x05},			/*		0x09		HT  			*/
		{0x01,			0x25},			/*		0x0a		IF  			*/
		{0x01,			0x0b},			/*		0x0b		VT				*/
		{0x01,			0x0c},			/*		0x0c		FF				*/
		{0x01,			0x0d},			/*		0x0d		CR				*/
		{0x01,			0x0e},			/*		0x0e		SO				*/
		{0x01,			0x0f},			/*		0x0f		SI				*/
		{0x01,			0x10},			/*		0x10		DEL				*/
		{0x01,			0x11},			/*		0x11		DC1				*/
		{0x01,			0x12},			/*		0x12		DC2				*/
		{0x01,			0x13},			/*		0x13		DC3				*/
		{0x01,			0x3c},			/*		0x14		DC4 			*/
		{0x01,			0x3d},			/*		0x15		NAK				*/
		{0x01,			0x32},			/*		0x16		SYN				*/
		{0x01,			0x26},			/*		0x17		ETB 			*/
		{0x01,			0x18},			/*		0x18		CAN				*/
		{0x01,			0x19},			/*		0x19		EM				*/
		{0x01,			0x3f},			/*		0x1a		SUB 			*/
		{0x01,			0x27},			/*		0x1b		ESC 			*/
		{0x01,			0x10},			/*		0x1c		SS  			*/
		{0x01,			0x1d},			/*		0x1d		GS				*/
		{0x01,			0x1e},			/*		0x1e		RS				*/
		{0x01,			0x1f},			/*		0x1f		US				*/
		{0x01,			0x40},			/*		0x20		���ڡ���		*/
		{0x01,			0x5a},			/*		0x21		����			*/
		{0x01,			0x7f},			/*		0x22		�ɡʰ������	*/
		{0x01,			0x7b},			/*		0x23		����			*/
		{0x01,			0xe0},			/*		0x24		�� 				*/
		{0x01,			0x6c},			/*		0x25		��				*/
		{0x01,			0x50},			/*		0x26		��				*/
		{0x01,			0x7d},			/*		0x27		�ǥ��ݥ��ȥ��ե�*/
		{0x01,			0x4d},			/*		0x28		��				*/
		{0x01,			0x5d},			/*		0x29		��				*/
		{0x01,			0x5c},			/*		0x2a		��				*/
		{0x01,			0x4e},			/*		0x2b		��				*/
		{0x01,			0x6b},			/*		0x2c		���ʥ���ޡ�	*/
		{0x01,			0x60},			/*		0x2d		�� �ǥ������	*/
		{0x01,			0x4b},			/*		0x2e		���ԥꥪ��		*/
		{0x01,			0x61},			/*		0x2f		�� ����å���	*/
		{0x01,			0xf0},			/*		0x30		��				*/
		{0x01,			0xf1},			/*		0x31		��				*/
		{0x01,			0xf2},			/*		0x32		��				*/
		{0x01,			0xf3},			/*		0x33		��				*/
		{0x01,			0xf4},			/*		0x34		��				*/
		{0x01,			0xf5},			/*		0x35		��				*/
		{0x01,			0xf6},			/*		0x36		��				*/
		{0x01,			0xf7},			/*		0x37		��				*/
		{0x01,			0xf8},			/*		0x38		��				*/
		{0x01,			0xf9},			/*		0x39		��				*/
		{0x01,			0x7a},			/*		0x3a		�� ������		*/
		{0x01,			0x5e},			/*		0x3b		�� ���ߥ�����	*/
		{0x01,			0x4c},			/*		0x3c		��				*/
		{0x01,			0x7e},			/*		0x3d		��				*/
		{0x01,			0x6e},			/*		0x3e		��				*/
		{0x01,			0x6f},			/*		0x3f		��				*/
		{0x01,			0x7c},			/*		0x40		��				*/
		{0x01,			0xc1},			/*		0x41		��				*/
		{0x01,			0xc2},			/*		0x42		��				*/
		{0x01,			0xc3},			/*		0x43		��				*/
		{0x01,			0xc4},			/*		0x44		��				*/
		{0x01,			0xc5},			/*		0x45		��				*/
		{0x01,			0xc6},			/*		0x46		��				*/
		{0x01,			0xc7},			/*		0x47		��				*/
		{0x01,			0xc8},			/*		0x48		��				*/
		{0x01,			0xc9},			/*		0x49		��				*/
		{0x01,			0xd1},			/*		0x4a		��				*/
		{0x01,			0xd2},			/*		0x4b		��				*/
		{0x01,			0xd3},			/*		0x4c		��				*/
		{0x01,			0xd4},			/*		0x4d		��				*/
		{0x01,			0xd5},			/*		0x4e		��				*/
		{0x01,			0xd6},			/*		0x4f		��				*/
		{0x01,			0xd7},			/*		0x50		��				*/
		{0x01,			0xd8},			/*		0x51		��				*/
		{0x01,			0xd9},			/*		0x52		��				*/
		{0x01,			0xe2},			/*		0x53		��				*/
		{0x01,			0xe3},			/*		0x54		��				*/
		{0x01,			0xe4},			/*		0x55		��				*/
		{0x01,			0xe5},			/*		0x56		��				*/
		{0x01,			0xe6},			/*		0x57		��				*/
		{0x01,			0xe7},			/*		0x58		��				*/
		{0x01,			0xe8},			/*		0x59		��				*/
		{0x01,			0xe9},			/*		0x5a		��				*/
		{0x00,			0x00},			/*		0x5b		��				*/
		{0x01,			0x5b},			/*		0x5c		��				*/
		{0x00,			0x00},			/*		0x5d		��				*/
		{0x01,			0x5f},			/*		0x5e		��				*/
		{0x01,			0x6d},			/*		0x5f		_ ��������饤��*/
		{0x01,			0x79},			/*		0x60		��				*/
		{0x01,			0x63},			/*		0x61		a				*/
		{0x00,			0x00},			/*		0x62		b				*/
		{0x00,			0x00},			/*		0x63		c ̤���		*/
		{0x00,			0x00},			/*		0x64		d ̤���		*/
		{0x00,			0x00},			/*		0x65		e ̤���		*/
		{0x00,			0x00},			/*		0x66		f ̤���		*/
		{0x00,			0x00},			/*		0x67		g ̤���		*/
		{0x00,			0x00},			/*		0x68		h ̤���		*/
		{0x00,			0x00},			/*		0x69		i ̤���		*/
		{0x00,			0x00},			/*		0x6a		j ̤���		*/
		{0x00,			0x00},			/*		0x6b		k ̤���		*/
		{0x00,			0x00},			/*		0x6c		l ̤���		*/
		{0x00,			0x00},			/*		0x6d		m ̤���		*/
		{0x00,			0x00},			/*		0x6e		n ̤���		*/
		{0x00,			0x00},			/*		0x6f		o ̤���		*/
		{0x01,			0xb0},			/*		0x70		p0(p)			*/
		{0x01,			0xb1},			/*		0x71		p1(q)			*/
		{0x01,			0xb2},			/*		0x72		p2(r)			*/
		{0x01,			0xb3},			/*		0x73		p3(s)			*/
		{0x01,			0xb4},			/*		0x74		p4(t)			*/
		{0x01,			0xb5},			/*		0x75		p5(u)			*/
		{0x01,			0xb6},			/*		0x76		p6(v)			*/
		{0x01,			0xb7},			/*		0x77		p7(w)			*/
		{0x01,			0xb8},			/*		0x78		p8(x)			*/
		{0x01,			0xb9},			/*		0x79		p9(y)			*/
		{0x01,			0xfa},			/*		0x7a		p10(z)			*/
		{0x00,			0x00},			/*		0x7b		p11(})	̤���	*/
		{0x01,			0x6a},			/*		0x7c		�� ����			*/
		{0x01,			0xd0},			/*		0x7d		��				*/
		{0x01,			0xa1},			/*		0x7e		~ ���ݥСݥ饤��*/
		{0x01,			0x07},			/*		0x7f		DEL				*/
		{0x01,			0x00},			/*		0x80		NUL				*/
		{0x01,			0x01},			/*		0x81		SOH				*/
		{0x01,			0x02},			/*		0x82		STX				*/
		{0x01,			0x03},			/*		0x83		ETX				*/
		{0x01,			0x37},			/*		0x84		EOT				*/
		{0x01,			0x2d},			/*		0x85		ENQ				*/
		{0x01,			0x2e},			/*		0x86		ACK				*/
		{0x01,			0x2f},			/*		0x87		BEL				*/
		{0x01,			0x16},			/*		0x88		BS				*/
		{0x01,			0x05},			/*		0x89		HT				*/
		{0x01,			0x25},			/*		0x8a		LF				*/
		{0x01,			0x0b},			/*		0x8b		VT				*/
		{0x01,			0x0c},			/*		0x8c		FF				*/
		{0x01,			0x0d},			/*		0x8d		CR				*/
		{0x01,			0x0e},			/*		0x8e		SO				*/
		{0x01,			0x0f},			/*		0x8f		SI				*/
		{0x00,			0x00},			/*		0x90		DLE	̤���		*/
		{0x01,			0x11},			/*		0x91		DC1				*/
		{0x01,			0x12},			/*		0x92		DC2				*/
		{0x01,			0x13},			/*		0x93		DC3				*/
		{0x01,			0x3c},			/*		0x94		DC4				*/
		{0x01,			0x3d},			/*		0x95		NAK				*/
		{0x01,			0x32},			/*		0x96		SYN				*/
		{0x01,			0x26},			/*		0x97		ETB				*/
		{0x01,			0x18},			/*		0x98		CAN				*/
		{0x01,			0x19},			/*		0x99		EM				*/
		{0x01,			0x3f},			/*		0x9a		SUB				*/
		{0x01,			0x27},			/*		0x9b		ESC				*/
		{0x01,			0x10},			/*		0x9c		SS				*/
		{0x01,			0x1d},			/*		0x9d		GS				*/
		{0x01,			0x1e},			/*		0x9e		RS				*/
		{0x01,			0x1f},			/*		0x9f		US				*/
		{0x01,			0x40},			/*		0xa0		SP				*/
		{0x01,			0x41},			/*		0xa1		�� ����		    */
		{0x01,			0x42},			/*		0xa2		��				*/
		{0x01,			0x43},			/*		0xa3		��				*/
		{0x01,			0x44},			/*		0xa4		�� ����			*/
		{0x01,			0x45},			/*		0xa5		�� ����			*/
		{0x01,			0x46},			/*		0xa6		��				*/
		{0x01,			0x47},			/*		0xa7		��				*/
		{0x01,			0x48},			/*		0xa8		��				*/
		{0x01,			0x49},			/*		0xa9		��				*/
		{0x01,			0x51},			/*		0xaa		��				*/
		{0x01,			0x52},			/*		0xab		��				*/
		{0x01,			0x53},			/*		0xac		��				*/
		{0x01,			0x54},			/*		0xad		��				*/
		{0x01,			0x55},			/*		0xae		��				*/
		{0x01,			0x56},			/*		0xaf		��				*/
		{0x01,			0x60},			/*		0xb0		�� Ĺ��			*/
		{0x01,			0x81},			/*		0xb1		����			*/
		{0x01,			0x82},			/*		0xb2		����			*/
		{0x01,			0x83},			/*		0xb3		����			*/
		{0x01,			0x84},			/*		0xb4		����			*/
		{0x01,			0x85},			/*		0xb5		����			*/
		{0x01,			0x86},			/*		0xb6		����			*/
		{0x01,			0x87},			/*		0xb7		����			*/
		{0x01,			0x88},			/*		0xb8		����			*/
		{0x01,			0x89},			/*		0xb9		����			*/
		{0x01,			0x8a},			/*		0xba		����			*/
		{0x01,			0x8c},			/*		0xbb		����			*/
		{0x01,			0x8d},			/*		0xbc		����			*/
		{0x01,			0x8e},			/*		0xbd		����			*/
		{0x01,			0x8f},			/*		0xbe		����			*/
		{0x01,			0x90},			/*		0xbf		����			*/
		{0x01,			0x91},			/*		0xc0		����			*/	
		{0x01,			0x92},			/*		0xc1		����			*/
		{0x01,			0x93},			/*		0xc2		�ġ�			*/
		{0x01,			0x94},			/*		0xc3		�ơ�			*/
		{0x01,			0x95},			/*		0xc4		�ȡ�			*/
		{0x01,			0x96},			/*		0xc5		�ʡ�			*/
		{0x01,			0x97},			/*		0xc6		�ˡ�			*/
		{0x01,			0x98},			/*		0xc7		�̡�			*/
		{0x01,			0x99},			/*		0xc8		�͡�			*/
		{0x01,			0x9a},			/*		0xc9		�Ρ�			*/
		{0x01,			0x9d},			/*		0xca		�ϡ�			*/
		{0x01,			0x9e},			/*		0xcb		�ҡ�			*/
		{0x01,			0x9f},			/*		0xcc		�ա�			*/
		{0x01,			0xa2},			/*		0xcd		�ء�			*/
		{0x01,			0xa3},			/*		0xce		�ۡ�			*/
		{0x01,			0xa4},			/*		0xcf		�ޡ�			*/
		{0x01,			0xa5},			/*		0xd0		�ߡ�			*/
		{0x01,			0xa6},			/*		0xd1		���			*/
		{0x01,			0xa7},			/*		0xd2		���			*/
		{0x01,			0xa8},			/*		0xd3		���			*/
		{0x01,			0xa9},			/*		0xd4		���			*/
		{0x01,			0xaa},			/*		0xd5		���			*/
		{0x01,			0xac},			/*		0xd6		���			*/
		{0x01,			0xad},			/*		0xd7		���			*/
		{0x01,			0xae},			/*		0xd8		���			*/
		{0x01,			0xaf},			/*		0xd9		���			*/
		{0x01,			0xba},			/*		0xda		���			*/
		{0x01,			0xbb},			/*		0xdb		����			*/
		{0x01,			0xbc},			/*		0xdc		���			*/
		{0x01,			0xbd},			/*		0xdd		���			*/
		{0x01,			0xbe},			/*		0xde		����			*/
		{0x01,			0xbf},			/*		0xdf		Ⱦ����			*/
		{0x00,			0x00},			/*		0xe0		̤���			*/
		{0x00,			0x00},			/*		0xe1		̤���			*/
		{0x00,			0x00},			/*		0xe2		̤���			*/
		{0x00,			0x00},			/*		0xe3		̤���			*/
		{0x00,			0x00},			/*		0xe4		̤���			*/
		{0x00,			0x00},			/*		0xe5		̤���			*/
		{0x00,			0x00},			/*		0xe6		̤���			*/
		{0x00,			0x00},			/*		0xe7		̤���			*/
		{0x00,			0x00},			/*		0xe8		̤���			*/
		{0x00,			0x00},			/*		0xe9		̤���			*/
		{0x00,			0x00},			/*		0xea		̤���			*/
		{0x00,			0x00},			/*		0xeb		̤���			*/
		{0x00,			0x00},			/*		0xec		̤���			*/
		{0x00,			0x00},			/*		0xed		̤���			*/
		{0x00,			0x00},			/*		0xee		̤���			*/
		{0x00,			0x00},			/*		0xef		̤���			*/
		{0x01,			0xb0},			/*		0xf0		p0				*/
		{0x01,			0xb1},			/*		0xf1		p1				*/
		{0x01,			0xb2},			/*		0xf2		p2				*/
		{0x01,			0xb3},			/*		0xf3		p3				*/
		{0x01,			0xb4},			/*		0xf4		p4				*/
		{0x01,			0xb5},			/*		0xf5		p5				*/
		{0x01,			0xb6},			/*		0xf6		p6				*/
		{0x01,			0xb7},			/*		0xf7		p7				*/
		{0x01,			0xb8},			/*		0xf8		p8				*/
		{0x01,			0xb9},			/*		0xf9		p9				*/
		{0x01,			0xfa},			/*		0xfa		p10				*/
		{0x00,			0x00},			/*		0xfb		p11				*/
		{0x00,			0x00},			/*		0xfc		̤���			*/
		{0x00,			0x00},			/*		0xfd		̤���			*/
		{0x00,			0x00},			/*		0xfe		̤���			*/
		{0x00,			0x00} 			/*		0xff		DEL ̤���		*/
};
