
/****************************************************************************/
/* エラー定義情報															*/
/****************************************************************************/
//errno, env._id, env._minor, server application r.c., notice1, notice2, keierr, ossenms2 r.c.
ERRINF	errtbl[ERRTBLNUM] =
{
	0,	"************",	0x00000000,	0,	0x00000000,	0x00,	0x0000,	0x00,	0x00000000,
	0,	"COMM_FAILURE",	0x464a0101,	1,	0x00000000,	0xFD,	0xD401,	0xFF,	0x80800097,
	0,	"COMM_FAILURE",	0x464a0901,	1,	0x00000000,	0xFD,	0xD401,	0xFF,	0x80800097,
	0,	"COMM_FAILURE",	0x464a0112,	1,	0x00000000,	0xFD,	0xD401,	0xFF,	0x80800097,
	0,	"COMM_FAILURE",	0x464a0912,	1,	0x00000000,	0xFD,	0xD401,	0xFF,	0x80800097,
	0,	"COMM_FAILURE",	0x00000000,	1,	0x00000000,	0xFD,	0xE200,	0xFF,	0x80800009,
	0,	"TRANSIENT",	0x00000000,	1,	0x00000000,	0xFD,	0xE201,	0xFF,	0x80800009,
	0,	"NO_IMPLEMENT",	0x00000000,	1,	0x00000000,	0xFD,	0xE202,	0xFF,	0x80800009,
	0,	"************",	0x00000000,	-1,	0x80800061,	0x00,	0x0000,	0x00,	0x80800061,
	0,	"************",	0x00000000,	-1,	0x00000000,	0x00,	0x0000,	0x00,	0x80800009,
	0,	"************",	0x00000000,	-2,	0x00000000,	0xFD,	0xE300,	0xFF,	0x00000000,
	0,	"************",	0x00000000,	-3,	0x00000000,	0xFF,	0xE100,	0xF4,	0x00000000,
	0,	"************",	0x00000000,	-4,	0x80800061,	0xFD,	0xE301,	0xFF,	0x00000000,
	0,	"************",	0x00000000,	-4,	0x00000000,	0xFD,	0xE301,	0xFF,	0x00000000,
	ERID_MOCHI,		"************",	0x00000000,	1,	0x00000000,	0xFF,	0xE002,	0xFF,	0x00000000,
	ERID_SNDND,		"************",	0x00000000,	1,	0x00000000,	0xFF,	0xE000,	0xFF,	0x00000000,
	ERID_TOUT,		"************",	0x00000000,	1,	0x00000000,	0xFD,	0xD401,	0xFF,	0x80800097,
	ERID_ENDMDX,	"************",	0x00000000,	1,	0x00000000,	0xFF,	0xE301,	0xFF,	0x80800009
};
