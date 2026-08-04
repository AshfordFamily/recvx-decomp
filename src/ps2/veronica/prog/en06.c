#include "../../../ps2/veronica/prog/en06.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_NaMath.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/Motion.h"

// ENEMY: MOTH

/*typedef struct npobj;
typedef struct _anon0;
typedef struct BH_PWORK;
typedef struct _anon1;
typedef struct _anon2;
typedef struct _anon3;
typedef struct _anon4;
typedef struct _anon5;
typedef struct _anon6;
typedef struct _anon7;
typedef struct _anon8;
typedef struct _anon9;
typedef struct _anon10;
typedef struct _anon11;
typedef struct _anon12;
typedef struct _anon13;
typedef struct _anon14;
typedef struct _anon15;
typedef struct _anon16;
typedef struct _anon17;
typedef struct _anon18;
typedef struct _anon19;
typedef struct _anon20;
typedef struct _anon21;
typedef struct _anon22;
typedef struct _anon23;
typedef struct _anon24;
typedef struct _anon25;
typedef struct _anon26;
typedef struct _anon27;
typedef struct _anon28;
typedef struct _anon29;
typedef struct _anon30;
typedef struct _anon31;
typedef struct _anon32;
typedef struct _anon33;
typedef struct _anon34;
typedef struct _anon35;
typedef struct _anon36;
typedef struct _anon37;
typedef struct _anon38;
typedef struct _anon39;
typedef struct _anon40;
typedef struct _anon41;
typedef struct _anon42;
typedef struct _anon43;
typedef struct _anon44;
typedef struct _anon45;
typedef struct _anon46;
typedef struct _anon47;

typedef void(*type_10)(BH_PWORK*);
typedef void(*type_24)(BH_PWORK*);
typedef void(*type_44)(BH_PWORK*);
typedef void(*type_56)(BH_PWORK*);
typedef void(*type_81)(BH_PWORK*);
typedef void(*type_99)(BH_PWORK*);
typedef void(*type_105)(BH_PWORK*);
typedef void(*type_108)(void*);

typedef unsigned int type_0[4];
typedef _anon0* type_1[512];
typedef _anon0* type_2[32];
typedef _anon1* type_3[16];
typedef _anon0* type_4[32];
typedef _anon0* type_5[512];
typedef _anon1* type_6[16][16];
typedef _anon1* type_7[16][16][100];
typedef char type_8[8];
typedef _anon0* type_9[32];
typedef _anon0* type_11[512];
typedef void(*type_12)(BH_PWORK*)[1];
typedef char type_13[8];
typedef _anon1* type_14[1300];
typedef char type_15[8][8];
typedef char type_16[32];
typedef float type_17[32];
typedef _anon0* type_18[512];
typedef int type_19[2];
typedef _anon1* type_20[200];
typedef char type_21[3];
typedef short type_22[32];
typedef _anon27 type_23[1];
typedef void(*type_25)(BH_PWORK*)[5];
typedef _anon0* type_26[128];
typedef char type_27[3];
typedef unsigned int type_28[1];
typedef _anon9 type_29[256];
typedef _anon1* type_30[8];
typedef int* type_31[16];
typedef _anon0* type_32[128];
typedef _anon47 type_33[16];
typedef npobj* type_34[16];
typedef _anon0* type_35[128];
typedef int type_36[4];
typedef _anon1* type_37[16];
typedef _anon7 type_38[21];
typedef unsigned int type_39[4];
typedef float type_40[4];
typedef _anon14 type_41[16];
typedef _anon0* type_42[512];
typedef float type_43[4];
typedef void(*type_45)(BH_PWORK*)[1];
typedef char type_46[256];
typedef float type_47[4];
typedef float type_48[4];
typedef char type_49[12];
typedef float type_50[4];
typedef float type_51[4];
typedef _anon6* type_52[128];
typedef unsigned char type_53[64];
typedef float type_54[16];
typedef float type_55[3];
typedef void(*type_57)(BH_PWORK*)[6];
typedef unsigned short type_58[3];
typedef char type_59[8];
typedef char type_60[4];
typedef int type_61[16];
typedef unsigned int type_62[3];
typedef void* type_63[2];
typedef _anon1* type_64[256];
typedef int type_65[4];
typedef unsigned char* type_66[256];
typedef unsigned int type_67[2];
typedef short type_68[256];
typedef BH_PWORK type_69[0];
typedef _anon32 type_70[4];
typedef float type_71[3];
typedef short type_72[256];
typedef _anon0 type_73[0];
typedef int type_74[3];
typedef int type_75[8];
typedef float type_76[3];
typedef char type_77[2];
typedef _anon1* type_78[256];
typedef _anon11 type_79[256];
typedef _anon27 type_80[450];
typedef void(*type_82)(BH_PWORK*)[11];
typedef _anon34 type_83[16];
typedef short type_84[256];
typedef char type_85[3];
typedef int type_86[64];
typedef _anon14 type_87[450];
typedef unsigned int type_88[16];
typedef unsigned int type_89[8];
typedef char type_90[4];
typedef _anon39 type_91[4];
typedef _anon36 type_92[23];
typedef _anon2 type_93[4];
typedef int type_94[450];
typedef unsigned int type_95[8];
typedef unsigned char type_96[450];
typedef float type_97[128];
typedef float type_98[5];
typedef void(*type_100)(BH_PWORK*)[2];
typedef int type_101[5];
typedef char type_102[6];
typedef char type_103[6][1];
typedef char type_104[16];
typedef char type_106[4];
typedef char type_107[4];
typedef unsigned int type_109[32];
typedef _anon25 type_110[2];
typedef _anon28 type_111[8];
typedef unsigned char type_112[256];
typedef unsigned int type_113[16];
typedef _anon22 type_114[64];
typedef unsigned int type_115[16];
typedef _anon22 type_116[64];
typedef unsigned int type_117[32];
typedef _anon22 type_118[64];
typedef unsigned int type_119[16];
typedef unsigned int type_120[3];
typedef BH_PWORK* type_121[16];
typedef unsigned int type_122[8];
typedef unsigned int type_123[1];
typedef unsigned int type_124[384];
typedef unsigned int type_125[2];
typedef unsigned char type_126[2];
typedef unsigned int type_127[4];
typedef int* type_128[16];
typedef char type_129[32];
typedef npobj* type_130[16];
typedef char type_131[64];
typedef _anon1* type_132[16];
typedef char type_133[4];
typedef _anon14 type_134[16];
typedef short type_135[4];
typedef unsigned char type_136[4];
typedef _anon37 type_137[16];
typedef unsigned int type_138[8];
typedef unsigned int type_139[32];
typedef unsigned int type_140[4];
typedef _anon35 type_141[32];
typedef _anon0* type_142[512];
typedef _anon0* type_143[128];
typedef _anon0* type_144[512];
typedef unsigned char type_145[64];
typedef _anon0* type_146[512];

struct npobj
{
	unsigned int evalflags;
	_anon33* model;
	float pos[3];
	int ang[3];
	float scl[3];
	npobj* child;
	npobj* sibling;
};

struct _anon0
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon1* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon6* mnwP;
	_anon6* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	unsigned char* objbak;
	_anon45 cspr;
	int pn;
	_anon39* pvp;
	_anon2* tvp;
	_anon39 pv[4];
	_anon2 tv[4];
	int bl_src;
	int bl_dst;
	int ani_ct;
	int tex_id;
	int aspd;
	unsigned int gidx;
	int bank;
	char jno[16];
	char hide[4];
	void(*func)(void*);
	int idx;
	int Dummy2;
};

struct BH_PWORK
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	char flr_nob;
	unsigned char mdlver;
	unsigned char param;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	float px;
	float py;
	float pz;
	int ax;
	int ay;
	int az;
	float ar;
	float aw;
	float ah;
	float ad;
	float car;
	float cah;
	float pxb;
	float pyb;
	float pzb;
	int axb;
	int ayb;
	int azb;
	float gpx;
	float gpy;
	float gpz;
	float lox;
	float loy;
	float loz;
	float aox;
	float aoy;
	float aoz;
	float spd;
	unsigned int flg2;
	unsigned int mdflg;
	unsigned int stflg;
	unsigned int Dummy3;
	int draw_tp;
	int mdl_n;
	void* mskp;
	unsigned int Dummy[1];
	int* skp[16];
	npobj* mbp[16];
	_anon1* txp[16];
	_anon14 mdl[16];
	_anon14* mlwP;
	unsigned int mdl_no;
	int lkono;
	unsigned char* lkwkp;
	unsigned char* exp0;
	unsigned char* exp1;
	unsigned char* exp2;
	unsigned char* exp3;
	unsigned char mtxbuf[64];
	float mtx[16];
	npobj* obj_a;
	npobj* obj_b;
	float shp_ct;
	char clp_jno[8];
	int lok_jno;
	_anon6* mnwP;
	_anon6* mnwPb;
	unsigned int mtn_attr;
	unsigned int mtn_no;
	int frm_no;
	unsigned int frm_mode;
	int hokan_rate;
	unsigned int hokan_count;
	unsigned int hokan_ctbak;
	int mtn_add;
	unsigned int mtn_md;
	unsigned char* mtn_tp;
	int axp;
	int ayp;
	int azp;
	short psh_ct;
	short psh_idx;
	int idx_ct;
	int mtn_chk;
	float ofx;
	float ofy;
	float ofz;
	float sx;
	float sy;
	float sz;
	float sxb;
	float syb;
	float szb;
	float xn;
	float yn;
	float zn;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	int wpnr_no;
	int wpnl_no;
	unsigned int at_flg;
	_anon46 watr;
	CPCL* cpcl;
	short wax;
	short way;
	short waz;
	short waxp;
	short wayp;
	short wazp;
	int hp;
	int dam[64];
	int djnt_no;
	int cpcl_no;
	int dax;
	int day;
	float dpx;
	float dpy;
	float dpz;
	float dvx;
	float dvy;
	float dvz;
	int flr_snd;
	int ko_num;
	int footeff;
	int src_no;
	unsigned char* kdnp;
	int kdnidx;
	void* dan_ap;
	unsigned int comb_flg;
	unsigned int comb_wep;
	int comb_pnt;
	int comb_timeout;
	int total_dam;
	unsigned int Dummy2[2];
};

struct _anon1
{
	_anon27* textures;
	unsigned int nbTexture;
};

struct _anon2
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int col;
};

struct _anon3 // NJS_MKEY 
{
	float key[3];
};

struct _anon4
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon5
{
	float px;
	float py;
	float pz;
	int ay;
};

struct _anon6
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon26* md2P;
	unsigned short* atrP;
};

struct _anon7
{
	char type[3];
	char bloodstain[3];
	char exef;
};

struct _anon8
{
	unsigned short flg;
	unsigned short type;
	short nxt_no;
	short keyf_n;
	_anon47 keyf[16];
};

struct _anon9
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon10
{
	unsigned int Type;
	unsigned int BitDepth;
	unsigned int PixelFormat;
	unsigned int nWidth;
	unsigned int nHeight;
	unsigned int TextureSize;
	unsigned int fSurfaceFlags;
	unsigned int* pSurface;
	unsigned int* pVirtual;
	unsigned int* pPhysical;
};

struct _anon11
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon12
{
	_anon13* cutp;
	_anon17* lgtp;
	_anon18* enep;
	_anon18* objp;
	_anon18* itmp;
	_anon21* effp;
	_anon22* walp;
	_anon22* etcp;
	_anon22* flrp;
	_anon5* posp;
	_anon22* rutp;
	unsigned char* ruttp;
	_anon29* evtp;
	_anon8* evcp;
	unsigned int* mesp;
	_anon17* evlp;
	unsigned char* dmp00;
	unsigned char* dmp01;
	unsigned char* dmp02;
	unsigned char* dmp03;
	unsigned char* dmp04;
	unsigned char* dmp05;
	unsigned char* dmp06;
	unsigned char* dmp07;
	unsigned char* dmp08;
	unsigned char* dmp09;
	unsigned char* dmp10;
	unsigned char* dmp11;
	unsigned char* dmp12;
	unsigned char* dmp13;
	unsigned char* dmp14;
	unsigned char* dmp15;
	int cut_n;
	int lgt_n;
	int ene_n;
	int obj_n;
	int itm_n;
	int eff_n;
	int wal_n;
	int etc_n;
	int flr_n;
	int pos_n;
	int rut_n;
	int evc_n;
	int mes_n;
	int evl_n;
	int dmy00;
	int dmy01;
	int dmy02;
	int dmy03;
	int dmy04;
	int dmy05;
	int dmy06;
	int dmy07;
	int dmy08;
	int dmy09;
	int dmy10;
	int dmy11;
	int dmy12;
	int dmy13;
	int dmy14;
	int dmy15;
	int dmy16;
	int dmy17;
	unsigned int flg;
	unsigned int bak_col;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float w;
	float h;
	float d;
	float grand[32];
	_anon14 mdl;
	float fog[128];
	char amb_rom;
	char amb_chr;
	char amb_obj;
	char amb_itm;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
};



struct _anon13
{
	unsigned char flg;
	unsigned char type;
	char flr_no;
	unsigned char ctab_n;
	_anon16* cuttp;
	float cx;
	float cy;
	float cz;
	float cw;
	float ch;
	float cd;
	_anon25 cam[2];
	unsigned char exd[256];
};

struct _anon14
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon4* owP;
};

struct _anon15
{
	unsigned int id;
	unsigned int support;
	unsigned int on;
	unsigned int off;
	unsigned int press;
	unsigned int release;
	unsigned short r;
	unsigned short l;
	short x1;
	short y1;
	short x2;
	short y2;
	char* name;
	void* extend;
	unsigned int old;
	_anon43* info;
};

struct _anon16
{
	unsigned int attr;
	char flr_no;
	char reserve0;
	char reserve1;
	char atr_tp;
	float h;
	float dmy;
	float minx;
	float minz;
	float maxx;
	float maxz;
};

struct _anon17
{
	unsigned int flg;
	unsigned int type;
	int aspd;
	int lkflg;
	int lkno;
	int lkono;
	int lsrc;
	float px;
	float py;
	float pz;
	float lx;
	float ly;
	float lz;
	float vx;
	float vy;
	float vz;
	float spc;
	float dif;
	float amb;
	float r;
	float g;
	float b;
	float nr;
	float fr;
	int iang;
	int oang;
	int ax;
	int ay;
	int az;
	unsigned int mode;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
	float wpx;
	float wpy;
	float wpz;
	float wvx;
	float wvy;
	float wvz;
	float wspc;
	float wdif;
	float wamb;
	float wr;
	float wg;
	float wb;
	float wnr;
	float wfr;
	int wiang;
	int woang;
	int wax;
	int way;
	int waz;
	unsigned char* lkwkp;
	unsigned char* exp;
	_anon31* light;
};

struct _anon18 ETTY_WORK
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	char flr_no;
	unsigned char mdlver;
	unsigned char wrk_no;
	char prm1;
	float px;
	float py;
	float pz;
	short ax;
	short az;
	short ay;
	short aspd;
	char hide[4];
};

struct _anon19
{
	unsigned int flg;
	char stg_no;
	char rom_no;
	unsigned char pos_no;
	unsigned char dor_tp;
	unsigned char mode0;
	unsigned char mode1;
	unsigned char mode2;
	unsigned char mode3;
	int ct0;
	int ct1;
	int ct2;
	int ct3;
};

struct _anon20
{
	unsigned short key[3];
};

struct _anon21
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
	int lkflg;
	int lkno;
	int lkono;
	float lx;
	float ly;
	float lz;
	int param;
};

struct _anon22
{
	unsigned char flg;
	unsigned char type;
	unsigned char id;
	char flr_no;
	unsigned int attr;
	float px;
	float py;
	float pz;
	float w;
	float h;
	float d;
	unsigned char prm0;
	unsigned char prm1;
	unsigned char prm2;
	unsigned char prm3;
};

struct _anon23
{
	unsigned int ssd_ver;
	unsigned int ssd_flg;
	unsigned int ssd_reserve;
	char keytype;
	char adjust_x;
	char adjust_y;
	char vibration;
	int best_tm[8];
	unsigned int sys_partid;
	unsigned int itm_partid;
	unsigned int fil_partid;
	unsigned int dor_partid;
	unsigned int ss_flg;
	int pdm_no;
	unsigned int typ_flg;
	unsigned short typ_md0;
	unsigned short typ_md1;
	void* typ_exp;
	unsigned int tk_flg;
	unsigned int ts_flg;
	unsigned int gm_flg;
	unsigned int st_flg;
	unsigned int cb_flg;
	unsigned int rm_flg;
	unsigned int pt_flg;
	unsigned int sp_flg;
	unsigned int ef_flg;
	unsigned int error;
	unsigned int version;
	int save_ct;
	char ply_id;
	char stg_no;
	char rom_no;
	char rcase;
	char pos_no;
	char cut_no;
	char flr_no;
	char reserve0;
	int gm_mode;
	unsigned int ev_flg[32];
	unsigned int it_flg[16];
	unsigned int ic_flg[16];
	unsigned int ed_flg[32];
	unsigned int ky_flg[16];
	unsigned int mp_flg[8];
	unsigned int itm[384];
	unsigned int ply_stflg[4];
	_anon35 ply_pos;
	int ply_ang;
	char ply_wno[4];
	short ply_hp[4];
	unsigned char evt_posno[4];
	int time;
	int stv_tm;
	short spray_ct;
	short retry_ct;
	short clear_ct;
	short reserve1;
	unsigned int save_end;
	char stg_nob;
	char rom_nob;
	char pos_nob;
	char rcase_b;
	unsigned int en_flg[4];
	_anon1* et_lp[16][16][100];
	_anon1* ot_lp[1300];
	_anon1* it_lp[200];
	int eft_n;
	_anon1* eft_lp[8];
	int loop_ct;
	int loop_now;
	int cng_pid;
	_anon15* p1per;
	_anon15* p2per;
	_anon15* kbper;
	_anon15* msper;
	_anon15 ms_per;
	int pad_port;
	unsigned int pad_on;
	unsigned int pad_oncpy;
	unsigned int pad_ps;
	unsigned int pad_rs;
	unsigned int pad_old;
	unsigned int pad_onb;
	unsigned int pad_psb;
	unsigned int pad_oldb;
	short pad_ax;
	short pad_ay;
	short pad_dx;
	short pad_dy;
	unsigned short pad_ar;
	unsigned short pad_al;
	int fixcno;
	int fixkno;
	unsigned int exm_attr;
	short evc_no;
	short evc_kn;
	short evc_ono;
	short evc_okn;
	int evc_sc;
	unsigned char mn_mode0;
	unsigned char mn_mode1;
	unsigned char mn_mode2;
	unsigned char mn_mode3;
	unsigned char mn_md0;
	unsigned char mn_md1;
	unsigned char mn_md2;
	unsigned char mn_md3;
	int mn_setct;
	unsigned int mn_stack[8];
	unsigned int sdm_flg;
	unsigned int sdm_mode;
	unsigned char* ltc_bp;
	unsigned int ltc_tsbak;
	int ewk_n;
	unsigned int enow;
	unsigned int onow;
	unsigned int efnow;
	int vsyc_ct;
	int vsyc_flg;
	int fog_ct;
	int bcl_ct;
	int gfrm_ct;
	int gframe;
	int eor_ct;
	unsigned int pfm_cts;
	int evt_tmd;
	int evt_tim;
	int evt_tdg;
	int evt_fcd;
	unsigned int evt_fcdct;
	unsigned int fsize;
	unsigned int rdtsz;
	unsigned char* memp;
	unsigned char* mempb;
	unsigned char* endp;
	unsigned char* rdtp;
	unsigned char* plmdlp;
	unsigned char* lmmdlp;
	unsigned char* wrmdlp;
	unsigned char* wlmdlp;
	unsigned char* plmthp;
	unsigned char* plbmtp;
	unsigned char* plwmtp;
	unsigned char* plzmtp;
	unsigned char* plemtp;
	unsigned char* plexwp;
	unsigned char* plhdwp;
	unsigned char* pletcp;
	unsigned char* subtxp;
	unsigned char* doordp;
	unsigned char* sbs_sp;
	_anon0* obwp;
	_anon0* itwp;
	_anon6* emtp[128];
	_anon6* rmthp;
	unsigned char* mspp;
	unsigned char* lspp;
	unsigned int* mes_ip;
	unsigned int* mes_sp;
	void* mes_tp;
	short txr_n;
	short txr_ct;
	_anon1* txlp[256];
	unsigned char* txdp[256];
	short txloff[256];
	short txb_ct;
	short txb_n;
	short txb[256];
	_anon1* txblp[256];
	_anon11 txbp[256];
	unsigned char* ef_psp;
	_anon27 ef_tex[450];
	_anon1 ef_tlist;
	_anon41 ef;
	short efid[256];
	_anon14 efm[450];
	int ef_ct;
	int ef_ctb;
	int ef_extn;
	int ef_tn[450];
	unsigned char ef_pbkb[450];
	int ef_pbnk;
	int ef_slow;
	int ef_ctrn;
	int yk_ct;
	int mg_ct;
	int bl_ct;
	int windr;
	float winds;
	int windrb;
	float windsb;
	unsigned int thunder;
	float gas_py;
	int en_objn;
	BH_PWORK* en_obj[16];
	int ef_poln;
	int ef_mdfn;
	int ef_linn;
	int ef_ntxn;
	int ef_trsn;
	int ef_pncn;
	int ef_opqn;
	int ef_thln;
	int ef_ntx2dn;
	int ef_trs2dn;
	int ef_pnc2dn;
	int ef_fncn;
	_anon0* ef_pol[512];
	_anon0* ef_mdf[128];
	_anon0* ef_lin[512];
	_anon0* ef_ntx[512];
	_anon0* ef_trs[512];
	_anon0* ef_pnc[512];
	_anon0* ef_opq[512];
	_anon0* ef_thl[512];
	_anon0* ef_ntx2d[128];
	_anon0* ef_trs2d[128];
	_anon0* ef_pnc2d[128];
	_anon0* ef_fnc[512];
	int ob_nlgn;
	int ob_hlgn;
	int ob_spcn;
	_anon0* ob_nlg[32];
	_anon0* ob_hlg[32];
	_anon0* ob_spc[32];
	unsigned int ren_gid;
	_anon24 ren_info;
	_anon27 ren_tex[1];
	_anon1 ren_tlist;
	_anon9 rpb[256];
	int ren_n;
	int ren_idx[4];
	int wt_nbpt;
	float wt_px;
	float wt_pz;
	int wt_xp;
	int wt_zp;
	int wt_minx;
	int wt_minz;
	int wt_maxx;
	int wt_maxz;
	unsigned char* wt_wvp;
	_anon42 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon17* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon32 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon34 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon22* pl_htp;
	int costume;
	_anon35 hd_pos;
	_anon35 apos;
	_anon22* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon22 mwalp[64];
	_anon22 metcp[64];
	_anon22 mflrp[64];
	int dla_n;
	_anon22* htp;
	int psh_snd;
	int fog_cngct;
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	float fade_ct;
	float fade_hkn;
	float fade_ao;
	float fade_an;
	float fade_ap;
	float fade_ro;
	float fade_rn;
	float fade_rp;
	float fade_go;
	float fade_gn;
	float fade_gp;
	float fade_bo;
	float fade_bn;
	float fade_bp;
	unsigned int fade_pbk;
	unsigned short ssv_md0;
	unsigned short ssv_md1;
	int ssv_tim;
	float ssv_ct;
	float ssv_hkn;
	float ssv_ao;
	float ssv_an;
	float ssv_ap;
	short fil_no;
	short fil_rt;
	float rvf_sc;
	float rvf_sn;
	unsigned int rvfc[4];
	float cine_an;
	float cine_ap;
	unsigned int sco_flg;
	float amb_r[4];
	float amb_g[4];
	float amb_b[4];
	int sb_id;
	int sb_cmd;
	int sb_rdid;
	int sb_rdsz;
	void* sb_rdp;
	void* sb_mlb;
	void* sb_ppp;
	_anon1* sb_tlist;
	int ddmd;
	_anon19 door;
	int mpmd;
	int mp_prm[4];
	unsigned short gov_md0;
	unsigned short gov_md1;
	int gov_ct;
	void* gov_exp;
	unsigned int com_flg;
	unsigned short com_md0;
	unsigned short com_md1;
	unsigned int com_num;
	void* com_exp;
	short ond_tnm;
	short ond_ud;
	char ond_cx;
	char ond_n[3];
	unsigned char ufo_md;
	unsigned char ufo_flg;
	short ufo_oidx;
	_anon35 ufo_pos;
	unsigned int opt_flg;
	unsigned short opt_md0;
	unsigned short opt_md1;
	void* opt_exp;
	unsigned int etc_idx;
	unsigned int flr_idx;
	int mvi_no;
	int mvi_tp;
	unsigned short mvi_md;
	unsigned short mvi_flg;
	unsigned int mvi_tsb;
	unsigned int mvi_spb;
	unsigned char* mvi_memp;
	unsigned int dcg_tkbak;
	unsigned int dcg_tsbak;
	unsigned int pau_spbak;
	unsigned int pau_pad_on;
	unsigned int pau_pad_ps;
	unsigned int pau_pad_old;
	unsigned char* pdm_dp;
	unsigned char* pdm_pd;
	int pdm_keytpb;
	int gat_ct;
	_anon37 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon35 ghtp[32];
	unsigned short db_md0;
	unsigned short db_md1;
	char db_stgno;
	char db_romno;
	char db_rcase;
	char db_muteki;
	short db_px;
	short db_py;
	int db_mes;
	int calc_v;
	unsigned int brkfg;
	char brkfg_typ[32];
	short brkfg_bit[32];
	unsigned int brkfg_tkb;
	unsigned int brkfg_tsb;
	int brkfg_ct;
	unsigned int bmt_size;
	unsigned int lmt_size;
	unsigned int emt_size;
	unsigned int wmt_size;
	char mes[256];
	float sfx;
	float sfy;
	float sfxn;
	float sfyn;
	float sfct;
};

struct _anon24
{
	void* texaddr;
	_anon10 texsurface;
};

struct _anon25
{
	unsigned short flg;
	unsigned char lgtclip;
	char spd;
	float px;
	float py;
	float pz;
	float ln;
	float w;
	float h;
	float d;
	float y0;
	float y1;
	float y2;
	float y3;
	float am_spd;
	int ax;
	int ay;
	int az;
	int lax;
	int lay;
	short laz0;
	short laz1;
	short laz2;
	short laz3;
	char aa_spd;
	char fil_no;
	char fil_rt;
	char reserve;
	int pers;
	unsigned int hidobj[16];
	unsigned int hidlgt[8];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
};

struct _anon26
{
	void* p[2];
};

struct _anon27
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon28
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon29
{
	unsigned short* scd0;
	unsigned short* scd1;
	unsigned short* evd;
};

struct _anon30
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon31
{
	float mtrx[16];
	_anon35 pnt;
	_anon35 vctr;
	int stat;
	int reserve;
	_anon38 ltcal;
	_anon44 attr;
};

struct _anon32
{
	_anon35 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon33
{
	int* vlist;
	short* plist;
	_anon35 center;
	float r;
};

struct _anon34
{
	float x;
	float y;
};

struct _anon35
{
	float x;
	float y;
	float z;
};

struct _anon36
{
	int flg;
	_anon35 ofp;
	float rx;
	float ry;
	float rz;
};

struct _anon37
{
	_anon35 c1;
	_anon35 c2;
	float r1;
	float r2;
};

struct _anon38
{
	float ratten;
	float ipd;
	float nrr;
	float frr;
	float cosi;
	float cose;
	float idev;
	float odev;
	float rate;
	float intns;
	int exp;
	int reserve;
	_anon35 lpnt;
	_anon35 lvctr;
	_anon35 lmvctr;
	_anon30 atten;
	_anon30 amb;
	_anon30 dif;
	_anon30 spc;
	_anon30 mamb;
	_anon30 mdif;
	_anon30 mspc;
};

struct _anon39
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon40
{
	_anon35 off_pos;
	int srd_dir;
	float srd_pos;
	float bld_spd;
	float srt_spd[5];
	int srt_dir[5];
};

struct _anon41
{
	unsigned int flg;
	unsigned short id;
	unsigned short type;
	short flr_no;
	unsigned short mdlver;
	float px;
	float py;
	float pz;
	float sx;
	float sy;
	float sz;
	short ay;
	short ax;
};

struct _anon42
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon43
{
	unsigned int type;
	unsigned int reserved[3];
	unsigned char is_root;
	unsigned char area_code;
	unsigned char connector_dir[2];
	char product_name[32];
	char license[64];
	unsigned short stdby_pow;
	unsigned short max_pow;
};

struct _anon44
{
	int lsrc;
	float iamb;
	float idif;
	float ispc;
	float nrang;
	float frang;
	void* func;
	int iang;
	int oang;
	_anon30 argb;
};

struct _anon45
{
	_anon35 c;
	float r;
};

struct _anon46
{
	_anon35 c1;
	_anon35 c2;
	float r;
};

struct _anon47
{
	unsigned short flg;
	short frame;
	float px;
	float py;
	float pz;
	short ax;
	short ay;
	short az;
	short pers;
	unsigned int hidobj[8];
	unsigned int hidlgt[4];
	unsigned int fog_col;
	float fog_nr;
	float fog_fr;
	short lkflg;
	short lkno;
	short lkono;
	short nxt_no;
	float lx;
	float ly;
	float lz;
	float prm_0;
	float prm_1;
	float prm_2;
	float prm_3;
	float prm_4;
	unsigned char* recp;
};

*/
static int ENE06_HITPOINT[16] = 
{
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1,
    1, 1, 1, 1
};

static char junction_tree[1][6] =
{
    { 0x00, 0xFF, 0x00, 0x00, 0x00, 0x00 }
};

/*
char player_junction_tree[8][8];  // unused?
*/

static char SdwTab[2] = { 0x00, 0xFF };

static ETTY_WORK ene06_child =
{
    0x8001,                                 /* flg */
    0x1F,                                   /* id */
    0,                                      /* type */
    0,                                      /* flr_no */
    0,                                      /* mdlver */
    0,                                      /* wrk_no */
    0,                                      /* prm1 */
    0.0f,                                   /* px */
    0.0f,                                   /* py */
    0.0f,                                   /* pz */
    0,                                      /* ax */
    0,                                      /* az */
    0,                                      /* ay */
    0,                                      /* aspd */
    {0, 0, 0, 0}                            /* hide */
};

static char BrokenParts[12] = {0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16};

static ETTY_WORK ene27 =
{
    0x8001,                                 /* flg */
    0x1B,                                   /* id */
    0,                                      /* type */
    0,                                      /* flr_no */
    0,                                      /* mdlver */
    0,                                      /* wrk_no */
    0,                                      /* prm1 */
    0.0f,                                   /* px */
    0.0f,                                   /* py */
    0.0f,                                   /* pz */
    0,                                      /* ax */
    0,                                      /* az */
    0,                                      /* ay */
    0,                                      /* aspd */
    {0, 0, 0, 0}                            /* hide */
};


static ETTY_WORK ene06_leader =
{
    0x01008001,                             /* flg */
    0x06,                                   /* id */
    0,                                      /* type */
    0,                                      /* flr_no */
    0,                                      /* mdlver */
    0,                                      /* wrk_no */
    0,                                      /* prm1 */
    0.0f,                                   /* px */
    0.0f,                                   /* py */
    0.0f,                                   /* pz */
    0,                                      /* ax */
    0,                                      /* az */
    0,                                      /* ay */
    0,                                      /* aspd */
    {0, 0, 0, 0}                            /* hide */
};

static BP_WORK BloodParam =
{
    {0.0f, 0.01f, 0.0f},                    /* off_pos */
    0,                                      /* srd_dir */
    0.0f,                                   /* srd_pos */
    0.05f,                                  /* bld_spd */
    {0.3f, 0.7f, 0.5f, 0.7f, 0.4f},         /* srt_spd */
    {0, 3, 6, 9, 12}                        /* srt_dir */
};

static CPCL CapColTab[8] =
{
    { 1,  1,  5 },                          /* [0] */
    { 0,  0, -6 },                          /* [1] */
    { 1,  2,  5 },                          /* [2] */
    { 2,  4,  6 },                          /* [3] */
    { 4,  6,  7 },                          /* [4] */
    { 6,  8,  7 },                          /* [5] */
    { 8, 10,  6 },                          /* [6] */
    { 0,  0,  0 }                           /* [7] */
};


/*
_anon7 DmgReact[21];


_anon36 BloodTbl[23];

*/

typedef void (*bhEne06_Mode0_proc)(BH_PWORK*);
typedef void (*bhEne06_BrainType_proc)(BH_PWORK*);
typedef void (*bhEne06_MoveMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_NageMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_DamageMode2_proc)(BH_PWORK*);
typedef void (*bhEne06_DeadMode2_proc)(BH_PWORK*);

bhEne06_Mode0_proc bhEne06_Mode0[6] =
{
    bhEne06_Init,                           
    bhEne06_Move,                           
    bhEne06_Nage,                           
    bhEne06_Damage,                         
    bhEne06_Die,                            
    bhEne_Event                             
};

bhEne06_BrainType_proc bhEne06_BrainType[1] =
{
    bhEne06_BR00
};

bhEne06_MoveMode2_proc bhEne06_MoveMode2[11] =
{
    bhEne06_MV00,                           
    bhEne06_MV01,                           
    bhEne06_MV02,                           
    bhEne06_MV03,                           
    bhEne06_MV04,
    bhEne06_MV05,
    bhEne06_MV06,
    bhEne06_MV07,
    bhEne06_MV08,
    bhEne06_MV09,
    bhEne06_MV10 
};

bhEne06_NageMode2_proc bhEne06_NageMode2[1] =
{
    bhEne06_NG00
};

bhEne06_DamageMode2_proc bhEne06_DamageMode2[2] =
{
    bhEne06_DG00,
    bhEne06_DG01
};

bhEne06_DeadMode2_proc bhEne06_DeadMode2[5] =
{
    bhEne06_DD00,
    bhEne06_DD01, 
    bhEne06_DD02,
    bhEne06_DD03,
    bhEne06_DD04
};

/*
BH_PWORK* plp;
_anon0 eff[0];
void(*bhEne06s)(BH_PWORK*);
_anon12* rom;
_anon23* sys;
BH_PWORK ene[0];*/

// 100% matching!
void bhEne06(BH_PWORK* epw)
{
    if ((epw->flg & 0x1000000))
    {
        if ((*(int*)epw->exp1 & 1) != 0)
        {
            if(plp->mode0 == 4)
            {
                bhEne06_PlayerControl(epw);
            }
        }
    } 
    else 
    {
        bhEne06_Mode0[epw->mode0](epw);
        
        bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
        
        epw->car += ((EXP0_F(0x70) - epw->car) / 8.0f);
        
        bhCheckPlayer(epw);
        
        if (epw->flg & 8)
        {
            bhEne_CheckEnemiesBall(epw);
        }
        
        bhEne06_FloorCollision(epw);
        
        if (epw->flg & 0x10)
        {
            bhEne06_CollisionWalls(epw);
        }
        
        bhCalcModel(epw);
        
        bhEne_SetWeponAtr(epw, 10, 1, 2.0f);
        
        return;
    }
}

// 
// Start address: 0x1b9970
void bhEne06_Init(BH_PWORK* epw)
{
	int sdw;
	int i;
	BH_PWORK* ep_leader;
	BH_PWORK* ep;
	BH_PWORK** epw2;
	//unsigned int i;
	//_anon4* owk;
	// Line 455, Address: 0x1b9970, Func Offset: 0
	// Line 457, Address: 0x1b9988, Func Offset: 0x18
	// Line 458, Address: 0x1b998c, Func Offset: 0x1c
	// Line 459, Address: 0x1b9994, Func Offset: 0x24
	// Line 460, Address: 0x1b999c, Func Offset: 0x2c
	// Line 457, Address: 0x1b99a0, Func Offset: 0x30
	// Line 458, Address: 0x1b99a8, Func Offset: 0x38
	// Line 461, Address: 0x1b99ac, Func Offset: 0x3c
	// Line 462, Address: 0x1b99b0, Func Offset: 0x40
	// Line 458, Address: 0x1b99b8, Func Offset: 0x48
	// Line 459, Address: 0x1b99c0, Func Offset: 0x50
	// Line 460, Address: 0x1b99cc, Func Offset: 0x5c
	// Line 461, Address: 0x1b99d0, Func Offset: 0x60
	// Line 462, Address: 0x1b99d4, Func Offset: 0x64
	// Line 464, Address: 0x1b99d8, Func Offset: 0x68
	// Line 467, Address: 0x1b9a28, Func Offset: 0xb8
	// Line 469, Address: 0x1b9a2c, Func Offset: 0xbc
	// Line 464, Address: 0x1b9a30, Func Offset: 0xc0
	// Line 467, Address: 0x1b9a34, Func Offset: 0xc4
	// Line 468, Address: 0x1b9a38, Func Offset: 0xc8
	// Line 469, Address: 0x1b9a3c, Func Offset: 0xcc
	// Line 470, Address: 0x1b9a40, Func Offset: 0xd0
	// Line 471, Address: 0x1b9a44, Func Offset: 0xd4
	// Line 475, Address: 0x1b9a48, Func Offset: 0xd8
	// Line 472, Address: 0x1b9a4c, Func Offset: 0xdc
	// Line 475, Address: 0x1b9a50, Func Offset: 0xe0
	// Line 476, Address: 0x1b9a54, Func Offset: 0xe4
	// Line 477, Address: 0x1b9a58, Func Offset: 0xe8
	// Line 478, Address: 0x1b9a5c, Func Offset: 0xec
	// Line 486, Address: 0x1b9a60, Func Offset: 0xf0
	// Line 487, Address: 0x1b9a64, Func Offset: 0xf4
	// Line 486, Address: 0x1b9a68, Func Offset: 0xf8
	// Line 487, Address: 0x1b9a6c, Func Offset: 0xfc
	// Line 488, Address: 0x1b9a74, Func Offset: 0x104
	// Line 489, Address: 0x1b9a78, Func Offset: 0x108
	// Line 488, Address: 0x1b9a7c, Func Offset: 0x10c
	// Line 489, Address: 0x1b9a84, Func Offset: 0x114
	// Line 492, Address: 0x1b9a9c, Func Offset: 0x12c
	// Line 498, Address: 0x1b9aa8, Func Offset: 0x138
	// Line 501, Address: 0x1b9ab8, Func Offset: 0x148
	// Line 502, Address: 0x1b9ac0, Func Offset: 0x150
	// Line 503, Address: 0x1b9ae0, Func Offset: 0x170
	// Line 504, Address: 0x1b9afc, Func Offset: 0x18c
	// Line 506, Address: 0x1b9b08, Func Offset: 0x198
	// Line 507, Address: 0x1b9b10, Func Offset: 0x1a0
	// Line 511, Address: 0x1b9b20, Func Offset: 0x1b0
	// Line 514, Address: 0x1b9b2c, Func Offset: 0x1bc
	// Line 516, Address: 0x1b9b34, Func Offset: 0x1c4
	// Line 517, Address: 0x1b9b4c, Func Offset: 0x1dc
	// Line 520, Address: 0x1b9b50, Func Offset: 0x1e0
	// Line 521, Address: 0x1b9b5c, Func Offset: 0x1ec
	// Line 522, Address: 0x1b9b64, Func Offset: 0x1f4
	// Line 524, Address: 0x1b9b68, Func Offset: 0x1f8
	// Line 526, Address: 0x1b9b70, Func Offset: 0x200
	// Line 528, Address: 0x1b9b88, Func Offset: 0x218
	// Line 529, Address: 0x1b9b94, Func Offset: 0x224
	// Line 528, Address: 0x1b9b98, Func Offset: 0x228
	// Line 530, Address: 0x1b9b9c, Func Offset: 0x22c
	// Line 532, Address: 0x1b9bb8, Func Offset: 0x248
	// Line 533, Address: 0x1b9bc0, Func Offset: 0x250
	// Line 534, Address: 0x1b9bc8, Func Offset: 0x258
	// Line 542, Address: 0x1b9bcc, Func Offset: 0x25c
	// Line 534, Address: 0x1b9bd4, Func Offset: 0x264
	// Line 535, Address: 0x1b9bd8, Func Offset: 0x268
	// Line 536, Address: 0x1b9be0, Func Offset: 0x270
	// Line 537, Address: 0x1b9be8, Func Offset: 0x278
	// Line 541, Address: 0x1b9bf8, Func Offset: 0x288
	// Line 542, Address: 0x1b9c20, Func Offset: 0x2b0
	// Line 545, Address: 0x1b9c2c, Func Offset: 0x2bc
	// Line 549, Address: 0x1b9c3c, Func Offset: 0x2cc
	// Line 550, Address: 0x1b9c48, Func Offset: 0x2d8
	// Line 551, Address: 0x1b9c50, Func Offset: 0x2e0
	// Line 554, Address: 0x1b9c98, Func Offset: 0x328
	// Line 556, Address: 0x1b9ca8, Func Offset: 0x338
	// Line 557, Address: 0x1b9cd0, Func Offset: 0x360
	// Line 559, Address: 0x1b9cf8, Func Offset: 0x388
	// Line 558, Address: 0x1b9d00, Func Offset: 0x390
	// Line 559, Address: 0x1b9d04, Func Offset: 0x394
	// Line 558, Address: 0x1b9d08, Func Offset: 0x398
	// Line 559, Address: 0x1b9d10, Func Offset: 0x3a0
	// Line 561, Address: 0x1b9d18, Func Offset: 0x3a8
	// Line 564, Address: 0x1b9d20, Func Offset: 0x3b0
	// Line 565, Address: 0x1b9d24, Func Offset: 0x3b4
	// Line 561, Address: 0x1b9d28, Func Offset: 0x3b8
	// Line 564, Address: 0x1b9d30, Func Offset: 0x3c0
	// Line 565, Address: 0x1b9d34, Func Offset: 0x3c4
	// Line 566, Address: 0x1b9d38, Func Offset: 0x3c8
	// Line 567, Address: 0x1b9d40, Func Offset: 0x3d0
	// Line 568, Address: 0x1b9d48, Func Offset: 0x3d8
	// Line 569, Address: 0x1b9d50, Func Offset: 0x3e0
	// Line 570, Address: 0x1b9d58, Func Offset: 0x3e8
	// Line 573, Address: 0x1b9d60, Func Offset: 0x3f0
	// Line 576, Address: 0x1b9d6c, Func Offset: 0x3fc
	// Line 582, Address: 0x1b9d7c, Func Offset: 0x40c
	// Line 584, Address: 0x1b9d90, Func Offset: 0x420
	// Line 586, Address: 0x1b9da4, Func Offset: 0x434
	// Func End, Address: 0x1b9dc0, Func Offset: 0x450
    scePrintf("bhEne06_Init - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_Brain(BH_PWORK* epw)
{ 
    bhEne06_BrainType[epw->type](epw); 
}

// Start address: 0x1b9de0
void bhEne06_BR00(BH_PWORK* epw)
{
	// Line 608, Address: 0x1b9de0, Func Offset: 0
	// Line 610, Address: 0x1b9dec, Func Offset: 0xc
	// Line 613, Address: 0x1b9df4, Func Offset: 0x14
	// Line 617, Address: 0x1b9e08, Func Offset: 0x28
	// Line 618, Address: 0x1b9e38, Func Offset: 0x58
	// Line 619, Address: 0x1b9e40, Func Offset: 0x60
	// Line 620, Address: 0x1b9e44, Func Offset: 0x64
	// Line 624, Address: 0x1b9e48, Func Offset: 0x68
	// Line 625, Address: 0x1b9e74, Func Offset: 0x94
	// Line 628, Address: 0x1b9e7c, Func Offset: 0x9c
	// Line 632, Address: 0x1b9ea0, Func Offset: 0xc0
	// Line 636, Address: 0x1b9f44, Func Offset: 0x164
	// Line 637, Address: 0x1b9f48, Func Offset: 0x168
	// Line 638, Address: 0x1b9f4c, Func Offset: 0x16c
	// Line 639, Address: 0x1b9f50, Func Offset: 0x170
	// Line 642, Address: 0x1b9f54, Func Offset: 0x174
	// Line 643, Address: 0x1b9f68, Func Offset: 0x188
	// Line 642, Address: 0x1b9f6c, Func Offset: 0x18c
	// Line 643, Address: 0x1b9f74, Func Offset: 0x194
	// Line 647, Address: 0x1b9f84, Func Offset: 0x1a4
	// Func End, Address: 0x1b9f94, Func Offset: 0x1b4
    scePrintf("bhEne06_BR00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_Move(BH_PWORK* epw)
{
    bhEne06_MoveMode2[epw->mode2](epw);
    if ((epw->flg & 4) && !(epw->flg & 2))
    {
        epw->mode0 = 3;
        epw->mode1 = 0;
        epw->mode2 = 0;
        epw->mode3 = 0;      
        epw->flg &= ~4;        
        bhEne06_Damage(epw);
        return;
    }
    if (epw->mode1 == 1)
    {
        bhEne06_Brain(epw);
    }
}

// 100% matching!
void bhEne06_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->mtn_no = 4;
        epw->frm_no = epw->mnwP[epw->mtn_no].frm_num * (32768.0f * njRandom());
        epw->hokan_count = 0;
        
        epw->flg |= 0x180000;
        epw->flg &= ~0x400000;
        
        if (njRandom() < 0.8f)
        {
            epw->ct0 = (int)(30.0f * njRandom()) + 30;
        } 
        else
        {
            epw->ct0 = (int)(90.0f * njRandom()) + 120;
        }
        epw->mode3++;

    case 1:
        epw->ax += (short)-epw->ax / 8;
        
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 0;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }

    }
}


// 
// Start address: 0x1ba270
void bhEne06_MV01(BH_PWORK* epw)
{
	// Line 743, Address: 0x1ba270, Func Offset: 0
	// Line 744, Address: 0x1ba280, Func Offset: 0x10
	// Line 747, Address: 0x1ba2a0, Func Offset: 0x30
	// Line 750, Address: 0x1ba2f0, Func Offset: 0x80
	// Line 752, Address: 0x1ba2f4, Func Offset: 0x84
	// Line 751, Address: 0x1ba2f8, Func Offset: 0x88
	// Line 752, Address: 0x1ba2fc, Func Offset: 0x8c
	// Line 753, Address: 0x1ba300, Func Offset: 0x90
	// Line 755, Address: 0x1ba308, Func Offset: 0x98
	// Line 756, Address: 0x1ba310, Func Offset: 0xa0
	// Line 757, Address: 0x1ba318, Func Offset: 0xa8
	// Line 758, Address: 0x1ba31c, Func Offset: 0xac
	// Line 755, Address: 0x1ba320, Func Offset: 0xb0
	// Line 756, Address: 0x1ba328, Func Offset: 0xb8
	// Line 757, Address: 0x1ba32c, Func Offset: 0xbc
	// Line 758, Address: 0x1ba334, Func Offset: 0xc4
	// Line 759, Address: 0x1ba338, Func Offset: 0xc8
	// Line 760, Address: 0x1ba344, Func Offset: 0xd4
	// Line 761, Address: 0x1ba34c, Func Offset: 0xdc
	// Line 762, Address: 0x1ba354, Func Offset: 0xe4
	// Line 766, Address: 0x1ba360, Func Offset: 0xf0
	// Line 767, Address: 0x1ba368, Func Offset: 0xf8
	// Line 768, Address: 0x1ba370, Func Offset: 0x100
	// Line 769, Address: 0x1ba378, Func Offset: 0x108
	// Line 771, Address: 0x1ba380, Func Offset: 0x110
	// Line 772, Address: 0x1ba38c, Func Offset: 0x11c
	// Line 773, Address: 0x1ba3bc, Func Offset: 0x14c
	// Line 774, Address: 0x1ba3d8, Func Offset: 0x168
	// Line 775, Address: 0x1ba3f4, Func Offset: 0x184
	// Line 776, Address: 0x1ba3fc, Func Offset: 0x18c
	// Line 778, Address: 0x1ba404, Func Offset: 0x194
	// Line 779, Address: 0x1ba408, Func Offset: 0x198
	// Line 781, Address: 0x1ba40c, Func Offset: 0x19c
	// Line 782, Address: 0x1ba410, Func Offset: 0x1a0
	// Line 783, Address: 0x1ba418, Func Offset: 0x1a8
	// Line 787, Address: 0x1ba41c, Func Offset: 0x1ac
	// Line 789, Address: 0x1ba434, Func Offset: 0x1c4
	// Line 790, Address: 0x1ba478, Func Offset: 0x208
	// Line 791, Address: 0x1ba480, Func Offset: 0x210
	// Line 792, Address: 0x1ba490, Func Offset: 0x220
	// Line 793, Address: 0x1ba4a0, Func Offset: 0x230
	// Line 794, Address: 0x1ba4b0, Func Offset: 0x240
	// Line 795, Address: 0x1ba4c4, Func Offset: 0x254
	// Line 800, Address: 0x1ba50c, Func Offset: 0x29c
	// Line 802, Address: 0x1ba518, Func Offset: 0x2a8
	// Line 803, Address: 0x1ba544, Func Offset: 0x2d4
	// Line 808, Address: 0x1ba550, Func Offset: 0x2e0
	// Func End, Address: 0x1ba560, Func Offset: 0x2f0
    scePrintf("bhEne06_MV01 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1ba560
void bhEne06_MV02(BH_PWORK* epw)
{
	// Line 818, Address: 0x1ba560, Func Offset: 0
	// Line 819, Address: 0x1ba570, Func Offset: 0x10
	// Line 822, Address: 0x1ba590, Func Offset: 0x30
	// Line 823, Address: 0x1ba59c, Func Offset: 0x3c
	// Line 825, Address: 0x1ba5a0, Func Offset: 0x40
	// Line 824, Address: 0x1ba5a4, Func Offset: 0x44
	// Line 825, Address: 0x1ba5a8, Func Offset: 0x48
	// Line 826, Address: 0x1ba5ac, Func Offset: 0x4c
	// Line 829, Address: 0x1ba5b4, Func Offset: 0x54
	// Line 830, Address: 0x1ba5bc, Func Offset: 0x5c
	// Line 831, Address: 0x1ba5c4, Func Offset: 0x64
	// Line 829, Address: 0x1ba5c8, Func Offset: 0x68
	// Line 830, Address: 0x1ba5d0, Func Offset: 0x70
	// Line 834, Address: 0x1ba5dc, Func Offset: 0x7c
	// Line 835, Address: 0x1ba61c, Func Offset: 0xbc
	// Line 836, Address: 0x1ba670, Func Offset: 0x110
	// Line 837, Address: 0x1ba674, Func Offset: 0x114
	// Line 840, Address: 0x1ba6b4, Func Offset: 0x154
	// Line 841, Address: 0x1ba704, Func Offset: 0x1a4
	// Line 842, Address: 0x1ba760, Func Offset: 0x200
	// Line 844, Address: 0x1ba768, Func Offset: 0x208
	// Line 847, Address: 0x1ba774, Func Offset: 0x214
	// Line 848, Address: 0x1ba78c, Func Offset: 0x22c
	// Line 847, Address: 0x1ba790, Func Offset: 0x230
	// Line 848, Address: 0x1ba794, Func Offset: 0x234
	// Line 847, Address: 0x1ba798, Func Offset: 0x238
	// Line 848, Address: 0x1ba7a0, Func Offset: 0x240
	// Line 847, Address: 0x1ba7a8, Func Offset: 0x248
	// Line 848, Address: 0x1ba7b0, Func Offset: 0x250
	// Line 849, Address: 0x1ba7cc, Func Offset: 0x26c
	// Line 850, Address: 0x1ba7f4, Func Offset: 0x294
	// Line 852, Address: 0x1ba7fc, Func Offset: 0x29c
	// Line 850, Address: 0x1ba800, Func Offset: 0x2a0
	// Line 852, Address: 0x1ba80c, Func Offset: 0x2ac
	// Line 853, Address: 0x1ba824, Func Offset: 0x2c4
	// Line 854, Address: 0x1ba840, Func Offset: 0x2e0
	// Line 855, Address: 0x1ba848, Func Offset: 0x2e8
	// Line 858, Address: 0x1ba868, Func Offset: 0x308
	// Line 859, Address: 0x1ba874, Func Offset: 0x314
	// Line 860, Address: 0x1ba880, Func Offset: 0x320
	// Line 862, Address: 0x1ba888, Func Offset: 0x328
	// Line 863, Address: 0x1ba89c, Func Offset: 0x33c
	// Line 864, Address: 0x1ba8a8, Func Offset: 0x348
	// Line 865, Address: 0x1ba8c4, Func Offset: 0x364
	// Line 867, Address: 0x1ba8e0, Func Offset: 0x380
	// Line 868, Address: 0x1ba8e8, Func Offset: 0x388
	// Line 870, Address: 0x1ba8fc, Func Offset: 0x39c
	// Line 871, Address: 0x1ba904, Func Offset: 0x3a4
	// Line 873, Address: 0x1ba90c, Func Offset: 0x3ac
	// Line 875, Address: 0x1ba914, Func Offset: 0x3b4
	// Line 876, Address: 0x1ba928, Func Offset: 0x3c8
	// Line 877, Address: 0x1ba934, Func Offset: 0x3d4
	// Line 878, Address: 0x1ba950, Func Offset: 0x3f0
	// Line 883, Address: 0x1ba970, Func Offset: 0x410
	// Line 884, Address: 0x1ba980, Func Offset: 0x420
	// Line 885, Address: 0x1ba9d0, Func Offset: 0x470
	// Line 886, Address: 0x1baa28, Func Offset: 0x4c8
	// Line 887, Address: 0x1baa6c, Func Offset: 0x50c
	// Line 891, Address: 0x1baa80, Func Offset: 0x520
	// Line 892, Address: 0x1baa90, Func Offset: 0x530
	// Line 893, Address: 0x1baaa4, Func Offset: 0x544
	// Line 897, Address: 0x1baae8, Func Offset: 0x588
	// Line 899, Address: 0x1bab00, Func Offset: 0x5a0
	// Line 900, Address: 0x1bab44, Func Offset: 0x5e4
	// Line 901, Address: 0x1bab4c, Func Offset: 0x5ec
	// Line 902, Address: 0x1bab5c, Func Offset: 0x5fc
	// Line 903, Address: 0x1bab6c, Func Offset: 0x60c
	// Line 904, Address: 0x1bab7c, Func Offset: 0x61c
	// Line 905, Address: 0x1bab90, Func Offset: 0x630
	// Line 911, Address: 0x1babd8, Func Offset: 0x678
	// Func End, Address: 0x1babe8, Func Offset: 0x688
    scePrintf("bhEne06_MV02 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1babf0
void bhEne06_MV03(BH_PWORK* epw)
{
	// Line 921, Address: 0x1babf0, Func Offset: 0
	// Line 922, Address: 0x1bac04, Func Offset: 0x14
	// Line 925, Address: 0x1bac24, Func Offset: 0x34
	// Line 926, Address: 0x1bac30, Func Offset: 0x40
	// Line 928, Address: 0x1bac34, Func Offset: 0x44
	// Line 927, Address: 0x1bac38, Func Offset: 0x48
	// Line 928, Address: 0x1bac3c, Func Offset: 0x4c
	// Line 929, Address: 0x1bac40, Func Offset: 0x50
	// Line 932, Address: 0x1bac48, Func Offset: 0x58
	// Line 933, Address: 0x1bac50, Func Offset: 0x60
	// Line 934, Address: 0x1bac58, Func Offset: 0x68
	// Line 932, Address: 0x1bac5c, Func Offset: 0x6c
	// Line 933, Address: 0x1bac64, Func Offset: 0x74
	// Line 937, Address: 0x1bac70, Func Offset: 0x80
	// Line 938, Address: 0x1bacb0, Func Offset: 0xc0
	// Line 939, Address: 0x1bad04, Func Offset: 0x114
	// Line 940, Address: 0x1bad08, Func Offset: 0x118
	// Line 943, Address: 0x1bad48, Func Offset: 0x158
	// Line 944, Address: 0x1bad80, Func Offset: 0x190
	// Line 943, Address: 0x1bad84, Func Offset: 0x194
	// Line 944, Address: 0x1bada0, Func Offset: 0x1b0
	// Line 945, Address: 0x1badc4, Func Offset: 0x1d4
	// Line 947, Address: 0x1badcc, Func Offset: 0x1dc
	// Line 950, Address: 0x1badd8, Func Offset: 0x1e8
	// Line 951, Address: 0x1badf0, Func Offset: 0x200
	// Line 950, Address: 0x1badf4, Func Offset: 0x204
	// Line 951, Address: 0x1badf8, Func Offset: 0x208
	// Line 950, Address: 0x1badfc, Func Offset: 0x20c
	// Line 951, Address: 0x1bae04, Func Offset: 0x214
	// Line 950, Address: 0x1bae0c, Func Offset: 0x21c
	// Line 951, Address: 0x1bae14, Func Offset: 0x224
	// Line 952, Address: 0x1bae30, Func Offset: 0x240
	// Line 953, Address: 0x1bae58, Func Offset: 0x268
	// Line 955, Address: 0x1bae60, Func Offset: 0x270
	// Line 953, Address: 0x1bae64, Func Offset: 0x274
	// Line 955, Address: 0x1bae70, Func Offset: 0x280
	// Line 956, Address: 0x1bae88, Func Offset: 0x298
	// Line 957, Address: 0x1baea0, Func Offset: 0x2b0
	// Line 958, Address: 0x1baea8, Func Offset: 0x2b8
	// Line 961, Address: 0x1baec8, Func Offset: 0x2d8
	// Line 964, Address: 0x1baed4, Func Offset: 0x2e4
	// Line 965, Address: 0x1baee8, Func Offset: 0x2f8
	// Line 966, Address: 0x1baef4, Func Offset: 0x304
	// Line 968, Address: 0x1baf10, Func Offset: 0x320
	// Line 971, Address: 0x1baf30, Func Offset: 0x340
	// Line 972, Address: 0x1baf40, Func Offset: 0x350
	// Line 973, Address: 0x1baf70, Func Offset: 0x380
	// Line 972, Address: 0x1baf74, Func Offset: 0x384
	// Line 973, Address: 0x1baf88, Func Offset: 0x398
	// Line 975, Address: 0x1baffc, Func Offset: 0x40c
	// Line 979, Address: 0x1bb040, Func Offset: 0x450
	// Line 980, Address: 0x1bb050, Func Offset: 0x460
	// Line 981, Address: 0x1bb064, Func Offset: 0x474
	// Line 984, Address: 0x1bb06c, Func Offset: 0x47c
	// Line 985, Address: 0x1bb07c, Func Offset: 0x48c
	// Line 986, Address: 0x1bb084, Func Offset: 0x494
	// Line 987, Address: 0x1bb08c, Func Offset: 0x49c
	// Line 991, Address: 0x1bb090, Func Offset: 0x4a0
	// Line 993, Address: 0x1bb0a8, Func Offset: 0x4b8
	// Line 994, Address: 0x1bb0ec, Func Offset: 0x4fc
	// Line 995, Address: 0x1bb0f4, Func Offset: 0x504
	// Line 996, Address: 0x1bb104, Func Offset: 0x514
	// Line 997, Address: 0x1bb114, Func Offset: 0x524
	// Line 998, Address: 0x1bb124, Func Offset: 0x534
	// Line 999, Address: 0x1bb138, Func Offset: 0x548
	// Line 1005, Address: 0x1bb180, Func Offset: 0x590
	// Func End, Address: 0x1bb194, Func Offset: 0x5a4
    scePrintf("bhEne06_MV03 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_MV04(void)
{

}

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 0;
        epw->frm_no = 0;
        
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mode3++;
        
        epw->ct0 = (int)(8.0f * njRandom()) + 14;
        epw->ayp = epw->ay + 32768;
        epw->spd = 1.0f;
        epw->flg |= 0x50;
        epw->car = 0.1f;
        
        EXP0_F(0x70) = 3.0f;
        epw->ar = 0.1f;
        EXP0_F(0x6C) = 5.0f;
        epw->yn = 15.0f + plp->py + (20.0f * njRandom());
        EXP0_F(0x20) = 0.0f;
        
    case 1:
        EXP0_F(0x20) += (0.1f * (epw->yn - epw->py));

        if (EXP0_F(0x20) > 0.4f)
        {
            EXP0_F(0x20) = 0.4f;
        }

        if (EXP0_F(0x20) < -0.4f)
        {
            EXP0_F(0x20) = -0.4f;
        }
        
        epw->py += EXP0_F(0x20);
        
        if (EXP0_F(0x20) > 0.0f)
        {
            epw->ax += (short)(-epw->ax) / 8;
        } 
        else
        {
            epw->ax += (short)(-3640 - epw->ax) / 8;
        }

        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px -= epw->spd * njSin(epw->ayp);
            epw->pz -= epw->spd * njCos(epw->ayp);
            epw->ct0--;
            break;
        }
        
        epw->car = 3.0f;
        
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
        
        epw->ax = 0;

    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne06_MV06(void)
{

}

// 100% matching!
void bhEne06_MV07(void)
{

}

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_MV08(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->mtn_no = 3;
        epw->frm_no = 0;
        
        epw->hokan_count = 5;
        epw->hokan_rate = 0x8000;
        
        epw->flg |= 0x580000;
        epw->flg &= ~0x400000;
        
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 8;
        epw->mode3++;
        
    case 1:
        if (epw->ct1 != 0)
        {
            epw->ax += (short)-epw->ax / epw->ct1;
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
            
            epw->px = epw->px + ((EXP0_F(0x28)- epw->px) / epw->ct1);   
            epw->pz = epw->pz + ((EXP0_F(0x30) - epw->pz) / epw->ct1);
            
            ((BH_PWORK*)EXP0_I(0x84))->sy += (2.0f - ((BH_PWORK*)EXP0_I(0x84))->sy) / (float)epw->ct1;
            
            epw->ct1--;
        }

        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, *junction_tree, &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            
            epw->ay = epw->ayp;
            
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
            
            epw->mtn_no = 4;
            epw->frm_no = 0;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne06_MV09(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 15)
        {
            epw->mtn_no = 15;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg &= ~0x180000;
        epw->flg |= 0x800000;
        
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;
        
        epw->flg |= 0x200000;
        epw->ct2 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        epw->ax += (short)(-epw->ax) / 8;
        epw->ay += (int)(1820.0f * njRandom());
        epw->ay -= 910;
        epw->spd = 0.2f * njRandom();
        
        bhAddSpeed(epw, 0);
        if (bhEne06_DeadCheck(epw) != 0)
        {
            epw->frm_no = 0;
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
            epw->flg |= 2;
            epw->flg &= ~0x28;
            epw->dvx = 0.0f;
            epw->dvy = -1.0f;
            epw->dvz = 0.0f;
            bhEne_SetBloodEffectBurst(epw, 3, 1, NULL, 0);
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8965);
            epw->mode3++;
        }
        
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 0.0f;
            EXP0_F(0x24) = 0.0f;
            epw->flg |= 0x200000;
            return;
        }
        
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.2f;

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
            epw->ct2 = (int)(20.0f * njRandom()) + 10;
        }
    }
}

// 100% matching!
void bhEne06_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no != 16)
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
        }
        
        epw->flg &= ~0x180000;
        epw->flg |= 0x800000;
        
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;
        
        epw->flg |= 0x200000;
        epw->ct2 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        epw->ax += (short)(-epw->ax) / 8;
        epw->ay += (int)(1820.0f * njRandom());
        epw->ay -= 910;
        epw->spd = 0.2f * njRandom();
        
        bhAddSpeed(epw, 0);
        
        if (bhEne06_DeadCheck(epw) != 0)
        {
            epw->frm_no = 0;
            epw->mtn_add = 0;
            epw->hokan_count = 5;
            epw->hokan_rate = 32768;
            epw->flg |= 2;
            epw->flg &= ~0x28;
            epw->dvx = 0.0f;
            epw->dvy = -1.0f;
            epw->dvz = 0.0f;
            bhEne_SetBloodEffectBurst(epw, 3, 1, NULL, 0);
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8965);
            epw->mode3++;
        }
        
        if (!(epw->flg & 0x200000))
        {
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 0.0f;
            EXP0_F(0x24) = 0.0f;
            epw->flg |= 0x200000;
            return;
        }
        
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.2f;

        if (epw->ct2-- == 0)
        {
            bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
            epw->ct2 = (int)(20.0f * njRandom()) + 10;
        }
    }
}

// 
// Start address: 0x1bbd50
void bhEne06_Nage(BH_PWORK* epw)
{
	// Line 1332, Address: 0x1bbd50, Func Offset: 0
	// Func End, Address: 0x1bbd70, Func Offset: 0x20
    scePrintf("bhEne06_Nage - UNIMPLEMENTED!\n");
}
/*
// 
// Start address: 0x1bbd70
void bhEne06_NG00(BH_PWORK* epw)
{
	unsigned int flg[3];
	int type;
	int i;
	BH_PWORK* epw2;
	_anon4* owk;
	_anon35 v;
	_anon35 offset;
	_anon35 pos;
	// Line 1343, Address: 0x1bbd70, Func Offset: 0
	// Line 1346, Address: 0x1bbd84, Func Offset: 0x14
	// Line 1349, Address: 0x1bbda4, Func Offset: 0x34
	// Line 1351, Address: 0x1bbdac, Func Offset: 0x3c
	// Line 1350, Address: 0x1bbdb0, Func Offset: 0x40
	// Line 1351, Address: 0x1bbdb4, Func Offset: 0x44
	// Line 1352, Address: 0x1bbdb8, Func Offset: 0x48
	// Line 1355, Address: 0x1bbdc0, Func Offset: 0x50
	// Line 1357, Address: 0x1bbdc4, Func Offset: 0x54
	// Line 1356, Address: 0x1bbdc8, Func Offset: 0x58
	// Line 1357, Address: 0x1bbdd0, Func Offset: 0x60
	// Line 1355, Address: 0x1bbdd4, Func Offset: 0x64
	// Line 1356, Address: 0x1bbde0, Func Offset: 0x70
	// Line 1357, Address: 0x1bbde8, Func Offset: 0x78
	// Line 1360, Address: 0x1bbdf4, Func Offset: 0x84
	// Line 1357, Address: 0x1bbdf8, Func Offset: 0x88
	// Line 1360, Address: 0x1bbe00, Func Offset: 0x90
	// Line 1363, Address: 0x1bbe28, Func Offset: 0xb8
	// Line 1364, Address: 0x1bbe2c, Func Offset: 0xbc
	// Line 1371, Address: 0x1bbe30, Func Offset: 0xc0
	// Line 1360, Address: 0x1bbe34, Func Offset: 0xc4
	// Line 1363, Address: 0x1bbe38, Func Offset: 0xc8
	// Line 1364, Address: 0x1bbe44, Func Offset: 0xd4
	// Line 1367, Address: 0x1bbe50, Func Offset: 0xe0
	// Line 1368, Address: 0x1bbe70, Func Offset: 0x100
	// Line 1370, Address: 0x1bbe7c, Func Offset: 0x10c
	// Line 1371, Address: 0x1bbe80, Func Offset: 0x110
	// Line 1374, Address: 0x1bbe84, Func Offset: 0x114
	// Line 1376, Address: 0x1bbe90, Func Offset: 0x120
	// Line 1374, Address: 0x1bbe94, Func Offset: 0x124
	// Line 1376, Address: 0x1bbe9c, Func Offset: 0x12c
	// Line 1378, Address: 0x1bbea8, Func Offset: 0x138
	// Line 1382, Address: 0x1bbeb4, Func Offset: 0x144
	// Line 1383, Address: 0x1bbec4, Func Offset: 0x154
	// Line 1384, Address: 0x1bbed8, Func Offset: 0x168
	// Line 1387, Address: 0x1bbedc, Func Offset: 0x16c
	// Line 1384, Address: 0x1bbee0, Func Offset: 0x170
	// Line 1383, Address: 0x1bbee4, Func Offset: 0x174
	// Line 1384, Address: 0x1bbee8, Func Offset: 0x178
	// Line 1383, Address: 0x1bbeec, Func Offset: 0x17c
	// Line 1384, Address: 0x1bbef0, Func Offset: 0x180
	// Line 1388, Address: 0x1bbef8, Func Offset: 0x188
	// Line 1384, Address: 0x1bbefc, Func Offset: 0x18c
	// Line 1387, Address: 0x1bbf04, Func Offset: 0x194
	// Line 1388, Address: 0x1bbf14, Func Offset: 0x1a4
	// Line 1390, Address: 0x1bbf1c, Func Offset: 0x1ac
	// Line 1392, Address: 0x1bbf28, Func Offset: 0x1b8
	// Line 1396, Address: 0x1bbf34, Func Offset: 0x1c4
	// Line 1392, Address: 0x1bbf38, Func Offset: 0x1c8
	// Line 1396, Address: 0x1bbf3c, Func Offset: 0x1cc
	// Line 1392, Address: 0x1bbf44, Func Offset: 0x1d4
	// Line 1393, Address: 0x1bbf54, Func Offset: 0x1e4
	// Line 1394, Address: 0x1bbf74, Func Offset: 0x204
	// Line 1396, Address: 0x1bbf94, Func Offset: 0x224
	// Line 1397, Address: 0x1bbf9c, Func Offset: 0x22c
	// Line 1398, Address: 0x1bbfb8, Func Offset: 0x248
	// Line 1400, Address: 0x1bbfdc, Func Offset: 0x26c
	// Line 1401, Address: 0x1bc010, Func Offset: 0x2a0
	// Line 1403, Address: 0x1bc044, Func Offset: 0x2d4
	// Line 1404, Address: 0x1bc04c, Func Offset: 0x2dc
	// Line 1406, Address: 0x1bc054, Func Offset: 0x2e4
	// Line 1407, Address: 0x1bc05c, Func Offset: 0x2ec
	// Line 1408, Address: 0x1bc064, Func Offset: 0x2f4
	// Line 1411, Address: 0x1bc06c, Func Offset: 0x2fc
	// Line 1412, Address: 0x1bc078, Func Offset: 0x308
	// Line 1413, Address: 0x1bc084, Func Offset: 0x314
	// Line 1417, Address: 0x1bc08c, Func Offset: 0x31c
	// Line 1413, Address: 0x1bc098, Func Offset: 0x328
	// Line 1414, Address: 0x1bc09c, Func Offset: 0x32c
	// Line 1415, Address: 0x1bc0a8, Func Offset: 0x338
	// Line 1417, Address: 0x1bc0b0, Func Offset: 0x340
	// Line 1418, Address: 0x1bc0b8, Func Offset: 0x348
	// Line 1419, Address: 0x1bc0d4, Func Offset: 0x364
	// Line 1423, Address: 0x1bc0f8, Func Offset: 0x388
	// Line 1425, Address: 0x1bc108, Func Offset: 0x398
	// Line 1426, Address: 0x1bc10c, Func Offset: 0x39c
	// Line 1428, Address: 0x1bc110, Func Offset: 0x3a0
	// Line 1430, Address: 0x1bc114, Func Offset: 0x3a4
	// Line 1425, Address: 0x1bc118, Func Offset: 0x3a8
	// Line 1426, Address: 0x1bc120, Func Offset: 0x3b0
	// Line 1428, Address: 0x1bc12c, Func Offset: 0x3bc
	// Line 1429, Address: 0x1bc130, Func Offset: 0x3c0
	// Line 1430, Address: 0x1bc134, Func Offset: 0x3c4
	// Line 1431, Address: 0x1bc138, Func Offset: 0x3c8
	// Line 1435, Address: 0x1bc13c, Func Offset: 0x3cc
	// Line 1436, Address: 0x1bc150, Func Offset: 0x3e0
	// Line 1439, Address: 0x1bc160, Func Offset: 0x3f0
	// Line 1446, Address: 0x1bc174, Func Offset: 0x404
	// Line 1439, Address: 0x1bc180, Func Offset: 0x410
	// Line 1446, Address: 0x1bc184, Func Offset: 0x414
	// Line 1449, Address: 0x1bc190, Func Offset: 0x420
	// Line 1450, Address: 0x1bc1cc, Func Offset: 0x45c
	// Line 1449, Address: 0x1bc1d4, Func Offset: 0x464
	// Line 1450, Address: 0x1bc1d8, Func Offset: 0x468
	// Line 1451, Address: 0x1bc1dc, Func Offset: 0x46c
	// Line 1452, Address: 0x1bc1f8, Func Offset: 0x488
	// Line 1453, Address: 0x1bc1fc, Func Offset: 0x48c
	// Line 1455, Address: 0x1bc204, Func Offset: 0x494
	// Line 1456, Address: 0x1bc208, Func Offset: 0x498
	// Line 1457, Address: 0x1bc218, Func Offset: 0x4a8
	// Line 1460, Address: 0x1bc228, Func Offset: 0x4b8
	// Line 1463, Address: 0x1bc240, Func Offset: 0x4d0
	// Line 1461, Address: 0x1bc244, Func Offset: 0x4d4
	// Line 1463, Address: 0x1bc248, Func Offset: 0x4d8
	// Line 1467, Address: 0x1bc24c, Func Offset: 0x4dc
	// Func End, Address: 0x1bc260, Func Offset: 0x4f0
}
*/
// 
// Start address: 0x1bc260
void bhEne06_Damage(BH_PWORK* epw)
{
	int dam;
	int dir;
	int i;
	// Line 1477, Address: 0x1bc260, Func Offset: 0
	// Line 1481, Address: 0x1bc278, Func Offset: 0x18
	// Line 1482, Address: 0x1bc284, Func Offset: 0x24
	// Line 1483, Address: 0x1bc290, Func Offset: 0x30
	// Line 1484, Address: 0x1bc294, Func Offset: 0x34
	// Line 1486, Address: 0x1bc29c, Func Offset: 0x3c
	// Line 1487, Address: 0x1bc2b4, Func Offset: 0x54
	// Line 1489, Address: 0x1bc2c0, Func Offset: 0x60
	// Line 1491, Address: 0x1bc2cc, Func Offset: 0x6c
	// Line 1494, Address: 0x1bc2d4, Func Offset: 0x74
	// Line 1497, Address: 0x1bc2e4, Func Offset: 0x84
	// Line 1500, Address: 0x1bc2ec, Func Offset: 0x8c
	// Line 1503, Address: 0x1bc358, Func Offset: 0xf8
	// Line 1504, Address: 0x1bc360, Func Offset: 0x100
	// Line 1505, Address: 0x1bc368, Func Offset: 0x108
	// Line 1506, Address: 0x1bc36c, Func Offset: 0x10c
	// Line 1509, Address: 0x1bc370, Func Offset: 0x110
	// Line 1512, Address: 0x1bc384, Func Offset: 0x124
	// Line 1525, Address: 0x1bc38c, Func Offset: 0x12c
	// Line 1526, Address: 0x1bc394, Func Offset: 0x134
	// Line 1528, Address: 0x1bc39c, Func Offset: 0x13c
	// Line 1531, Address: 0x1bc3a0, Func Offset: 0x140
	// Line 1528, Address: 0x1bc3b0, Func Offset: 0x150
	// Line 1529, Address: 0x1bc3b4, Func Offset: 0x154
	// Line 1531, Address: 0x1bc3b8, Func Offset: 0x158
	// Line 1529, Address: 0x1bc3c0, Func Offset: 0x160
	// Line 1530, Address: 0x1bc3c4, Func Offset: 0x164
	// Line 1531, Address: 0x1bc3c8, Func Offset: 0x168
	// Line 1532, Address: 0x1bc3d0, Func Offset: 0x170
	// Line 1533, Address: 0x1bc3ec, Func Offset: 0x18c
	// Line 1534, Address: 0x1bc3f4, Func Offset: 0x194
	// Line 1536, Address: 0x1bc400, Func Offset: 0x1a0
	// Line 1537, Address: 0x1bc40c, Func Offset: 0x1ac
	// Line 1539, Address: 0x1bc414, Func Offset: 0x1b4
	// Line 1546, Address: 0x1bc418, Func Offset: 0x1b8
	// Line 1547, Address: 0x1bc41c, Func Offset: 0x1bc
	// Line 1550, Address: 0x1bc420, Func Offset: 0x1c0
	// Line 1546, Address: 0x1bc424, Func Offset: 0x1c4
	// Line 1547, Address: 0x1bc42c, Func Offset: 0x1cc
	// Line 1550, Address: 0x1bc434, Func Offset: 0x1d4
	// Line 1551, Address: 0x1bc43c, Func Offset: 0x1dc
	// Line 1556, Address: 0x1bc444, Func Offset: 0x1e4
	// Line 1557, Address: 0x1bc464, Func Offset: 0x204
	// Func End, Address: 0x1bc47c, Func Offset: 0x21c
    scePrintf("bhEne06_Damage - UNIMPLEMENTED!\n");
}
/*
// 
// Start address: 0x1bc480
void bhEne06_DG00(BH_PWORK* epw)
{
	_anon35 trans;
	_anon3* mkfP;
	char parts[4];
	_anon4* owk;
	int pno;
	_anon35 pos;
	// Line 1567, Address: 0x1bc480, Func Offset: 0
	// Line 1571, Address: 0x1bc48c, Func Offset: 0xc
	// Line 1567, Address: 0x1bc490, Func Offset: 0x10
	// Line 1571, Address: 0x1bc494, Func Offset: 0x14
	// Line 1567, Address: 0x1bc498, Func Offset: 0x18
	// Line 1571, Address: 0x1bc49c, Func Offset: 0x1c
	// Line 1578, Address: 0x1bc4ac, Func Offset: 0x2c
	// Line 1580, Address: 0x1bc4e4, Func Offset: 0x64
	// Line 1582, Address: 0x1bc4ec, Func Offset: 0x6c
	// Line 1581, Address: 0x1bc4f0, Func Offset: 0x70
	// Line 1582, Address: 0x1bc4f4, Func Offset: 0x74
	// Line 1583, Address: 0x1bc4f8, Func Offset: 0x78
	// Line 1585, Address: 0x1bc500, Func Offset: 0x80
	// Line 1586, Address: 0x1bc508, Func Offset: 0x88
	// Line 1585, Address: 0x1bc510, Func Offset: 0x90
	// Line 1586, Address: 0x1bc518, Func Offset: 0x98
	// Line 1591, Address: 0x1bc524, Func Offset: 0xa4
	// Line 1592, Address: 0x1bc530, Func Offset: 0xb0
	// Line 1593, Address: 0x1bc53c, Func Offset: 0xbc
	// Line 1594, Address: 0x1bc548, Func Offset: 0xc8
	// Line 1595, Address: 0x1bc554, Func Offset: 0xd4
	// Line 1596, Address: 0x1bc558, Func Offset: 0xd8
	// Line 1600, Address: 0x1bc56c, Func Offset: 0xec
	// Line 1601, Address: 0x1bc570, Func Offset: 0xf0
	// Line 1602, Address: 0x1bc5ac, Func Offset: 0x12c
	// Line 1603, Address: 0x1bc5b4, Func Offset: 0x134
	// Line 1610, Address: 0x1bc5bc, Func Offset: 0x13c
	// Line 1602, Address: 0x1bc5c0, Func Offset: 0x140
	// Line 1607, Address: 0x1bc5d4, Func Offset: 0x154
	// Line 1610, Address: 0x1bc5d8, Func Offset: 0x158
	// Line 1602, Address: 0x1bc5e0, Func Offset: 0x160
	// Line 1603, Address: 0x1bc5e8, Func Offset: 0x168
	// Line 1604, Address: 0x1bc5f8, Func Offset: 0x178
	// Line 1607, Address: 0x1bc608, Func Offset: 0x188
	// Line 1610, Address: 0x1bc60c, Func Offset: 0x18c
	// Line 1612, Address: 0x1bc614, Func Offset: 0x194
	// Line 1613, Address: 0x1bc634, Func Offset: 0x1b4
	// Line 1616, Address: 0x1bc640, Func Offset: 0x1c0
	// Line 1621, Address: 0x1bc650, Func Offset: 0x1d0
	// Line 1622, Address: 0x1bc664, Func Offset: 0x1e4
	// Line 1628, Address: 0x1bc668, Func Offset: 0x1e8
	// Line 1626, Address: 0x1bc66c, Func Offset: 0x1ec
	// Line 1628, Address: 0x1bc670, Func Offset: 0x1f0
	// Line 1634, Address: 0x1bc674, Func Offset: 0x1f4
	// Line 1622, Address: 0x1bc678, Func Offset: 0x1f8
	// Line 1623, Address: 0x1bc67c, Func Offset: 0x1fc
	// Line 1635, Address: 0x1bc680, Func Offset: 0x200
	// Line 1637, Address: 0x1bc684, Func Offset: 0x204
	// Line 1623, Address: 0x1bc688, Func Offset: 0x208
	// Line 1624, Address: 0x1bc68c, Func Offset: 0x20c
	// Line 1626, Address: 0x1bc694, Func Offset: 0x214
	// Line 1627, Address: 0x1bc698, Func Offset: 0x218
	// Line 1628, Address: 0x1bc69c, Func Offset: 0x21c
	// Line 1631, Address: 0x1bc6a8, Func Offset: 0x228
	// Line 1632, Address: 0x1bc6b0, Func Offset: 0x230
	// Line 1631, Address: 0x1bc6b4, Func Offset: 0x234
	// Line 1632, Address: 0x1bc6c8, Func Offset: 0x248
	// Line 1631, Address: 0x1bc6d4, Func Offset: 0x254
	// Line 1632, Address: 0x1bc6d8, Func Offset: 0x258
	// Line 1633, Address: 0x1bc6e0, Func Offset: 0x260
	// Line 1634, Address: 0x1bc6e8, Func Offset: 0x268
	// Line 1635, Address: 0x1bc6f0, Func Offset: 0x270
	// Line 1637, Address: 0x1bc6f4, Func Offset: 0x274
	// Line 1638, Address: 0x1bc6fc, Func Offset: 0x27c
	// Line 1639, Address: 0x1bc708, Func Offset: 0x288
	// Line 1641, Address: 0x1bc718, Func Offset: 0x298
	// Line 1648, Address: 0x1bc720, Func Offset: 0x2a0
	// Line 1641, Address: 0x1bc724, Func Offset: 0x2a4
	// Line 1642, Address: 0x1bc72c, Func Offset: 0x2ac
	// Line 1643, Address: 0x1bc73c, Func Offset: 0x2bc
	// Line 1645, Address: 0x1bc74c, Func Offset: 0x2cc
	// Line 1648, Address: 0x1bc758, Func Offset: 0x2d8
	// Line 1652, Address: 0x1bc764, Func Offset: 0x2e4
	// Line 1653, Address: 0x1bc778, Func Offset: 0x2f8
	// Line 1654, Address: 0x1bc780, Func Offset: 0x300
	// Line 1655, Address: 0x1bc784, Func Offset: 0x304
	// Line 1656, Address: 0x1bc788, Func Offset: 0x308
	// Line 1657, Address: 0x1bc790, Func Offset: 0x310
	// Line 1656, Address: 0x1bc794, Func Offset: 0x314
	// Line 1658, Address: 0x1bc7b0, Func Offset: 0x330
	// Line 1660, Address: 0x1bc7b8, Func Offset: 0x338
	// Line 1663, Address: 0x1bc7bc, Func Offset: 0x33c
	// Line 1660, Address: 0x1bc7c4, Func Offset: 0x344
	// Line 1663, Address: 0x1bc7c8, Func Offset: 0x348
	// Line 1660, Address: 0x1bc7cc, Func Offset: 0x34c
	// Line 1661, Address: 0x1bc7d8, Func Offset: 0x358
	// Line 1662, Address: 0x1bc7ec, Func Offset: 0x36c
	// Line 1663, Address: 0x1bc800, Func Offset: 0x380
	// Line 1665, Address: 0x1bc80c, Func Offset: 0x38c
	// Line 1667, Address: 0x1bc814, Func Offset: 0x394
	// Line 1669, Address: 0x1bc824, Func Offset: 0x3a4
	// Line 1670, Address: 0x1bc82c, Func Offset: 0x3ac
	// Line 1671, Address: 0x1bc830, Func Offset: 0x3b0
	// Line 1672, Address: 0x1bc838, Func Offset: 0x3b8
	// Line 1675, Address: 0x1bc83c, Func Offset: 0x3bc
	// Line 1680, Address: 0x1bc84c, Func Offset: 0x3cc
	// Line 1681, Address: 0x1bc868, Func Offset: 0x3e8
	// Func End, Address: 0x1bc880, Func Offset: 0x400
}

// 
// Start address: 0x1bc880
void bhEne06_DG01(BH_PWORK* epw)
{
	_anon35 trans;
	_anon3* mkfP;
	char parts[4];
	_anon4* owk;
	int pno;
	_anon35 pos;
	// Line 1691, Address: 0x1bc880, Func Offset: 0
	// Line 1695, Address: 0x1bc88c, Func Offset: 0xc
	// Line 1691, Address: 0x1bc890, Func Offset: 0x10
	// Line 1695, Address: 0x1bc894, Func Offset: 0x14
	// Line 1691, Address: 0x1bc898, Func Offset: 0x18
	// Line 1695, Address: 0x1bc89c, Func Offset: 0x1c
	// Line 1702, Address: 0x1bc8ac, Func Offset: 0x2c
	// Line 1704, Address: 0x1bc8e4, Func Offset: 0x64
	// Line 1706, Address: 0x1bc8ec, Func Offset: 0x6c
	// Line 1705, Address: 0x1bc8f0, Func Offset: 0x70
	// Line 1706, Address: 0x1bc8f4, Func Offset: 0x74
	// Line 1707, Address: 0x1bc8f8, Func Offset: 0x78
	// Line 1709, Address: 0x1bc900, Func Offset: 0x80
	// Line 1710, Address: 0x1bc908, Func Offset: 0x88
	// Line 1709, Address: 0x1bc910, Func Offset: 0x90
	// Line 1710, Address: 0x1bc918, Func Offset: 0x98
	// Line 1715, Address: 0x1bc924, Func Offset: 0xa4
	// Line 1716, Address: 0x1bc930, Func Offset: 0xb0
	// Line 1717, Address: 0x1bc93c, Func Offset: 0xbc
	// Line 1718, Address: 0x1bc948, Func Offset: 0xc8
	// Line 1719, Address: 0x1bc954, Func Offset: 0xd4
	// Line 1720, Address: 0x1bc958, Func Offset: 0xd8
	// Line 1724, Address: 0x1bc960, Func Offset: 0xe0
	// Line 1720, Address: 0x1bc964, Func Offset: 0xe4
	// Line 1721, Address: 0x1bc970, Func Offset: 0xf0
	// Line 1724, Address: 0x1bc974, Func Offset: 0xf4
	// Line 1727, Address: 0x1bc978, Func Offset: 0xf8
	// Line 1728, Address: 0x1bc97c, Func Offset: 0xfc
	// Line 1729, Address: 0x1bc9b8, Func Offset: 0x138
	// Line 1730, Address: 0x1bc9c0, Func Offset: 0x140
	// Line 1734, Address: 0x1bc9c4, Func Offset: 0x144
	// Line 1729, Address: 0x1bc9cc, Func Offset: 0x14c
	// Line 1730, Address: 0x1bc9e0, Func Offset: 0x160
	// Line 1734, Address: 0x1bc9e4, Func Offset: 0x164
	// Line 1729, Address: 0x1bc9e8, Func Offset: 0x168
	// Line 1730, Address: 0x1bc9f0, Func Offset: 0x170
	// Line 1731, Address: 0x1bca00, Func Offset: 0x180
	// Line 1734, Address: 0x1bca0c, Func Offset: 0x18c
	// Line 1736, Address: 0x1bca14, Func Offset: 0x194
	// Line 1737, Address: 0x1bca34, Func Offset: 0x1b4
	// Line 1740, Address: 0x1bca40, Func Offset: 0x1c0
	// Line 1745, Address: 0x1bca50, Func Offset: 0x1d0
	// Line 1746, Address: 0x1bca64, Func Offset: 0x1e4
	// Line 1752, Address: 0x1bca68, Func Offset: 0x1e8
	// Line 1750, Address: 0x1bca6c, Func Offset: 0x1ec
	// Line 1752, Address: 0x1bca70, Func Offset: 0x1f0
	// Line 1758, Address: 0x1bca74, Func Offset: 0x1f4
	// Line 1746, Address: 0x1bca78, Func Offset: 0x1f8
	// Line 1747, Address: 0x1bca7c, Func Offset: 0x1fc
	// Line 1759, Address: 0x1bca80, Func Offset: 0x200
	// Line 1761, Address: 0x1bca84, Func Offset: 0x204
	// Line 1747, Address: 0x1bca88, Func Offset: 0x208
	// Line 1748, Address: 0x1bca8c, Func Offset: 0x20c
	// Line 1750, Address: 0x1bca94, Func Offset: 0x214
	// Line 1751, Address: 0x1bca98, Func Offset: 0x218
	// Line 1752, Address: 0x1bca9c, Func Offset: 0x21c
	// Line 1755, Address: 0x1bcaa8, Func Offset: 0x228
	// Line 1756, Address: 0x1bcab0, Func Offset: 0x230
	// Line 1755, Address: 0x1bcab4, Func Offset: 0x234
	// Line 1756, Address: 0x1bcac8, Func Offset: 0x248
	// Line 1755, Address: 0x1bcad4, Func Offset: 0x254
	// Line 1756, Address: 0x1bcad8, Func Offset: 0x258
	// Line 1757, Address: 0x1bcae0, Func Offset: 0x260
	// Line 1758, Address: 0x1bcae8, Func Offset: 0x268
	// Line 1759, Address: 0x1bcaf0, Func Offset: 0x270
	// Line 1761, Address: 0x1bcaf4, Func Offset: 0x274
	// Line 1762, Address: 0x1bcafc, Func Offset: 0x27c
	// Line 1763, Address: 0x1bcb08, Func Offset: 0x288
	// Line 1765, Address: 0x1bcb18, Func Offset: 0x298
	// Line 1772, Address: 0x1bcb20, Func Offset: 0x2a0
	// Line 1765, Address: 0x1bcb24, Func Offset: 0x2a4
	// Line 1766, Address: 0x1bcb2c, Func Offset: 0x2ac
	// Line 1767, Address: 0x1bcb3c, Func Offset: 0x2bc
	// Line 1769, Address: 0x1bcb4c, Func Offset: 0x2cc
	// Line 1772, Address: 0x1bcb58, Func Offset: 0x2d8
	// Line 1776, Address: 0x1bcb64, Func Offset: 0x2e4
	// Line 1777, Address: 0x1bcb78, Func Offset: 0x2f8
	// Line 1778, Address: 0x1bcb80, Func Offset: 0x300
	// Line 1779, Address: 0x1bcb84, Func Offset: 0x304
	// Line 1780, Address: 0x1bcb88, Func Offset: 0x308
	// Line 1781, Address: 0x1bcb90, Func Offset: 0x310
	// Line 1780, Address: 0x1bcb94, Func Offset: 0x314
	// Line 1782, Address: 0x1bcbb0, Func Offset: 0x330
	// Line 1784, Address: 0x1bcbb8, Func Offset: 0x338
	// Line 1787, Address: 0x1bcbbc, Func Offset: 0x33c
	// Line 1784, Address: 0x1bcbc4, Func Offset: 0x344
	// Line 1787, Address: 0x1bcbc8, Func Offset: 0x348
	// Line 1784, Address: 0x1bcbcc, Func Offset: 0x34c
	// Line 1785, Address: 0x1bcbd8, Func Offset: 0x358
	// Line 1786, Address: 0x1bcbec, Func Offset: 0x36c
	// Line 1787, Address: 0x1bcc00, Func Offset: 0x380
	// Line 1789, Address: 0x1bcc0c, Func Offset: 0x38c
	// Line 1791, Address: 0x1bcc14, Func Offset: 0x394
	// Line 1793, Address: 0x1bcc24, Func Offset: 0x3a4
	// Line 1794, Address: 0x1bcc2c, Func Offset: 0x3ac
	// Line 1795, Address: 0x1bcc30, Func Offset: 0x3b0
	// Line 1798, Address: 0x1bcc38, Func Offset: 0x3b8
	// Line 1796, Address: 0x1bcc3c, Func Offset: 0x3bc
	// Line 1798, Address: 0x1bcc40, Func Offset: 0x3c0
	// Line 1799, Address: 0x1bcc44, Func Offset: 0x3c4
	// Line 1800, Address: 0x1bcc48, Func Offset: 0x3c8
	// Line 1803, Address: 0x1bcc4c, Func Offset: 0x3cc
	// Line 1805, Address: 0x1bcc50, Func Offset: 0x3d0
	// Line 1803, Address: 0x1bcc54, Func Offset: 0x3d4
	// Line 1805, Address: 0x1bcc60, Func Offset: 0x3e0
	// Line 1810, Address: 0x1bcc6c, Func Offset: 0x3ec
	// Line 1811, Address: 0x1bcc88, Func Offset: 0x408
	// Func End, Address: 0x1bcca0, Func Offset: 0x420
}
*/
// 100% matching!
void bhEne06_Die(BH_PWORK* epw)
{
    bhEne06_DeadMode2[epw->mode2](epw); 
}

// 
// Start address: 0x1bccc0
void bhEne06_DD00(BH_PWORK* epw)
{
	//_anon35 trans;
	//_anon3* mkfP;
	//_anon35 pos;
	// Line 1833, Address: 0x1bccc0, Func Offset: 0
	// Line 1836, Address: 0x1bccd4, Func Offset: 0x14
	// Line 1838, Address: 0x1bcd0c, Func Offset: 0x4c
	// Line 1840, Address: 0x1bcd14, Func Offset: 0x54
	// Line 1839, Address: 0x1bcd18, Func Offset: 0x58
	// Line 1840, Address: 0x1bcd1c, Func Offset: 0x5c
	// Line 1841, Address: 0x1bcd20, Func Offset: 0x60
	// Line 1843, Address: 0x1bcd28, Func Offset: 0x68
	// Line 1844, Address: 0x1bcd30, Func Offset: 0x70
	// Line 1843, Address: 0x1bcd38, Func Offset: 0x78
	// Line 1844, Address: 0x1bcd40, Func Offset: 0x80
	// Line 1846, Address: 0x1bcd4c, Func Offset: 0x8c
	// Line 1847, Address: 0x1bcd58, Func Offset: 0x98
	// Line 1848, Address: 0x1bcd64, Func Offset: 0xa4
	// Line 1849, Address: 0x1bcd70, Func Offset: 0xb0
	// Line 1850, Address: 0x1bcd7c, Func Offset: 0xbc
	// Line 1851, Address: 0x1bcd80, Func Offset: 0xc0
	// Line 1858, Address: 0x1bcd88, Func Offset: 0xc8
	// Line 1861, Address: 0x1bcd8c, Func Offset: 0xcc
	// Line 1851, Address: 0x1bcd90, Func Offset: 0xd0
	// Line 1861, Address: 0x1bcd94, Func Offset: 0xd4
	// Line 1851, Address: 0x1bcd9c, Func Offset: 0xdc
	// Line 1854, Address: 0x1bcda4, Func Offset: 0xe4
	// Line 1857, Address: 0x1bcdc4, Func Offset: 0x104
	// Line 1858, Address: 0x1bcdc8, Func Offset: 0x108
	// Line 1861, Address: 0x1bcdcc, Func Offset: 0x10c
	// Line 1863, Address: 0x1bcdd4, Func Offset: 0x114
	// Line 1866, Address: 0x1bcde0, Func Offset: 0x120
	// Line 1871, Address: 0x1bcdf0, Func Offset: 0x130
	// Line 1872, Address: 0x1bce04, Func Offset: 0x144
	// Line 1878, Address: 0x1bce08, Func Offset: 0x148
	// Line 1876, Address: 0x1bce0c, Func Offset: 0x14c
	// Line 1878, Address: 0x1bce10, Func Offset: 0x150
	// Line 1884, Address: 0x1bce14, Func Offset: 0x154
	// Line 1872, Address: 0x1bce18, Func Offset: 0x158
	// Line 1873, Address: 0x1bce1c, Func Offset: 0x15c
	// Line 1885, Address: 0x1bce20, Func Offset: 0x160
	// Line 1887, Address: 0x1bce24, Func Offset: 0x164
	// Line 1873, Address: 0x1bce28, Func Offset: 0x168
	// Line 1874, Address: 0x1bce2c, Func Offset: 0x16c
	// Line 1876, Address: 0x1bce34, Func Offset: 0x174
	// Line 1877, Address: 0x1bce38, Func Offset: 0x178
	// Line 1878, Address: 0x1bce3c, Func Offset: 0x17c
	// Line 1881, Address: 0x1bce48, Func Offset: 0x188
	// Line 1882, Address: 0x1bce50, Func Offset: 0x190
	// Line 1881, Address: 0x1bce54, Func Offset: 0x194
	// Line 1882, Address: 0x1bce68, Func Offset: 0x1a8
	// Line 1881, Address: 0x1bce74, Func Offset: 0x1b4
	// Line 1882, Address: 0x1bce78, Func Offset: 0x1b8
	// Line 1883, Address: 0x1bce80, Func Offset: 0x1c0
	// Line 1884, Address: 0x1bce88, Func Offset: 0x1c8
	// Line 1885, Address: 0x1bce90, Func Offset: 0x1d0
	// Line 1887, Address: 0x1bce94, Func Offset: 0x1d4
	// Line 1888, Address: 0x1bce9c, Func Offset: 0x1dc
	// Line 1889, Address: 0x1bcea8, Func Offset: 0x1e8
	// Line 1891, Address: 0x1bceb8, Func Offset: 0x1f8
	// Line 1898, Address: 0x1bcec0, Func Offset: 0x200
	// Line 1891, Address: 0x1bcec4, Func Offset: 0x204
	// Line 1892, Address: 0x1bcecc, Func Offset: 0x20c
	// Line 1893, Address: 0x1bcedc, Func Offset: 0x21c
	// Line 1895, Address: 0x1bceec, Func Offset: 0x22c
	// Line 1898, Address: 0x1bcef8, Func Offset: 0x238
	// Line 1902, Address: 0x1bcf04, Func Offset: 0x244
	// Line 1903, Address: 0x1bcf18, Func Offset: 0x258
	// Line 1904, Address: 0x1bcf20, Func Offset: 0x260
	// Line 1905, Address: 0x1bcf24, Func Offset: 0x264
	// Line 1906, Address: 0x1bcf28, Func Offset: 0x268
	// Line 1907, Address: 0x1bcf30, Func Offset: 0x270
	// Line 1906, Address: 0x1bcf34, Func Offset: 0x274
	// Line 1908, Address: 0x1bcf50, Func Offset: 0x290
	// Line 1910, Address: 0x1bcf58, Func Offset: 0x298
	// Line 1913, Address: 0x1bcf5c, Func Offset: 0x29c
	// Line 1910, Address: 0x1bcf64, Func Offset: 0x2a4
	// Line 1913, Address: 0x1bcf68, Func Offset: 0x2a8
	// Line 1910, Address: 0x1bcf6c, Func Offset: 0x2ac
	// Line 1911, Address: 0x1bcf78, Func Offset: 0x2b8
	// Line 1912, Address: 0x1bcf8c, Func Offset: 0x2cc
	// Line 1913, Address: 0x1bcfa0, Func Offset: 0x2e0
	// Line 1915, Address: 0x1bcfac, Func Offset: 0x2ec
	// Line 1917, Address: 0x1bcfb4, Func Offset: 0x2f4
	// Line 1918, Address: 0x1bcfc4, Func Offset: 0x304
	// Line 1923, Address: 0x1bcfcc, Func Offset: 0x30c
	// Line 1918, Address: 0x1bcfd4, Func Offset: 0x314
	// Line 1919, Address: 0x1bcfdc, Func Offset: 0x31c
	// Line 1920, Address: 0x1bcfe0, Func Offset: 0x320
	// Line 1923, Address: 0x1bcfec, Func Offset: 0x32c
	// Line 1927, Address: 0x1bcff8, Func Offset: 0x338
	// Line 1928, Address: 0x1bd014, Func Offset: 0x354
	// Func End, Address: 0x1bd02c, Func Offset: 0x36c
    scePrintf("bhEne06_DD00 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1bd030
void bhEne06_DD01(BH_PWORK* epw)
{
	//_anon35 trans;
	//_anon3* mkfP;
	//_anon35 pos;
	// Line 1938, Address: 0x1bd030, Func Offset: 0
	// Line 1941, Address: 0x1bd044, Func Offset: 0x14
	// Line 1943, Address: 0x1bd07c, Func Offset: 0x4c
	// Line 1945, Address: 0x1bd084, Func Offset: 0x54
	// Line 1944, Address: 0x1bd088, Func Offset: 0x58
	// Line 1945, Address: 0x1bd08c, Func Offset: 0x5c
	// Line 1946, Address: 0x1bd090, Func Offset: 0x60
	// Line 1948, Address: 0x1bd098, Func Offset: 0x68
	// Line 1949, Address: 0x1bd0a0, Func Offset: 0x70
	// Line 1948, Address: 0x1bd0a8, Func Offset: 0x78
	// Line 1949, Address: 0x1bd0b0, Func Offset: 0x80
	// Line 1951, Address: 0x1bd0bc, Func Offset: 0x8c
	// Line 1952, Address: 0x1bd0c8, Func Offset: 0x98
	// Line 1953, Address: 0x1bd0d4, Func Offset: 0xa4
	// Line 1954, Address: 0x1bd0e0, Func Offset: 0xb0
	// Line 1955, Address: 0x1bd0ec, Func Offset: 0xbc
	// Line 1956, Address: 0x1bd0f0, Func Offset: 0xc0
	// Line 1962, Address: 0x1bd0f8, Func Offset: 0xc8
	// Line 1956, Address: 0x1bd100, Func Offset: 0xd0
	// Line 1962, Address: 0x1bd104, Func Offset: 0xd4
	// Line 1956, Address: 0x1bd108, Func Offset: 0xd8
	// Line 1959, Address: 0x1bd110, Func Offset: 0xe0
	// Line 1962, Address: 0x1bd12c, Func Offset: 0xfc
	// Line 1964, Address: 0x1bd134, Func Offset: 0x104
	// Line 1967, Address: 0x1bd140, Func Offset: 0x110
	// Line 1972, Address: 0x1bd150, Func Offset: 0x120
	// Line 1973, Address: 0x1bd164, Func Offset: 0x134
	// Line 1979, Address: 0x1bd168, Func Offset: 0x138
	// Line 1977, Address: 0x1bd16c, Func Offset: 0x13c
	// Line 1979, Address: 0x1bd170, Func Offset: 0x140
	// Line 1985, Address: 0x1bd174, Func Offset: 0x144
	// Line 1973, Address: 0x1bd178, Func Offset: 0x148
	// Line 1974, Address: 0x1bd17c, Func Offset: 0x14c
	// Line 1986, Address: 0x1bd180, Func Offset: 0x150
	// Line 1988, Address: 0x1bd184, Func Offset: 0x154
	// Line 1974, Address: 0x1bd188, Func Offset: 0x158
	// Line 1975, Address: 0x1bd18c, Func Offset: 0x15c
	// Line 1977, Address: 0x1bd194, Func Offset: 0x164
	// Line 1978, Address: 0x1bd198, Func Offset: 0x168
	// Line 1979, Address: 0x1bd19c, Func Offset: 0x16c
	// Line 1982, Address: 0x1bd1a8, Func Offset: 0x178
	// Line 1983, Address: 0x1bd1b0, Func Offset: 0x180
	// Line 1982, Address: 0x1bd1b4, Func Offset: 0x184
	// Line 1983, Address: 0x1bd1c8, Func Offset: 0x198
	// Line 1982, Address: 0x1bd1d4, Func Offset: 0x1a4
	// Line 1983, Address: 0x1bd1d8, Func Offset: 0x1a8
	// Line 1984, Address: 0x1bd1e0, Func Offset: 0x1b0
	// Line 1985, Address: 0x1bd1e8, Func Offset: 0x1b8
	// Line 1986, Address: 0x1bd1f0, Func Offset: 0x1c0
	// Line 1988, Address: 0x1bd1f4, Func Offset: 0x1c4
	// Line 1989, Address: 0x1bd1fc, Func Offset: 0x1cc
	// Line 1990, Address: 0x1bd208, Func Offset: 0x1d8
	// Line 1992, Address: 0x1bd218, Func Offset: 0x1e8
	// Line 1999, Address: 0x1bd220, Func Offset: 0x1f0
	// Line 1992, Address: 0x1bd224, Func Offset: 0x1f4
	// Line 1993, Address: 0x1bd22c, Func Offset: 0x1fc
	// Line 1994, Address: 0x1bd23c, Func Offset: 0x20c
	// Line 1996, Address: 0x1bd24c, Func Offset: 0x21c
	// Line 1999, Address: 0x1bd258, Func Offset: 0x228
	// Line 2003, Address: 0x1bd264, Func Offset: 0x234
	// Line 2004, Address: 0x1bd278, Func Offset: 0x248
	// Line 2005, Address: 0x1bd280, Func Offset: 0x250
	// Line 2006, Address: 0x1bd284, Func Offset: 0x254
	// Line 2007, Address: 0x1bd288, Func Offset: 0x258
	// Line 2008, Address: 0x1bd290, Func Offset: 0x260
	// Line 2007, Address: 0x1bd294, Func Offset: 0x264
	// Line 2009, Address: 0x1bd2b0, Func Offset: 0x280
	// Line 2011, Address: 0x1bd2b8, Func Offset: 0x288
	// Line 2014, Address: 0x1bd2bc, Func Offset: 0x28c
	// Line 2011, Address: 0x1bd2c4, Func Offset: 0x294
	// Line 2014, Address: 0x1bd2c8, Func Offset: 0x298
	// Line 2011, Address: 0x1bd2cc, Func Offset: 0x29c
	// Line 2012, Address: 0x1bd2d8, Func Offset: 0x2a8
	// Line 2013, Address: 0x1bd2ec, Func Offset: 0x2bc
	// Line 2014, Address: 0x1bd300, Func Offset: 0x2d0
	// Line 2016, Address: 0x1bd30c, Func Offset: 0x2dc
	// Line 2018, Address: 0x1bd314, Func Offset: 0x2e4
	// Line 2019, Address: 0x1bd324, Func Offset: 0x2f4
	// Line 2024, Address: 0x1bd32c, Func Offset: 0x2fc
	// Line 2019, Address: 0x1bd334, Func Offset: 0x304
	// Line 2020, Address: 0x1bd33c, Func Offset: 0x30c
	// Line 2021, Address: 0x1bd340, Func Offset: 0x310
	// Line 2024, Address: 0x1bd34c, Func Offset: 0x31c
	// Line 2029, Address: 0x1bd358, Func Offset: 0x328
	// Line 2030, Address: 0x1bd374, Func Offset: 0x344
	// Func End, Address: 0x1bd38c, Func Offset: 0x35c
    scePrintf("bhEne06_DD01 - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1bd390
void bhEne06_DD02(BH_PWORK* epw)
{
	//_anon35 trans;
	//_anon3* mkfP;
	//_anon35 pos;
	// Line 2040, Address: 0x1bd390, Func Offset: 0
	// Line 2043, Address: 0x1bd3a4, Func Offset: 0x14
	// Line 2045, Address: 0x1bd3dc, Func Offset: 0x4c
	// Line 2047, Address: 0x1bd3e4, Func Offset: 0x54
	// Line 2046, Address: 0x1bd3e8, Func Offset: 0x58
	// Line 2047, Address: 0x1bd3ec, Func Offset: 0x5c
	// Line 2048, Address: 0x1bd3f0, Func Offset: 0x60
	// Line 2050, Address: 0x1bd3f8, Func Offset: 0x68
	// Line 2051, Address: 0x1bd400, Func Offset: 0x70
	// Line 2050, Address: 0x1bd408, Func Offset: 0x78
	// Line 2051, Address: 0x1bd410, Func Offset: 0x80
	// Line 2053, Address: 0x1bd41c, Func Offset: 0x8c
	// Line 2054, Address: 0x1bd428, Func Offset: 0x98
	// Line 2055, Address: 0x1bd434, Func Offset: 0xa4
	// Line 2056, Address: 0x1bd440, Func Offset: 0xb0
	// Line 2057, Address: 0x1bd44c, Func Offset: 0xbc
	// Line 2058, Address: 0x1bd450, Func Offset: 0xc0
	// Line 2064, Address: 0x1bd458, Func Offset: 0xc8
	// Line 2058, Address: 0x1bd460, Func Offset: 0xd0
	// Line 2064, Address: 0x1bd464, Func Offset: 0xd4
	// Line 2058, Address: 0x1bd468, Func Offset: 0xd8
	// Line 2061, Address: 0x1bd470, Func Offset: 0xe0
	// Line 2064, Address: 0x1bd48c, Func Offset: 0xfc
	// Line 2066, Address: 0x1bd494, Func Offset: 0x104
	// Line 2069, Address: 0x1bd4a0, Func Offset: 0x110
	// Line 2074, Address: 0x1bd4b0, Func Offset: 0x120
	// Line 2075, Address: 0x1bd4c4, Func Offset: 0x134
	// Line 2081, Address: 0x1bd4c8, Func Offset: 0x138
	// Line 2079, Address: 0x1bd4cc, Func Offset: 0x13c
	// Line 2081, Address: 0x1bd4d0, Func Offset: 0x140
	// Line 2087, Address: 0x1bd4d4, Func Offset: 0x144
	// Line 2075, Address: 0x1bd4d8, Func Offset: 0x148
	// Line 2076, Address: 0x1bd4dc, Func Offset: 0x14c
	// Line 2088, Address: 0x1bd4e0, Func Offset: 0x150
	// Line 2090, Address: 0x1bd4e4, Func Offset: 0x154
	// Line 2076, Address: 0x1bd4e8, Func Offset: 0x158
	// Line 2077, Address: 0x1bd4ec, Func Offset: 0x15c
	// Line 2079, Address: 0x1bd4f4, Func Offset: 0x164
	// Line 2080, Address: 0x1bd4f8, Func Offset: 0x168
	// Line 2081, Address: 0x1bd4fc, Func Offset: 0x16c
	// Line 2084, Address: 0x1bd508, Func Offset: 0x178
	// Line 2085, Address: 0x1bd510, Func Offset: 0x180
	// Line 2084, Address: 0x1bd514, Func Offset: 0x184
	// Line 2085, Address: 0x1bd528, Func Offset: 0x198
	// Line 2084, Address: 0x1bd534, Func Offset: 0x1a4
	// Line 2085, Address: 0x1bd538, Func Offset: 0x1a8
	// Line 2086, Address: 0x1bd540, Func Offset: 0x1b0
	// Line 2087, Address: 0x1bd548, Func Offset: 0x1b8
	// Line 2088, Address: 0x1bd550, Func Offset: 0x1c0
	// Line 2090, Address: 0x1bd554, Func Offset: 0x1c4
	// Line 2091, Address: 0x1bd55c, Func Offset: 0x1cc
	// Line 2092, Address: 0x1bd568, Func Offset: 0x1d8
	// Line 2094, Address: 0x1bd578, Func Offset: 0x1e8
	// Line 2101, Address: 0x1bd580, Func Offset: 0x1f0
	// Line 2094, Address: 0x1bd584, Func Offset: 0x1f4
	// Line 2095, Address: 0x1bd58c, Func Offset: 0x1fc
	// Line 2096, Address: 0x1bd59c, Func Offset: 0x20c
	// Line 2098, Address: 0x1bd5ac, Func Offset: 0x21c
	// Line 2101, Address: 0x1bd5b8, Func Offset: 0x228
	// Line 2105, Address: 0x1bd5c4, Func Offset: 0x234
	// Line 2106, Address: 0x1bd5d8, Func Offset: 0x248
	// Line 2107, Address: 0x1bd5e0, Func Offset: 0x250
	// Line 2108, Address: 0x1bd5e4, Func Offset: 0x254
	// Line 2109, Address: 0x1bd5e8, Func Offset: 0x258
	// Line 2110, Address: 0x1bd5f0, Func Offset: 0x260
	// Line 2109, Address: 0x1bd5f4, Func Offset: 0x264
	// Line 2111, Address: 0x1bd610, Func Offset: 0x280
	// Line 2113, Address: 0x1bd618, Func Offset: 0x288
	// Line 2116, Address: 0x1bd61c, Func Offset: 0x28c
	// Line 2113, Address: 0x1bd624, Func Offset: 0x294
	// Line 2116, Address: 0x1bd628, Func Offset: 0x298
	// Line 2113, Address: 0x1bd62c, Func Offset: 0x29c
	// Line 2114, Address: 0x1bd638, Func Offset: 0x2a8
	// Line 2115, Address: 0x1bd64c, Func Offset: 0x2bc
	// Line 2116, Address: 0x1bd660, Func Offset: 0x2d0
	// Line 2118, Address: 0x1bd66c, Func Offset: 0x2dc
	// Line 2120, Address: 0x1bd674, Func Offset: 0x2e4
	// Line 2121, Address: 0x1bd684, Func Offset: 0x2f4
	// Line 2125, Address: 0x1bd68c, Func Offset: 0x2fc
	// Line 2121, Address: 0x1bd694, Func Offset: 0x304
	// Line 2122, Address: 0x1bd69c, Func Offset: 0x30c
	// Line 2123, Address: 0x1bd6a0, Func Offset: 0x310
	// Line 2125, Address: 0x1bd6ac, Func Offset: 0x31c
	// Line 2130, Address: 0x1bd6b8, Func Offset: 0x328
	// Line 2131, Address: 0x1bd6d4, Func Offset: 0x344
	// Func End, Address: 0x1bd6ec, Func Offset: 0x35c
    scePrintf("bhEne06_DD02 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne06_DD03(BH_PWORK* epw)
{
    O_WORK* owk;
	int i;
	
    switch (epw->mode3)
    {
    case 0:
        owk = epw->mlwP->owP;
        for (i = 0; i < 12U; i++)
        {
            owk[BrokenParts[i]].flg |= 3;
            *(char *)(*(int *)(epw->exp0 + i * 4 + 0x34) + 0xC) = 1;
            *(char *)(*(int *)(epw->exp0 + i * 4 + 0x34) + 0xE) = (i < 4);
        }
        
        epw->mlwP->objP[1].evalflags |= 8;
        epw->mlwP->objP[2].evalflags |= 8;
        
        epw->stflg |= 8;
        epw->flg &= ~0x78;
        epw->flg |= 0x8000;
        
        epw->mtn_add = 0;
        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8960);
        epw->mode3++;        
    } 
}

// 100% matching!
void bhEne06_DD04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->frm_no = 0;
        epw->mtn_add = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->flg |= 2;
        epw->flg &= ~0x28;
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;
    }
}

// 100% matching!
void bhEne06_SearchPlayer(BH_PWORK* epw)
{
    float dx;
    float dz;
    
    EXP0_C(0x16) = 0;
    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    EXP0_F(0) = njSqrt(dx * dx + dz * dz);
    EXP0_C(0x16) = 1;
}


// 
// Start address: 0x1bd910
void bhEne06_CollisionWalls(BH_PWORK* epw)
{
	//npobj* objP;
	//_anon20* mkaP;
	//_anon35 trans;
	//_anon35 ofp;
	// Line 2238, Address: 0x1bd910, Func Offset: 0
	// Line 2243, Address: 0x1bd92c, Func Offset: 0x1c
	// Line 2246, Address: 0x1bd93c, Func Offset: 0x2c
	// Line 2243, Address: 0x1bd940, Func Offset: 0x30
	// Line 2246, Address: 0x1bd954, Func Offset: 0x44
	// Line 2247, Address: 0x1bd964, Func Offset: 0x54
	// Line 2248, Address: 0x1bd96c, Func Offset: 0x5c
	// Line 2249, Address: 0x1bd974, Func Offset: 0x64
	// Line 2250, Address: 0x1bd97c, Func Offset: 0x6c
	// Line 2251, Address: 0x1bd980, Func Offset: 0x70
	// Line 2250, Address: 0x1bd984, Func Offset: 0x74
	// Line 2251, Address: 0x1bd988, Func Offset: 0x78
	// Line 2253, Address: 0x1bd998, Func Offset: 0x88
	// Line 2254, Address: 0x1bd9a0, Func Offset: 0x90
	// Line 2256, Address: 0x1bd9a4, Func Offset: 0x94
	// Line 2253, Address: 0x1bd9a8, Func Offset: 0x98
	// Line 2254, Address: 0x1bd9c0, Func Offset: 0xb0
	// Line 2256, Address: 0x1bd9d0, Func Offset: 0xc0
	// Line 2257, Address: 0x1bd9d8, Func Offset: 0xc8
	// Line 2258, Address: 0x1bd9e4, Func Offset: 0xd4
	// Line 2259, Address: 0x1bd9f8, Func Offset: 0xe8
	// Line 2265, Address: 0x1bda08, Func Offset: 0xf8
	// Line 2268, Address: 0x1bda0c, Func Offset: 0xfc
	// Line 2269, Address: 0x1bda10, Func Offset: 0x100
	// Line 2272, Address: 0x1bda14, Func Offset: 0x104
	// Line 2265, Address: 0x1bda18, Func Offset: 0x108
	// Line 2267, Address: 0x1bda1c, Func Offset: 0x10c
	// Line 2268, Address: 0x1bda24, Func Offset: 0x114
	// Line 2269, Address: 0x1bda2c, Func Offset: 0x11c
	// Line 2272, Address: 0x1bda34, Func Offset: 0x124
	// Line 2274, Address: 0x1bda48, Func Offset: 0x138
	// Line 2275, Address: 0x1bda54, Func Offset: 0x144
	// Line 2276, Address: 0x1bda60, Func Offset: 0x150
	// Line 2278, Address: 0x1bda70, Func Offset: 0x160
	// Line 2284, Address: 0x1bda78, Func Offset: 0x168
	// Line 2285, Address: 0x1bda7c, Func Offset: 0x16c
	// Line 2297, Address: 0x1bda80, Func Offset: 0x170
	// Line 2278, Address: 0x1bda84, Func Offset: 0x174
	// Line 2279, Address: 0x1bda8c, Func Offset: 0x17c
	// Line 2280, Address: 0x1bda9c, Func Offset: 0x18c
	// Line 2283, Address: 0x1bdaac, Func Offset: 0x19c
	// Line 2284, Address: 0x1bdabc, Func Offset: 0x1ac
	// Line 2285, Address: 0x1bdacc, Func Offset: 0x1bc
	// Line 2297, Address: 0x1bdad8, Func Offset: 0x1c8
	// Line 2298, Address: 0x1bdae8, Func Offset: 0x1d8
	// Line 2299, Address: 0x1bdaf8, Func Offset: 0x1e8
	// Line 2300, Address: 0x1bdb08, Func Offset: 0x1f8
	// Line 2303, Address: 0x1bdb18, Func Offset: 0x208
	// Line 2304, Address: 0x1bdb28, Func Offset: 0x218
	// Line 2305, Address: 0x1bdb38, Func Offset: 0x228
	// Line 2306, Address: 0x1bdb48, Func Offset: 0x238
	// Func End, Address: 0x1bdb68, Func Offset: 0x258
    scePrintf("bhEne06_CollisionWalls - UNIMPLEMENTED!\n");
}

// 
// Start address: 0x1bdb70
void bhEne06_FloorCollision(BH_PWORK* epw)
{
	//_anon22* hp;
	// Line 2316, Address: 0x1bdb70, Func Offset: 0
	// Line 2319, Address: 0x1bdb80, Func Offset: 0x10
	// Line 2320, Address: 0x1bdb94, Func Offset: 0x24
	// Line 2321, Address: 0x1bdb9c, Func Offset: 0x2c
	// Line 2322, Address: 0x1bdba8, Func Offset: 0x38
	// Line 2323, Address: 0x1bdbb4, Func Offset: 0x44
	// Line 2324, Address: 0x1bdbb8, Func Offset: 0x48
	// Line 2323, Address: 0x1bdbc4, Func Offset: 0x54
	// Line 2324, Address: 0x1bdbc8, Func Offset: 0x58
	// Line 2325, Address: 0x1bdbe0, Func Offset: 0x70
	// Line 2326, Address: 0x1bdbec, Func Offset: 0x7c
	// Line 2325, Address: 0x1bdbf0, Func Offset: 0x80
	// Line 2326, Address: 0x1bdbf8, Func Offset: 0x88
	// Line 2327, Address: 0x1bdc04, Func Offset: 0x94
	// Line 2329, Address: 0x1bdc1c, Func Offset: 0xac
	// Line 2332, Address: 0x1bdc24, Func Offset: 0xb4
	// Line 2333, Address: 0x1bdc74, Func Offset: 0x104
	// Line 2336, Address: 0x1bdc78, Func Offset: 0x108
	// Line 2338, Address: 0x1bdc9c, Func Offset: 0x12c
	// Line 2340, Address: 0x1bdca0, Func Offset: 0x130
	// Line 2342, Address: 0x1bdccc, Func Offset: 0x15c
	// Line 2343, Address: 0x1bdcd4, Func Offset: 0x164
	// Line 2346, Address: 0x1bdcdc, Func Offset: 0x16c
	// Func End, Address: 0x1bdcf0, Func Offset: 0x180
    scePrintf("bhEne06_FloorCollision - UNIMPLEMENTED!\n");
}

// 100% matching!
int bhEne06_CheckLeaningWall(BH_PWORK* epw)
{
	NJS_VECTOR vec;
	NJS_POINT3 pos;
	ATR_WORK* hp;
	NJS_VECTOR n; 
	BH_PWORK* ep;
	float dist;    
	int i;

    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = -10.0f;
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &vec, &vec);
    ep = ene;
    i = 0;
    pos.x = epw->px + vec.x;
    pos.y = epw->py;
    pos.z = epw->pz + vec.z;

    while (i < sys->ewk_n)
    {
        if ((ep->flg & 1) && (ep->id == 6) && (ep != epw))
        {
            dist = njDistanceP2P((NJS_POINT3*)&ep->px, &pos);
            if (dist < 10.0f)
            {
                return 0;
            }
        }
        
        i++;
        ep++;
    }

    hp = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, &pos);
    if ((hp != NULL) && !(hp->attr & 8))
    {
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        epw->ayp = bhArcTan2(n.x, n.z);
        EXP0_F(0x28) = pos.x + n.x;
        EXP0_F(0x2C) = pos.y + n.y;
        EXP0_F(0x30) = pos.z + n.z;
        return 1;
    }

    return 0;
}

/*
// 
// Start address: 0x1bded0
int bhEne06_AvoidWall(BH_PWORK* epw, int dir)
{
	npobj* objP;
	float wdist;
	float dist;
	BH_PWORK* ep2;
	BH_PWORK* ep;
	int i;
	_anon20* mkaP;
	int ret;
	_anon35 trans;
	_anon35 ofp;
	_anon22* hp2;
	_anon22* hp1;
	_anon35 pos2;
	_anon35 pos1;
	// Line 2410, Address: 0x1bded0, Func Offset: 0
	// Line 2425, Address: 0x1bdefc, Func Offset: 0x2c
	// Line 2410, Address: 0x1bdf04, Func Offset: 0x34
	// Line 2415, Address: 0x1bdf10, Func Offset: 0x40
	// Line 2424, Address: 0x1bdf14, Func Offset: 0x44
	// Line 2425, Address: 0x1bdf18, Func Offset: 0x48
	// Line 2426, Address: 0x1bdf20, Func Offset: 0x50
	// Line 2427, Address: 0x1bdf40, Func Offset: 0x70
	// Line 2430, Address: 0x1bdf64, Func Offset: 0x94
	// Line 2431, Address: 0x1bdf88, Func Offset: 0xb8
	// Line 2432, Address: 0x1bdfa0, Func Offset: 0xd0
	// Line 2433, Address: 0x1bdfa4, Func Offset: 0xd4
	// Line 2436, Address: 0x1bdfa8, Func Offset: 0xd8
	// Line 2438, Address: 0x1bdfd0, Func Offset: 0x100
	// Line 2439, Address: 0x1be004, Func Offset: 0x134
	// Line 2440, Address: 0x1be01c, Func Offset: 0x14c
	// Line 2441, Address: 0x1be030, Func Offset: 0x160
	// Line 2442, Address: 0x1be038, Func Offset: 0x168
	// Line 2452, Address: 0x1be050, Func Offset: 0x180
	// Line 2453, Address: 0x1be064, Func Offset: 0x194
	// Line 2454, Address: 0x1be06c, Func Offset: 0x19c
	// Line 2455, Address: 0x1be074, Func Offset: 0x1a4
	// Line 2456, Address: 0x1be07c, Func Offset: 0x1ac
	// Line 2457, Address: 0x1be080, Func Offset: 0x1b0
	// Line 2456, Address: 0x1be084, Func Offset: 0x1b4
	// Line 2457, Address: 0x1be088, Func Offset: 0x1b8
	// Line 2459, Address: 0x1be098, Func Offset: 0x1c8
	// Line 2460, Address: 0x1be0a0, Func Offset: 0x1d0
	// Line 2462, Address: 0x1be0a4, Func Offset: 0x1d4
	// Line 2459, Address: 0x1be0a8, Func Offset: 0x1d8
	// Line 2460, Address: 0x1be0c0, Func Offset: 0x1f0
	// Line 2462, Address: 0x1be0d0, Func Offset: 0x200
	// Line 2463, Address: 0x1be0d8, Func Offset: 0x208
	// Line 2464, Address: 0x1be0e4, Func Offset: 0x214
	// Line 2465, Address: 0x1be0f8, Func Offset: 0x228
	// Line 2471, Address: 0x1be108, Func Offset: 0x238
	// Line 2474, Address: 0x1be10c, Func Offset: 0x23c
	// Line 2478, Address: 0x1be110, Func Offset: 0x240
	// Line 2471, Address: 0x1be114, Func Offset: 0x244
	// Line 2473, Address: 0x1be118, Func Offset: 0x248
	// Line 2474, Address: 0x1be120, Func Offset: 0x250
	// Line 2475, Address: 0x1be128, Func Offset: 0x258
	// Line 2478, Address: 0x1be134, Func Offset: 0x264
	// Line 2480, Address: 0x1be148, Func Offset: 0x278
	// Line 2481, Address: 0x1be154, Func Offset: 0x284
	// Line 2482, Address: 0x1be160, Func Offset: 0x290
	// Line 2488, Address: 0x1be170, Func Offset: 0x2a0
	// Line 2489, Address: 0x1be17c, Func Offset: 0x2ac
	// Line 2492, Address: 0x1be180, Func Offset: 0x2b0
	// Line 2489, Address: 0x1be184, Func Offset: 0x2b4
	// Line 2488, Address: 0x1be188, Func Offset: 0x2b8
	// Line 2490, Address: 0x1be18c, Func Offset: 0x2bc
	// Line 2493, Address: 0x1be190, Func Offset: 0x2c0
	// Line 2488, Address: 0x1be194, Func Offset: 0x2c4
	// Line 2494, Address: 0x1be198, Func Offset: 0x2c8
	// Line 2488, Address: 0x1be1a0, Func Offset: 0x2d0
	// Line 2489, Address: 0x1be1a4, Func Offset: 0x2d4
	// Line 2492, Address: 0x1be1b0, Func Offset: 0x2e0
	// Line 2490, Address: 0x1be1b4, Func Offset: 0x2e4
	// Line 2489, Address: 0x1be1b8, Func Offset: 0x2e8
	// Line 2490, Address: 0x1be1c4, Func Offset: 0x2f4
	// Line 2492, Address: 0x1be1dc, Func Offset: 0x30c
	// Line 2490, Address: 0x1be1e0, Func Offset: 0x310
	// Line 2491, Address: 0x1be1e4, Func Offset: 0x314
	// Line 2492, Address: 0x1be1ec, Func Offset: 0x31c
	// Line 2493, Address: 0x1be1f8, Func Offset: 0x328
	// Line 2494, Address: 0x1be1fc, Func Offset: 0x32c
	// Line 2504, Address: 0x1be208, Func Offset: 0x338
	// Line 2505, Address: 0x1be210, Func Offset: 0x340
	// Line 2506, Address: 0x1be218, Func Offset: 0x348
	// Line 2505, Address: 0x1be220, Func Offset: 0x350
	// Line 2507, Address: 0x1be224, Func Offset: 0x354
	// Line 2505, Address: 0x1be228, Func Offset: 0x358
	// Line 2506, Address: 0x1be234, Func Offset: 0x364
	// Line 2507, Address: 0x1be250, Func Offset: 0x380
	// Line 2509, Address: 0x1be26c, Func Offset: 0x39c
	// Line 2510, Address: 0x1be284, Func Offset: 0x3b4
	// Line 2509, Address: 0x1be288, Func Offset: 0x3b8
	// Line 2510, Address: 0x1be290, Func Offset: 0x3c0
	// Line 2511, Address: 0x1be2a8, Func Offset: 0x3d8
	// Line 2512, Address: 0x1be2c0, Func Offset: 0x3f0
	// Line 2511, Address: 0x1be2c8, Func Offset: 0x3f8
	// Line 2512, Address: 0x1be2cc, Func Offset: 0x3fc
	// Line 2524, Address: 0x1be2d8, Func Offset: 0x408
	// Line 2528, Address: 0x1be2e0, Func Offset: 0x410
	// Line 2524, Address: 0x1be2e8, Func Offset: 0x418
	// Line 2526, Address: 0x1be2ec, Func Offset: 0x41c
	// Line 2524, Address: 0x1be2f0, Func Offset: 0x420
	// Line 2530, Address: 0x1be2f4, Func Offset: 0x424
	// Line 2524, Address: 0x1be2fc, Func Offset: 0x42c
	// Line 2525, Address: 0x1be304, Func Offset: 0x434
	// Line 2526, Address: 0x1be31c, Func Offset: 0x44c
	// Line 2528, Address: 0x1be334, Func Offset: 0x464
	// Line 2526, Address: 0x1be338, Func Offset: 0x468
	// Line 2527, Address: 0x1be33c, Func Offset: 0x46c
	// Line 2528, Address: 0x1be344, Func Offset: 0x474
	// Line 2529, Address: 0x1be350, Func Offset: 0x480
	// Line 2530, Address: 0x1be354, Func Offset: 0x484
	// Line 2540, Address: 0x1be35c, Func Offset: 0x48c
	// Line 2541, Address: 0x1be364, Func Offset: 0x494
	// Line 2542, Address: 0x1be36c, Func Offset: 0x49c
	// Line 2541, Address: 0x1be374, Func Offset: 0x4a4
	// Line 2543, Address: 0x1be378, Func Offset: 0x4a8
	// Line 2541, Address: 0x1be37c, Func Offset: 0x4ac
	// Line 2542, Address: 0x1be388, Func Offset: 0x4b8
	// Line 2543, Address: 0x1be3a4, Func Offset: 0x4d4
	// Line 2545, Address: 0x1be3c0, Func Offset: 0x4f0
	// Line 2546, Address: 0x1be3d8, Func Offset: 0x508
	// Line 2545, Address: 0x1be3dc, Func Offset: 0x50c
	// Line 2546, Address: 0x1be3e4, Func Offset: 0x514
	// Line 2547, Address: 0x1be3fc, Func Offset: 0x52c
	// Line 2548, Address: 0x1be414, Func Offset: 0x544
	// Line 2547, Address: 0x1be41c, Func Offset: 0x54c
	// Line 2548, Address: 0x1be420, Func Offset: 0x550
	// Line 2560, Address: 0x1be428, Func Offset: 0x558
	// Line 2561, Address: 0x1be438, Func Offset: 0x568
	// Line 2562, Address: 0x1be450, Func Offset: 0x580
	// Line 2561, Address: 0x1be454, Func Offset: 0x584
	// Line 2562, Address: 0x1be458, Func Offset: 0x588
	// Line 2564, Address: 0x1be460, Func Offset: 0x590
	// Line 2565, Address: 0x1be470, Func Offset: 0x5a0
	// Line 2566, Address: 0x1be480, Func Offset: 0x5b0
	// Line 2567, Address: 0x1be494, Func Offset: 0x5c4
	// Line 2568, Address: 0x1be49c, Func Offset: 0x5cc
	// Line 2570, Address: 0x1be4bc, Func Offset: 0x5ec
	// Line 2571, Address: 0x1be4c8, Func Offset: 0x5f8
	// Line 2570, Address: 0x1be4cc, Func Offset: 0x5fc
	// Line 2573, Address: 0x1be4d8, Func Offset: 0x608
	// Line 2574, Address: 0x1be4e8, Func Offset: 0x618
	// Line 2575, Address: 0x1be4f8, Func Offset: 0x628
	// Line 2576, Address: 0x1be514, Func Offset: 0x644
	// Line 2577, Address: 0x1be51c, Func Offset: 0x64c
	// Line 2579, Address: 0x1be534, Func Offset: 0x664
	// Line 2580, Address: 0x1be540, Func Offset: 0x670
	// Line 2579, Address: 0x1be544, Func Offset: 0x674
	// Line 2584, Address: 0x1be550, Func Offset: 0x680
	// Line 2585, Address: 0x1be568, Func Offset: 0x698
	// Line 2584, Address: 0x1be56c, Func Offset: 0x69c
	// Line 2585, Address: 0x1be574, Func Offset: 0x6a4
	// Line 2586, Address: 0x1be598, Func Offset: 0x6c8
	// Line 2587, Address: 0x1be5b0, Func Offset: 0x6e0
	// Line 2586, Address: 0x1be5bc, Func Offset: 0x6ec
	// Line 2587, Address: 0x1be5c0, Func Offset: 0x6f0
	// Line 2588, Address: 0x1be5dc, Func Offset: 0x70c
	// Line 2589, Address: 0x1be5f4, Func Offset: 0x724
	// Line 2588, Address: 0x1be5f8, Func Offset: 0x728
	// Line 2596, Address: 0x1be600, Func Offset: 0x730
	// Line 2597, Address: 0x1be604, Func Offset: 0x734
	// Func End, Address: 0x1be638, Func Offset: 0x768
}
*/

#pragma divbyzerocheck on

// 100% matching!
void bhEne06_PlayerControl(BH_PWORK* epw)
{
    // Not present in DWARF
    float dx, dz;

    switch (plp->mode2)
    {
    case 0:
        break;
    default:
        return;
    }

    switch (plp->mode3)
    {        
    case 0:
        plp->flg &= ~0x40000;
        plp->flg |= 0x10004;
        plp->mnwP = epw->mnwP;
        plp->mtn_no = 20;
        plp->frm_no = 0;
        plp->hokan_count = 5;
        plp->hokan_rate = 52428;
        plp->mtn_add = 65536;
        plp->ct1 = 8;
        plp->mode3++;
        break;
        
    case 1:

        if (plp->ct1 > 0)
        {
            plp->ay += (short)(plp->ayp - plp->ay) / plp->ct1;
            plp->ct1--;
        }
        if (plp->frm_no == 0)
        {
            plp->mnwP = plp->mnwPb;
            
            plp->flg &= ~0x10004;
            plp->flg |= 8;
            plp->at_flg = 0;
            plp->stflg &= ~0x10000;
            
            *(int*)&plp->mode0 = 1;
            *(int*)epw->exp1 &= ~1;
        }
        
        dx = plp->mlwP->owP[5].mtx[12] - plp->px;
        dz = plp->mlwP->owP[5].mtx[14] - plp->pz;
        
        plp->px += dx;
        plp->pz += dz;
        
        bhCheckWall(plp);
        
        plp->px -= dx;
        plp->pz -= dz;
    }
}

#pragma divbyzerocheck off

/*
// 
// Start address: 0x1be8b0
void bhEne06_SetRinpunEffect(BH_PWORK* epw, int num, int flg)
{
	float size;
	int eno;
	// Line 2671, Address: 0x1be8b0, Func Offset: 0
	// Line 2680, Address: 0x1be8c0, Func Offset: 0x10
	// Line 2681, Address: 0x1be8c8, Func Offset: 0x18
	// Line 2682, Address: 0x1be8d4, Func Offset: 0x24
	// Line 2681, Address: 0x1be8d8, Func Offset: 0x28
	// Line 2682, Address: 0x1be8e4, Func Offset: 0x34
	// Line 2683, Address: 0x1be8f8, Func Offset: 0x48
	// Line 2685, Address: 0x1be908, Func Offset: 0x58
	// Line 2686, Address: 0x1be930, Func Offset: 0x80
	// Line 2685, Address: 0x1be934, Func Offset: 0x84
	// Line 2686, Address: 0x1be944, Func Offset: 0x94
	// Line 2688, Address: 0x1be948, Func Offset: 0x98
	// Line 2686, Address: 0x1be94c, Func Offset: 0x9c
	// Line 2685, Address: 0x1be954, Func Offset: 0xa4
	// Line 2686, Address: 0x1be964, Func Offset: 0xb4
	// Line 2687, Address: 0x1be968, Func Offset: 0xb8
	// Line 2688, Address: 0x1be97c, Func Offset: 0xcc
	// Line 2690, Address: 0x1be98c, Func Offset: 0xdc
	// Line 2692, Address: 0x1be9ec, Func Offset: 0x13c
	// Line 2693, Address: 0x1bea04, Func Offset: 0x154
	// Line 2692, Address: 0x1bea0c, Func Offset: 0x15c
	// Line 2693, Address: 0x1bea20, Func Offset: 0x170
	// Line 2694, Address: 0x1bea54, Func Offset: 0x1a4
	// Line 2695, Address: 0x1bea88, Func Offset: 0x1d8
	// Line 2697, Address: 0x1beab0, Func Offset: 0x200
	// Line 2695, Address: 0x1beab4, Func Offset: 0x204
	// Line 2697, Address: 0x1beacc, Func Offset: 0x21c
	// Line 2695, Address: 0x1bead4, Func Offset: 0x224
	// Line 2697, Address: 0x1beaec, Func Offset: 0x23c
	// Line 2698, Address: 0x1beb04, Func Offset: 0x254
	// Line 2699, Address: 0x1beb10, Func Offset: 0x260
	// Line 2700, Address: 0x1beb34, Func Offset: 0x284
	// Line 2699, Address: 0x1beb40, Func Offset: 0x290
	// Line 2700, Address: 0x1beb48, Func Offset: 0x298
	// Line 2701, Address: 0x1beb4c, Func Offset: 0x29c
	// Line 2700, Address: 0x1beb5c, Func Offset: 0x2ac
	// Line 2703, Address: 0x1beb60, Func Offset: 0x2b0
	// Line 2704, Address: 0x1beb68, Func Offset: 0x2b8
	// Line 2705, Address: 0x1beb74, Func Offset: 0x2c4
	// Func End, Address: 0x1beb88, Func Offset: 0x2d8
}

// 
// Start address: 0x1beb90
void bhEne06_HitMark(BH_PWORK* epw)
{
	_anon35 ofp;
	_anon36* blp;
	int range;
	int i;
	// Line 2715, Address: 0x1beb90, Func Offset: 0
	// Line 2721, Address: 0x1bebb0, Func Offset: 0x20
	// Line 2722, Address: 0x1bebb4, Func Offset: 0x24
	// Line 2721, Address: 0x1bebbc, Func Offset: 0x2c
	// Line 2716, Address: 0x1bebc4, Func Offset: 0x34
	// Line 2721, Address: 0x1bebc8, Func Offset: 0x38
	// Line 2722, Address: 0x1bebd8, Func Offset: 0x48
	// Line 2723, Address: 0x1bebdc, Func Offset: 0x4c
	// Line 2724, Address: 0x1bebec, Func Offset: 0x5c
	// Line 2725, Address: 0x1bebfc, Func Offset: 0x6c
	// Line 2726, Address: 0x1bec24, Func Offset: 0x94
	// Line 2727, Address: 0x1bec28, Func Offset: 0x98
	// Line 2728, Address: 0x1bec2c, Func Offset: 0x9c
	// Line 2726, Address: 0x1bec30, Func Offset: 0xa0
	// Line 2727, Address: 0x1bec34, Func Offset: 0xa4
	// Line 2728, Address: 0x1bec3c, Func Offset: 0xac
	// Line 2729, Address: 0x1bec44, Func Offset: 0xb4
	// Line 2730, Address: 0x1bec84, Func Offset: 0xf4
	// Line 2731, Address: 0x1becc4, Func Offset: 0x134
	// Line 2732, Address: 0x1bece0, Func Offset: 0x150
	// Line 2731, Address: 0x1becec, Func Offset: 0x15c
	// Line 2732, Address: 0x1becfc, Func Offset: 0x16c
	// Line 2731, Address: 0x1bed00, Func Offset: 0x170
	// Line 2732, Address: 0x1bed14, Func Offset: 0x184
	// Line 2734, Address: 0x1bed38, Func Offset: 0x1a8
	// Line 2735, Address: 0x1bed60, Func Offset: 0x1d0
	// Line 2739, Address: 0x1bed74, Func Offset: 0x1e4
	// Line 2740, Address: 0x1beda8, Func Offset: 0x218
	// Line 2741, Address: 0x1bedac, Func Offset: 0x21c
	// Line 2742, Address: 0x1bedb0, Func Offset: 0x220
	// Line 2743, Address: 0x1bedb4, Func Offset: 0x224
	// Line 2741, Address: 0x1bedb8, Func Offset: 0x228
	// Line 2742, Address: 0x1bedbc, Func Offset: 0x22c
	// Line 2743, Address: 0x1bedc4, Func Offset: 0x234
	// Line 2744, Address: 0x1bedcc, Func Offset: 0x23c
	// Line 2745, Address: 0x1bee0c, Func Offset: 0x27c
	// Line 2746, Address: 0x1bee4c, Func Offset: 0x2bc
	// Line 2747, Address: 0x1bee88, Func Offset: 0x2f8
	// Line 2748, Address: 0x1bef10, Func Offset: 0x380
	// Line 2751, Address: 0x1bef20, Func Offset: 0x390
	// Line 2752, Address: 0x1bef48, Func Offset: 0x3b8
	// Line 2753, Address: 0x1bef4c, Func Offset: 0x3bc
	// Line 2754, Address: 0x1bef50, Func Offset: 0x3c0
	// Line 2752, Address: 0x1bef54, Func Offset: 0x3c4
	// Line 2753, Address: 0x1bef58, Func Offset: 0x3c8
	// Line 2754, Address: 0x1bef60, Func Offset: 0x3d0
	// Line 2755, Address: 0x1bef68, Func Offset: 0x3d8
	// Line 2756, Address: 0x1befa8, Func Offset: 0x418
	// Line 2757, Address: 0x1befe8, Func Offset: 0x458
	// Line 2758, Address: 0x1bf004, Func Offset: 0x474
	// Line 2757, Address: 0x1bf008, Func Offset: 0x478
	// Line 2758, Address: 0x1bf02c, Func Offset: 0x49c
	// Line 2762, Address: 0x1bf038, Func Offset: 0x4a8
	// Line 2763, Address: 0x1bf060, Func Offset: 0x4d0
	// Line 2764, Address: 0x1bf078, Func Offset: 0x4e8
	// Line 2766, Address: 0x1bf084, Func Offset: 0x4f4
	// Func End, Address: 0x1bf0a8, Func Offset: 0x518
}
*/


// 
// Start address: 0x1bf0b0
int bhEne06_DeadCheck(BH_PWORK* epw)
{
	int joint[2];
	int i;
	//_anon4* owk;
	float mov;
	int w;
	int ang;
	//_anon35 vec;
	//_anon35 pos;
	// Line 2776, Address: 0x1bf0b0, Func Offset: 0
	// Line 2782, Address: 0x1bf0d4, Func Offset: 0x24
	// Line 2776, Address: 0x1bf0d8, Func Offset: 0x28
	// Line 2782, Address: 0x1bf0dc, Func Offset: 0x2c
	// Line 2776, Address: 0x1bf0e0, Func Offset: 0x30
	// Line 2782, Address: 0x1bf0e4, Func Offset: 0x34
	// Line 2784, Address: 0x1bf0f0, Func Offset: 0x40
	// Line 2782, Address: 0x1bf0fc, Func Offset: 0x4c
	// Line 2786, Address: 0x1bf100, Func Offset: 0x50
	// Line 2788, Address: 0x1bf10c, Func Offset: 0x5c
	// Line 2789, Address: 0x1bf110, Func Offset: 0x60
	// Line 2786, Address: 0x1bf114, Func Offset: 0x64
	// Line 2795, Address: 0x1bf118, Func Offset: 0x68
	// Line 2786, Address: 0x1bf11c, Func Offset: 0x6c
	// Line 2787, Address: 0x1bf130, Func Offset: 0x80
	// Line 2788, Address: 0x1bf138, Func Offset: 0x88
	// Line 2789, Address: 0x1bf140, Func Offset: 0x90
	// Line 2792, Address: 0x1bf148, Func Offset: 0x98
	// Line 2793, Address: 0x1bf160, Func Offset: 0xb0
	// Line 2794, Address: 0x1bf178, Func Offset: 0xc8
	// Line 2795, Address: 0x1bf18c, Func Offset: 0xdc
	// Line 2798, Address: 0x1bf194, Func Offset: 0xe4
	// Line 2801, Address: 0x1bf1a4, Func Offset: 0xf4
	// Line 2802, Address: 0x1bf1bc, Func Offset: 0x10c
	// Line 2805, Address: 0x1bf1c8, Func Offset: 0x118
	// Line 2812, Address: 0x1bf1cc, Func Offset: 0x11c
	// Line 2805, Address: 0x1bf1d0, Func Offset: 0x120
	// Line 2812, Address: 0x1bf1d4, Func Offset: 0x124
	// Line 2805, Address: 0x1bf1e0, Func Offset: 0x130
	// Line 2812, Address: 0x1bf1e4, Func Offset: 0x134
	// Line 2806, Address: 0x1bf1e8, Func Offset: 0x138
	// Line 2807, Address: 0x1bf1f8, Func Offset: 0x148
	// Line 2810, Address: 0x1bf208, Func Offset: 0x158
	// Line 2812, Address: 0x1bf210, Func Offset: 0x160
	// Line 2817, Address: 0x1bf228, Func Offset: 0x178
	// Line 2818, Address: 0x1bf250, Func Offset: 0x1a0
	// Line 2826, Address: 0x1bf258, Func Offset: 0x1a8
	// Line 2818, Address: 0x1bf260, Func Offset: 0x1b0
	// Line 2826, Address: 0x1bf268, Func Offset: 0x1b8
	// Line 2828, Address: 0x1bf270, Func Offset: 0x1c0
	// Line 2829, Address: 0x1bf274, Func Offset: 0x1c4
	// Func End, Address: 0x1bf2a4, Func Offset: 0x1f4
    scePrintf("bhEne06_DeadCheck - UNIMPLEMENTED!\n");
}
