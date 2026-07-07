#include "../../../ps2/veronica/prog/en24.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/en03.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchk.h"


/*typedef struct npobj;
typedef struct _anon0;
typedef struct _anon1;
typedef struct _anon2;
typedef struct BH_PWORK;
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

typedef void(*type_25)(BH_PWORK*);
typedef void(*type_67)(BH_PWORK*);
typedef void(*type_70)(void*);
typedef void(*type_94)(BH_PWORK*);

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
typedef _anon0* type_10[512];
typedef _anon1* type_11[1300];
typedef char type_12[32];
typedef _anon0* type_13[512];
typedef _anon1* type_14[200];
typedef short type_15[32];
typedef _anon12 type_16[1];
typedef _anon0* type_17[128];
typedef unsigned int type_18[1];
typedef _anon4 type_19[256];
typedef _anon1* type_20[8];
typedef int* type_21[16];
typedef _anon0* type_22[128];
typedef npobj* type_23[16];
typedef _anon0* type_24[128];
typedef int type_26[4];
typedef void(*type_27)(BH_PWORK*)[6];
typedef _anon1* type_28[16];
typedef unsigned int type_29[4];
typedef _anon7 type_30[16];
typedef _anon0* type_31[512];
typedef char type_32[256];
typedef float type_33[4];
typedef float type_34[4];
typedef float type_35[4];
typedef _anon3* type_36[128];
typedef unsigned char type_37[64];
typedef float type_38[16];
typedef char type_39[8];
typedef void* type_40[2];
typedef float type_41[19];
typedef _anon1* type_42[256];
typedef int type_43[4];
typedef unsigned char* type_44[256];
typedef unsigned int type_45[2];
typedef short type_46[256];
typedef _anon19 type_47[4];
typedef float type_48[3];
typedef short type_49[256];
typedef int type_50[3];
typedef int type_51[8];
typedef float type_52[3];
typedef _anon1* type_53[256];
typedef _anon6 type_54[256];
typedef _anon12 type_55[450];
typedef _anon21 type_56[16];
typedef short type_57[256];
typedef char type_58[3];
typedef int type_59[64];
typedef _anon7 type_60[450];
typedef _anon25 type_61[4];
typedef _anon2 type_62[4];
typedef int type_63[450];
typedef unsigned int type_64[8];
typedef unsigned char type_65[450];
typedef char type_66[16];
typedef void(*type_68)(BH_PWORK*)[1];
typedef char type_69[4];
typedef unsigned int type_71[32];
typedef unsigned int type_72[16];
typedef _anon13 type_73[3];
typedef _anon27 type_74[64];
typedef unsigned int type_75[16];
typedef _anon27 type_76[64];
typedef unsigned int type_77[32];
typedef _anon27 type_78[64];
typedef unsigned int type_79[16];
typedef unsigned int type_80[3];
typedef BH_PWORK* type_81[16];
typedef unsigned int type_82[8];
typedef unsigned int type_83[1];
typedef unsigned int type_84[384];
typedef unsigned int type_85[2];
typedef unsigned char type_86[2];
typedef unsigned int type_87[4];
typedef int* type_88[16];
typedef char type_89[32];
typedef npobj* type_90[16];
typedef char type_91[64];
typedef _anon1* type_92[16];
typedef char type_93[4];
typedef void(*type_95)(BH_PWORK*)[7];
typedef _anon7 type_96[16];
typedef short type_97[4];
typedef unsigned char type_98[4];
typedef _anon23 type_99[16];
typedef unsigned int type_100[32];
typedef _anon22 type_101[32];
typedef _anon0* type_102[512];
typedef _anon0* type_103[128];
typedef int type_104[2];
typedef _anon0* type_105[512];
typedef unsigned char type_106[64];
typedef _anon0* type_107[512];

struct npobj
{
	unsigned int evalflags;
	_anon20* model;
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
	_anon7 mdl[16];
	_anon7* mlwP;
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
	_anon3* mnwP;
	_anon3* mnwPb;
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
	_anon31 cspr;
	int pn;
	_anon25* pvp;
	_anon2* tvp;
	_anon25 pv[4];
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

struct _anon1
{
	_anon12* textures;
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
	_anon7 mdl[16];
	_anon7* mlwP;
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
	_anon3* mnwP;
	_anon3* mnwPb;
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
	_anon32 watr;
	_anon13* cpcl;
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

struct _anon3
{
	unsigned int flg;
	unsigned int obj_num;
	unsigned int frm_num;
	void* datP;
	_anon11* md2P;
	unsigned short* atrP;
};

struct _anon4
{
	float x;
	float y;
	float z;
	float u;
	float v;
	unsigned int bcol;
	unsigned int ocol;
};

struct _anon5
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

struct _anon6
{
	unsigned char* adr;
	unsigned int gidx;
	unsigned int attr;
	unsigned int w;
	unsigned int h;
};

struct _anon7
{
	unsigned int flg;
	unsigned int obj_num;
	void* datP;
	npobj* objP;
	_anon1* texP;
	_anon17* owP;
};

struct _anon8
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
	_anon29* info;
};

struct _anon9
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

struct _anon10
{
	void* texaddr;
	_anon5 texsurface;
};

struct _anon11
{
	void* p[2];
};

struct _anon12
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

struct _anon13
{
	short jnt_a;
	short jnt_b;
	int cap_r;
};

struct _anon14
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
	_anon18* light;
};

struct _anon15
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
	_anon22 ply_pos;
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
	_anon8* p1per;
	_anon8* p2per;
	_anon8* kbper;
	_anon8* msper;
	_anon8 ms_per;
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
	_anon3* emtp[128];
	_anon3* rmthp;
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
	_anon6 txbp[256];
	unsigned char* ef_psp;
	_anon12 ef_tex[450];
	_anon1 ef_tlist;
	_anon26 ef;
	short efid[256];
	_anon7 efm[450];
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
	_anon10 ren_info;
	_anon12 ren_tex[1];
	_anon1 ren_tlist;
	_anon4 rpb[256];
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
	_anon28 mr_pl;
	unsigned char* zan_memp;
	unsigned char* zanp;
	_anon14* lgtp;
	float lg_vx;
	float lg_vy;
	float lg_vz;
	float lg_r;
	float lg_g;
	float lg_b;
	int lg_pnt;
	_anon19 lg_ptb[4];
	int mes_idx;
	unsigned int* mes_dp;
	int mes_ct;
	int mes_tim;
	int mes_fls;
	int mes_sel;
	int mes_seln;
	_anon21 mes_sps[16];
	int rt_sp;
	unsigned char* rt_wp;
	unsigned char* rt_dp;
	unsigned char* rt_nw;
	unsigned char* rt_nx;
	float* rt_ln;
	BH_PWORK* plp;
	_anon27* pl_htp;
	int costume;
	_anon22 hd_pos;
	_anon22 apos;
	_anon27* ahtp;
	int mwal_n;
	int metc_n;
	int mflr_n;
	_anon27 mwalp[64];
	_anon27 metcp[64];
	_anon27 mflrp[64];
	int dla_n;
	_anon27* htp;
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
	_anon9 door;
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
	_anon22 ufo_pos;
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
	_anon23 gatc[16];
	int ght_ct;
	unsigned int ghtc[32];
	_anon22 ghtp[32];
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

struct _anon16
{
	float a;
	float r;
	float g;
	float b;
};

struct _anon17
{
	unsigned int flg;
	int dmy;
	unsigned int dummy[2];
	float mtx[16];
};

struct _anon18
{
	float mtrx[16];
	_anon22 pnt;
	_anon22 vctr;
	int stat;
	int reserve;
	_anon24 ltcal;
	_anon30 attr;
};

struct _anon19
{
	_anon22 ps;
	float nr;
	float fr;
	float cr;
	float cg;
	float cb;
};

struct _anon20
{
	int* vlist;
	short* plist;
	_anon22 center;
	float r;
};

struct _anon21
{
	float x;
	float y;
};

struct _anon22
{
	float x;
	float y;
	float z;
};

struct _anon23
{
	_anon22 c1;
	_anon22 c2;
	float r1;
	float r2;
};

struct _anon24
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
	_anon22 lpnt;
	_anon22 lvctr;
	_anon22 lmvctr;
	_anon16 atten;
	_anon16 amb;
	_anon16 dif;
	_anon16 spc;
	_anon16 mamb;
	_anon16 mdif;
	_anon16 mspc;
};

struct _anon25
{
	float x;
	float y;
	float z;
	unsigned int col;
};

struct _anon26
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

struct _anon27
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

struct _anon28
{
	float px;
	float py;
	float pz;
	float vx;
	float vy;
	float vz;
};

struct _anon29
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

struct _anon30
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
	_anon16 argb;
};

struct _anon31
{
	_anon22 c;
	float r;
};

struct _anon32
{
	_anon22 c1;
	_anon22 c2;
	float r;
};

float DeadRate[19];
_anon13 CapColTab[3];
void(*bhEne24_Mode0)(BH_PWORK*)[7];
void(*bhEne24_BrainType)(BH_PWORK*)[1];
void(*bhEne24_MoveMode2)(BH_PWORK*)[6];
BH_PWORK* plp;
_anon15* sys;*/

// 
// Start address: 0x207620
void bhEne24(BH_PWORK* epw)
{
	BH_PWORK* ep;
	// Line 204, Address: 0x207620, Func Offset: 0
	// Line 206, Address: 0x20762c, Func Offset: 0xc
	// Line 210, Address: 0x20763c, Func Offset: 0x1c
	// Line 213, Address: 0x20765c, Func Offset: 0x3c
	// Line 214, Address: 0x207664, Func Offset: 0x44
	// Line 215, Address: 0x207674, Func Offset: 0x54
	// Line 218, Address: 0x20767c, Func Offset: 0x5c
	// Line 221, Address: 0x207688, Func Offset: 0x68
	// Line 226, Address: 0x20768c, Func Offset: 0x6c
	// Line 227, Address: 0x207694, Func Offset: 0x74
	// Line 221, Address: 0x207698, Func Offset: 0x78
	// Line 222, Address: 0x20769c, Func Offset: 0x7c
	// Line 223, Address: 0x2076a4, Func Offset: 0x84
	// Line 224, Address: 0x2076ac, Func Offset: 0x8c
	// Line 225, Address: 0x2076b4, Func Offset: 0x94
	// Line 226, Address: 0x2076bc, Func Offset: 0x9c
	// Line 227, Address: 0x2076c8, Func Offset: 0xa8
	// Line 230, Address: 0x2076cc, Func Offset: 0xac
	// Line 233, Address: 0x2076ec, Func Offset: 0xcc
	// Line 234, Address: 0x207700, Func Offset: 0xe0
	// Line 235, Address: 0x207720, Func Offset: 0x100
	// Line 237, Address: 0x20772c, Func Offset: 0x10c
	// Func End, Address: 0x20773c, Func Offset: 0x11c
	scePrintf("bhEne24 - UNIMPLEMENTED!\n");
}

/*// 
// Start address: 0x207740
void bhEne24_Init(BH_PWORK* epw)
{
	// Line 247, Address: 0x207740, Func Offset: 0
	// Line 249, Address: 0x20774c, Func Offset: 0xc
	// Line 252, Address: 0x207750, Func Offset: 0x10
	// Line 250, Address: 0x207758, Func Offset: 0x18
	// Line 256, Address: 0x20775c, Func Offset: 0x1c
	// Line 249, Address: 0x207760, Func Offset: 0x20
	// Line 250, Address: 0x207768, Func Offset: 0x28
	// Line 260, Address: 0x20776c, Func Offset: 0x2c
	// Line 250, Address: 0x207770, Func Offset: 0x30
	// Line 251, Address: 0x207778, Func Offset: 0x38
	// Line 252, Address: 0x207784, Func Offset: 0x44
	// Line 253, Address: 0x207788, Func Offset: 0x48
	// Line 254, Address: 0x20778c, Func Offset: 0x4c
	// Line 255, Address: 0x207790, Func Offset: 0x50
	// Line 256, Address: 0x207794, Func Offset: 0x54
	// Line 257, Address: 0x207798, Func Offset: 0x58
	// Line 260, Address: 0x2077a4, Func Offset: 0x64
	// Line 263, Address: 0x2077a8, Func Offset: 0x68
	// Line 264, Address: 0x2077b4, Func Offset: 0x74
	// Line 266, Address: 0x2077c4, Func Offset: 0x84
	// Line 267, Address: 0x2077c8, Func Offset: 0x88
	// Line 279, Address: 0x2077d0, Func Offset: 0x90
	// Line 275, Address: 0x2077d4, Func Offset: 0x94
	// Line 266, Address: 0x2077d8, Func Offset: 0x98
	// Line 267, Address: 0x2077dc, Func Offset: 0x9c
	// Line 276, Address: 0x2077e0, Func Offset: 0xa0
	// Line 279, Address: 0x2077e4, Func Offset: 0xa4
	// Line 267, Address: 0x2077e8, Func Offset: 0xa8
	// Line 268, Address: 0x2077ec, Func Offset: 0xac
	// Line 269, Address: 0x2077f4, Func Offset: 0xb4
	// Line 270, Address: 0x2077fc, Func Offset: 0xbc
	// Line 271, Address: 0x207804, Func Offset: 0xc4
	// Line 274, Address: 0x20780c, Func Offset: 0xcc
	// Line 275, Address: 0x207810, Func Offset: 0xd0
	// Line 276, Address: 0x207814, Func Offset: 0xd4
	// Line 282, Address: 0x207820, Func Offset: 0xe0
	// Line 283, Address: 0x207868, Func Offset: 0x128
	// Func End, Address: 0x207878, Func Offset: 0x138
}

// 
// Start address: 0x207880
void bhEne24_Brain(BH_PWORK* epw)
{
	// Line 294, Address: 0x207880, Func Offset: 0
	// Func End, Address: 0x2078a0, Func Offset: 0x20
}
*/

// 100% matching!
void bhEne24_BR00(BH_PWORK* epw)
{
    EXP0_F(0) = njDistanceP2P((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px);
    
    if (bhSearchPlayer(epw, 10922) == -1)
    {
        EXP0_UC(0x20) = 0;
    } 
    else
    {
        EXP0_UC(0x20) = 1;
    }
    
    if ((plp->stflg & 0x80000000) || (plp->flg & 0x4) || (epw->flg & 0x4))
    {
        return;
    }

    if (EXP0_I(0x24))
    {
        EXP0_I(0x24)--;
        return;
    }

    if (EXP0_UC(0x20) == 0)
    {
        return;
    }

    if (EXP0_F(0) >= 5.0F)
    {
        return;
    }

    epw->mode1 = 0;
    epw->mode2 = 4;
    epw->mode3 = 0;

    EXP0_I(0x24) = (int)(30.0F * njRandom()) + 30;
}
/*
// 
// Start address: 0x2079f0
void bhEne24_Move(BH_PWORK* epw)
{
	_anon22 pos;
	// Line 343, Address: 0x2079f0, Func Offset: 0
	// Line 345, Address: 0x2079fc, Func Offset: 0xc
	// Line 346, Address: 0x207a0c, Func Offset: 0x1c
	// Line 349, Address: 0x207a14, Func Offset: 0x24
	// Line 350, Address: 0x207a2c, Func Offset: 0x3c
	// Line 351, Address: 0x207a3c, Func Offset: 0x4c
	// Line 352, Address: 0x207a4c, Func Offset: 0x5c
	// Line 357, Address: 0x207a58, Func Offset: 0x68
	// Line 358, Address: 0x207a68, Func Offset: 0x78
	// Line 359, Address: 0x207a74, Func Offset: 0x84
	// Line 361, Address: 0x207a80, Func Offset: 0x90
	// Line 362, Address: 0x207ad4, Func Offset: 0xe4
	// Line 363, Address: 0x207adc, Func Offset: 0xec
	// Line 365, Address: 0x207ae4, Func Offset: 0xf4
	// Line 370, Address: 0x207af0, Func Offset: 0x100
	// Line 373, Address: 0x207b00, Func Offset: 0x110
	// Line 377, Address: 0x207b14, Func Offset: 0x124
	// Line 376, Address: 0x207b18, Func Offset: 0x128
	// Line 377, Address: 0x207b1c, Func Offset: 0x12c
	// Line 378, Address: 0x207b20, Func Offset: 0x130
	// Line 379, Address: 0x207b24, Func Offset: 0x134
	// Line 380, Address: 0x207b28, Func Offset: 0x138
	// Line 382, Address: 0x207b2c, Func Offset: 0x13c
	// Line 379, Address: 0x207b34, Func Offset: 0x144
	// Line 380, Address: 0x207b38, Func Offset: 0x148
	// Line 382, Address: 0x207b3c, Func Offset: 0x14c
	// Line 380, Address: 0x207b48, Func Offset: 0x158
	// Line 381, Address: 0x207b50, Func Offset: 0x160
	// Line 382, Address: 0x207b54, Func Offset: 0x164
	// Line 385, Address: 0x207b5c, Func Offset: 0x16c
	// Line 386, Address: 0x207b68, Func Offset: 0x178
	// Line 391, Address: 0x207b6c, Func Offset: 0x17c
	// Line 385, Address: 0x207b70, Func Offset: 0x180
	// Line 386, Address: 0x207b7c, Func Offset: 0x18c
	// Line 396, Address: 0x207b84, Func Offset: 0x194
	// Line 386, Address: 0x207b90, Func Offset: 0x1a0
	// Line 387, Address: 0x207b9c, Func Offset: 0x1ac
	// Line 388, Address: 0x207bb0, Func Offset: 0x1c0
	// Line 389, Address: 0x207bc8, Func Offset: 0x1d8
	// Line 390, Address: 0x207be0, Func Offset: 0x1f0
	// Line 391, Address: 0x207bf8, Func Offset: 0x208
	// Line 392, Address: 0x207c0c, Func Offset: 0x21c
	// Line 393, Address: 0x207c20, Func Offset: 0x230
	// Line 394, Address: 0x207c34, Func Offset: 0x244
	// Line 395, Address: 0x207c48, Func Offset: 0x258
	// Line 396, Address: 0x207c60, Func Offset: 0x270
	// Line 398, Address: 0x207c78, Func Offset: 0x288
	// Line 399, Address: 0x207c7c, Func Offset: 0x28c
	// Line 398, Address: 0x207c80, Func Offset: 0x290
	// Line 399, Address: 0x207c88, Func Offset: 0x298
	// Line 400, Address: 0x207c8c, Func Offset: 0x29c
	// Line 403, Address: 0x207c90, Func Offset: 0x2a0
	// Line 407, Address: 0x207c98, Func Offset: 0x2a8
	// Line 408, Address: 0x207cb8, Func Offset: 0x2c8
	// Func End, Address: 0x207cc8, Func Offset: 0x2d8
}
*/

// 100% matching!
void bhEne24_MV00(void)
{

}

// 100% matching!
void bhEne24_MV01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x80000;
        epw->flg |= 0x20;
        epw->ct0 = (int)(20.0f * njRandom()) + 10;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = (njRandom() > 0.5f) ? 2 : 3;
            epw->mode3 = 0;
        }

    }
}

// 100% matching!
void bhEne24_MV02(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    { 
    case 0:
        epw->ct0 = (int)(30.0f * njRandom()) + 60;
        
        epw->ct1 = (njRandom() < 0.5f) ? -1 : 1;
        
        epw->ct2 = (int)(20.0f + (20.0f * njRandom()) - (20.0f * njRandom()));
        
        epw->spd = 0.3f;
        
        epw->flg |= 0x80000;
        
        epw->way = (njRandom() > 0.5f) ? 273 : -273;
        
        epw->flg |= 0x20;
        epw->mode3++;

    case 1:
        bhAddSpeed(epw, 0);
        
        if (EXP0_UC(0x20) == 1) 
        {
            epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 455);
        }
        
        pos.x = epw->px - (5.0f * njSin(epw->ay));
        pos.y = epw->py;
        pos.z = epw->pz - (5.0f * njCos(epw->ay));
        
        if (bhCheckWallType(&pos, 0, 1.0f, 1.0f))
        {
            epw->ay += epw->way;
        }

        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        
        if ((epw->py > bhGetGroundPosition((NJS_POINT3*)&epw->px)))
        {
            epw->mode1 = 0;
            epw->mode2 = 4;
            epw->mode3 = 0;
        }

    }
    epw->ct2--;
    if (epw->ct2 < 0)
    {
        bhEne_CallSE(epw, (NJS_POINT3*) &epw->px, 74496);
        epw->ct2 = (int)(40.0f + (40.0f * njRandom()));
    }
}

// 100% matching!
void bhEne24_MV03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->way = (njRandom() > 0.5f) ? 273 : -273;
        
        epw->ct0 = (int)(45.0f * njRandom()) + 15;
        
        epw->flg |= 0x80000;
        
        epw->mode3++;

    case 1:
        epw->ay += epw->way;
        
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne24_MV04(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->flg |= 0x100000;
        
        EXP0_F(0x14) = 0.6f * -njSin(epw->ay);
        EXP0_F(0x18) = 2.5f;
        EXP0_F(0x1C) = 0.6f * -njCos(epw->ay);
        
        epw->flg &= ~0x80000;
        epw->flg &= ~0x20;
        
        epw->mode3++;

    case 1:
        if (epw->flg & 0x100000)
        {
            epw->px += EXP0_F(0x14);
            epw->py += EXP0_F(0x18);
            epw->pz += EXP0_F(0x1C);
            EXP0_F(0x18) -= 0.33f;
            
            if (!(plp->flg & 4))
            {
                if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000) && (plp->hp >= 0) && (bhEne_AttackHitCheck(plp, (NJS_POINT3*)&epw->px, 2.0f)))
                {
                    plp->flg |= 0x10004;
                    plp->stflg |= 0x10000;
                    
                    plp->hp -= 1;
                    if (plp->hp < 0)
                    {
                        plp->hp = 0;
                    }
                    plp->mode0 = 2;
                    plp->mode1 = 0;
                    plp->mode2 = 0;
                    plp->mode3 = 0;
                    
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74498);
                    bhEne_SetBloodEffect4((NJS_POINT3*)&epw->px, (NJS_POINT3*)&EXP0_UC(0x14), 0, 9, 1);
                    EXP0_F(0x14) *= -1.0f;
                    EXP0_F(0x1C) *= -1.0f;
                    epw->ay += 32768;
                    break;
                }
            }
        } 
        else
        {
            epw->mode1 = 0;
            epw->mode2 = 2;
            epw->mode3 = 0;
            
            epw->flg |= 0x20;
        }
    }
}

// 100% matching!
void bhEne24_MV05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x100000;
        epw->flg &= ~0x80000;
        epw->flg &= ~0x20;
        epw->mode3++;

    case 1:
        if (epw->flg & 0x100000)
        {
            epw->px += epw->xn;
            epw->py += epw->yn;
            epw->pz += epw->zn;
            epw->yn -= 0.33f;
            break;
        }
        epw->flg |= 0x20;
        epw->mode1 = 0;
        epw->mode2 = 2;
        epw->mode3 = 0;
    }
}

// 100% matching!
void bhEne24_Nage(void)
{

}

// 100% matching!
void bhEne24_Damage(void)
{

}

// 100% matching!
void bhEne24_Die(void)
{

}

// 100% matching!
void bhEne24_Dummy(void)
{

}

// 100% matching!
void bhEne24_CollisionWalls(BH_PWORK* epw) {
    epw->py += epw->ar;
    bhEne03_Collision(epw);
    epw->py -= epw->ar;
}

/*
// 
// Start address: 0x2086c0
void bhEne24_CollisionLine(BH_PWORK* epw)
{
	_anon27* hp;
	_anon22 n;
	// Line 711, Address: 0x2086c0, Func Offset: 0
	// Line 715, Address: 0x2086d0, Func Offset: 0x10
	// Line 716, Address: 0x2086e4, Func Offset: 0x24
	// Line 717, Address: 0x2086f0, Func Offset: 0x30
	// Line 718, Address: 0x2086f8, Func Offset: 0x38
	// Line 719, Address: 0x208700, Func Offset: 0x40
	// Line 720, Address: 0x208708, Func Offset: 0x48
	// Line 721, Address: 0x20872c, Func Offset: 0x6c
	// Line 725, Address: 0x208740, Func Offset: 0x80
	// Func End, Address: 0x208750, Func Offset: 0x90
}

// 
// Start address: 0x208750
int bhEne24_DeadCheck(BH_PWORK* epw)
{
	int joint[2];
	int i;
	_anon17* owk;
	float mov;
	int w;
	int ang;
	_anon22 vec;
	_anon22 pos;
	// Line 735, Address: 0x208750, Func Offset: 0
	// Line 741, Address: 0x208774, Func Offset: 0x24
	// Line 735, Address: 0x208778, Func Offset: 0x28
	// Line 741, Address: 0x20877c, Func Offset: 0x2c
	// Line 735, Address: 0x208780, Func Offset: 0x30
	// Line 741, Address: 0x208784, Func Offset: 0x34
	// Line 743, Address: 0x208790, Func Offset: 0x40
	// Line 741, Address: 0x20879c, Func Offset: 0x4c
	// Line 745, Address: 0x2087a0, Func Offset: 0x50
	// Line 747, Address: 0x2087ac, Func Offset: 0x5c
	// Line 748, Address: 0x2087b0, Func Offset: 0x60
	// Line 745, Address: 0x2087b4, Func Offset: 0x64
	// Line 754, Address: 0x2087b8, Func Offset: 0x68
	// Line 745, Address: 0x2087bc, Func Offset: 0x6c
	// Line 746, Address: 0x2087d0, Func Offset: 0x80
	// Line 747, Address: 0x2087d8, Func Offset: 0x88
	// Line 748, Address: 0x2087e0, Func Offset: 0x90
	// Line 751, Address: 0x2087e8, Func Offset: 0x98
	// Line 752, Address: 0x208800, Func Offset: 0xb0
	// Line 753, Address: 0x208818, Func Offset: 0xc8
	// Line 754, Address: 0x20882c, Func Offset: 0xdc
	// Line 757, Address: 0x208834, Func Offset: 0xe4
	// Line 760, Address: 0x208844, Func Offset: 0xf4
	// Line 761, Address: 0x20885c, Func Offset: 0x10c
	// Line 764, Address: 0x208868, Func Offset: 0x118
	// Line 771, Address: 0x20886c, Func Offset: 0x11c
	// Line 764, Address: 0x208870, Func Offset: 0x120
	// Line 771, Address: 0x208874, Func Offset: 0x124
	// Line 764, Address: 0x208880, Func Offset: 0x130
	// Line 771, Address: 0x208884, Func Offset: 0x134
	// Line 765, Address: 0x208888, Func Offset: 0x138
	// Line 766, Address: 0x208898, Func Offset: 0x148
	// Line 769, Address: 0x2088a8, Func Offset: 0x158
	// Line 771, Address: 0x2088b0, Func Offset: 0x160
	// Line 776, Address: 0x2088c8, Func Offset: 0x178
	// Line 777, Address: 0x2088f0, Func Offset: 0x1a0
	// Line 785, Address: 0x2088f8, Func Offset: 0x1a8
	// Line 777, Address: 0x208900, Func Offset: 0x1b0
	// Line 785, Address: 0x208908, Func Offset: 0x1b8
	// Line 787, Address: 0x208910, Func Offset: 0x1c0
	// Line 788, Address: 0x208914, Func Offset: 0x1c4
	// Func End, Address: 0x208944, Func Offset: 0x1f4
}*/
