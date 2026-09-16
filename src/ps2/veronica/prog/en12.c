#include "../../../ps2/veronica/prog/en12.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/ps2_dummy.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/eneset.h"
#include "../../../ps2/veronica/prog/macros.h"
#include "../../../ps2/veronica/prog/effect.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/njplus.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"

// ENEMY: First Form Alexia 

/*_anon25 vm1_012[30];
_anon25 vm1_013[57];
_anon25 vm1_014[150];
unsigned char flip_tree[22];
char SdwTab[8];
char joint_tree[8][3];
_anon27 DmgReact[21];
_anon36 CombWepTbl[21];
_anon39 CombJointTbl[33];
_anon33 BloodTbl[22];
_anon16 CapColTab[25];
_anon24 pc_eff_tab[49];
_anon24 alex_eff_tab[17];
_anon26 ShapeTbl_Acid[6];
void(*bhEne12_Mode0)(BH_PWORK*)[6];
void(*bhEne12_BrainType)(BH_PWORK*)[2];
void(*bhEne12_MoveMode2)(BH_PWORK*)[8];
void(*bhEne12_NageMode2)(BH_PWORK*)[1];
void(*bhEne12_DamageMode2)(BH_PWORK*)[1];
void(*bhEne12_DieMode2)(BH_PWORK*)[1];*/

NJS_POINT3 vm1_013[57] = 
{
    { 0.000000f,  0.000000f,  0.000000f},
    {-0.002481f, -0.128437f, -0.504067f},
    {-0.006499f, -0.148468f, -0.510247f},
    {-0.009104f, -0.151393f, -0.515869f},
    {-0.010295f, -0.137214f, -0.520933f},
    {-0.010072f, -0.105930f, -0.525441f},
    {-0.008436f, -0.057540f, -0.529392f},
    {-0.005385f, -0.003426f, -0.532783f},
    {-0.000921f, -0.001771f, -0.535620f},
    { 0.007501f, -0.040022f, -0.537896f},
    { 0.086997f, -0.114544f, -0.539617f},
    { 0.155376f, -0.263456f, -0.540780f},
    { 0.165567f, -0.341299f, -0.541386f},
    { 0.117574f, -0.075522f, -0.541433f},
    { 0.018625f,  0.099774f, -0.540924f},
    {-0.047476f,  0.186966f, -0.539902f},
    {-0.086010f,  0.186051f, -0.538276f},
    {-0.108811f,  0.099336f, -0.534524f},
    {-0.115880f,  0.022939f, -0.528369f},
    {-0.107216f, -0.021505f, -0.519810f},
    {-0.082820f, -0.060955f, -0.508845f},
    {-0.056624f, -0.147566f, -0.495477f},
    {-0.039583f, -0.222074f, -0.479705f},
    {-0.023238f, -0.202680f, -0.461528f},
    {-0.007591f, -0.089386f, -0.440950f},
    { 0.006010f,  0.019816f, -0.417963f},
    { 0.015734f,  0.057234f, -0.392575f},
    { 0.022013f,  0.087011f, -0.364781f},
    { 0.024847f,  0.109149f, -0.334645f},
    { 0.024236f,  0.123651f, -0.304028f},
    { 0.020182f,  0.130511f, -0.275094f},
    { 0.012681f,  0.129733f, -0.247963f},
    { 0.005624f,  0.120672f, -0.222635f},
    { 0.005011f,  0.107456f, -0.199106f},
    { 0.004632f,  0.095420f, -0.177381f},
    { 0.004267f,  0.084666f, -0.157460f},
    { 0.003918f,  0.075190f, -0.139338f},
    { 0.003583f,  0.066995f, -0.123020f},
    { 0.003263f,  0.060081f, -0.108504f},
    { 0.002957f,  0.054445f, -0.095790f},
    { 0.002667f,  0.050091f, -0.084877f},
    { 0.002391f,  0.046372f, -0.075768f},
    { 0.002129f,  0.042516f, -0.068460f},
    { 0.001884f,  0.038779f, -0.062954f},
    { 0.001651f,  0.035161f, -0.059252f},
    { 0.001435f,  0.031663f, -0.057350f},
    { 0.001233f,  0.028283f, -0.056893f},
    { 0.001045f,  0.025024f, -0.054168f},
    { 0.000873f,  0.021883f, -0.050333f},
    { 0.000715f,  0.018862f, -0.046055f},
    { 0.000572f,  0.015960f, -0.041340f},
    { 0.000443f,  0.013177f, -0.036186f},
    { 0.000329f,  0.010514f, -0.030590f},
    { 0.000231f,  0.007969f, -0.024559f},
    { 0.000146f,  0.005545f, -0.018084f},
    { 0.000078f,  0.003240f, -0.011173f},
    { 0.000022f,  0.001053f, -0.003823f},
};

NJS_POINT3 vm1_014[150] = {
	{ 0.0f, 0.0f, 0.0f },
	{ 0.011157999746501446f, -0.011560999788343906f, -0.10652600228786469f },
	{ 0.01475400011986494f, -0.020925000309944153f, -0.10976199805736542f },
	{ 0.019457999616861343f, -0.035909999161958694f, -0.11394199728965759f },
	{ 0.025268999859690666f, -0.05651700124144554f, -0.11906799674034119f },
	{ 0.03218799829483032f, -0.08274500072002411f, -0.12513799965381622f },
	{ 0.04021500051021576f, -0.11459600180387497f, -0.1321530044078827f },
	{ 0.04934899881482124f, -0.15206900238990784f, -0.1401129961013794f },
	{ 0.05959099903702736f, -0.18354399502277374f, -0.14901800453662872f },
	{ 0.0709410011768341f, -0.20054300129413605f, -0.1588670015335083f },
	{ 0.0833979994058609f, -0.23796400427818298f, -0.1696610003709793f },
	{ 0.09696300327777863f, -0.29726698994636536f, -0.18140000104904175f },
	{ 0.11163599789142609f, -0.3771969974040985f, -0.19434699416160583f },
	{ 0.1274159997701645f, -0.4457879960536957f, -0.21263299882411957f },
	{ 0.14430400729179382f, -0.5053510069847107f, -0.229435995221138f },
	{ 0.1623000055551529f, -0.5651400089263916f, -0.24189400672912598f },
	{ 0.18140199780464172f, -0.6296929717063904f, -0.25001099705696106f },
	{ 0.20161400735378265f, -0.7007840275764465f, -0.25378599762916565f },
	{ 0.22293199598789215f, -0.723222017288208f, -0.25321799516677856f },
	{ 0.24535900354385376f, -0.6908190250396729f, -0.248308002948761f },
	{ 0.28777799010276794f, -0.6292309761047363f, -0.23905399441719055f },
	{ 0.3566789925098419f, -0.5697230100631714f, -0.2254589945077896f },
	{ 0.3884809911251068f, -0.5140870213508606f, -0.20752200484275818f },
	{ 0.3806599974632263f, -0.4623259902000427f, -0.1852409988641739f },
	{ 0.33321499824523926f, -0.41443899273872375f, -0.1592089980840683f },
	{ 0.24615000188350677f, -0.3704279959201813f, -0.14304399490356445f },
	{ 0.14635999500751495f, -0.3302929997444153f, -0.13216400146484375f },
	{ 0.09748999774456024f, -0.19216200709342957f, -0.12170899659395218f },
	{ 0.06004900112748146f, -0.01030999980866909f, -0.1116819977760315f },
	{ 0.03155500069260597f, 0.08628500252962112f, -0.10207899659872055f },
	{ 0.012006999924778938f, 0.09762100130319595f, -0.0929030030965805f },
	{ 0.0014049999881535769f, 0.03845600038766861f, -0.08415199816226959f },
	{ -0.0002500000118743628f, 0.015402999706566334f, -0.075825996696949f },
	{ 0.000914999982342124f, 0.005739999935030937f, -0.0679280012845993f },
	{ -0.0010400000028312206f, -0.0016410000389441848f, -0.060453999787569046f },
	{ -0.0029619999695569277f, -0.006744000129401684f, -0.0534060001373291f },
	{ -0.0048500001430511475f, -0.009564000181853771f, -0.04678399860858917f },
	{ -0.006703999824821949f, -0.010106000117957592f, -0.04058799892663956f },
	{ -0.008526000194251537f, -0.00836700014770031f, -0.034818001091480255f },
	{ -0.010313999839127064f, -0.004505999851971865f, -0.029472999274730682f },
	{ -0.012067999690771103f, -0.002492000116035342f, -0.02455499954521656f },
	{ -0.013787999749183655f, -0.0017640000442042947f, -0.020061999559402466f },
	{ -0.015475999563932419f, -0.0011060000397264957f, -0.0159939993172884f },
	{ -0.017128000035881996f, -0.0005150000215508044f, -0.01235399954020977f },
	{ -0.018749000504612923f, 1.9999999949504854e-06f, -0.00913699995726347f },
	{ -0.020336000248789787f, 0.0004529999860096723f, -0.00634900014847517f },
	{ -0.021888000890612602f, 0.0008350000134669244f, -0.003984000068157911f },
	{ -0.02340799942612648f, 0.0011449999874457717f, -0.002044999971985817f },
	{ -0.024893000721931458f, 0.0013879999751225114f, -0.0005339999916031957f },
	{ -0.026347000151872635f, 0.001560000004246831f, 0.0005530000198632479f },
	{ -0.027765000239014626f, 0.001661999966017902f, 0.0012130000395700336f },
	{ -0.02914999984204769f, 0.0016980000073090196f, 0.001449999981559813f },
	{ -0.030501000583171844f, 0.0016609999584034085f, 0.0012570000253617764f },
	{ -0.03182100132107735f, 0.0015559999737888575f, 0.0006409999914467335f },
	{ -0.03310399875044823f, 0.0013810000382363796f, -0.00040099999750964344f },
	{ -0.03435700014233589f, 0.0050849998369812965f, -0.0018690000288188457f },
	{ -0.035572998225688934f, 0.030957000330090523f, -0.0033179998863488436f },
	{ -0.036757998168468475f, 0.05699799954891205f, -0.003863000078126788f },
	{ -0.03790799900889397f, 0.0790959969162941f, -0.004317999817430973f },
	{ -0.03902599960565567f, 0.09725099802017212f, -0.004728000145405531f },
	{ -0.04010799899697304f, 0.1114640012383461f, -0.005090999882668257f },
	{ -0.041159000247716904f, 0.12173599749803543f, -0.005410999990999699f },
	{ -0.04217499867081642f, 0.12806299328804016f, -0.005683000199496746f },
	{ -0.04315900057554245f, 0.13044899702072144f, -0.005911999847739935f },
	{ -0.04410700127482414f, 0.1288910061120987f, -0.006093999836593866f },
	{ -0.04502300173044205f, 0.1233920007944107f, -0.006231999956071377f },
	{ -0.04590599983930588f, 0.11423499882221222f, -0.0063229999504983425f },
	{ -0.046755000948905945f, 0.1084820032119751f, -0.006370000075548887f },
	{ -0.047568999230861664f, 0.1050650030374527f, -0.006370999850332737f },
	{ -0.04835199937224388f, 0.10180100053548813f, -0.006326999980956316f },
	{ -0.04909899830818176f, 0.09868499636650085f, -0.006238000001758337f },
	{ -0.04981499910354614f, 0.09572300314903259f, -0.006101000122725964f },
	{ -0.050494998693466187f, 0.09290999919176102f, -0.005921999923884869f },
	{ -0.05114300176501274f, 0.09025000035762787f, -0.005696000065654516f },
	{ -0.051757000386714935f, 0.087738998234272f, -0.005423999857157469f },
	{ -0.052338000386953354f, 0.08538000285625458f, -0.005107999779284f },
	{ -0.05288499966263771f, 0.08317200094461441f, -0.004745999816805124f },
	{ -0.053397998213768005f, 0.08111400157213211f, -0.0043390002101659775f },
	{ -0.053877998143434525f, 0.07920899987220764f, -0.003886000020429492f },
	{ -0.05432400107383728f, 0.07745400071144104f, -0.003387999953702092f },
	{ -0.05473800003528595f, 0.07584899663925171f, -0.0028440000023692846f },
	{ -0.05511600151658058f, 0.07439800351858139f, -0.002254999941214919f },
	{ -0.055463001132011414f, 0.07309400290250778f, -0.0016210000030696392f },
	{ -0.05602100118994713f, 0.07194399833679199f, -0.0009410000056959689f },
	{ -0.05735599994659424f, 0.07094399631023407f, -0.00021699999342672527f },
	{ -0.05909600108861923f, 0.07009600102901459f, 0.0005549999768845737f },
	{ -0.061216000467538834f, 0.0693959966301918f, 0.0013699999544769526f },
	{ -0.06371700018644333f, 0.06885100156068802f, 0.002230999991297722f },
	{ -0.06659699976444244f, 0.06845500320196152f, 0.003137999912723899f },
	{ -0.06985899806022644f, 0.06820999830961227f, 0.004089999943971634f },
	{ -0.07350099831819534f, 0.06811700016260147f, 0.0050860000774264336f },
	{ -0.07752300053834915f, 0.06817299872636795f, 0.006130999885499477f },
	{ -0.08192499727010727f, 0.06978599727153778f, 0.007602000143378973f },
	{ -0.08670900017023087f, 0.07523900270462036f, 0.009371999651193619f },
	{ -0.09187199920415878f, 0.08149799704551697f, 0.00989300012588501f },
	{ -0.0974159985780716f, 0.08841200172901154f, 0.009108999744057655f },
	{ -0.10333999991416931f, 0.09597700089216232f, 0.007019000127911568f },
	{ -0.10964599996805191f, 0.10419999808073044f, 0.0036239998880773783f },
	{ -0.11633100360631943f, 0.11307699978351593f, -0.0010770000517368317f },
	{ -0.12339600175619125f, 0.12260600179433823f, -0.007081000134348869f },
	{ -0.13084200024604797f, 0.1327890008687973f, -0.014391999691724777f },
	{ -0.1386760026216507f, 0.1436299979686737f, -0.023006999865174294f },
	{ -0.1465570032596588f, 0.15512299537658691f, -0.03292899951338768f },
	{ -0.15244899690151215f, 0.1672700047492981f, -0.044155001640319824f },
	{ -0.15559899806976318f, 0.17822900414466858f, -0.056685999035835266f },
	{ -0.15601800382137299f, 0.18292100727558136f, -0.07052399963140488f },
	{ -0.1537020057439804f, 0.18336600065231323f, -0.0856660008430481f },
	{ -0.14865100383758545f, 0.17971600592136383f, -0.10211300104856491f },
	{ -0.14086399972438812f, 0.17197200655937195f, -0.11986400187015533f },
	{ -0.13034799695014954f, 0.1601399928331375f, -0.13892300426959991f },
	{ -0.11709500104188919f, 0.14421400427818298f, -0.1592860072851181f },
	{ -0.10110799968242645f, 0.12419400364160538f, -0.18095499277114868f },
	{ -0.08238700032234192f, 0.10008099675178528f, -0.2039259970188141f },
	{ -0.06093300133943558f, 0.07187800109386444f, -0.2282170057296753f },
	{ -0.03674300014972687f, 0.03958100080490112f, -0.2723950147628784f },
	{ -0.009820999577641487f, 0.003191000083461404f, -0.3335840106010437f },
	{ 0.019835999235510826f, -0.037289999425411224f, -0.39165401458740234f },
	{ 0.05222700163722038f, -0.08186499774456024f, -0.4466240108013153f },
	{ 0.08735200017690659f, -0.13053199648857117f, -0.49848300218582153f },
	{ 0.12521100044250488f, -0.19626599550247192f, -0.547236979007721f },
	{ 0.16558299958705902f, -0.29565200209617615f, -0.5928769707679749f },
	{ 0.19975300133228302f, -0.3964020013809204f, -0.6354209780693054f },
	{ 0.22043099999427795f, -0.4970189929008484f, -0.6748560070991516f },
	{ 0.22812999784946442f, -0.5975069999694824f, -0.7111809849739075f },
	{ 0.22284400463104248f, -0.6978579759597778f, -0.7443940043449402f },
	{ 0.204584002494812f, -0.7585409879684448f, -0.7745130062103271f },
	{ 0.17333799600601196f, -0.9162989854812622f, -0.8015199899673462f },
	{ 0.12911400198936462f, -1.1865160465240479f, -0.8254200220108032f },
	{ 0.07190699875354767f, -0.8814749717712402f, -0.8134859800338745f },
	{ 0.0017219999572262168f, -0.1626559942960739f, -0.6663529872894287f },
	{ -0.07813899964094162f, 0.1000870019197464f, -0.4377860128879547f },
	{ -0.13751299679279327f, 0.15776300430297852f, -0.31150099635124207f },
	{ -0.17175500094890594f, 0.19122600555419922f, -0.2329539954662323f },
	{ -0.18266700208187103f, 0.18833699822425842f, -0.1813330054283142f },
	{ -0.17024099826812744f, 0.1490889936685562f, -0.15664300322532654f },
	{ -0.13447999954223633f, 0.07348400354385376f, -0.13298399746418f },
	{ -0.07538499683141708f, -0.03709600120782852f, -0.09650500118732452f },
	{ -0.018043000251054764f, -0.14261400699615479f, -0.06608299911022186f },
	{ -0.010900000110268593f, -0.19845600426197052f, -0.041738998144865036f },
	{ -0.00686000008136034f, -0.20231300592422485f, -0.023461999371647835f },
	{ -0.003381999908015132f, -0.15418699383735657f, -0.011258999817073345f },
	{ -0.00046800001291558146f, -0.0583220012485981f, -0.005125000141561031f },
	{ 0.0018860000418499112f, -0.017625000327825546f, -0.004519000183790922f },
	{ 0.0036750000435858965f, -0.011122999712824821f, -0.004455000162124634f },
	{ 0.004904000088572502f, -0.005582999903708696f, -0.004112999886274338f },
	{ 0.0055680000223219395f, -0.001006999984383583f, -0.003785999957472086f },
	{ 0.005671000108122826f, 0.0026080000679939985f, -0.003467000089585781f },
	{ 0.005210000090301037f, 0.005257999990135431f, -0.003166999900713563f },
	{ 0.004188999999314547f, 0.006947999820113182f, -0.0028719999827444553f },
	{ 0.0026030000299215317f, 0.007672999985516071f, -0.0025939999613910913f },
};

static unsigned char flip_tree[22] = {0, 1, 2, 3, 4, 5, 10, 11, 12, 13, 6, 7, 8, 9, 18, 19, 20, 21, 14, 15, 16, 17};
static char SdwTab[8] = {1, 2, 5, 0xD, 9, 0x15, 0x11, 0xFF};

static char joint_tree[8][3] = 
{
    {0,     0xFF,      0},
    {0,     0,         0},
    {0,     0,         0},
    {1,     18,       19},
    {20,    21,     0xFF},
    {0,     0,         1},
    {14,    15,       16},
    {17,    0xFF,      0},
};

DMG_REACT DmgReact[21] = {
	{ { 0, 1, 0 }, { 0, 0, 0 }, 0 },
	{ { 0, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 0, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 1, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 1, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 0, 0, 0 }, { 1, 0, 0 }, 0 },
	{ { 1, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 0, 0, 0 }, { 1, 0, 0 }, 0 },
	{ { 0, 0, 0 }, { 0, 0, 0 }, 0 },
	{ { 0, 0, 0 }, { 0, 0, 0 }, 0 },
	{ { 0, 0, 0 }, { 1, 0, 0 }, 0 },
	{ { 2, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 0, 0, 0 }, { 0, 0, 0 }, 0 },
	{ { 1, 1, 0 }, { 1, 0, 0 }, 0 },
	{ { 2, 1, 0 }, { 1, 1, 1 }, 1 },
	{ { -1, -1, -1 }, { 1, 0, 0 }, 2 },
	{ { -1, -1, -1 }, { 1, 0, 0 }, 1 },
	{ { -1, -1, -1 }, { 1, 0, 0 }, 0 },
	{ { 2, 2, 2 }, { 1, 1, 1 }, 0 },
	{ { 2, 2, 2 }, { 1, 0, 0 }, 1 },
	{ { 2, 2, 2 }, { 1, 1, 1 }, 0 },
};

static COMBWEP_WORK CombWepTbl[21] = 
{
    {  0, {  0, 0, 0 },  0,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
    {  4, {  1, 0, 0 },  5, 20 },
    { 10, {  4, 3, 1 }, 20, 10 },
    { 10, {  4, 3, 1 }, 20, 10 },
    { 10, {  4, 3, 1 }, 10,  0 },
    {  0, {  0, 0, 0 }, 25,  0 },
    {  0, {  0, 0, 0 }, 25,  0 },
    { 25, {  5, 3, 1 },  5,  0 },
    {  0, {  0, 0, 0 }, 25,  0 },
    {  0, {  0, 0, 0 }, 10,  0 },
    {  0, {  0, 0, 0 }, 30,  0 },
    { 25, {  5, 4, 2 }, 10,  0 },
    {  0, {  0, 0, 0 }, 60,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
    { 15, {  1, 1, 1 },  0,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
    {  0, {  0, 0, 0 },  0,  0 },
};

static COMBJOINT_WORK CombJointTbl[33] = {};

static BLOOD_TBL BloodTbl[22] = {
	{ 1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f },
	{ 0, { 0.0f, 3.0f, -1.0f }, 2.0f, 3.0f, 0.0f },
	{ 0, { 0.0f, 3.0f, -1.5f }, 3.0f, 2.0f, 0.0f },
	{ 0, { 0.0f, 3.0f, -1.5f }, 3.0f, 2.0f, 0.0f },
	{ 1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f },
	{ 1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f },
	{ 0, { 0.0f, 1.0f, 0.0f }, 1.0f, 0.0f, 1.0f },
	{ 0, { 1.5f, 0.5f, 0.0f }, 1.5f, 0.0f, 1.0f },
	{ 0, { 1.5f, 0.5f, 0.0f }, 1.5f, 0.0f, 1.0f },
	{ 1, { 0.0f, 1.0f, 0.0f }, 1.0f, 0.0f, 1.0f },
	{ 0, { 0.0f, 1.0f, 0.0f }, 1.0f, 0.0f, 1.0f },
	{ 0, { -1.5f, 0.5f, 0.0f }, 1.5f, 0.0f, 1.0f },
	{ 0, { -1.5f, 0.5f, 0.0f }, 1.5f, 0.0f, 1.0f },
	{ 1, { 0.0f, 0.0f, 0.0f }, 0.0f, 0.0f, 0.0f },
	{ 0, { 0.0f, -2.0f, -1.0f }, 1.0f, 2.0f, 0.0f },
	{ 0, { 0.0f, -2.0f, -1.0f }, 1.0f, 2.0f, 0.0f },
	{ 1, { 0.0f, 1.0f, -1.0f }, 1.0f, 0.0f, 0.0f },
	{ 1, { 0.0f, 0.0f, -1.0f }, 1.0f, 0.0f, 0.0f },
	{ 0, { 0.0f, -2.0f, -1.0f }, 1.0f, 2.0f, 0.0f },
	{ 0, { 0.0f, -2.0f, -1.0f }, 1.0f, 2.0f, 0.0f },
	{ 1, { 0.0f, 1.0f, -1.0f }, 1.0f, 0.0f, 0.0f },
	{ 1, { 0.0f, 0.0f, -1.0f }, 1.0f, 0.0f, 0.0f },
};


static CPCL CapColTab[25] = 
{
    {  1,  2, 12 },
    {  2,  3,  8 },
    {  3,  4,  6 },
    {  3,  3, 12 },
    {  0, 12,  0 },
    {  4,  5,  5 },
    {  5,  5, 10 },
    {  0,  8,  0 },
    {  6,  7,  4 },
    {  7,  8,  3 },
    {  8,  9,  3 },
    {  9,  9,  6 },
    {  8,  0,  0 },
    { 10, 11,  4 },
    { 11, 12,  3 },
    { 12, 13,  3 },
    { 13, 13,  6 },
    { -8,  0,  0 },
    { 14, 15,  7 },
    { 15, 16,  4 },
    { 16, 17,  3 },
    { 18, 19,  7 },
    { 19, 20,  4 },
    { 20, 21,  3 },
    {  0,  0,  0 },
};

EN12_WORK pc_eff_tab[49] = {
    { 2, {-1.0f, 1.0f, 1.0f}, 1.3f, 50, 1 },
    { 3, { 1.0f, 2.0f, 1.0f}, 1.4f, 55, 2 },
    { 4, { 0.0f, 0.0f, 1.0f}, 1.5f, 52, 0 },
    { 5, { 0.0f, 0.0f, 1.0f}, 3.3f, 10, 0 },
    { 2, { 1.0f, 2.0f,-1.0f}, 1.3f, 20, 1 },
    { 3, {-1.0f, 1.0f,-1.0f}, 1.2f, 57, 2 },
    { 4, { 0.0f, 0.0f,-1.0f}, 1.5f, 26, 0 },
    { 5, { 0.0f, 0.0f,-1.0f}, 1.3f, 81, 1 },
    { 1, {-0.4f, 2.0f, 1.0f}, 1.5f, 36, 2 },
    { 2, { 0.5f, 2.0f, 1.0f}, 1.3f, 46, 3 },
    { 3, { 0.8f, 1.0f, 1.0f}, 1.6f, 32, 3 },
    { 4, {-0.1f, 0.0f, 1.0f}, 1.8f, 37, 2 },
    { 5, { 0.3f, 0.0f, 1.0f}, 1.7f, 34, 2 },
    { 6, {-0.4f, 1.0f, 1.0f}, 1.3f, 38, 3 },
    { 10,{ 0.3f, 1.0f, 1.0f}, 1.6f, 41, 3 },
    { 1, {-0.3f, 3.0f,-2.0f}, 1.7f, 54, 2 },
    { 2, { 0.5f, 2.0f,-2.0f}, 1.4f, 24, 2 },
    { 3, { 0.2f, 1.0f,-2.0f}, 1.6f, 52, 2 },
    { 4, {-0.3f, 0.0f,-1.0f}, 1.5f, 74, 3 },
    { 5, {-0.1f, 0.0f,-1.0f}, 1.3f, 47, 2 },
    { 6, {-0.3f, 1.0f,-2.0f}, 1.2f, 44, 3 },
    { 10,{ 0.6f,0.0f,-2.0f}, 1.1f, 22, 2 },
    { 1, {-0.3f, 1.0f, 1.0f}, 2.0f, 31, 3 },
    { 2, { 0.5f, 2.0f, 1.0f}, 2.0f, 36, 4 },
    { 3, { 0.2f, 1.0f, 1.0f}, 2.80f,38, 4 },
    { 4, {-0.3f, 0.0f, 1.0f}, 2.1f, 34, 3 },
    { 5, {-0.1f, 0.0f, 1.0f}, 1.8f, 36, 4 },
    { 6, {-0.3f, 2.0f, 1.0f}, 2.80f,39, 3 },
    { 7, { 0.6f,0.0f, 1.0f}, 1.8f, 35, 5 },
    { 10,{-0.3f, 1.0f, 1.0f}, 1.7f, 32, 3 },
    { 11,{ 0.5f, 0.0f, 1.0f}, 1.9f, 34, 5 },
    { 14,{ 0.2f,-2.0f, 1.0f}, 1.5f, 35, 5 },
    { 15,{-0.3f,-1.0f, 1.0f}, 1.3f, 32, 6 },
    { 18,{-0.1f,-2.0f, 1.0f}, 1.5f, 31, 5 },
    { 19,{-0.3f,-1.0f, 1.0f}, 1.2f, 37, 5 },
    { 1, { 0.5f, 0.0f,-1.0f}, 2.5f, 33, 3 },
    { 2, { 0.8f, 0.0f,-1.0f}, 2.7f, 32, 4 },
    { 3, {-0.1f, 0.0f,-1.0f}, 2.6f, 31, 3 },
    { 4, { 0.3f, 0.0f,-1.0f}, 2.80f,36, 4 },
    { 5, { 0.6f,0.0f,-1.0f}, 2.7f, 37, 3 },
    { 6, {-0.3f, 0.0f,-1.0f}, 2.5f, 33, 3 },
    { 7, { 0.5f, 0.0f,-1.0f}, 2.3f, 34, 6 },
    { 10,{ 0.2f, 0.0f,-1.0f}, 2.2f, 31, 3 },
    { 11,{-0.3f, 0.0f,-1.0f}, 2.3f, 30, 5 },
    { 14,{ 0.8f,-1.0f,-1.0f}, 1.7f, 35, 5 },
    { 15,{-0.1f,-1.0f,-1.0f}, 1.4f, 37, 6 },
    { 18,{ 0.3f,-2.0f,-1.0f}, 1.6f, 31, 6 },
    { 19,{ 0.6f,-1.0f,-1.0f},1.3f, 33, 5 },
    { 0, { 0.0f, 0.0f, 0.0f}, 0.0f, 0,  0 },
};

EN12_WORK alex_eff_tab[17] = {
	{ 8, { 0.3f, 0.2f, 0.2f }, 0.1f, 300, 5 },
	{ 8, { 0.5f, 0.2f, 0.1f }, 0.1f, 300, 5 },
	{ 8, { 0.6f, 0.2f, -0.3f }, 0.2f, 300, 5 },
	{ 8, { 0.8f, 0.1f, -0.2f }, 0.3f, 300, 5 },
	{ 8, { 1.0f, 0.2f, 0.1f }, 0.2f, 300, 4 },
	{ 8, { 1.3f, 0.3f, 0.2f }, 0.3f, 300, 4 },
	{ 8, { 1.6f, -0.1f, -0.4f }, 0.4f, 300, 4 },
	{ 8, { 1.7f, 0.2f, 0.1f }, 0.3f, 300, 3 },
	{ 8, { 1.9f, -0.2f, 0.5f }, 0.4f, 300, 3 },
	{ 9, { 1.2f, 0.1f, 0.1f }, 0.5f, 300, 2 },
	{ 9, { 1.0f, 0.2f, 0.0f }, 0.4f, 300, 2 },
	{ 9, { 0.8f, 0.1f, -0.3f }, 0.5f, 300, 2 },
	{ 9, { 0.7f, 0.0f, 0.2f }, 0.4f, 300, 2 },
	{ 9, { 0.5f, 0.1f, 0.0f }, 0.3f, 300, 1 },
	{ 9, { 0.3f, 0.0f, 0.3f }, 0.4f, 300, 1 },
	{ 9, { 0.1f, 0.2f, 0.1f }, 0.5f, 300, 1 },
	{ 0, { 0.0f, 0.0f, 0.0f }, 0.0f, 0, 0 },
};


static P_WORK ShapeTbl_Acid[6] = 
{
    {    0,    0.0f },
    {   26,    0.0f },
    {   30, 1000.0f },
    {   40, 1000.0f },
    {   50,    0.0f },
    {  999,    0.0f },
};

void(*bhEne12_Mode0[6])(BH_PWORK*) = 
{
    bhEne12_Init,
    bhEne12_Move,
    bhEne12_Nage,
    bhEne12_Damage,
    bhEne12_Die,
    bhEne_Event,
};

void(*bhEne12_BrainType[2])(BH_PWORK*) = 
{
    bhEne12_BR00,
    bhEne12_MV00,
};

void(*bhEne12_MoveMode2[8])(BH_PWORK*) = 
{
    bhEne12_MV00,
    bhEne12_MV01,
    bhEne12_MV02,
    bhEne12_MV03,
    bhEne12_MV04,
    bhEne12_MV05,
    bhEne12_MV06,
    bhEne12_MV07,
};

void(*bhEne12_NageMode2[1])(BH_PWORK*) = 
{
    bhEne12_NG00,
};

void(*bhEne12_DamageMode2[1])(BH_PWORK*) = 
{
    bhEne12_DG00,
};

void(*bhEne12_DieMode2[1])(BH_PWORK*) =
{
    bhEne12_DD00,
};

// 100% matching!
void bhEne12(BH_PWORK* epw) 
{

    if (epw->mode0 != 5) {
        epw->flg &= ~0x100;
        epw->mtn_md |= 0x10;
        epw->mtn_md &= ~0x20;
    }
    if (epw->type == 1) {
        if (epw->flg & 4) {
            epw->flg &= ~4;
            bhEne12_HitMark(epw);
            epw->mode0 = 1;
            epw->mode1 = 0;
            epw->mode2 = 7;
            epw->mode3 = 0;
            epw->type = 0;
        }
    }
    
    bhEne12_Mode0[epw->mode0](epw);
    bhEne12_CallSE(epw);
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    bhEne12_FixedLegPos(epw);
    bhEne_SetWeponAtr(epw, 5, 0x15, 4.0f);
    bhCheckPlayer(epw);
    
    if (epw->flg & 0x10) {
        bhEne12_CheckWall(epw);
    }
    
    bhEne12_LookPlayaer(epw);
    bhEne12_SetFireBintaEffect(epw, 3);
    bhCalcModel(epw);
    bhEne12_PlayerControl(epw);
}

// 100% matching!
void bhEne12_Init(BH_PWORK* epw)
{
    int eno;

    epw->flg |= 0x78;
    epw->flg &= ~6;

    epw->ar  = 3.5f;   
    epw->ah  = 1.0f;   
    epw->car = 3.0f;   

    epw->hp = 0x12C;

    epw->mode0 = 1;
    epw->mode1 = 1;
    epw->mode2 = 1;
    epw->mode3 = 0;

    epw->mtn_no      = 0;
    epw->mtn_md      = 0x20;
    epw->hokan_rate  = 0;
    epw->hokan_count = 0;
    epw->mtn_add     = 0x10000;
    epw->mtn_tp      = flip_tree;
    epw->frm_no      = 0;

    epw->clp_jno[0] = 5;
    epw->clp_jno[1] = 1;
    epw->clp_jno[2] = 7;
    epw->clp_jno[3] = 0xB;
    epw->clp_jno[4] = 0xD;
    epw->clp_jno[5] = 0xD;
    epw->clp_jno[6] = 0x11;
    epw->clp_jno[7] = 0x15;

    epw->mdflg &= ~0x20;

    if (epw->exp0 == NULL) {
        epw->exp0 = bhEne_CallocWork(0xB0, 8);
        sys->ef.id = 0x106;
        sys->ef.flg = 1;

        eno = bhSetEffectTb(&sys->ef, 0, 0, 0);
        EXP0_I(0x20) = (int)&eff[eno];

    }

    EXP0_I(0x4)  = 0x1E;
    EXP0_I(0x8)  = 0x78;
    EXP0_I(0xC)  = 0;
    EXP0_I(0x10) = 0;
    EXP0_I(0x14) = 0x3C;

    if (!(epw->flg & 0x800)) {
        bhSetShadow(SdwTab, (unsigned char*)epw, 2, 6.0f, 6.0f, 4.0f);
        epw->flg |= 0x800;
    }

    epw->stflg &= ~8;
    epw->lok_jno = 5;
    epw->cpcl    = CapColTab;

    epw->flg &= 0xFFEFFFFF;

    EXP0_I(0x1C) = 0x10;

    sys->rm_flg &= ~1;
}

void bhEne12_Brain(BH_PWORK* epw)
{
    bhEne12_BrainType[epw->type](epw);
}


/*// 
// Start address: 0x1d5a50
void bhEne12_BR00(BH_PWORK* epw)
{
	_anon25 pos;
	int act_no;
	int i;
	int inter[4];
	int act[16][2];
	int mode[4];
	float dist;
	// Line 667, Address: 0x1d5a50, Func Offset: 0
	// Line 669, Address: 0x1d5a5c, Func Offset: 0xc
	// Line 667, Address: 0x1d5a64, Func Offset: 0x14
	// Line 669, Address: 0x1d5a68, Func Offset: 0x18
	// Line 675, Address: 0x1d5a74, Func Offset: 0x24
	// Line 669, Address: 0x1d5a7c, Func Offset: 0x2c
	// Line 675, Address: 0x1d5a80, Func Offset: 0x30
	// Line 680, Address: 0x1d5aa8, Func Offset: 0x58
	// Line 684, Address: 0x1d5ab8, Func Offset: 0x68
	// Line 680, Address: 0x1d5ac0, Func Offset: 0x70
	// Line 684, Address: 0x1d5ac4, Func Offset: 0x74
	// Line 687, Address: 0x1d5ad4, Func Offset: 0x84
	// Line 688, Address: 0x1d5adc, Func Offset: 0x8c
	// Line 689, Address: 0x1d5b00, Func Offset: 0xb0
	// Line 691, Address: 0x1d5b10, Func Offset: 0xc0
	// Line 692, Address: 0x1d5b2c, Func Offset: 0xdc
	// Line 696, Address: 0x1d5b3c, Func Offset: 0xec
	// Line 697, Address: 0x1d5b88, Func Offset: 0x138
	// Line 698, Address: 0x1d5b90, Func Offset: 0x140
	// Line 699, Address: 0x1d5b94, Func Offset: 0x144
	// Line 700, Address: 0x1d5b98, Func Offset: 0x148
	// Line 703, Address: 0x1d5b9c, Func Offset: 0x14c
	// Line 704, Address: 0x1d5bb0, Func Offset: 0x160
	// Line 703, Address: 0x1d5bb4, Func Offset: 0x164
	// Line 704, Address: 0x1d5bbc, Func Offset: 0x16c
	// Line 706, Address: 0x1d5bc8, Func Offset: 0x178
	// Line 711, Address: 0x1d5bd0, Func Offset: 0x180
	// Line 714, Address: 0x1d5bf0, Func Offset: 0x1a0
	// Line 718, Address: 0x1d5c00, Func Offset: 0x1b0
	// Line 719, Address: 0x1d5c14, Func Offset: 0x1c4
	// Line 721, Address: 0x1d5c1c, Func Offset: 0x1cc
	// Line 720, Address: 0x1d5c20, Func Offset: 0x1d0
	// Line 721, Address: 0x1d5c24, Func Offset: 0x1d4
	// Line 723, Address: 0x1d5c28, Func Offset: 0x1d8
	// Line 727, Address: 0x1d5c30, Func Offset: 0x1e0
	// Line 728, Address: 0x1d5c50, Func Offset: 0x200
	// Line 730, Address: 0x1d5c68, Func Offset: 0x218
	// Line 728, Address: 0x1d5c74, Func Offset: 0x224
	// Line 730, Address: 0x1d5c78, Func Offset: 0x228
	// Line 728, Address: 0x1d5c7c, Func Offset: 0x22c
	// Line 729, Address: 0x1d5c80, Func Offset: 0x230
	// Line 730, Address: 0x1d5c84, Func Offset: 0x234
	// Line 734, Address: 0x1d5c9c, Func Offset: 0x24c
	// Line 736, Address: 0x1d5cac, Func Offset: 0x25c
	// Line 741, Address: 0x1d5cec, Func Offset: 0x29c
	// Line 745, Address: 0x1d5da8, Func Offset: 0x358
	// Line 746, Address: 0x1d5dc4, Func Offset: 0x374
	// Line 749, Address: 0x1d5de0, Func Offset: 0x390
	// Line 750, Address: 0x1d5df4, Func Offset: 0x3a4
	// Line 751, Address: 0x1d5dfc, Func Offset: 0x3ac
	// Line 752, Address: 0x1d5e04, Func Offset: 0x3b4
	// Line 753, Address: 0x1d5e20, Func Offset: 0x3d0
	// Line 754, Address: 0x1d5e24, Func Offset: 0x3d4
	// Line 756, Address: 0x1d5e2c, Func Offset: 0x3dc
	// Line 759, Address: 0x1d5e34, Func Offset: 0x3e4
	// Line 763, Address: 0x1d5e40, Func Offset: 0x3f0
	// Func End, Address: 0x1d5e54, Func Offset: 0x404
}*/

// 100% matching!
void bhEne12_Move(BH_PWORK* epw) 
{
    bhEne12_MoveMode2[epw->mode2](epw);
    if (epw->flg & 4) {
        bhEne12_InitDamage(epw);
        return;
    }
    if (epw->mode1 != 0) {
        bhEne12_Brain(epw);
    }
}

// 100% matching!
void bhEne12_MV00(BH_PWORK* epw) 
{
    float dist;

    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x100000;
        epw->flg &= 0xFFF7FFFF;
        epw->mtn_no = 0;
        epw->frm_no  = 0;
        epw->mtn_add = 0x10000;
        epw->mode3 += 1;
        epw->ct0 = 0xA;

    case 1:
        if (epw->ct0 != 0) {
            epw->ct0--;
            return;
        }

        epw->mode1 = 1;
        {
            float px = plp->px - epw->px;
            float pz = plp->pz - epw->pz;
            dist = njSqrt((px * px) + (pz * pz));
        }

        if (dist > 9.0f || bhEne_CheckDirTarget(epw, plp->px, plp->pz, 0x1C71) == 0) {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0U;
        }
    }
}

// 100% matching!
void bhEne12_MV01(BH_PWORK* epw)
{
    float dist;
    
    switch (epw->mode3) {                             
    case 0:
        epw->flg |= 0x100000;
        epw->flg |= 0x80000;
        epw->flg |= 0x40000;
        
        if (epw->mtn_no != 1) {
            epw->mtn_no = 1;
            epw->frm_no = 0;
        }
        
        epw->mtn_add = 0x10000;

        epw->mode3 += 1;
        /* fallthrough */
        
    case 1:
        epw->xn =  plp->px;
        epw->zn =  plp->pz;
        
        if (bhEne12_AvoidWall(epw) != 0) {
            bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, (NJS_POINT3*)&epw->xn);
        }
        
        {
            float px = plp->px - epw->px;
            float pz = plp->pz - epw->pz;
            dist = njSqrt((px *px) + (pz * pz));
        }

        if (bhEne_CheckDirTarget(epw,  plp->px, plp->pz, 0x2AAA) != 0) {
            epw->ayp = bhEne_DirTarget(epw, epw->xn, epw->zn, 0x111);
        } else if (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 0x5555) != 0) {
            epw->ayp = bhEne_DirTarget(epw,  epw->xn, epw->zn, 0x1C7);
        } else {
            epw->ayp = bhEne_DirTarget(epw,  epw->xn, epw->zn, 0x27D);
        }
        
        epw->ay += epw->ayp;
        
        if ((dist < 5.0f) && (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 0x1555) != 0)) {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0U;
        }
    }
}

// 100% matching!
void bhEne12_MV02(BH_PWORK* epw)
{
    switch (epw->mode3) {
    case 0:
        epw->flg &= 0xFFEFFFFF;
        epw->flg |= 0x80000;
        epw->mtn_no = 6;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->flg |= 0x40000;
        epw->mlwP = epw->mdl;
        epw->obj_a = epw->mdl[0].objP;
        epw->obj_b = epw->mdl[1].objP;
        epw->mdflg |= 2;
        epw->mode3 += 1;
        return;

    case 1:
        epw->shp_ct = bhEne_GetShapeCnt(ShapeTbl_Acid, epw->frm_no >> 0x10);

        if (epw->frm_no == 0) {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            epw->mtn_no = 1;
            epw->mdflg &= ~2;
        }

        if ((epw->frm_no >= 0x1E0000) && (epw->frm_no < 0x280001)) {
            bhEne12_Acid(epw);
        }

        if (epw->frm_no >= 0x280000) {
            epw->flg &= 0xFFBFFFFF;
        }

        epw->xn = plp->px;
        epw->zn = plp->pz;

        if (bhEne12_AvoidWall(epw) != 0) {
            bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, (NJS_POINT3*)&epw->xn);
        }

        if (bhEne_CheckDirTarget(epw,  plp->px, plp->pz, 0x2AAA) != 0) {
            epw->ayp = bhEne_DirTarget(epw,  epw->xn, epw->zn, 0x111);
        } else if (bhEne_CheckDirTarget(epw,  plp->px, plp->pz, 0x5555) != 0) {
            epw->ayp = bhEne_DirTarget(epw,  epw->xn, epw->zn, 0x1C7);
        } else {
            epw->ayp = bhEne_DirTarget(epw,  epw->xn, epw->zn, 0x27D);
        }

        epw->ay += epw->ayp;
    }
}

// 100% matching!
void bhEne12_MV03(BH_PWORK* epw) {
    int i;
    NJS_POINT3 v;

    switch (epw->mode3) {                             
    case 0:
        epw->flg |= 0x100000;
        epw->flg |= 0x80000;
        epw->flg |= 0x40000;
        epw->mtn_no = 4;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->ct1 = 0;
        epw->mode3 += 1;
        return;
        
    case 1:
        if ((epw->frm_no >= 0xF0000) && (epw->frm_no < 0x110001)) {
            for(i = 0; i <  8; i++) {
                njUnitMatrix(NULL);
                njRotateY(NULL, epw->ay);
                v.x = 4.0f - (2.0f * (-rand() / -2.1474836e9f));
                v.y = -1.0f;
                v.z = (-20.0f - (2.2f * epw->ct1)) - (2.2f * (-rand() / -2.1474836e9f));
                njCalcVector(NULL, &v, &v);
                njAddVector(&v, (NJS_VECTOR*)&epw->px);
                bhEne12_FlameLiquid(epw, &v,  (int)(((double)(epw->ct1) / 2.5) + 40.0));
                epw->ct1 += 1;
            }
        }
        
        if (epw->frm_no >= 0x110000) {
            epw->flg &= 0xFFBFFFFF;
        }
        
        if (epw->frm_no == 0) {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            epw->mtn_no = 1;
        }
        
        epw->xn = plp->px;
        epw->zn = plp->pz;
        
        if (bhEne12_AvoidWall(epw) != 0) {
            bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, (NJS_POINT3*)&epw->xn);
        }
        
        if (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 0x2AAA) != 0) {
            epw->ayp = bhEne_DirTarget(epw, epw->xn, epw->zn, 0x111);
        } else if (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 0x5555) != 0) {
            epw->ayp = bhEne_DirTarget(epw, epw->xn, epw->zn, 0x1C7);
        } else {
            epw->ayp = bhEne_DirTarget(epw, epw->xn, epw->zn, 0x27D);
        }
        
        epw->ay += epw->ayp;
        
        if (epw->frm_no == 0x50000) {
            bhEne12_SetFireBintaEffect(epw, 0);
        }
        
        if (epw->frm_no == 0) {
            bhEne12_SetFireBintaEffect(epw, 1);
        }
        
        if ((epw->frm_no >= 0xA0000) && (epw->frm_no < 0x140001)) {
            bhEne12_SetFireBintaEffect(epw, 2);
        }
        
    }
}

/*// 
// Start address: 0x1d6850
void bhEne12_MV04(BH_PWORK* epw)
{
	_anon25 v;
	int num;
	int i;
	float dist;
	// Line 1043, Address: 0x1d6850, Func Offset: 0
	// Line 1049, Address: 0x1d6870, Func Offset: 0x20
	// Line 1051, Address: 0x1d689c, Func Offset: 0x4c
	// Line 1052, Address: 0x1d68a4, Func Offset: 0x54
	// Line 1055, Address: 0x1d68a8, Func Offset: 0x58
	// Line 1057, Address: 0x1d68ac, Func Offset: 0x5c
	// Line 1051, Address: 0x1d68b0, Func Offset: 0x60
	// Line 1052, Address: 0x1d68b8, Func Offset: 0x68
	// Line 1059, Address: 0x1d68bc, Func Offset: 0x6c
	// Line 1066, Address: 0x1d68c0, Func Offset: 0x70
	// Line 1052, Address: 0x1d68c4, Func Offset: 0x74
	// Line 1055, Address: 0x1d68cc, Func Offset: 0x7c
	// Line 1057, Address: 0x1d68d8, Func Offset: 0x88
	// Line 1058, Address: 0x1d68dc, Func Offset: 0x8c
	// Line 1059, Address: 0x1d68e0, Func Offset: 0x90
	// Line 1060, Address: 0x1d68e4, Func Offset: 0x94
	// Line 1062, Address: 0x1d68e8, Func Offset: 0x98
	// Line 1063, Address: 0x1d68f0, Func Offset: 0xa0
	// Line 1064, Address: 0x1d68f8, Func Offset: 0xa8
	// Line 1066, Address: 0x1d6900, Func Offset: 0xb0
	// Line 1070, Address: 0x1d6934, Func Offset: 0xe4
	// Line 1071, Address: 0x1d6954, Func Offset: 0x104
	// Line 1072, Address: 0x1d6978, Func Offset: 0x128
	// Line 1076, Address: 0x1d6980, Func Offset: 0x130
	// Line 1077, Address: 0x1d69a0, Func Offset: 0x150
	// Line 1078, Address: 0x1d69c4, Func Offset: 0x174
	// Line 1083, Address: 0x1d69cc, Func Offset: 0x17c
	// Line 1084, Address: 0x1d69ec, Func Offset: 0x19c
	// Line 1085, Address: 0x1d6a10, Func Offset: 0x1c0
	// Line 1087, Address: 0x1d6a18, Func Offset: 0x1c8
	// Line 1091, Address: 0x1d6a20, Func Offset: 0x1d0
	// Line 1092, Address: 0x1d6a3c, Func Offset: 0x1ec
	// Line 1093, Address: 0x1d6a5c, Func Offset: 0x20c
	// Line 1095, Address: 0x1d6a80, Func Offset: 0x230
	// Line 1097, Address: 0x1d6a8c, Func Offset: 0x23c
	// Line 1098, Address: 0x1d6a94, Func Offset: 0x244
	// Line 1097, Address: 0x1d6a98, Func Offset: 0x248
	// Line 1098, Address: 0x1d6ab4, Func Offset: 0x264
	// Line 1099, Address: 0x1d6ab8, Func Offset: 0x268
	// Line 1100, Address: 0x1d6ac0, Func Offset: 0x270
	// Line 1103, Address: 0x1d6ac8, Func Offset: 0x278
	// Line 1104, Address: 0x1d6af0, Func Offset: 0x2a0
	// Line 1105, Address: 0x1d6b28, Func Offset: 0x2d8
	// Line 1106, Address: 0x1d6b34, Func Offset: 0x2e4
	// Line 1107, Address: 0x1d6b3c, Func Offset: 0x2ec
	// Line 1108, Address: 0x1d6be8, Func Offset: 0x398
	// Line 1109, Address: 0x1d6bec, Func Offset: 0x39c
	// Line 1110, Address: 0x1d6bf0, Func Offset: 0x3a0
	// Line 1111, Address: 0x1d6c0c, Func Offset: 0x3bc
	// Line 1110, Address: 0x1d6c18, Func Offset: 0x3c8
	// Line 1111, Address: 0x1d6c38, Func Offset: 0x3e8
	// Line 1112, Address: 0x1d6c40, Func Offset: 0x3f0
	// Line 1113, Address: 0x1d6c4c, Func Offset: 0x3fc
	// Line 1114, Address: 0x1d6ca4, Func Offset: 0x454
	// Line 1115, Address: 0x1d6ca8, Func Offset: 0x458
	// Line 1114, Address: 0x1d6cb0, Func Offset: 0x460
	// Line 1115, Address: 0x1d6cb4, Func Offset: 0x464
	// Line 1116, Address: 0x1d6cbc, Func Offset: 0x46c
	// Line 1118, Address: 0x1d6cc0, Func Offset: 0x470
	// Line 1119, Address: 0x1d6cd4, Func Offset: 0x484
	// Line 1122, Address: 0x1d6ce8, Func Offset: 0x498
	// Line 1123, Address: 0x1d6cf4, Func Offset: 0x4a4
	// Line 1124, Address: 0x1d6cfc, Func Offset: 0x4ac
	// Line 1125, Address: 0x1d6d00, Func Offset: 0x4b0
	// Line 1126, Address: 0x1d6d04, Func Offset: 0x4b4
	// Line 1129, Address: 0x1d6d08, Func Offset: 0x4b8
	// Line 1131, Address: 0x1d6d10, Func Offset: 0x4c0
	// Line 1129, Address: 0x1d6d14, Func Offset: 0x4c4
	// Line 1130, Address: 0x1d6d18, Func Offset: 0x4c8
	// Line 1129, Address: 0x1d6d1c, Func Offset: 0x4cc
	// Line 1130, Address: 0x1d6d20, Func Offset: 0x4d0
	// Line 1131, Address: 0x1d6d28, Func Offset: 0x4d8
	// Line 1133, Address: 0x1d6d38, Func Offset: 0x4e8
	// Line 1137, Address: 0x1d6d50, Func Offset: 0x500
	// Line 1138, Address: 0x1d6d74, Func Offset: 0x524
	// Line 1139, Address: 0x1d6d88, Func Offset: 0x538
	// Line 1140, Address: 0x1d6db4, Func Offset: 0x564
	// Line 1141, Address: 0x1d6dc8, Func Offset: 0x578
	// Line 1142, Address: 0x1d6dd0, Func Offset: 0x580
	// Line 1144, Address: 0x1d6de8, Func Offset: 0x598
	// Line 1147, Address: 0x1d6df0, Func Offset: 0x5a0
	// Line 1144, Address: 0x1d6df4, Func Offset: 0x5a4
	// Line 1147, Address: 0x1d6dfc, Func Offset: 0x5ac
	// Line 1148, Address: 0x1d6e14, Func Offset: 0x5c4
	// Line 1149, Address: 0x1d6e2c, Func Offset: 0x5dc
	// Line 1151, Address: 0x1d6e60, Func Offset: 0x610
	// Func End, Address: 0x1d6e84, Func Offset: 0x634
}
*/

// 100% matching!
void bhEne12_MV05()
{
}

// 100% matching!
void bhEne12_MV06(BH_PWORK* epw) 
{
    
    switch (epw->mode3) {
    case 0:
        epw->flg |= 0x100000;
        epw->flg &= 0xFFF7FFFF;
        epw->mtn_no = 0;
        epw->hokan_count = 0x14;
        epw->frm_no = 0;
        epw->mode3 += 1;
        break;
    }
}

// 100% matching!
void bhEne12_MV07(BH_PWORK* epw)
{
    NJS_MKEY_A_MOD* mkaP;

    switch (epw->mode3) {
        case 0:
            break;
        default:
            return;
    } 

    bhEne_GetPartsPos(epw, &joint_tree[0][0], (NJS_POINT3*)&epw->px);

    epw->py += 5.0f;
    epw->py = bhGetGroundPosition((NJS_POINT3*)&epw->px);

    epw->mtn_md |= 0x100;

    mkaP = epw->mnwP[epw->mtn_no].md2P->p[1];
    mkaP += (epw->frm_no >> 0x10);
    epw->ay = mkaP->key[1];

    epw->flg |= 0x40000;
    epw->flg |= 0x100000;
    epw->flg &= 0xFFF7FFFF;

    epw->mnwP     = epw->mnwPb;
    epw->mtn_no   = 0;
    epw->frm_no   = 0;
    epw->mtn_add  = 0x10000;
    epw->hokan_count = 0xA;

    epw->mode3 = epw->mode3 + 1;

    sys->rm_flg |= 1;
}

// 100% matching!
void bhEne12_Nage(BH_PWORK* epw)
{
    bhEne12_NageMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne12_NG00(BH_PWORK* epw) 
{
    NJS_POINT3 pos[2] = {0, 1};
    NJS_POINT3 wp;
    EN12_WORK* efp;

    switch (epw->mode3) {                            
    case 0:
        epw->flg &= 0xFFFBFFFF;
        epw->flg |= 0x100000;
        epw->flg = epw->flg & 0xFFF7FFFF;
        epw->flg = epw->flg & ~0x40;
        epw->mtn_no = 8;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        plp->mode0 = 6;
        plp->mode3 = 0;
        
        if ((int)abs((short)(epw->ay - plp->ay)) > 0x4000) {
            plp->mode2 = 0;
        } else {
            plp->mode2 = 1;
        }
        
        epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
        epw->ct1 = 8;
        epw->ct2 = 0;
        ((int*)plp->exp1)[0] &= ~1; 
        plp->mlwP->texP = plp->txp[0];
        epw->mode3 += 1;
        /* fallthrough */
    case 1:
        if (epw->ct0-- == 0) {
            bhEne_GetPartsPos(epw, &joint_tree[0][0], &wp);
            epw->px = wp.x;
            epw->pz = wp.z;
            epw->flg |= 0x100000;
            epw->mtn_no = 0;
            epw->frm_no = 0;
            epw->mode3 += 1;
            return;
        }
        
        if (epw->frm_no < 0x640000) {
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ayp + 0x7FFF + 1);
            njCalcPoint(NULL, &pos[plp->mode2], (NJS_VECTOR*)&epw->xn);
            njAddVector((NJS_VECTOR* ) &epw->xn, (NJS_VECTOR* ) &plp->px);
            if (epw->ct1 != 0) {
                epw->ay +=  ((short)(epw->ayp - epw->ay))  / epw->ct1;
                epw->px +=  ((epw->xn - epw->px) /  epw->ct1);
                epw->pz +=  ((epw->zn - epw->pz) /  epw->ct1);
                epw->ct1 -= 1;
            } else {
                epw->px = epw->xn;
                epw->pz = epw->zn;
            }
        }
        
        if (epw->frm_no == 0x3C0000) {
            plp->flg |= 2;
        }
        
        if (epw->frm_no == 0x410000) {
            npSetAllMatColor(plp->mlwP->objP, plp->mlwP->obj_num, 0xFF402020);
            npSetAllMatColor(sys->obwp->mlwP->objP, 1U, 0xFF402020);
            npSetAllMatColor(sys->obwp[1].mlwP->objP, 1U, 0xFF402020);
        }

        
        if (epw->frm_no > 0x410000) {
            efp = pc_eff_tab;
            while(efp->jno != 0) {
                if (efp->delay == epw->ct2) {
                    bhEne_SetFireEffect(plp, efp->jno, &efp->ofp, efp->size, efp->life);
                }
                efp++;
            }

            epw->ct2 += 1;
        }
        
    }
}

// 100% matching!
void bhEne12_Damage(BH_PWORK* epw) 
{
    if ((epw->flg & 4) &&
        ((epw->flg = (int)(epw->flg & ~4),
          bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl),
          (epw->wpnr_no != 0x10)) ||
         (epw->flg2 & 4) ||
         (epw->comb_pnt == 1))) {

        epw->hp -= (epw->total_dam);

        if (epw->wpnr_no != 0x11 || (epw->flg2 & 4)) {
            bhEne12_HitMark(epw);
        }
    }

    bhEne12_DamageMode2[epw->mode2](epw);
}

// 100% matching
void bhEne12_DG00(BH_PWORK* epw) 
{
    int temp_v0;

    switch (epw->mode3) {                             
    case 0:                                         
        epw->flg = epw->flg & 0xFFEFFFFF;
        epw->flg &= 0xFFF7FFFF;
        if (bhEne_DGDirCheck(epw) != 0) {
            epw->mtn_no = 0xD;
            epw->flg &= 0xFFFBFFFF;
            epw->mtn_md &= ~2;
        } else {
            switch (epw->mtn_no) {
            case 1:
            case 4:
            case 5:
            case 6:
                if ((epw->frm_no >= 0x60000) && (epw->frm_no < 0x230001)) {
                    epw->mtn_md = epw->mtn_md | 2;
                } else {
                    epw->mtn_md = epw->mtn_md & ~2;
                }
            }
            epw->mtn_no = 0xC;
        }
        
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->hokan_count = 0xA;
        epw->hokan_rate = 0xB333;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3 += 1;

    case 1:                                         
        if (epw->mtn_no == 0xD) {
            bhEne_AddNullTrans(epw, vm1_013);
        }
        
        if (epw->ct0-- == 0) {
            temp_v0 = (int)(3.0f * (-rand() / -2.1474836e9f));
            switch (temp_v0) {                      
            case 0:                                 
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 3;
                epw->mode3 = 0;
                epw->mtn_no = 4;
                epw->frm_no = 0;
                break;
                
            case 1:                                 
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 4;
                epw->mode3 = 0;
                epw->mtn_no = 5;
                epw->frm_no = 0;
                break;
                
            default:                              
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 2;
                epw->mode3 = 0;
                epw->mtn_no = 6;
                epw->frm_no = 0;
                break;
            }
            
            epw->hokan_count = 0xF;
            epw->mtn_md &= ~2;
            epw->flg &= ~4;
            EXP0_I(4) = 0;
            EXP0_I(8) = 0;
            EXP0_I(0xC) = 0;
            EXP0_I(0x10) = 0;
            epw->flg |= 0x400000;
        }
    }
}

// 100% matching!
void bhEne12_Die(BH_PWORK* epw)
{
    bhEne12_DieMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne12_DD00(BH_PWORK* epw) {
    switch (epw->mode3) {                         
    case 0:
        epw->flg &= 0xFFFBFFFF;
        epw->flg &= 0xFFF7FFFF;
        epw->flg &=  0xFFEFFFFF;
        epw->flg &= ~0x60;
        epw->mtn_no = 0xE;
        epw->frm_no = 0;
        epw->mtn_add = 0x10000;
        epw->hokan_count = 0xA;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3 += 1;
        /* fallthrough */
    case 1:
        bhEne_AddNullTrans(epw, vm1_014);
        if (epw->ct0-- == 0) {
            epw->mtn_add = 0;
            epw->mode3 += 1;
            epw->flg |= 2;
        }
        return;
    }
}

// 100% matching!
void bhEne12_InitDamage(BH_PWORK* epw) {
    epw->flg &= ~4;
    bhEne_CalcDamage(epw, CombWepTbl, CombJointTbl);

    if ((epw->wpnr_no != 0x10) || (epw->flg2 & 4) || (epw->comb_pnt == 1)) {
        epw->hp -= epw->total_dam;

        if (epw->wpnr_no != 0x11 || (epw->flg2 & 4)) {
            bhEne12_HitMark(epw);

            if (epw->hp < 0) {
                epw->mode0 = 4;
                epw->mode1 = 0;
                epw->mode2 = 0;
                epw->mode3 = 0;
            } else if (!(epw->flg & 0x400000)) {
                if ((epw->total_dam >= 0x15) || (epw->comb_flg & 1)) {
                    epw->mode0 = 3;
                    epw->mode1 = 0;
                    epw->mode2 = 0;
                    epw->mode3 = 0;
                }
            }
        }
    }
}

// 100% matching!
void bhEne12_LookPlayaer(BH_PWORK* epw)
{
    float* mat;
    float* mat2;
    int rx;
    int ry;
    int rz;
    int rz1;
    int rz2;
    NJS_POINT3 view;
    NJS_POINT3 vec;
    NJS_POINT3 ov;
    float out;
    int ang;
    NJS_MKEY_A_MOD* mkaP;
    NJS_CNK_OBJECT* objP;

    
    mat = (float*)&lcmat;
    mat2 = (float*)&lcmat[1];
    
    if (epw->mnwP != epw->mnwPb) {
        epw->flg &= 0xFFEFFFFF;
        return;
    }

    if (!(epw->flg & 0x100000)) {
        if (EXP0_I(0x1C) == 0) {
            return;
        }

        mkaP = epw->mnwP[epw->mtn_no].md2P[5].p[1];
        mkaP += (epw->frm_no >> 0x10);
        if (epw->mtn_md & 2) {
            njUnitMatrix(lcmat);
            njRotateXYZ(lcmat,  mkaP->key[0], -mkaP->key[1], -mkaP->key[2]);
        } else {
            njUnitMatrix(lcmat);
            njRotateXYZ(lcmat, mkaP->key[0], mkaP->key[1], mkaP->key[2]);
        }
    } else {
        view.x = plp->mlwP->owP[5].mtx[12] - epw->mlwP->owP[5].mtx[12];
        view.y = plp->mlwP->owP[5].mtx[13] - epw->mlwP->owP[5].mtx[13];
        view.z = plp->mlwP->owP[5].mtx[14] - epw->mlwP->owP[5].mtx[14];
        njUnitVector(&view);
        njSetMatrix(NULL, &epw->mlwP->owP[4].mtx);
        njInvertMatrix(NULL);
        njCalcVector(NULL, &view, &view);

        rx = (int)(10430.381f * asinf(view.y));
        ry = bhArcTan2(-view.x, -view.z);
        if (ry > NJM_DEG_ANG(60.0f)) {
            ry = NJM_DEG_ANG(60.0f);
        } 
        
        if (ry < NJM_DEG_ANG(-60.0f))  {
            ry = NJM_DEG_ANG(-60.0f);
        }

        if (rx > NJM_DEG_ANG(60.0f)) {
            rx = NJM_DEG_ANG(60.0f);
        } 
        
        if (rx < NJM_DEG_ANG(-30.0f)) {
            rx = NJM_DEG_ANG(-30.0f);
        }
        
        view.x = 0.0f;
        view.y = 0.0f;
        view.z = -1.0f;
        njUnitMatrix(NULL);
        njRotateXYZ(NULL, rx, ry, 0);
        njCalcVector(NULL, &view, &view);
        vec.x = 0.0f;
        vec.y = 0.0f;
        vec.z = -1.0f;
        {

            float inner = njOuterProduct(&vec, &view, &ov);
            njUnitVector(&ov);
            ang = (int)(10430.381f * asinf(inner));
            njUnitMatrix(lcmat);
            njRotate(lcmat, &ov, ang);
        }

        njRotateZ(lcmat, -(int)(10430.381f * asinf(mat[1])));
        EXP0_I(0x1C) = 0x10;
    }

    (void*)epw->mlwP;  // Hack
    njSetMatrix((NJS_MATRIX*)&(lcmat[1]), (NJS_MATRIX*)&epw->mlwP->owP[5].mtx[0]);
    njSetMatrix(NULL, &epw->mlwP->owP[4].mtx);
    njInvertMatrix(NULL);
    njMultiMatrix(NULL, (NJS_MATRIX*)&(lcmat[1]));
    njGetMatrix((NJS_MATRIX*)&(lcmat[1]));
    rz2 = (int)(10430.381f * asinf(mat[1]));
    rz1 = (int)(10430.381f * asinf(mat2[1]));
    out = njOuterProduct((NJS_VECTOR*) &mat2[8], (NJS_VECTOR*) &mat[8], &ov);
    njUnitVector(&ov);
    ang = (int)(10430.381f * asinf(out)) / EXP0_I(0x1C);
    njUnitMatrix(NULL);
    njRotate(NULL, &ov, ang);
    njMultiMatrix(NULL, (NJS_MATRIX*)&(lcmat[1]));
    njGetMatrix(lcmat);

    njRotateZ(lcmat, ((short)(rz2 - rz1)) / EXP0_I(0x1C));
    rx = bhArcTan2(mat[6], mat[5]);
    ry = bhArcTan2(-mat[2], mat[0]);
    rz = (int)(10430.381f * asinf(mat[1]));
    objP = &epw->mlwP->objP[5];
    objP->ang[0] = rx;
    objP->ang[1] = ry;
    objP->ang[2] = rz;

    njSetMatrix(NULL, &epw->mlwP->owP[4].mtx);
    njRotateXYZ(NULL, rx, ry, rz);
    njGetMatrix(&epw->mlwP->owP[5].mtx);

    if (!(epw->flg & 0x100000)) {
        if (EXP0_I(0x1C) != 0) {
            EXP0_I(0x1C) -= 1;
        }
        return;
    }
}

// 100% matching!
void bhEne12_HitMark(BH_PWORK* epw)
{
    int i;
    int range;
    BLOOD_TBL* blp;
    NJS_POINT3 ofp;

    blp = &BloodTbl[epw->djnt_no];

    range = 0;
    
    if ((epw->comb_flg & 0x10))
    {
        range = 0;
    }
    
    if ((epw->comb_flg & 0x20))
    {
        range = 1;
    }
    
    if ((epw->comb_flg & 0x40))
    {
        range = 2;
    }

    if (DmgReact[epw->wpnr_no].type[range] >= 0) {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = (epw->comb_flg & 4) ? blp->ofp.z : -blp->ofp.z;

        ofp.x += (blp->rx * (-rand() / -2147483648.0f)) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * (-rand() / -2147483648.0f)) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * (-rand() / -2147483648.0f)) - (blp->rz / 2.0f);

        switch (epw->wpnr_no) {
        case 10:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, (NJS_POINT3*)&epw->dpx, 1);
            break;
        default:
            bhEne_SetBloodEffectBurst(epw, DmgReact[epw->wpnr_no].type[range], epw->djnt_no, &ofp, 0);
            break;
        }

        if (epw->type != 1) {
            char bloodstain = DmgReact[epw->wpnr_no].bloodstain[range];
            if ((short)bloodstain != 0)
                bhEne12_Blood(epw, bloodstain);
        }
    }

    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0)) {
        for (i = 0; i < 4; i++) {
            float size;
            int len;

            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;

            ofp.x += (blp->rx * (-rand() / -2147483648.0f)) - (blp->rx / 2.0f);
            ofp.y += (blp->ry * (-rand() / -2147483648.0f)) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * (-rand() / -2147483648.0f)) - (blp->rz / 2.0f);

            bhEne_SetFireEffect(epw, epw->djnt_no, &ofp, 0.5f + (0.5f * (-rand() / -2147483648.0f)), (int)(40.0f * (-rand() / -2147483648.0f)) + 0x14);
        }
    }

    if (DmgReact[epw->wpnr_no].exef & 2) {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;

        ofp.x += (blp->rx * (-rand() / -2147483648.0f)) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * (-rand() / -2147483648.0f)) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * (-rand() / -2147483648.0f)) - (blp->rz / 2.0f);

        bhEne_SetAcidEffect(epw, epw->djnt_no, &ofp, 2.0f);
    }
}

// 100% matching!
void bhEne12_FixedLegPos(BH_PWORK* epw) {
    int fno;
    NJS_POINT3 ret;

    if ((epw->flg & 0x40000) && (epw->mnwP == epw->mnwPb)) {
        fno = epw->frm_no / 65536;

        switch (epw->mtn_no) {
        case 1:
        case 4:
        case 5:
        case 6:
            if (epw->mtn_md & 2) {
                EXP0_I(24) = ((fno >= 17) && (fno <= 47)) ? (int)(&joint_tree[2][2]) : (int)(&joint_tree[5][1]);
            } else {
                EXP0_I(24) = ((fno >= 17) && (fno <= 47)) ? (int)(&joint_tree[5][1]) : (int)(&joint_tree[2][2]);
            }
            
            break;

        case 12:
            if (epw->mtn_md & 2) {
                EXP0_I(24) = (fno <= 12) ? (int)(&joint_tree[5][1]) : (int)(&joint_tree[2][2]);
            } else {
                EXP0_I(24) = (fno <= 12) ? (int)(&joint_tree[2][2]) : (int)(&joint_tree[5][1]);
            }
            
            break;
        }

        if (EXP0_I(24) != 0) {
            bhCalcFixOffset(epw, (char*)EXP0_I(24), 0, &ret);
            epw->px -= ret.x;
            epw->pz -= ret.z;
        }
    }
}

/*// 
// Start address: 0x1d8700
void bhEne12_PlayerControl(BH_PWORK* epw)
{
	// Line 1861, Address: 0x1d8700, Func Offset: 0
	// Line 1864, Address: 0x1d8714, Func Offset: 0x14
	// Line 1865, Address: 0x1d872c, Func Offset: 0x2c
	// Line 1868, Address: 0x1d874c, Func Offset: 0x4c
	// Line 1870, Address: 0x1d8778, Func Offset: 0x78
	// Line 1871, Address: 0x1d8784, Func Offset: 0x84
	// Line 1870, Address: 0x1d8788, Func Offset: 0x88
	// Line 1871, Address: 0x1d8790, Func Offset: 0x90
	// Line 1874, Address: 0x1d8798, Func Offset: 0x98
	// Line 1871, Address: 0x1d879c, Func Offset: 0x9c
	// Line 1874, Address: 0x1d87a4, Func Offset: 0xa4
	// Line 1875, Address: 0x1d87b4, Func Offset: 0xb4
	// Line 1876, Address: 0x1d87b8, Func Offset: 0xb8
	// Line 1877, Address: 0x1d87c0, Func Offset: 0xc0
	// Line 1879, Address: 0x1d87c8, Func Offset: 0xc8
	// Line 1880, Address: 0x1d87d0, Func Offset: 0xd0
	// Line 1881, Address: 0x1d87d4, Func Offset: 0xd4
	// Line 1882, Address: 0x1d87d8, Func Offset: 0xd8
	// Line 1886, Address: 0x1d87dc, Func Offset: 0xdc
	// Line 1879, Address: 0x1d87e0, Func Offset: 0xe0
	// Line 1880, Address: 0x1d87e4, Func Offset: 0xe4
	// Line 1881, Address: 0x1d87f0, Func Offset: 0xf0
	// Line 1882, Address: 0x1d87fc, Func Offset: 0xfc
	// Line 1883, Address: 0x1d8808, Func Offset: 0x108
	// Line 1886, Address: 0x1d8818, Func Offset: 0x118
	// Line 1888, Address: 0x1d8820, Func Offset: 0x120
	// Line 1889, Address: 0x1d882c, Func Offset: 0x12c
	// Line 1891, Address: 0x1d8834, Func Offset: 0x134
	// Line 1892, Address: 0x1d8840, Func Offset: 0x140
	// Line 1893, Address: 0x1d8844, Func Offset: 0x144
	// Line 1892, Address: 0x1d8848, Func Offset: 0x148
	// Line 1893, Address: 0x1d884c, Func Offset: 0x14c
	// Line 1894, Address: 0x1d885c, Func Offset: 0x15c
	// Line 1895, Address: 0x1d8860, Func Offset: 0x160
	// Line 1896, Address: 0x1d8868, Func Offset: 0x168
	// Line 1898, Address: 0x1d8870, Func Offset: 0x170
	// Line 1899, Address: 0x1d8878, Func Offset: 0x178
	// Line 1900, Address: 0x1d887c, Func Offset: 0x17c
	// Line 1901, Address: 0x1d8880, Func Offset: 0x180
	// Line 1898, Address: 0x1d8884, Func Offset: 0x184
	// Line 1899, Address: 0x1d8888, Func Offset: 0x188
	// Line 1900, Address: 0x1d8894, Func Offset: 0x194
	// Line 1901, Address: 0x1d88a0, Func Offset: 0x1a0
	// Line 1902, Address: 0x1d88ac, Func Offset: 0x1ac
	// Line 1904, Address: 0x1d88bc, Func Offset: 0x1bc
	// Line 1906, Address: 0x1d88c4, Func Offset: 0x1c4
	// Line 1908, Address: 0x1d88d0, Func Offset: 0x1d0
	// Line 1909, Address: 0x1d88d4, Func Offset: 0x1d4
	// Line 1913, Address: 0x1d88e0, Func Offset: 0x1e0
	// Line 1910, Address: 0x1d88e4, Func Offset: 0x1e4
	// Line 1908, Address: 0x1d88e8, Func Offset: 0x1e8
	// Line 1909, Address: 0x1d88ec, Func Offset: 0x1ec
	// Line 1914, Address: 0x1d88f0, Func Offset: 0x1f0
	// Line 1909, Address: 0x1d88f4, Func Offset: 0x1f4
	// Line 1910, Address: 0x1d88f8, Func Offset: 0x1f8
	// Line 1909, Address: 0x1d88fc, Func Offset: 0x1fc
	// Line 1910, Address: 0x1d8904, Func Offset: 0x204
	// Line 1911, Address: 0x1d890c, Func Offset: 0x20c
	// Line 1910, Address: 0x1d8910, Func Offset: 0x210
	// Line 1911, Address: 0x1d8918, Func Offset: 0x218
	// Line 1912, Address: 0x1d8920, Func Offset: 0x220
	// Line 1911, Address: 0x1d8924, Func Offset: 0x224
	// Line 1912, Address: 0x1d892c, Func Offset: 0x22c
	// Line 1913, Address: 0x1d8934, Func Offset: 0x234
	// Line 1914, Address: 0x1d8940, Func Offset: 0x240
	// Line 1913, Address: 0x1d8944, Func Offset: 0x244
	// Line 1914, Address: 0x1d894c, Func Offset: 0x24c
	// Line 1919, Address: 0x1d8950, Func Offset: 0x250
	// Line 1920, Address: 0x1d8964, Func Offset: 0x264
	// Line 1923, Address: 0x1d8984, Func Offset: 0x284
	// Line 1925, Address: 0x1d89b0, Func Offset: 0x2b0
	// Line 1926, Address: 0x1d89bc, Func Offset: 0x2bc
	// Line 1925, Address: 0x1d89c8, Func Offset: 0x2c8
	// Line 1926, Address: 0x1d89d0, Func Offset: 0x2d0
	// Line 1927, Address: 0x1d89d4, Func Offset: 0x2d4
	// Line 1935, Address: 0x1d89dc, Func Offset: 0x2dc
	// Line 1926, Address: 0x1d89e0, Func Offset: 0x2e0
	// Line 1927, Address: 0x1d89e4, Func Offset: 0x2e4
	// Line 1926, Address: 0x1d89e8, Func Offset: 0x2e8
	// Line 1927, Address: 0x1d89f0, Func Offset: 0x2f0
	// Line 1928, Address: 0x1d89f8, Func Offset: 0x2f8
	// Line 1927, Address: 0x1d89fc, Func Offset: 0x2fc
	// Line 1928, Address: 0x1d8a04, Func Offset: 0x304
	// Line 1931, Address: 0x1d8a0c, Func Offset: 0x30c
	// Line 1928, Address: 0x1d8a10, Func Offset: 0x310
	// Line 1931, Address: 0x1d8a18, Func Offset: 0x318
	// Line 1935, Address: 0x1d8a20, Func Offset: 0x320
	// Line 1931, Address: 0x1d8a24, Func Offset: 0x324
	// Line 1935, Address: 0x1d8a30, Func Offset: 0x330
	// Line 1937, Address: 0x1d8a38, Func Offset: 0x338
	// Line 1935, Address: 0x1d8a3c, Func Offset: 0x33c
	// Line 1937, Address: 0x1d8a48, Func Offset: 0x348
	// Line 1939, Address: 0x1d8a58, Func Offset: 0x358
	// Line 1941, Address: 0x1d8a5c, Func Offset: 0x35c
	// Line 1942, Address: 0x1d8a88, Func Offset: 0x388
	// Line 1944, Address: 0x1d8a90, Func Offset: 0x390
	// Line 1946, Address: 0x1d8a98, Func Offset: 0x398
	// Line 1948, Address: 0x1d8ac8, Func Offset: 0x3c8
	// Line 1953, Address: 0x1d8ad4, Func Offset: 0x3d4
	// Line 1954, Address: 0x1d8ad8, Func Offset: 0x3d8
	// Line 1948, Address: 0x1d8adc, Func Offset: 0x3dc
	// Line 1950, Address: 0x1d8ae0, Func Offset: 0x3e0
	// Line 1951, Address: 0x1d8aec, Func Offset: 0x3ec
	// Line 1950, Address: 0x1d8af0, Func Offset: 0x3f0
	// Line 1951, Address: 0x1d8af4, Func Offset: 0x3f4
	// Line 1952, Address: 0x1d8afc, Func Offset: 0x3fc
	// Line 1951, Address: 0x1d8b00, Func Offset: 0x400
	// Line 1952, Address: 0x1d8b08, Func Offset: 0x408
	// Line 1953, Address: 0x1d8b10, Func Offset: 0x410
	// Line 1954, Address: 0x1d8b1c, Func Offset: 0x41c
	// Line 1955, Address: 0x1d8b28, Func Offset: 0x428
	// Line 1957, Address: 0x1d8b34, Func Offset: 0x434
	// Line 1959, Address: 0x1d8b48, Func Offset: 0x448
	// Line 1961, Address: 0x1d8b60, Func Offset: 0x460
	// Line 1962, Address: 0x1d8b70, Func Offset: 0x470
	// Line 1964, Address: 0x1d8b80, Func Offset: 0x480
	// Line 1962, Address: 0x1d8b84, Func Offset: 0x484
	// Line 1964, Address: 0x1d8ba0, Func Offset: 0x4a0
	// Line 1967, Address: 0x1d8bb0, Func Offset: 0x4b0
	// Line 1968, Address: 0x1d8bc4, Func Offset: 0x4c4
	// Line 1969, Address: 0x1d8bf0, Func Offset: 0x4f0
	// Line 1968, Address: 0x1d8bf4, Func Offset: 0x4f4
	// Line 1969, Address: 0x1d8bfc, Func Offset: 0x4fc
	// Line 1971, Address: 0x1d8c08, Func Offset: 0x508
	// Line 1974, Address: 0x1d8c10, Func Offset: 0x510
	// Line 1975, Address: 0x1d8c1c, Func Offset: 0x51c
	// Line 1976, Address: 0x1d8c48, Func Offset: 0x548
	// Line 1975, Address: 0x1d8c4c, Func Offset: 0x54c
	// Line 1976, Address: 0x1d8c54, Func Offset: 0x554
	// Line 1979, Address: 0x1d8c64, Func Offset: 0x564
	// Line 1981, Address: 0x1d8c7c, Func Offset: 0x57c
	// Line 1984, Address: 0x1d8c88, Func Offset: 0x588
	// Line 1985, Address: 0x1d8c9c, Func Offset: 0x59c
	// Line 1986, Address: 0x1d8d00, Func Offset: 0x600
	// Line 1987, Address: 0x1d8d0c, Func Offset: 0x60c
	// Line 1992, Address: 0x1d8d20, Func Offset: 0x620
	// Line 1993, Address: 0x1d8d30, Func Offset: 0x630
	// Line 1995, Address: 0x1d8d34, Func Offset: 0x634
	// Line 1992, Address: 0x1d8d38, Func Offset: 0x638
	// Line 1993, Address: 0x1d8d40, Func Offset: 0x640
	// Line 1992, Address: 0x1d8d44, Func Offset: 0x644
	// Line 1993, Address: 0x1d8d48, Func Offset: 0x648
	// Line 1994, Address: 0x1d8d4c, Func Offset: 0x64c
	// Line 1995, Address: 0x1d8d54, Func Offset: 0x654
	// Line 1996, Address: 0x1d8d5c, Func Offset: 0x65c
	// Line 1995, Address: 0x1d8d60, Func Offset: 0x660
	// Line 1996, Address: 0x1d8d68, Func Offset: 0x668
	// Line 1997, Address: 0x1d8d70, Func Offset: 0x670
	// Line 1998, Address: 0x1d8d7c, Func Offset: 0x67c
	// Line 1997, Address: 0x1d8d80, Func Offset: 0x680
	// Line 1998, Address: 0x1d8d88, Func Offset: 0x688
	// Line 2002, Address: 0x1d8d98, Func Offset: 0x698
	// Func End, Address: 0x1d8db0, Func Offset: 0x6b0
}

// 
// Start address: 0x1d8db0
void bhEne12_FlameLiquid(BH_PWORK* epw, _anon25* pos, int time)
{
	float scale;
	_anon25 n;
	_anon13* hp;
	int eno;
	_anon25 p2;
	_anon25 p1;
	_anon1* p;
	// Line 2012, Address: 0x1d8db0, Func Offset: 0
	// Line 2021, Address: 0x1d8dd0, Func Offset: 0x20
	// Line 2026, Address: 0x1d8ddc, Func Offset: 0x2c
	// Line 2027, Address: 0x1d8de0, Func Offset: 0x30
	// Line 2021, Address: 0x1d8de4, Func Offset: 0x34
	// Line 2028, Address: 0x1d8de8, Func Offset: 0x38
	// Line 2022, Address: 0x1d8df4, Func Offset: 0x44
	// Line 2023, Address: 0x1d8dfc, Func Offset: 0x4c
	// Line 2024, Address: 0x1d8e04, Func Offset: 0x54
	// Line 2025, Address: 0x1d8e0c, Func Offset: 0x5c
	// Line 2026, Address: 0x1d8e14, Func Offset: 0x64
	// Line 2027, Address: 0x1d8e1c, Func Offset: 0x6c
	// Line 2028, Address: 0x1d8e20, Func Offset: 0x70
	// Line 2029, Address: 0x1d8e2c, Func Offset: 0x7c
	// Line 2057, Address: 0x1d8e34, Func Offset: 0x84
	// Line 2058, Address: 0x1d8e3c, Func Offset: 0x8c
	// Line 2059, Address: 0x1d8e44, Func Offset: 0x94
	// Line 2060, Address: 0x1d8e58, Func Offset: 0xa8
	// Line 2059, Address: 0x1d8e5c, Func Offset: 0xac
	// Line 2061, Address: 0x1d8e60, Func Offset: 0xb0
	// Line 2063, Address: 0x1d8e64, Func Offset: 0xb4
	// Line 2059, Address: 0x1d8e6c, Func Offset: 0xbc
	// Line 2064, Address: 0x1d8e70, Func Offset: 0xc0
	// Line 2059, Address: 0x1d8e74, Func Offset: 0xc4
	// Line 2060, Address: 0x1d8e78, Func Offset: 0xc8
	// Line 2061, Address: 0x1d8e8c, Func Offset: 0xdc
	// Line 2063, Address: 0x1d8ea0, Func Offset: 0xf0
	// Line 2064, Address: 0x1d8eb0, Func Offset: 0x100
	// Line 2065, Address: 0x1d8ec4, Func Offset: 0x114
	// Line 2066, Address: 0x1d8ed8, Func Offset: 0x128
	// Line 2067, Address: 0x1d8ef0, Func Offset: 0x140
	// Line 2068, Address: 0x1d8f08, Func Offset: 0x158
	// Line 2069, Address: 0x1d8f1c, Func Offset: 0x16c
	// Line 2070, Address: 0x1d8f44, Func Offset: 0x194
	// Line 2069, Address: 0x1d8f48, Func Offset: 0x198
	// Line 2070, Address: 0x1d8f58, Func Offset: 0x1a8
	// Line 2071, Address: 0x1d8f5c, Func Offset: 0x1ac
	// Line 2075, Address: 0x1d8f60, Func Offset: 0x1b0
	// Line 2070, Address: 0x1d8f6c, Func Offset: 0x1bc
	// Line 2069, Address: 0x1d8f74, Func Offset: 0x1c4
	// Line 2070, Address: 0x1d8f84, Func Offset: 0x1d4
	// Line 2071, Address: 0x1d8f88, Func Offset: 0x1d8
	// Line 2072, Address: 0x1d8f9c, Func Offset: 0x1ec
	// Line 2075, Address: 0x1d8fb0, Func Offset: 0x200
	// Line 2076, Address: 0x1d8fc8, Func Offset: 0x218
	// Line 2077, Address: 0x1d8fd4, Func Offset: 0x224
	// Line 2078, Address: 0x1d8ffc, Func Offset: 0x24c
	// Line 2079, Address: 0x1d9010, Func Offset: 0x260
	// Line 2080, Address: 0x1d9024, Func Offset: 0x274
	// Line 2083, Address: 0x1d9038, Func Offset: 0x288
	// Line 2084, Address: 0x1d9064, Func Offset: 0x2b4
	// Line 2087, Address: 0x1d9080, Func Offset: 0x2d0
	// Line 2089, Address: 0x1d9090, Func Offset: 0x2e0
	// Func End, Address: 0x1d90b4, Func Offset: 0x304
}

// 
// Start address: 0x1d90c0
void bhEne12_Acid(BH_PWORK* epw)
{
	float size;
	float spd;
	_anon1* owk;
	int i;
	int eno;
	// Line 2099, Address: 0x1d90c0, Func Offset: 0
	// Line 2107, Address: 0x1d90f4, Func Offset: 0x34
	// Line 2108, Address: 0x1d9100, Func Offset: 0x40
	// Line 2109, Address: 0x1d9104, Func Offset: 0x44
	// Line 2110, Address: 0x1d9108, Func Offset: 0x48
	// Line 2113, Address: 0x1d910c, Func Offset: 0x4c
	// Line 2115, Address: 0x1d911c, Func Offset: 0x5c
	// Line 2117, Address: 0x1d9130, Func Offset: 0x70
	// Line 2115, Address: 0x1d913c, Func Offset: 0x7c
	// Line 2118, Address: 0x1d9140, Func Offset: 0x80
	// Line 2119, Address: 0x1d9144, Func Offset: 0x84
	// Line 2117, Address: 0x1d9148, Func Offset: 0x88
	// Line 2118, Address: 0x1d9154, Func Offset: 0x94
	// Line 2124, Address: 0x1d915c, Func Offset: 0x9c
	// Line 2118, Address: 0x1d9160, Func Offset: 0xa0
	// Line 2119, Address: 0x1d916c, Func Offset: 0xac
	// Line 2120, Address: 0x1d9180, Func Offset: 0xc0
	// Line 2121, Address: 0x1d9194, Func Offset: 0xd4
	// Line 2122, Address: 0x1d91a8, Func Offset: 0xe8
	// Line 2125, Address: 0x1d91bc, Func Offset: 0xfc
	// Line 2126, Address: 0x1d91d4, Func Offset: 0x114
	// Line 2125, Address: 0x1d91dc, Func Offset: 0x11c
	// Line 2130, Address: 0x1d91e0, Func Offset: 0x120
	// Line 2125, Address: 0x1d91e8, Func Offset: 0x128
	// Line 2126, Address: 0x1d91f8, Func Offset: 0x138
	// Line 2130, Address: 0x1d9200, Func Offset: 0x140
	// Line 2125, Address: 0x1d9204, Func Offset: 0x144
	// Line 2126, Address: 0x1d9208, Func Offset: 0x148
	// Line 2127, Address: 0x1d920c, Func Offset: 0x14c
	// Line 2128, Address: 0x1d9220, Func Offset: 0x160
	// Line 2130, Address: 0x1d9234, Func Offset: 0x174
	// Line 2131, Address: 0x1d924c, Func Offset: 0x18c
	// Line 2132, Address: 0x1d9258, Func Offset: 0x198
	// Line 2136, Address: 0x1d927c, Func Offset: 0x1bc
	// Line 2135, Address: 0x1d9284, Func Offset: 0x1c4
	// Line 2136, Address: 0x1d9288, Func Offset: 0x1c8
	// Line 2132, Address: 0x1d928c, Func Offset: 0x1cc
	// Line 2133, Address: 0x1d9294, Func Offset: 0x1d4
	// Line 2138, Address: 0x1d9298, Func Offset: 0x1d8
	// Line 2137, Address: 0x1d92a0, Func Offset: 0x1e0
	// Line 2141, Address: 0x1d92a4, Func Offset: 0x1e4
	// Line 2133, Address: 0x1d92a8, Func Offset: 0x1e8
	// Line 2134, Address: 0x1d92ac, Func Offset: 0x1ec
	// Line 2135, Address: 0x1d92b0, Func Offset: 0x1f0
	// Line 2136, Address: 0x1d92b4, Func Offset: 0x1f4
	// Line 2137, Address: 0x1d92b8, Func Offset: 0x1f8
	// Line 2141, Address: 0x1d92bc, Func Offset: 0x1fc
	// Line 2142, Address: 0x1d92c4, Func Offset: 0x204
	// Line 2143, Address: 0x1d9310, Func Offset: 0x250
	// Line 2145, Address: 0x1d9320, Func Offset: 0x260
	// Line 2146, Address: 0x1d9330, Func Offset: 0x270
	// Line 2145, Address: 0x1d9334, Func Offset: 0x274
	// Line 2146, Address: 0x1d9340, Func Offset: 0x280
	// Line 2145, Address: 0x1d9344, Func Offset: 0x284
	// Line 2146, Address: 0x1d9348, Func Offset: 0x288
	// Line 2147, Address: 0x1d9354, Func Offset: 0x294
	// Line 2148, Address: 0x1d9368, Func Offset: 0x2a8
	// Line 2149, Address: 0x1d937c, Func Offset: 0x2bc
	// Line 2150, Address: 0x1d9380, Func Offset: 0x2c0
	// Line 2151, Address: 0x1d9390, Func Offset: 0x2d0
	// Func End, Address: 0x1d93c8, Func Offset: 0x308
}

// 
// Start address: 0x1d93d0
void bhEne12_CheckWall(BH_PWORK* epw)
{
	_anon1* owk;
	// Line 2161, Address: 0x1d93d0, Func Offset: 0
	// Line 2165, Address: 0x1d93e8, Func Offset: 0x18
	// Line 2166, Address: 0x1d93ec, Func Offset: 0x1c
	// Line 2168, Address: 0x1d93f0, Func Offset: 0x20
	// Line 2167, Address: 0x1d93f4, Func Offset: 0x24
	// Line 2165, Address: 0x1d93fc, Func Offset: 0x2c
	// Line 2166, Address: 0x1d9400, Func Offset: 0x30
	// Line 2168, Address: 0x1d9404, Func Offset: 0x34
	// Line 2167, Address: 0x1d9408, Func Offset: 0x38
	// Line 2166, Address: 0x1d940c, Func Offset: 0x3c
	// Line 2168, Address: 0x1d9410, Func Offset: 0x40
	// Line 2171, Address: 0x1d9414, Func Offset: 0x44
	// Line 2172, Address: 0x1d941c, Func Offset: 0x4c
	// Line 2167, Address: 0x1d9420, Func Offset: 0x50
	// Line 2172, Address: 0x1d9424, Func Offset: 0x54
	// Line 2173, Address: 0x1d942c, Func Offset: 0x5c
	// Line 2174, Address: 0x1d9434, Func Offset: 0x64
	// Line 2175, Address: 0x1d943c, Func Offset: 0x6c
	// Line 2180, Address: 0x1d9440, Func Offset: 0x70
	// Line 2175, Address: 0x1d9444, Func Offset: 0x74
	// Line 2176, Address: 0x1d944c, Func Offset: 0x7c
	// Line 2177, Address: 0x1d9458, Func Offset: 0x88
	// Line 2180, Address: 0x1d9460, Func Offset: 0x90
	// Line 2181, Address: 0x1d9468, Func Offset: 0x98
	// Func End, Address: 0x1d9484, Func Offset: 0xb4
}

// 
// Start address: 0x1d9490
void bhEne12_Blood(BH_PWORK* epw, int num)
{
	int i;
	float dist;
	int ang;
	int base_ang;
	float scale;
	int eno;
	// Line 2191, Address: 0x1d9490, Func Offset: 0
	// Line 2198, Address: 0x1d94b0, Func Offset: 0x20
	// Line 2199, Address: 0x1d94c0, Func Offset: 0x30
	// Line 2198, Address: 0x1d94c4, Func Offset: 0x34
	// Line 2199, Address: 0x1d94d0, Func Offset: 0x40
	// Line 2200, Address: 0x1d94e8, Func Offset: 0x58
	// Line 2201, Address: 0x1d94fc, Func Offset: 0x6c
	// Line 2203, Address: 0x1d9520, Func Offset: 0x90
	// Line 2201, Address: 0x1d9524, Func Offset: 0x94
	// Line 2203, Address: 0x1d9528, Func Offset: 0x98
	// Line 2204, Address: 0x1d9530, Func Offset: 0xa0
	// Line 2205, Address: 0x1d9568, Func Offset: 0xd8
	// Line 2206, Address: 0x1d95c4, Func Offset: 0x134
	// Line 2207, Address: 0x1d95dc, Func Offset: 0x14c
	// Line 2208, Address: 0x1d95e4, Func Offset: 0x154
	// Line 2206, Address: 0x1d95e8, Func Offset: 0x158
	// Line 2207, Address: 0x1d95f8, Func Offset: 0x168
	// Line 2208, Address: 0x1d9614, Func Offset: 0x184
	// Line 2209, Address: 0x1d9638, Func Offset: 0x1a8
	// Line 2210, Address: 0x1d9660, Func Offset: 0x1d0
	// Line 2209, Address: 0x1d9664, Func Offset: 0x1d4
	// Line 2210, Address: 0x1d9674, Func Offset: 0x1e4
	// Line 2211, Address: 0x1d9678, Func Offset: 0x1e8
	// Line 2215, Address: 0x1d967c, Func Offset: 0x1ec
	// Line 2210, Address: 0x1d9688, Func Offset: 0x1f8
	// Line 2209, Address: 0x1d9690, Func Offset: 0x200
	// Line 2210, Address: 0x1d96a0, Func Offset: 0x210
	// Line 2211, Address: 0x1d96a4, Func Offset: 0x214
	// Line 2212, Address: 0x1d96b8, Func Offset: 0x228
	// Line 2215, Address: 0x1d96cc, Func Offset: 0x23c
	// Line 2216, Address: 0x1d96e4, Func Offset: 0x254
	// Line 2217, Address: 0x1d96f0, Func Offset: 0x260
	// Line 2218, Address: 0x1d9714, Func Offset: 0x284
	// Line 2219, Address: 0x1d971c, Func Offset: 0x28c
	// Line 2220, Address: 0x1d9720, Func Offset: 0x290
	// Line 2221, Address: 0x1d9724, Func Offset: 0x294
	// Line 2220, Address: 0x1d9728, Func Offset: 0x298
	// Line 2221, Address: 0x1d9730, Func Offset: 0x2a0
	// Line 2222, Address: 0x1d9734, Func Offset: 0x2a4
	// Line 2223, Address: 0x1d9738, Func Offset: 0x2a8
	// Line 2224, Address: 0x1d9748, Func Offset: 0x2b8
	// Func End, Address: 0x1d976c, Func Offset: 0x2dc
}

// 
// Start address: 0x1d9770
int bhEne12_AvoidWall(BH_PWORK* epw)
{
	int i;
	_anon25 p2;
	_anon25 p1;
	// Line 2234, Address: 0x1d9770, Func Offset: 0
	// Line 2238, Address: 0x1d9788, Func Offset: 0x18
	// Line 2240, Address: 0x1d978c, Func Offset: 0x1c
	// Line 2242, Address: 0x1d9790, Func Offset: 0x20
	// Line 2244, Address: 0x1d9798, Func Offset: 0x28
	// Line 2238, Address: 0x1d979c, Func Offset: 0x2c
	// Line 2239, Address: 0x1d97a0, Func Offset: 0x30
	// Line 2246, Address: 0x1d97a4, Func Offset: 0x34
	// Line 2239, Address: 0x1d97a8, Func Offset: 0x38
	// Line 2240, Address: 0x1d97ac, Func Offset: 0x3c
	// Line 2242, Address: 0x1d97b4, Func Offset: 0x44
	// Line 2246, Address: 0x1d97b8, Func Offset: 0x48
	// Line 2242, Address: 0x1d97bc, Func Offset: 0x4c
	// Line 2243, Address: 0x1d97c4, Func Offset: 0x54
	// Line 2244, Address: 0x1d97cc, Func Offset: 0x5c
	// Line 2246, Address: 0x1d97d0, Func Offset: 0x60
	// Line 2248, Address: 0x1d97e8, Func Offset: 0x78
	// Line 2250, Address: 0x1d97f8, Func Offset: 0x88
	// Line 2248, Address: 0x1d97fc, Func Offset: 0x8c
	// Line 2249, Address: 0x1d9808, Func Offset: 0x98
	// Line 2251, Address: 0x1d981c, Func Offset: 0xac
	// Line 2253, Address: 0x1d9824, Func Offset: 0xb4
	// Line 2251, Address: 0x1d9830, Func Offset: 0xc0
	// Line 2252, Address: 0x1d9838, Func Offset: 0xc8
	// Line 2253, Address: 0x1d9848, Func Offset: 0xd8
	// Line 2254, Address: 0x1d9864, Func Offset: 0xf4
	// Line 2255, Address: 0x1d9874, Func Offset: 0x104
	// Func End, Address: 0x1d9890, Func Offset: 0x120
}

// 
// Start address: 0x1d9890
void bhEne12_CallSE(BH_PWORK* epw)
{
	// Line 2265, Address: 0x1d9890, Func Offset: 0
	// Line 2266, Address: 0x1d989c, Func Offset: 0xc
	// Line 2268, Address: 0x1d98ac, Func Offset: 0x1c
	// Line 2270, Address: 0x1d9918, Func Offset: 0x88
	// Line 2271, Address: 0x1d9928, Func Offset: 0x98
	// Line 2273, Address: 0x1d9930, Func Offset: 0xa0
	// Line 2274, Address: 0x1d9940, Func Offset: 0xb0
	// Line 2276, Address: 0x1d994c, Func Offset: 0xbc
	// Line 2279, Address: 0x1d9954, Func Offset: 0xc4
	// Line 2280, Address: 0x1d9964, Func Offset: 0xd4
	// Line 2282, Address: 0x1d9970, Func Offset: 0xe0
	// Line 2283, Address: 0x1d9980, Func Offset: 0xf0
	// Line 2285, Address: 0x1d998c, Func Offset: 0xfc
	// Line 2287, Address: 0x1d999c, Func Offset: 0x10c
	// Line 2288, Address: 0x1d99b0, Func Offset: 0x120
	// Line 2290, Address: 0x1d99c0, Func Offset: 0x130
	// Line 2292, Address: 0x1d99c8, Func Offset: 0x138
	// Line 2293, Address: 0x1d99d8, Func Offset: 0x148
	// Line 2295, Address: 0x1d99e0, Func Offset: 0x150
	// Line 2296, Address: 0x1d99f0, Func Offset: 0x160
	// Line 2298, Address: 0x1d9a04, Func Offset: 0x174
	// Line 2300, Address: 0x1d9a0c, Func Offset: 0x17c
	// Line 2301, Address: 0x1d9a1c, Func Offset: 0x18c
	// Line 2303, Address: 0x1d9a24, Func Offset: 0x194
	// Line 2304, Address: 0x1d9a34, Func Offset: 0x1a4
	// Line 2306, Address: 0x1d9a48, Func Offset: 0x1b8
	// Line 2308, Address: 0x1d9a50, Func Offset: 0x1c0
	// Line 2309, Address: 0x1d9a5c, Func Offset: 0x1cc
	// Line 2311, Address: 0x1d9a6c, Func Offset: 0x1dc
	// Line 2312, Address: 0x1d9a7c, Func Offset: 0x1ec
	// Line 2314, Address: 0x1d9a88, Func Offset: 0x1f8
	// Line 2316, Address: 0x1d9a90, Func Offset: 0x200
	// Line 2317, Address: 0x1d9a9c, Func Offset: 0x20c
	// Line 2319, Address: 0x1d9aac, Func Offset: 0x21c
	// Line 2320, Address: 0x1d9abc, Func Offset: 0x22c
	// Line 2322, Address: 0x1d9ac8, Func Offset: 0x238
	// Line 2323, Address: 0x1d9ad8, Func Offset: 0x248
	// Line 2325, Address: 0x1d9ae4, Func Offset: 0x254
	// Line 2327, Address: 0x1d9aec, Func Offset: 0x25c
	// Line 2328, Address: 0x1d9af8, Func Offset: 0x268
	// Line 2330, Address: 0x1d9b08, Func Offset: 0x278
	// Line 2331, Address: 0x1d9b18, Func Offset: 0x288
	// Line 2333, Address: 0x1d9b28, Func Offset: 0x298
	// Line 2334, Address: 0x1d9b38, Func Offset: 0x2a8
	// Line 2338, Address: 0x1d9b48, Func Offset: 0x2b8
	// Func End, Address: 0x1d9b58, Func Offset: 0x2c8
}

// 
// Start address: 0x1d9b60
void bhEne12_CallFootSE(BH_PWORK* epw, int flg)
{
	_anon25 pos;
	_anon13* hp;
	// Line 2349, Address: 0x1d9b60, Func Offset: 0
	// Line 2354, Address: 0x1d9b6c, Func Offset: 0xc
	// Line 2355, Address: 0x1d9b7c, Func Offset: 0x1c
	// Line 2358, Address: 0x1d9b84, Func Offset: 0x24
	// Line 2360, Address: 0x1d9b8c, Func Offset: 0x2c
	// Line 2361, Address: 0x1d9ba0, Func Offset: 0x40
	// Line 2363, Address: 0x1d9ba8, Func Offset: 0x48
	// Line 2366, Address: 0x1d9bbc, Func Offset: 0x5c
	// Line 2367, Address: 0x1d9bcc, Func Offset: 0x6c
	// Line 2369, Address: 0x1d9be4, Func Offset: 0x84
	// Line 2370, Address: 0x1d9bf8, Func Offset: 0x98
	// Line 2372, Address: 0x1d9c00, Func Offset: 0xa0
	// Line 2374, Address: 0x1d9c14, Func Offset: 0xb4
	// Func End, Address: 0x1d9c24, Func Offset: 0xc4
}

// 
// Start address: 0x1d9c30
void bhEne12_SetFireBintaEffect(BH_PWORK* epw, int act)
{
	float scale;
	//_anon25 vec2;
	//_anon25 vec;
	//_anon25 ofp;
	//_anon1* owk;
	int eno;
	int i;
	//_anon24* efp;
	// Line 2385, Address: 0x1d9c30, Func Offset: 0
	// Line 2393, Address: 0x1d9c44, Func Offset: 0x14
	// Line 2385, Address: 0x1d9c48, Func Offset: 0x18
	// Line 2393, Address: 0x1d9c4c, Func Offset: 0x1c
	// Line 2395, Address: 0x1d9c7c, Func Offset: 0x4c
	// Line 2404, Address: 0x1d9c84, Func Offset: 0x54
	// Line 2395, Address: 0x1d9c88, Func Offset: 0x58
	// Line 2404, Address: 0x1d9c8c, Func Offset: 0x5c
	// Line 2395, Address: 0x1d9c90, Func Offset: 0x60
	// Line 2396, Address: 0x1d9c9c, Func Offset: 0x6c
	// Line 2404, Address: 0x1d9ca4, Func Offset: 0x74
	// Line 2396, Address: 0x1d9cac, Func Offset: 0x7c
	// Line 2397, Address: 0x1d9cb8, Func Offset: 0x88
	// Line 2398, Address: 0x1d9ccc, Func Offset: 0x9c
	// Line 2399, Address: 0x1d9ce0, Func Offset: 0xb0
	// Line 2400, Address: 0x1d9cf4, Func Offset: 0xc4
	// Line 2401, Address: 0x1d9d08, Func Offset: 0xd8
	// Line 2402, Address: 0x1d9d1c, Func Offset: 0xec
	// Line 2404, Address: 0x1d9d2c, Func Offset: 0xfc
	// Line 2405, Address: 0x1d9d34, Func Offset: 0x104
	// Line 2407, Address: 0x1d9d40, Func Offset: 0x110
	// Line 2405, Address: 0x1d9d48, Func Offset: 0x118
	// Line 2406, Address: 0x1d9d54, Func Offset: 0x124
	// Line 2407, Address: 0x1d9d6c, Func Offset: 0x13c
	// Line 2408, Address: 0x1d9d88, Func Offset: 0x158
	// Line 2409, Address: 0x1d9d94, Func Offset: 0x164
	// Line 2410, Address: 0x1d9dc0, Func Offset: 0x190
	// Line 2411, Address: 0x1d9dd4, Func Offset: 0x1a4
	// Line 2413, Address: 0x1d9dec, Func Offset: 0x1bc
	// Line 2414, Address: 0x1d9e04, Func Offset: 0x1d4
	// Line 2416, Address: 0x1d9e0c, Func Offset: 0x1dc
	// Line 2417, Address: 0x1d9e24, Func Offset: 0x1f4
	// Line 2418, Address: 0x1d9e38, Func Offset: 0x208
	// Line 2420, Address: 0x1d9e54, Func Offset: 0x224
	// Line 2423, Address: 0x1d9e5c, Func Offset: 0x22c
	// Line 2424, Address: 0x1d9e74, Func Offset: 0x244
	// Line 2426, Address: 0x1d9e7c, Func Offset: 0x24c
	// Line 2427, Address: 0x1d9e88, Func Offset: 0x258
	// Line 2435, Address: 0x1d9e8c, Func Offset: 0x25c
	// Line 2426, Address: 0x1d9e90, Func Offset: 0x260
	// Line 2427, Address: 0x1d9e9c, Func Offset: 0x26c
	// Line 2437, Address: 0x1d9ea4, Func Offset: 0x274
	// Line 2427, Address: 0x1d9ea8, Func Offset: 0x278
	// Line 2428, Address: 0x1d9eb4, Func Offset: 0x284
	// Line 2429, Address: 0x1d9ec8, Func Offset: 0x298
	// Line 2430, Address: 0x1d9edc, Func Offset: 0x2ac
	// Line 2433, Address: 0x1d9ef0, Func Offset: 0x2c0
	// Line 2437, Address: 0x1d9ef4, Func Offset: 0x2c4
	// Line 2433, Address: 0x1d9efc, Func Offset: 0x2cc
	// Line 2437, Address: 0x1d9f00, Func Offset: 0x2d0
	// Line 2433, Address: 0x1d9f0c, Func Offset: 0x2dc
	// Line 2434, Address: 0x1d9f10, Func Offset: 0x2e0
	// Line 2435, Address: 0x1d9f14, Func Offset: 0x2e4
	// Line 2437, Address: 0x1d9f18, Func Offset: 0x2e8
	// Line 2439, Address: 0x1d9f24, Func Offset: 0x2f4
	// Line 2440, Address: 0x1d9f38, Func Offset: 0x308
	// Line 2439, Address: 0x1d9f3c, Func Offset: 0x30c
	// Line 2441, Address: 0x1d9f4c, Func Offset: 0x31c
	// Line 2442, Address: 0x1d9f50, Func Offset: 0x320
	// Line 2439, Address: 0x1d9f54, Func Offset: 0x324
	// Line 2440, Address: 0x1d9f58, Func Offset: 0x328
	// Line 2439, Address: 0x1d9f60, Func Offset: 0x330
	// Line 2440, Address: 0x1d9f6c, Func Offset: 0x33c
	// Line 2441, Address: 0x1d9f78, Func Offset: 0x348
	// Line 2440, Address: 0x1d9f80, Func Offset: 0x350
	// Line 2441, Address: 0x1d9f90, Func Offset: 0x360
	// Line 2442, Address: 0x1d9fa8, Func Offset: 0x378
	// Line 2444, Address: 0x1d9fb0, Func Offset: 0x380
	// Line 2445, Address: 0x1d9fd8, Func Offset: 0x3a8
	// Line 2444, Address: 0x1d9fdc, Func Offset: 0x3ac
	// Line 2445, Address: 0x1d9fe0, Func Offset: 0x3b0
	// Line 2444, Address: 0x1d9fe4, Func Offset: 0x3b4
	// Line 2447, Address: 0x1d9fe8, Func Offset: 0x3b8
	// Line 2445, Address: 0x1d9ff4, Func Offset: 0x3c4
	// Line 2444, Address: 0x1d9ffc, Func Offset: 0x3cc
	// Line 2445, Address: 0x1da014, Func Offset: 0x3e4
	// Line 2446, Address: 0x1da018, Func Offset: 0x3e8
	// Line 2447, Address: 0x1da02c, Func Offset: 0x3fc
	// Line 2448, Address: 0x1da044, Func Offset: 0x414
	// Line 2449, Address: 0x1da050, Func Offset: 0x420
	// Line 2450, Address: 0x1da088, Func Offset: 0x458
	// Line 2451, Address: 0x1da09c, Func Offset: 0x46c
	// Line 2450, Address: 0x1da0a8, Func Offset: 0x478
	// Line 2451, Address: 0x1da0ac, Func Offset: 0x47c
	// Line 2454, Address: 0x1da0b8, Func Offset: 0x488
	// Line 2455, Address: 0x1da0d4, Func Offset: 0x4a4
	// Line 2456, Address: 0x1da0f4, Func Offset: 0x4c4
	// Line 2458, Address: 0x1da0fc, Func Offset: 0x4cc
	// Line 2455, Address: 0x1da100, Func Offset: 0x4d0
	// Line 2458, Address: 0x1da110, Func Offset: 0x4e0
	// Line 2456, Address: 0x1da114, Func Offset: 0x4e4
	// Line 2458, Address: 0x1da11c, Func Offset: 0x4ec
	// Line 2455, Address: 0x1da120, Func Offset: 0x4f0
	// Line 2456, Address: 0x1da128, Func Offset: 0x4f8
	// Line 2457, Address: 0x1da12c, Func Offset: 0x4fc
	// Line 2458, Address: 0x1da140, Func Offset: 0x510
	// Line 2459, Address: 0x1da158, Func Offset: 0x528
	// Line 2460, Address: 0x1da164, Func Offset: 0x534
	// Line 2461, Address: 0x1da19c, Func Offset: 0x56c
	// Line 2462, Address: 0x1da1b0, Func Offset: 0x580
	// Line 2461, Address: 0x1da1bc, Func Offset: 0x58c
	// Line 2462, Address: 0x1da1c0, Func Offset: 0x590
	// Line 2465, Address: 0x1da1cc, Func Offset: 0x59c
	// Line 2466, Address: 0x1da1e8, Func Offset: 0x5b8
	// Line 2467, Address: 0x1da208, Func Offset: 0x5d8
	// Line 2466, Address: 0x1da210, Func Offset: 0x5e0
	// Line 2469, Address: 0x1da224, Func Offset: 0x5f4
	// Line 2467, Address: 0x1da228, Func Offset: 0x5f8
	// Line 2469, Address: 0x1da230, Func Offset: 0x600
	// Line 2466, Address: 0x1da238, Func Offset: 0x608
	// Line 2467, Address: 0x1da248, Func Offset: 0x618
	// Line 2468, Address: 0x1da24c, Func Offset: 0x61c
	// Line 2469, Address: 0x1da260, Func Offset: 0x630
	// Line 2470, Address: 0x1da278, Func Offset: 0x648
	// Line 2471, Address: 0x1da284, Func Offset: 0x654
	// Line 2472, Address: 0x1da2bc, Func Offset: 0x68c
	// Line 2473, Address: 0x1da2d0, Func Offset: 0x6a0
	// Line 2472, Address: 0x1da2dc, Func Offset: 0x6ac
	// Line 2473, Address: 0x1da2e0, Func Offset: 0x6b0
	// Line 2475, Address: 0x1da2e8, Func Offset: 0x6b8
	// Line 2477, Address: 0x1da2f0, Func Offset: 0x6c0
	// Line 2479, Address: 0x1da2f4, Func Offset: 0x6c4
	// Line 2481, Address: 0x1da2f8, Func Offset: 0x6c8
	// Line 2477, Address: 0x1da2fc, Func Offset: 0x6cc
	// Line 2478, Address: 0x1da300, Func Offset: 0x6d0
	// Line 2479, Address: 0x1da304, Func Offset: 0x6d4
	// Line 2480, Address: 0x1da308, Func Offset: 0x6d8
	// Line 2481, Address: 0x1da30c, Func Offset: 0x6dc
	// Line 2477, Address: 0x1da310, Func Offset: 0x6e0
	// Line 2481, Address: 0x1da314, Func Offset: 0x6e4
	// Line 2483, Address: 0x1da320, Func Offset: 0x6f0
	// Func End, Address: 0x1da33c, Func Offset: 0x70c
	scePrintf("bhEne12_SetFireBintaEffect - UNIMPLEMENTED!\n");
}
*/
