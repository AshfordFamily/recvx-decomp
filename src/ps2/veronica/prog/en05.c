#include "../../../ps2/veronica/prog/en05.h"
#include "../../../ps2/veronica/prog/en05sub.h"
#include "../../../ps2/veronica/prog/MdlPut.h"
#include "../../../ps2/veronica/prog/Motion.h"
#include "../../../ps2/veronica/prog/main.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/subpl.h"
#include "../../../ps2/veronica/prog/zonzon1.h"
#include "../../../ps2/veronica/prog/hitchkl.h"
#include "../../../ps2/veronica/prog/pwksub.h"
#include "../../../ps2/veronica/prog/rutchk.h"
#include "../../../ps2/veronica/prog/ps2_NaMatrix.h"
#include "../../../ps2/veronica/prog/hitchk.h"
#include "../../../ps2/veronica/prog/ps2_NaColi.h"
#include "../../../ps2/veronica/prog/njplus.h"

// ENEMY: Hunter/Sweeper 

NJS_VECTOR hu_020[25] =
{
  {0.0f, 0.0f, 0.0f},
  {-0.09893f, 0.037473f, -1.7096829f},
  {-0.029872f, -0.188397f, -1.406179f},
  {0.0048759999f, -0.677109f, -1.246938f},
  {0.013828f, -1.390315f, -1.1803499f},
  {0.022023f, -1.656158f, -1.043251f},
  {0.029457999f, -1.957589f, -0.835771f},
  {0.036134f, -1.95469f, -0.621527f},
  {0.042052999f, -1.3111399f, -0.458056f},
  {0.047212f, -0.22862799f, -0.32362199f},
  {0.051612999f, 0.00013499999f, -0.218224f},
  {0.034662999f, 0.0f, -0.14185999f},
  {0.007363f, 0.0f, -0.094534f},
  {-0.007433f, 0.0f, -0.076242f},
  {-0.002475f, 0.0f, -0.083143f},
  {-0.000666f, 0.0f, -0.076738998f},
  {-0.004011f, 0.0f, -0.065213f},
  {-0.00655f, 0.0f, -0.054499999f},
  {-0.008285f, 0.0f, -0.044599f},
  {-0.0092169996f, 0.0f, -0.03551f},
  {-0.009344f, 0.0f, -0.027232f},
  {-0.0086669996f, 0.0f, -0.019768f},
  {-0.007187f, 0.000095f, -0.013114f},
  {-0.0049009998f, 0.010611f, -0.007273f},
  {-0.001813f, 0.009494f, -0.002244f},
};
 
NJS_VECTOR hu_021[40] =
{
  {0.0f, 0.0f, 0.0f},
  {0.00036199999f, -0.315135f, -2.381923f},
  {0.000536f, -0.82415199f, -1.607366f},
  {0.000658f, -1.194188f, -1.454301f},
  {0.00072399998f, -1.425244f, -1.846777f},
  {0.000737f, -1.512552f, -1.990694f},
  {0.000696f, -1.368859f, -1.940206f},
  {0.0006f, -1.1311539f, -1.795672f},
  {0.000452f, -0.861554f, -1.557088f},
  {0.000248f, -0.560058f, -1.224457f},
  {0.00012f, -0.22667f, -0.967364f},
  {0.000104f, 0.200011f, -0.85339898f},
  {0.000089f, 0.56348f, -0.74677998f},
  {0.000073f, 0.699765f, -0.647503f},
  {0.000060999999f, 0.608708f, -0.55556899f},
  {0.000047f, 0.29031f, -0.47097799f},
  {0.000035f, -0.174723f, -0.39373f},
  {0.000024f, -0.503344f, -0.32382399f},
  {0.000014f, -0.65534598f, -0.26126099f},
  {0.0000049999999f, -0.631262f, -0.20604099f},
  {-0.0000049999999f, -0.43108699f, -0.158163f},
  {-0.000011f, -0.094261996f, -0.12709799f},
  {-0.000018999999f, 0.027879f, -0.130547f},
  {-0.000024999999f, 0.068085f, -0.134739f},
  {-0.000029999999f, 0.087292999f, -0.13699099f},
  {-0.000034f, 0.085497998f, -0.137308f},
  {-0.000037f, 0.062702f, -0.135689f},
  {-0.000040999999f, 0.018871f, -0.13213f},
  {-0.000040999999f, -0.043666f, -0.126632f},
  {-0.000043f, -0.090448998f, -0.119202f},
  {-0.000043f, -0.109064f, -0.109831f},
  {-0.000042f, -0.099514f, -0.098522f},
  {-0.000039999999f, -0.061797f, -0.085276f},
  {-0.000037999998f, -0.024649f, -0.059092999f},
  {-0.000034f, -0.0095849996f, -0.02369f},
  {-0.000029999999f, 0.0013689999f, 0.002177f},
  {-0.000024f, 0.008216f, 0.018426999f},
  {-0.000018999999f, 0.010955f, 0.025064f},
  {-0.000012f, 0.0095849996f, 0.022090999f},
  {-0.000004f, 0.0041089999f, 0.009499f},
};
 
NJS_VECTOR hu_012[30] =
{
  {0.0f, 0.0f, 0.0f},
  {0.0f, -0.353098f, -1.466337f},
  {0.0f, -0.528661f, -1.533836f},
  {0.0f, -0.69194198f, -1.55802f},
  {0.0f, -0.842938f, -1.538889f},
  {0.0f, -0.98165298f, -1.476443f},
  {-0.000050999999f, -1.108085f, -1.370681f},
  {-0.000083999999f, -1.222233f, -1.221607f},
  {-0.000017f, -1.324098f, -1.029214f},
  {0.00015199999f, -1.413681f, -0.79350698f},
  {0.00028499999f, -0.55195099f, -0.606677f},
  {0.00031199999f, 0.31106499f, -0.504634f},
  {0.00033499999f, 0.194211f, -0.413142f},
  {0.000352f, 0.085262f, -0.33219999f},
  {0.00036599999f, -0.015783999f, -0.261812f},
  {0.000375f, -0.108923f, -0.20197099f},
  {0.000382f, -0.194158f, -0.152683f},
  {0.000382f, -0.27148899f, -0.113947f},
  {0.000379f, -0.072539f, -0.085759997f},
  {0.000372f, -0.00062599999f, -0.068126f},
  {0.000361f, -0.001014f, -0.061042f},
  {0.000345f, -0.001309f, -0.064507999f},
  {0.000325f, -0.0015069999f, -0.078527f},
  {0.00030099999f, -0.0016139999f, -0.103097f},
  {0.000273f, -0.001624f, -0.138216f},
  {0.000165f, -0.00154f, -0.101901f},
  {0.000019999999f, -0.001363f, -0.012628f},
  {-0.000061999999f, -0.00109f, 0.038368f},
  {-0.000081999999f, -0.00072299998f, 0.051088f},
  {-0.000040999999f, -0.00026199999f, 0.025536f},
};
 
NJS_VECTOR hu_0135[30] =
{
  {0.0f, 0.0f, 0.0f},
  {0.000059f, 0.74350798f, 2.737795f},
  {0.000093f, 0.29528099f, 2.4121799f},
  {0.000125f, -0.28883f, 2.1120279f},
  {0.00015199999f, -0.955568f, 1.837335f},
  {0.00017499999f, -1.490047f, 1.588109f},
  {0.00019599999f, -1.874245f, 1.364344f},
  {0.000212f, -2.110176f, 1.1660399f},
  {0.000224f, -2.197832f, 0.993201f},
  {0.000234f, -1.8749f, 0.845825f},
  {0.000239f, 0.26302999f, 0.581978f},
  {0.00024199999f, 0.18431599f, 0.317232f},
  {0.000239f, 0.070332997f, 0.251304f},
  {0.000234f, -0.044548f, 0.269093f},
  {0.000224f, -0.160324f, 0.239216f},
  {0.000212f, -0.180641f, 0.211092f},
  {0.00019599999f, -0.114166f, 0.184719f},
  {0.00017499999f, -0.061593f, 0.160097f},
  {0.00015199999f, -0.022922f, 0.137224f},
  {0.000125f, 0.001849f, 0.116106f},
  {0.000093f, 0.012717f, 0.096736997f},
  {0.000059f, 0.009684f, 0.079121f},
  {0.000019999999f, 0.002796f, 0.063253f},
  {0.0f, 0.001511f, 0.049137f},
  {0.0f, 0.000508f, 0.036773998f},
  {0.0f, -0.000216f, 0.026161f},
  {0.0f, -0.000657f, 0.0173f},
  {0.0f, -0.00081699999f, 0.010187f},
  {0.0f, -0.000696f, 0.004829f},
  {0.0f, -0.000295f, 0.001221f},
};
 
NJS_VECTOR hu_016[48] =
{
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.50830698f, 0.00065499998f},
  {0.0f, 0.48316699f, 0.000688f},
  {0.0f, 0.45727f, 0.000391f},
  {0.0f, 0.430615f, -0.000236f},
  {0.0f, 0.403198f, -0.001192f},
  {0.0f, 0.37502199f, 0.073945999f},
  {0.0f, 0.346086f, 0.300518f},
  {0.0f, 0.316392f, 0.39592299f},
  {0.0f, 0.28593299f, 0.343685f},
  {0.0f, 0.254718f, 0.254879f},
  {0.0f, 0.22274099f, 0.229063f},
  {0.0f, 0.190006f, 0.204943f},
  {0.0f, 0.15647f, 0.182524f},
  {0.0f, 0.121714f, 0.1618f},
  {0.0f, 0.089123f, 0.14277899f},
  {0.0f, 0.059863999f, 0.125456f},
  {0.0f, 0.033939f, 0.109828f},
  {0.0f, 0.011348f, 0.095902f},
  {0.0f, -0.0079089999f, 0.083673f},
  {0.0f, -0.023833999f, 0.073142998f},
  {0.0f, -0.036424f, 0.064314f},
  {0.0f, -0.045682f, 0.057181f},
  {0.0f, -0.051605f, 0.051748f},
  {0.0f, -0.054195f, 0.048012f},
  {0.0f, -0.053452f, 0.045976f},
  {0.0f, -0.049375f, 0.045639f},
  {0.0f, -0.041965999f, 0.047001f},
  {0.0f, -0.03122f, 0.050060999f},
  {0.000034f, -0.017144f, 0.054818999f},
  {0.000075f, 0.000268f, 0.061275f},
  {0.000075f, 0.021012f, 0.069433f},
  {0.000034f, 0.045090999f, 0.079287f},
  {-0.000048f, 0.072502f, 0.090838999f},
  {-0.00017f, 0.103247f, 0.0f},
  {-0.000279f, 0.145291f, 0.058646f},
  {-0.00033899999f, 0.192111f, 0.065727f},
  {-0.000387f, 0.232482f, 0.071157f},
  {-0.000425f, 0.266402f, 0.07494f},
  {-0.000448f, 0.293872f, 0.077073999f},
  {-0.000462f, 0.31489199f, 0.077559f},
  {-0.000463f, 0.32946199f, 0.076394998f},
  {-0.00045299999f, 0.337587f, 0.073582999f},
  {-0.00043099999f, 0.339252f, 0.069121f},
  {-0.00039599999f, 0.33447099f, 0.063009f},
  {-0.000351f, 0.32324f, 0.055252f},
  {-0.000294f, 0.30555999f, 0.045843f},
  {-0.000224f, 0.281428f, 0.034786f},
};
 
NJS_VECTOR hu_017[45] =
{
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.053994998f, -0.028841f},
  {0.0f, 0.057215f, -0.038950998f},
  {0.0f, 0.060722f, -0.041604f},
  {0.0f, 0.064515f, -0.036793999f},
  {0.0f, 0.068593f, -0.024527f},
  {0.0f, 0.072958f, -0.0087559996f},
  {0.0f, 0.077609f, -0.051869f},
  {0.0f, 0.082546f, -0.110081f},
  {0.0f, 0.087769f, -0.159362f},
  {0.0f, 0.097883f, -0.199719f},
  {0.0f, 0.111722f, -0.23115f},
  {0.0f, 0.124597f, -0.253652f},
  {0.0f, 0.136507f, -0.267307f},
  {0.0f, 0.14745399f, -0.287844f},
  {0.0f, 0.15743899f, -0.313831f},
  {0.0f, 0.166456f, -0.334553f},
  {0.0f, 0.174512f, -0.350008f},
  {0.0f, 0.181603f, -0.36019799f},
  {0.0f, 0.187732f, -0.365121f},
  {0.0f, 0.192895f, -0.364777f},
  {0.0f, 0.197096f, -0.35916799f},
  {0.0f, 0.200331f, -0.348291f},
  {0.0f, 0.20260499f, -0.332151f},
  {0.0f, 0.203912f, -0.310741f},
  {-0.000001f, 0.189489f, -0.274087f},
  {-0.000003f, 0.168348f, -0.228712f},
  {-0.000003f, 0.159767f, -0.18786199f},
  {-0.000004f, 0.163744f, -0.151537f},
  {-0.000003f, 0.180282f, -0.119737f},
  {-0.000001f, 0.209379f, -0.092460997f},
  {0.0f, 0.25103599f, -0.06971f},
  {0.000003f, 0.303206f, -0.051481999f},
  {0.000007f, 0.340472f, -0.037781f},
  {0.000113f, 0.366963f, -0.030885f},
  {0.00038499999f, 0.387225f, -0.039414f},
  {0.00043799999f, 0.40125099f, -0.047619f},
  {0.00046899999f, 0.40904599f, -0.052919f},
  {0.00047699999f, 0.41061199f, -0.055303998f},
  {0.000464f, 0.405945f, -0.054781f},
  {0.000428f, 0.395044f, -0.051348f},
  {0.000372f, 0.377913f, -0.045003999f},
  {0.00029299999f, 0.35455f, -0.035748f},
  {0.000191f, 0.324956f, -0.023584f},
  {0.000069f, 0.28912899f, -0.0085079996f},
};
 
NJS_VECTOR hu_040[40] =
{
  {0.0f, 0.0f, 0.0f},
  {-0.000299f, -0.303813f, 1.98975f},
  {-0.00028099999f, -0.46564499f, 1.964031f},
  {-0.000264f, -0.594164f, 1.921051f},
  {-0.00024699999f, -0.689376f, 1.860811f},
  {-0.000231f, -0.751277f, 1.78331f},
  {-0.000216f, -0.779868f, 1.688549f},
  {-0.00019999999f, -0.775151f, 1.576528f},
  {-0.000186f, -0.73712099f, 1.413378f},
  {-0.000172f, -0.665784f, 1.054306f},
  {-0.000158f, -0.55286998f, 0.60233998f},
  {-0.000146f, -0.430519f, 0.282059f},
  {-0.00013299999f, -0.32306799f, 0.165142f},
  {-0.000121f, -0.230515f, 0.080162f},
  {-0.00011f, -0.152862f, 0.027110999f},
  {-0.000098999997f, -0.090108f, 0.005993f},
  {-0.000089f, -0.042250998f, 0.016812f},
  {-0.000078999998f, -0.009297f, 0.027846999f},
  {-0.00007f, 0.0087609999f, 0.01868f},
  {-0.000060999999f, 0.028754f, 0.010807f},
  {-0.000053f, 0.037976f, 0.0042349999f},
  {-0.000045f, 0.013233f, -0.001047f},
  {-0.000037999998f, -0.045474999f, -0.005028f},
  {-0.000032f, -0.13814899f, -0.0077169999f},
  {-0.000026f, -0.26478299f, -0.009106f},
  {-0.000019999999f, -0.449465f, -0.009203f},
  {-0.000015f, -0.546998f, -0.007999f},
  {-0.000011f, -0.460713f, -0.005503f},
  {-0.000006f, -0.190603f, -0.001709f},
  {-0.000004f, 0.169761f, 0.000513f},
  {0.0f, 0.400628f, 0.000317f},
  {0.000001f, 0.485675f, 0.00015399999f},
  {0.000004f, 0.424907f, 0.000018999999f},
  {0.0000049999999f, 0.218324f, -0.000081999999f},
  {0.0000049999999f, -0.096065f, -0.00015199999f},
  {0.000006f, -0.31832299f, -0.000195f},
  {0.0000049999999f, -0.386494f, -0.000206f},
  {0.0000049999999f, -0.300578f, -0.000183f},
  {0.000003f, -0.11961f, -0.000134f},
  {0.000001f, -0.016483f, -0.000050999999f},
};
 
NJS_VECTOR hu_041[100] =
{
  {0.0f, 0.0f, 0.0f},
  {0.0f, -0.31694f, 0.735836f},
  {0.0f, -0.389225f, 1.205061f},
  {0.0f, -0.34777299f, 1.177072f},
  {0.0f, -0.192587f, 0.65187f},
  {0.003887f, -0.058285f, 0.191358f},
  {0.010079f, -0.024899f, 0.131707f},
  {0.0139f, 0.002176f, 0.079095997f},
  {0.01535f, 0.022939f, 0.033526f},
  {0.014427f, 0.03739f, -0.0050019999f},
  {0.011133f, 0.045529f, -0.036492f},
  {0.005468f, 0.047357f, -0.060938999f},
  {-0.002569f, 0.042874f, -0.078345f},
  {-0.012978f, 0.032078f, -0.088712998f},
  {-0.025758f, 0.01497f, -0.092037f},
  {-0.040995f, -0.008248f, -0.089217998f},
  {-0.061021f, -0.026593f, -0.119717f},
  {-0.079755999f, -0.038467f, -0.162364f},
  {-0.094320998f, -0.047844f, -0.194363f},
  {-0.104717f, -0.054722998f, -0.21571399f},
  {-0.110942f, -0.059105f, -0.22641499f},
  {-0.113f, -0.060989f, -0.22646999f},
  {-0.110886f, -0.060376f, -0.215875f},
  {-0.104605f, -0.057266f, -0.194631f},
  {-0.094152f, -0.051658999f, -0.16274f},
  {-0.079531997f, -0.043552998f, -0.1202f},
  {-0.060741f, -0.032951f, -0.067011997f},
  {-0.040126f, -0.01733f, -0.0063609998f},
  {-0.03114f, 0.011197f, 0.039597999f},
  {-0.024734f, 0.032687999f, 0.077118f},
  {-0.018755f, 0.044101f, 0.108695f},
  {-0.013202f, 0.045433f, 0.13432799f},
  {-0.008076f, 0.036685f, 0.154018f},
  {-0.003377f, 0.017857f, 0.16776399f},
  {0.000897f, -0.0026839999f, 0.175566f},
  {0.0047419998f, -0.011728f, 0.177425f},
  {0.008163f, -0.018484f, 0.17333999f},
  {0.011155f, -0.023173f, 0.163312f},
  {0.013722f, -0.025796f, 0.147339f},
  {0.015861f, -0.026353f, 0.125424f},
  {0.017574999f, -0.024845f, 0.097563997f},
  {0.018860999f, -0.021269999f, 0.063762f},
  {0.019722f, -0.015628999f, 0.024015f},
  {0.020683f, -0.009495f, -0.00437f},
  {0.02305f, -0.007426f, 0.019337f},
  {0.025367999f, -0.005847f, 0.045224998f},
  {0.027508f, -0.004406f, 0.069038f},
  {0.029472f, -0.003103f, 0.090778999f},
  {0.031257f, -0.001937f, 0.110445f},
  {0.032867f, -0.00091f, 0.128038f},
  {0.034297999f, -0.000018999999f, 0.143556f},
  {0.035551999f, 0.00073199999f, 0.157002f},
  {0.036628999f, 0.001346f, 0.168372f},
  {0.03753f, 0.001823f, 0.177671f},
  {0.038252f, 0.0021619999f, 0.184893f},
  {0.038798999f, -0.064998f, 0.190044f},
  {0.039166f, -0.209116f, 0.193119f},
  {0.039358f, -0.338903f, 0.194122f},
  {0.039372f, -0.454034f, 0.193055f},
  {0.039209f, -0.554515f, 0.19438f},
  {0.038867999f, -0.640334f, 0.19792999f},
  {0.038350999f, -0.71149898f, 0.200045f},
  {0.037657f, -0.76801097f, 0.200717f},
  {0.036784f, -0.80986798f, 0.199949f},
  {0.035735998f, -0.83706897f, 0.197743f},
  {0.03451f, -0.84961897f, 0.194098f},
  {0.033105f, -0.84750497f, 0.189009f},
  {0.031525999f, -0.747518f, 0.182483f},
  {0.029766999f, 0.163617f, 0.174516f},
  {0.027833f, 0.120077f, 0.16510899f},
  {0.02572f, 0.082377f, 0.154263f},
  {0.023430999f, 0.050515998f, 0.141976f},
  {0.020965f, 0.024493f, 0.128249f},
  {0.01832f, 0.0043119998f, 0.113083f},
  {0.0155f, -0.010032f, 0.096476f},
  {0.012502f, -0.018534999f, 0.078431f},
  {0.0093259998f, -0.021199999f, 0.058943f},
  {0.0059739999f, -0.018023999f, 0.038017999f},
  {0.002444f, -0.009011f, 0.01565f},
  {0.000051999999f, -0.00021499999f, 0.000333f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
  {0.0f, 0.0f, 0.0f},
};
 
NJS_VECTOR hu_001[60] =
{
  {-0.048877f, -0.137895f, -0.074804f},
  {-0.043379f, -0.070106998f, 0.0f},
  {-0.037246f, -0.013014f, 0.0f},
  {-0.023497f, 0.016604999f, 0.0f},
  {-0.019159f, 0.033707f, -0.033429f},
  {-0.015092f, 0.048062999f, -0.096973f},
  {-0.011293f, 0.059675999f, -0.155545f},
  {-0.007763f, 0.068543f, -0.20914599f},
  {-0.004501f, 0.074667998f, -0.257775f},
  {-0.001508f, 0.078047998f, -0.301434f},
  {0.0012159999f, 0.078682996f, -0.340121f},
  {0.003671f, 0.076573998f, -0.373836f},
  {0.0058579999f, 0.071721f, -0.402581f},
  {0.007776f, 0.064124f, -0.426353f},
  {0.009425f, 0.053782f, -0.445154f},
  {0.010805f, 0.040695999f, -0.458985f},
  {0.011917f, 0.024866f, -0.467843f},
  {0.01276f, 0.013936f, -0.471731f},
  {0.013335f, 0.009722f, -0.47064599f},
  {0.013931f, 0.0054879999f, -0.464591f},
  {0.021753f, 0.001234f, -0.45356399f},
  {0.031521f, -0.00304f, -0.437565f},
  {0.039586f, -0.007332f, -0.41741699f},
  {0.045945998f, -0.011647f, -0.428496f},
  {0.050602f, -0.022595f, -0.437814f},
  {0.053552f, -0.070344f, -0.419709f},
  {0.054798f, -0.110257f, -0.37417799f},
  {0.054338999f, -0.133959f, -0.301225f},
  {0.052175f, -0.14145f, -0.200844f},
  {0.048307f, -0.13273f, -0.073043f},
  {0.042734f, -0.1078f, 0.0f},
  {0.035457f, -0.066659f, 0.0f},
  {0.026709f, -0.012372f, 0.0f},
  {0.021585f, 0.016437f, -0.029794f},
  {0.01832f, 0.0335f, -0.086719997f},
  {0.015153f, 0.047826f, -0.139659f},
  {0.012084f, 0.059418f, -0.188607f},
  {0.0091129998f, 0.068271f, -0.233563f},
  {0.006238f, 0.07439f, -0.274531f},
  {0.003464f, 0.077772997f, -0.311511f},
  {0.00078499998f, 0.078418f, -0.34449899f},
  {-0.001794f, 0.076327f, -0.373496f},
  {-0.004276f, 0.071502f, -0.398505f},
  {-0.00666f, 0.063938998f, -0.419526f},
  {-0.0089469999f, 0.053638998f, -0.436553f},
  {-0.011135f, 0.040605f, -0.449593f},
  {-0.013225f, 0.024834f, -0.458644f},
  {-0.015218f, 0.014877f, -0.463701f},
  {-0.017113f, 0.011998f, -0.464771f},
  {-0.019060999f, 0.008282f, -0.461852f},
  {-0.024764f, 0.003728f, -0.45494199f},
  {-0.031390999f, -0.001665f, -0.444041f},
  {-0.037032f, -0.0078959996f, -0.429153f},
  {-0.041685f, -0.014963f, -0.415674f},
  {-0.045350999f, -0.018825f, -0.426275f},
  {-0.04803f, -0.061306f, -0.41546699f},
  {-0.049722999f, -0.106973f, -0.37491599f},
  {-0.050427f, -0.13496099f, -0.304621f},
  {-0.050147f, -0.14526799f, -0.204584f},
  {-0.048877f, -0.137895f, -0.074804f},
};

static int ENE05_HITPOINT[2][16] =
{
  {120, 120, 120, 135, 135, 135, 135, 150, 150, 150, 150, 165, 165, 165, 165, 165},
  {45, 45, 45, 45, 45, 45, 45, 60, 60, 60, 60, 60, 75, 75, 75, 75}
};

static char joint_tree[11][8] = 
{
    { 0, 0xFF,  0,  0,    0,    0,    0,    0 }, 
    { 0,    1, 20, 21,   22, 0xFF,    0,    0 },
    { 0,    1, 24, 25,   26, 0xFF,    0,    0 },
    { 0,    1,  2,  3,    6,    7,    8, 0xFF },
    { 0,    1,  2,  3,   13,   14,   15, 0xFF },
    { 0,    1,  2,  3,    4, 0xFF,    0,    0 },
    { 0,    1,  2,  3,    6, 0xFF,    0,    0 },
    { 0,    1,  2,  3,   13, 0xFF,    0,    0 },
    { 0,    1, 20, 21,   22,   23, 0xFF,    0 }, 
    { 0,    1, 24, 25,   26,   27, 0xFF,    0 },  
    { 0,    1,  2,  3, 0xFF,    0,    0,    0 },
};

static unsigned char flip_tree[28] =
{
  0, 1, 2, 3, 4, 5, 13, 14, 15, 16, 17, 18, 19, 6, 7, 8, 9, 10, 11, 12, 24, 25, 26, 27, 20, 21, 22, 23
};

static char SdwTab[6] =
{
  1, 23, 27, 7, 14, -1
};

static ETTY_WORK ene05_child =
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

static BP_WORK BloodParam =
{
    {0.0f, 0.1f, 0.0f},                      /* off_pos */
    0,                                       /* srd_dir */
    0.0f,                                    /* srd_pos */
    0.059999999f,                            /* bld_spd */
    {1.6f, 1.2f, 1.0f, 1.6f, 1.2f},          /* srt_spd */
    {0, 3, 6, 9, 13}                         /* srt_dir */
};

static DMG_REACT DmgReact[21] =
{
    {{0, 1, 0}, {0, 0, 0}, 0},
    {{0, 1, 0}, {0, 0, 0}, 0},
    {{0, 0, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{0, 0, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{0, 0, 0}, {0, 0, 0}, 0},
    {{2, 1, 0}, {1, 0, 0}, 0},
    {{0, 0, 0}, {0, 0, 0}, 0},
    {{1, 1, 0}, {0, 0, 0}, 0},
    {{2, 1, 0}, {1, 1, 1}, 1},
    {{-1, -1, -1}, {0, 0, 0}, 2},
    {{-1, -1, -1}, {0, 0, 0}, 1},
    {{-1, -1, -1}, {0, 0, 0}, 0},
    {{2, 2, 2}, {1, 1, 1}, 5},
    {{2, 2, 2}, {0, 0, 0}, 1},
    {{2, 2, 2}, {1, 1, 1}, 5}
};

static BLOOD_TBL BloodTblF[28] =
{
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {0, {0.0f, 0.0f, -2.0f}, 5.0f, 3.0f, 1.0f},
    {0, {0.0f, 0.0f, -2.0f}, 5.0f, 3.0f, 1.0f},
    {0, {0.0f, 2.0f, -2.0f}, 6.0f, 5.0f, 1.0f},
    {1, {0.0f, 1.0f, 1.0f}, 2.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 0.0f},
    {0, {2.0f, 0.0f, -1.0f}, 3.0f, 2.0f, 2.0f},
    {0, {3.0f, 0.0f, -1.0f}, 2.0f, 1.0f, 1.0f},
    {0, {1.0f, 0.0f, -0.5f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {0, {-2.0f, 0.0f, -1.0f}, 3.0f, 2.0f, 2.0f},
    {0, {-3.0f, 0.0f, -1.0f}, 2.0f, 1.0f, 1.0f},
    {0, {-1.0f, 0.0f, -0.5f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {0, {0.0f, -2.0f, -2.0f}, 2.0f, 4.0f, 1.0f},
    {0, {0.0f, -2.0f, -2.0f}, 2.0f, 4.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f},
    {0, {0.0f, -2.0f, -2.0f}, 2.0f, 4.0f, 1.0f},
    {0, {0.0f, -2.0f, -2.0f}, 2.0f, 4.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f}
};

static BLOOD_TBL BloodTblR[28] = {
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {0, {0.0f, 0.0f, 1.0f}, 5.0f, 3.0f, 0.5f},
    {0, {0.0f, 0.0f, 1.0f}, 5.0f, 3.0f, 0.5f},
    {0, {0.0f, 2.0f, 1.0f}, 6.0f, 5.0f, 0.5f},
    {1, {0.0f, 1.0f, -1.0f}, 2.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 0.0f},
    {0, {2.0f, 0.0f, -1.0f}, 3.0f, 2.0f, 2.0f},
    {0, {3.0f, 0.0f, -1.0f}, 2.0f, 1.0f, 1.0f},
    {0, {1.0f, 0.0f, -1.0f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {0, {2.0f, 0.0f, -1.0f}, 3.0f, 2.0f, 2.0f},
    {0, {3.0f, 0.0f, -1.0f}, 2.0f, 1.0f, 1.0f},
    {0, {1.0f, 0.0f, -1.0f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {1, {0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, 0.0f},
    {0, {0.0f, -2.0f, 2.0f}, 2.0f, 4.0f, 1.0f},
    {0, {0.0f, -2.0f, 2.0f}, 2.0f, 4.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f},
    {0, {0.0f, -2.0f, 2.0f}, 2.0f, 4.0f, 1.0f},
    {0, {0.0f, -2.0f, 2.0f}, 2.0f, 4.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f},
    {1, {0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f}
};

static COMBWEP_WORK CombWepTbl[21] =
{
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 5, {1, 0, 0}, 30, 20 },
    { 13, {3, 2, 0}, 20, 10 },
    { 13, {3, 2, 0}, 20, 10 },
    { 13, {3, 2, 0}, 10, 0 },
    { 0, {0, 0, 0}, 25, 0 },
    { 0, {0, 0, 0}, 25, 0 },
    { 26, {5, 3, 1}, 5, 0 },
    { 0, {0, 0, 0}, 60, 0 },
    { 0, {0, 0, 0}, 10, 0 },
    { 2, {1, 1, 0}, 30, 0 },
    { 26, {5, 4, 2}, 10, 0 },
    { 0, {0, 0, 0}, 60, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 15, {1, 1, 1}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 },
    { 0, {0, 0, 0}, 0, 0 }
};

static COMBJOINT_WORK CombJointTbl[28] =
{
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 },
    { 0x0, 0 }
};

static EN05_SWITCH_WORK DmgSwitchTbl[9] =
{
    { 17, 0, 15, 13, 8, 32768, 10, 7, 1, 0 },
    { 17, 16, 22, 13, 7, 32768, 10, 7, 1, 0 },
    { 17, 23, 99, 13, 0, 32768, 10, 7, 1, 0 },
    { 16, 0, 8, 12, 8, 32768, 10, 6, 1, 0 },
    { 16, 9, 33, 12, 7, 32768, 10, 6, 1, 0 },
    { 16, 34, 99, 12, 5, 32768, 10, 6, 1, 0 },
    { 37, 0, 99, 12, 10, 32768, 10, 6, 1, 0 },
    { 38, 0, 99, 13, 10, 32768, 10, 7, 1, 0 },
    { -1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

static EN05_SWITCH_WORK DeadSwitchTbl[14] =
{
    { 17, 0, 15, 13, 8, 32768, 10, 1, 1, 0 },
    { 17, 16, 22, 13, 7, 32768, 10, 1, 1, 0 },
    { 17, 23, 99, 13, 0, 32768, 10, 1, 1, 0 },
    { 16, 0, 8, 37, 0, 45875, 10, 0, 1, 10 },
    { 16, 9, 12, 12, 7, 32768, 10, 0, 1, 0 },
    { 16, 13, 40, 12, 5, 32768, 10, 0, 1, 0 },
    { 16, 41, 99, 12, 3, 32768, 10, 0, 1, 0 },
    { 37, 0, 99, 12, 10, 32768, 10, 0, 1, 0 },
    { 38, 0, 99, 13, 10, 32768, 10, 1, 1, 0 },
    { 5, 0, 99, 27, 20, 52428, 30, 2, 2, 0 },
    { 6, 0, 99, 28, 20, 52428, 30, 3, 2, 0 },
    { 12, 0, 99, 12, -1, 0, 0, 0, 1, 0 },
    { 13, 0, 99, 13, -1, 0, 0, 1, 1, 0 },
    { -1, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

static EN05_WE_WORK WE_01[2] =
{
    {0, 0.0f, 0.0f, 0},
    {30, 0.0f, 0.0f, 0}
};

static EN05_WE_WORK WE_02[4] =
{
    {0, 2.0f, -1.0f, 0},
    {2, 2.0f, 3.0f, 1},
    {15, -2.0f, -1.0f, 0},
    {17, -2.0f, 3.0f, 1}
};

static EN05_WE_WORK WE_34[1] =
{
    {0, 0.0f, 0.0f, 2}
};

static EN05_WE_WORK WE_12[2] =
{
    {8, 0.0f, 0.0f, 2},
    {40, 0.0f, -10.0f, 2}
};

static EN05_WE_WORK WE_13[3] =
{
    {8, 0.0f, 10.0f, 2},
    {16, 0.0f, 10.0f, 2},
    {20, 0.0f, 10.0f, 1}
};

static EN05_WE_WORK WE_40[6] =
{
    {0, 0.0f, 0.0f, 2},
    {10, 0.0f, 5.0f, 2},
    {15, 0.0f, 5.0f, 2},
    {20, 0.0f, 5.0f, 1},
    {25, 0.0f, 5.0f, 1},
    {30, 0.0f, 5.0f, 1}
};

static EN05_WE_WORK WE_41[4] =
{
    {10, 0.0f, 0.0f, 1},
    {20, 0.0f, 0.0f, 1},
    {60, 0.0f, 10.0f, 2},
    {68, 0.0f, 10.0f, 1}
};

static EN05_WE_WORK WE_23[6] =
{
    {0, -2.0f, 5.0f, 1},
    {3, -2.0f, 5.0f, 0},
    {5, -2.0f, 5.0f, 0},
    {17, 2.0f, 2.0f, 1},
    {20, 2.0f, 2.0f, 0},
    {22, 2.0f, 1.0f, 0}
};

static EN05_WATER_EFFECT_WORK WaterEffectTbl[14] =
{
    {0, WE_01, 2},
    {1, WE_02, 5},
    {11, WE_34, 1},
    {12, WE_12, 2},
    {13, WE_13, 4},
    {20, WE_34, 1},
    {23, WE_23, 8},
    {32, WE_34, 1},
    {41, WE_40, 8},
    {42, WE_41, 5},
    {31, WE_34, 1},
    {47, WE_34, 1},
    {48, WE_34, 1},
    {-1, NULL, 0}
};

static CPCL CapColTab[25] =
{
    {1, 3, 10},
    {1, 2, 10},
    {3, 3, 20},
    {0, 0, 0},
    {3, 3, 20},
    {0, 17, -11},
    {3, 3, 20},
    {10, 7, -3},
    {3, 3, 20},
    {-10, 7, -3},
    {6, 7, 8},
    {7, 8, 6},
    {8, 11, 5},
    {13, 14, 8},
    {14, 15, 6},
    {15, 18, 5},
    {1, 20, 10},
    {20, 21, 10},
    {21, 22, 5},
    {22, 23, 5},
    {1, 24, 10},
    {24, 25, 10},
    {25, 26, 5},
    {26, 27, 5},
    {0, 0, 0}
};

typedef void (*bhEne05_Mode0_proc)(BH_PWORK* epw);
bhEne05_Mode0_proc bhEne05_Mode0[6] = 
{
    bhEne05_Init,
    bhEne05_Move,
    bhEne05_Nage,
    bhEne05_Damage,
    bhEne05_Die,
    bhEne_Event
};
typedef void (*bhEne05_BrainType_proc)(BH_PWORK* epw);
bhEne05_BrainType_proc bhEne05_BrainType[8] =
{
    bhEne05_BR00,
    bhEne05_BR00,
    bhEne05_BR01,
    bhEne05_BR01,
    bhEne05_BR02,
    bhEne05_BR02,
    bhEne05_BR02,
    bhEne05_BR02
};
typedef void (*bhEne05_MoveMode2_proc)(BH_PWORK* epw);
bhEne05_MoveMode2_proc bhEne05_MoveMode2[18] =
{
    bhEne05_MV00,
    bhEne05_MV01,
    bhEne05_MV02,
    bhEne05_MV03,
    bhEne05_MV04,
    bhEne05_MV05,
    bhEne05_MV06,
    bhEne05_MV07,
    bhEne05_MV08,
    bhEne05_MV09,
    bhEne05_MV10,
    bhEne05_MV11,
    bhEne05_MV12,
    bhEne05_MV13,
    bhEne05_MV14,
    bhEne05_MV15,
    bhEne05_MV16,
    bhEne05_MV17
};

// void(*bhEne05_NageMode2)(BH_PWORK*)[1]; // unused

typedef void (*bhEne05_DamageMode2_proc)(BH_PWORK* epw);
bhEne05_DamageMode2_proc bhEne05_DamageMode2[14] =
{
    bhEne05_DG00,
    bhEne05_DG01,
    bhEne05_DG02,
    bhEne05_DG03,
    bhEne05_DG04,
    bhEne05_DG05,
    bhEne05_DG06,
    bhEne05_DG07,
    bhEne05_DG08,
    bhEne05_DG09,
    bhEne05_DG10,
    bhEne05_DG11,
    bhEne05_DG12,
    bhEne05_DG13
};

typedef void (*bhEne05_DeadMode2_proc)(BH_PWORK* epw);
bhEne05_DeadMode2_proc bhEne05_DeadMode2[9] =
{
    bhEne05_DD00,
    bhEne05_DD01,
    bhEne05_DD02,
    bhEne05_DD03,
    bhEne05_DD04,
    bhEne05_DD05,
    bhEne05_DD06,
    bhEne05_DD07,
    bhEne05_DD08
};

// 100% matching!
void bhEne05(BH_PWORK* epw) 
{
    NJS_POINT3 pos1; 
    NJS_POINT3 pos2; 

    if (epw->mode0 != 5) 
    {
        epw->flg &= ~0x100;
        
        epw->mtn_md |= 0x10;
        epw->mtn_md &= ~0x20;
    }
    
    bhEne05_Mode0[epw->mode0](epw);
    
    if ((epw->flg & 0x1000000)) 
    {
        bhEne05_ChainDamage(epw);
    }
    
    if ((!(epw->stflg & 0x100000)) && (bhCheckWater((NJS_POINT3*)&epw->px) != NULL))
    {
        epw->stflg |= 0x100000;
    }
    
    if ((epw->stflg & 0x100000)) 
    {
        bhEne05_WaterEffect(epw);
    }
    
    bhEne05_CallSE(epw);
    
    bhSetMotion(epw, epw->mtn_add, epw->mtn_md, epw->mtn_tp);
    
    bhEne05_FixedLegPos(epw);
    
    bhEne_GetPartsPos(epw,  joint_tree[5], &pos1);
    bhEne_GetPartsPos(epw, joint_tree[10], &pos2);
    
    epw->aox = (0.5f * (pos1.x + pos2.x)) - epw->px;
    epw->aoz = (0.5f * (pos1.z + pos2.z)) - epw->pz;
    
    bhEne_GetPartsPos(epw, joint_tree[0], &pos1);
    
    epw->aoy = pos1.y - epw->py;
    
    epw->car += (((float*)epw->exp0)[17] - epw->car) / 8.0f;
    
    if (!(epw->flg & 0x4000000))
    {
        bhCheckPlayer(epw);
    }
    
    if (epw->mode0 != 4) 
    {
        bhCheckEnemies(epw);
    }
    
    bhEne05_FloorCollision(epw);
    
    if ((epw->flg & 0x10)) 
    {
        bhEne05_CheckWall(epw);
    }
    
    bhCalcModel(epw);
    
    bhEne05_SetWeponAtr(epw);
    
    if ((epw->flg & 0x8000000)) 
    {
        bhEne05_PlayerControl(epw);
    }
}

// 
// Start address: 0x1aca10
void bhEne05_Init(BH_PWORK* epw)
{
	//_anon31* owk;
	int i;
	BH_PWORK* ep;
	// Line 848, Address: 0x1aca10, Func Offset: 0
	// Line 854, Address: 0x1aca1c, Func Offset: 0xc
	// Line 857, Address: 0x1aca20, Func Offset: 0x10
	// Line 856, Address: 0x1aca28, Func Offset: 0x18
	// Line 858, Address: 0x1aca2c, Func Offset: 0x1c
	// Line 859, Address: 0x1aca30, Func Offset: 0x20
	// Line 854, Address: 0x1aca34, Func Offset: 0x24
	// Line 855, Address: 0x1aca3c, Func Offset: 0x2c
	// Line 860, Address: 0x1aca40, Func Offset: 0x30
	// Line 862, Address: 0x1aca44, Func Offset: 0x34
	// Line 855, Address: 0x1aca4c, Func Offset: 0x3c
	// Line 856, Address: 0x1aca54, Func Offset: 0x44
	// Line 857, Address: 0x1aca60, Func Offset: 0x50
	// Line 858, Address: 0x1aca6c, Func Offset: 0x5c
	// Line 859, Address: 0x1aca70, Func Offset: 0x60
	// Line 860, Address: 0x1aca74, Func Offset: 0x64
	// Line 861, Address: 0x1aca78, Func Offset: 0x68
	// Line 862, Address: 0x1aca7c, Func Offset: 0x6c
	// Line 863, Address: 0x1aca8c, Func Offset: 0x7c
	// Line 864, Address: 0x1acadc, Func Offset: 0xcc
	// Line 865, Address: 0x1acae4, Func Offset: 0xd4
	// Line 871, Address: 0x1acb38, Func Offset: 0x128
	// Line 869, Address: 0x1acb3c, Func Offset: 0x12c
	// Line 870, Address: 0x1acb40, Func Offset: 0x130
	// Line 871, Address: 0x1acb44, Func Offset: 0x134
	// Line 870, Address: 0x1acb48, Func Offset: 0x138
	// Line 871, Address: 0x1acb4c, Func Offset: 0x13c
	// Line 872, Address: 0x1acb50, Func Offset: 0x140
	// Line 873, Address: 0x1acb54, Func Offset: 0x144
	// Line 877, Address: 0x1acb58, Func Offset: 0x148
	// Line 874, Address: 0x1acb5c, Func Offset: 0x14c
	// Line 877, Address: 0x1acb60, Func Offset: 0x150
	// Line 878, Address: 0x1acb64, Func Offset: 0x154
	// Line 879, Address: 0x1acb68, Func Offset: 0x158
	// Line 880, Address: 0x1acb6c, Func Offset: 0x15c
	// Line 883, Address: 0x1acb70, Func Offset: 0x160
	// Line 884, Address: 0x1acb7c, Func Offset: 0x16c
	// Line 887, Address: 0x1acb8c, Func Offset: 0x17c
	// Line 900, Address: 0x1acba8, Func Offset: 0x198
	// Line 897, Address: 0x1acbb0, Func Offset: 0x1a0
	// Line 900, Address: 0x1acbb4, Func Offset: 0x1a4
	// Line 887, Address: 0x1acbb8, Func Offset: 0x1a8
	// Line 888, Address: 0x1acbbc, Func Offset: 0x1ac
	// Line 889, Address: 0x1acbc8, Func Offset: 0x1b8
	// Line 890, Address: 0x1acbd4, Func Offset: 0x1c4
	// Line 891, Address: 0x1acbe0, Func Offset: 0x1d0
	// Line 892, Address: 0x1acbec, Func Offset: 0x1dc
	// Line 893, Address: 0x1acbf8, Func Offset: 0x1e8
	// Line 897, Address: 0x1acc0c, Func Offset: 0x1fc
	// Line 900, Address: 0x1acc24, Func Offset: 0x214
	// Line 902, Address: 0x1acc2c, Func Offset: 0x21c
	// Line 903, Address: 0x1acc30, Func Offset: 0x220
	// Line 904, Address: 0x1acc78, Func Offset: 0x268
	// Line 905, Address: 0x1acc80, Func Offset: 0x270
	// Line 908, Address: 0x1acc88, Func Offset: 0x278
	// Line 909, Address: 0x1acc98, Func Offset: 0x288
	// Line 910, Address: 0x1accc0, Func Offset: 0x2b0
	// Line 914, Address: 0x1acccc, Func Offset: 0x2bc
	// Line 915, Address: 0x1accd4, Func Offset: 0x2c4
	// Line 916, Address: 0x1accdc, Func Offset: 0x2cc
	// Line 917, Address: 0x1acce0, Func Offset: 0x2d0
	// Line 916, Address: 0x1acce4, Func Offset: 0x2d4
	// Line 917, Address: 0x1acce8, Func Offset: 0x2d8
	// Line 918, Address: 0x1accec, Func Offset: 0x2dc
	// Line 919, Address: 0x1accf4, Func Offset: 0x2e4
	// Line 920, Address: 0x1accfc, Func Offset: 0x2ec
	// Line 921, Address: 0x1acd04, Func Offset: 0x2f4
	// Line 927, Address: 0x1acd0c, Func Offset: 0x2fc
	// Line 924, Address: 0x1acd10, Func Offset: 0x300
	// Line 927, Address: 0x1acd14, Func Offset: 0x304
	// Line 930, Address: 0x1acd1c, Func Offset: 0x30c
	// Line 931, Address: 0x1acd20, Func Offset: 0x310
	// Line 932, Address: 0x1acd28, Func Offset: 0x318
	// Line 930, Address: 0x1acd30, Func Offset: 0x320
	// Line 932, Address: 0x1acd34, Func Offset: 0x324
	// Line 933, Address: 0x1acd4c, Func Offset: 0x33c
	// Line 934, Address: 0x1acd54, Func Offset: 0x344
	// Line 935, Address: 0x1acd70, Func Offset: 0x360
	// Line 936, Address: 0x1acd74, Func Offset: 0x364
	// Line 938, Address: 0x1acd7c, Func Offset: 0x36c
	// Line 941, Address: 0x1acd98, Func Offset: 0x388
	// Line 944, Address: 0x1acda8, Func Offset: 0x398
	// Line 945, Address: 0x1acdac, Func Offset: 0x39c
	// Line 948, Address: 0x1acdb0, Func Offset: 0x3a0
	// Line 941, Address: 0x1acdb4, Func Offset: 0x3a4
	// Line 951, Address: 0x1acdb8, Func Offset: 0x3a8
	// Line 952, Address: 0x1acdbc, Func Offset: 0x3ac
	// Line 953, Address: 0x1acdc0, Func Offset: 0x3b0
	// Line 941, Address: 0x1acdc4, Func Offset: 0x3b4
	// Line 944, Address: 0x1acdcc, Func Offset: 0x3bc
	// Line 945, Address: 0x1acdd4, Func Offset: 0x3c4
	// Line 946, Address: 0x1acddc, Func Offset: 0x3cc
	// Line 947, Address: 0x1acde4, Func Offset: 0x3d4
	// Line 948, Address: 0x1acdec, Func Offset: 0x3dc
	// Line 951, Address: 0x1acdf4, Func Offset: 0x3e4
	// Line 954, Address: 0x1ace00, Func Offset: 0x3f0
	// Line 951, Address: 0x1ace04, Func Offset: 0x3f4
	// Line 952, Address: 0x1ace18, Func Offset: 0x408
	// Line 953, Address: 0x1ace24, Func Offset: 0x414
	// Line 954, Address: 0x1ace30, Func Offset: 0x420
	// Line 955, Address: 0x1ace44, Func Offset: 0x434
	// Func End, Address: 0x1ace54, Func Offset: 0x444
	scePrintf("bhEne05_Init - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne05_Brain(BH_PWORK* epw) 
{
    bhEne05_BrainType[epw->type](epw);
}

// 
// Start address: 0x1ace80
void bhEne05_BR00(BH_PWORK* epw)
{
	int fno;
	int hikkaki;
	int kubikari;
	int ang2;
	int ang;
	//_anon6* hp;
	int crit_hp[4];
	// Line 977, Address: 0x1ace80, Func Offset: 0
	// Line 986, Address: 0x1acea0, Func Offset: 0x20
	// Line 987, Address: 0x1acec8, Func Offset: 0x48
	// Line 989, Address: 0x1acecc, Func Offset: 0x4c
	// Line 991, Address: 0x1acee0, Func Offset: 0x60
	// Line 992, Address: 0x1acf1c, Func Offset: 0x9c
	// Line 993, Address: 0x1acf20, Func Offset: 0xa0
	// Line 997, Address: 0x1acf24, Func Offset: 0xa4
	// Line 1001, Address: 0x1acf2c, Func Offset: 0xac
	// Line 1003, Address: 0x1acf5c, Func Offset: 0xdc
	// Line 1004, Address: 0x1acf80, Func Offset: 0x100
	// Line 1005, Address: 0x1acf90, Func Offset: 0x110
	// Line 1006, Address: 0x1acf94, Func Offset: 0x114
	// Line 1012, Address: 0x1acf98, Func Offset: 0x118
	// Line 1013, Address: 0x1acfa8, Func Offset: 0x128
	// Line 1014, Address: 0x1acfb8, Func Offset: 0x138
	// Line 1015, Address: 0x1acfbc, Func Offset: 0x13c
	// Line 1016, Address: 0x1acfcc, Func Offset: 0x14c
	// Line 1017, Address: 0x1acfd0, Func Offset: 0x150
	// Line 1028, Address: 0x1acfd4, Func Offset: 0x154
	// Line 1029, Address: 0x1acfec, Func Offset: 0x16c
	// Line 1030, Address: 0x1ad004, Func Offset: 0x184
	// Line 1032, Address: 0x1ad01c, Func Offset: 0x19c
	// Line 1030, Address: 0x1ad020, Func Offset: 0x1a0
	// Line 1035, Address: 0x1ad024, Func Offset: 0x1a4
	// Line 1032, Address: 0x1ad028, Func Offset: 0x1a8
	// Line 1035, Address: 0x1ad02c, Func Offset: 0x1ac
	// Line 1036, Address: 0x1ad040, Func Offset: 0x1c0
	// Line 1037, Address: 0x1ad05c, Func Offset: 0x1dc
	// Line 1039, Address: 0x1ad098, Func Offset: 0x218
	// Line 1040, Address: 0x1ad0b8, Func Offset: 0x238
	// Line 1041, Address: 0x1ad0bc, Func Offset: 0x23c
	// Line 1042, Address: 0x1ad10c, Func Offset: 0x28c
	// Line 1041, Address: 0x1ad110, Func Offset: 0x290
	// Line 1042, Address: 0x1ad124, Func Offset: 0x2a4
	// Line 1043, Address: 0x1ad188, Func Offset: 0x308
	// Line 1045, Address: 0x1ad198, Func Offset: 0x318
	// Line 1046, Address: 0x1ad1b4, Func Offset: 0x334
	// Line 1048, Address: 0x1ad1f8, Func Offset: 0x378
	// Line 1046, Address: 0x1ad1fc, Func Offset: 0x37c
	// Line 1047, Address: 0x1ad204, Func Offset: 0x384
	// Line 1048, Address: 0x1ad208, Func Offset: 0x388
	// Line 1051, Address: 0x1ad20c, Func Offset: 0x38c
	// Line 1053, Address: 0x1ad214, Func Offset: 0x394
	// Line 1054, Address: 0x1ad22c, Func Offset: 0x3ac
	// Line 1056, Address: 0x1ad270, Func Offset: 0x3f0
	// Line 1054, Address: 0x1ad274, Func Offset: 0x3f4
	// Line 1055, Address: 0x1ad27c, Func Offset: 0x3fc
	// Line 1056, Address: 0x1ad280, Func Offset: 0x400
	// Line 1057, Address: 0x1ad284, Func Offset: 0x404
	// Line 1060, Address: 0x1ad288, Func Offset: 0x408
	// Line 1066, Address: 0x1ad290, Func Offset: 0x410
	// Line 1068, Address: 0x1ad2d0, Func Offset: 0x450
	// Line 1069, Address: 0x1ad2ec, Func Offset: 0x46c
	// Line 1071, Address: 0x1ad30c, Func Offset: 0x48c
	// Line 1072, Address: 0x1ad32c, Func Offset: 0x4ac
	// Line 1073, Address: 0x1ad330, Func Offset: 0x4b0
	// Line 1074, Address: 0x1ad350, Func Offset: 0x4d0
	// Line 1073, Address: 0x1ad354, Func Offset: 0x4d4
	// Line 1074, Address: 0x1ad358, Func Offset: 0x4d8
	// Line 1075, Address: 0x1ad37c, Func Offset: 0x4fc
	// Line 1077, Address: 0x1ad38c, Func Offset: 0x50c
	// Line 1078, Address: 0x1ad3a8, Func Offset: 0x528
	// Line 1080, Address: 0x1ad3b8, Func Offset: 0x538
	// Line 1078, Address: 0x1ad3bc, Func Offset: 0x53c
	// Line 1079, Address: 0x1ad3c4, Func Offset: 0x544
	// Line 1080, Address: 0x1ad3c8, Func Offset: 0x548
	// Line 1083, Address: 0x1ad3cc, Func Offset: 0x54c
	// Line 1085, Address: 0x1ad3d4, Func Offset: 0x554
	// Line 1086, Address: 0x1ad3ec, Func Offset: 0x56c
	// Line 1088, Address: 0x1ad3fc, Func Offset: 0x57c
	// Line 1086, Address: 0x1ad400, Func Offset: 0x580
	// Line 1087, Address: 0x1ad408, Func Offset: 0x588
	// Line 1088, Address: 0x1ad40c, Func Offset: 0x58c
	// Line 1089, Address: 0x1ad410, Func Offset: 0x590
	// Line 1092, Address: 0x1ad414, Func Offset: 0x594
	// Line 1098, Address: 0x1ad41c, Func Offset: 0x59c
	// Line 1100, Address: 0x1ad45c, Func Offset: 0x5dc
	// Line 1101, Address: 0x1ad474, Func Offset: 0x5f4
	// Line 1103, Address: 0x1ad47c, Func Offset: 0x5fc
	// Line 1104, Address: 0x1ad49c, Func Offset: 0x61c
	// Line 1105, Address: 0x1ad4a4, Func Offset: 0x624
	// Line 1107, Address: 0x1ad4b4, Func Offset: 0x634
	// Line 1108, Address: 0x1ad4d0, Func Offset: 0x650
	// Line 1109, Address: 0x1ad4d4, Func Offset: 0x654
	// Line 1112, Address: 0x1ad4d8, Func Offset: 0x658
	// Line 1114, Address: 0x1ad4e0, Func Offset: 0x660
	// Line 1115, Address: 0x1ad4f8, Func Offset: 0x678
	// Line 1116, Address: 0x1ad4fc, Func Offset: 0x67c
	// Line 1117, Address: 0x1ad500, Func Offset: 0x680
	// Line 1122, Address: 0x1ad504, Func Offset: 0x684
	// Line 1124, Address: 0x1ad538, Func Offset: 0x6b8
	// Line 1125, Address: 0x1ad540, Func Offset: 0x6c0
	// Line 1124, Address: 0x1ad54c, Func Offset: 0x6cc
	// Line 1125, Address: 0x1ad550, Func Offset: 0x6d0
	// Line 1127, Address: 0x1ad568, Func Offset: 0x6e8
	// Line 1129, Address: 0x1ad570, Func Offset: 0x6f0
	// Line 1131, Address: 0x1ad580, Func Offset: 0x700
	// Line 1129, Address: 0x1ad584, Func Offset: 0x704
	// Line 1130, Address: 0x1ad58c, Func Offset: 0x70c
	// Line 1132, Address: 0x1ad598, Func Offset: 0x718
	// Line 1134, Address: 0x1ad5a0, Func Offset: 0x720
	// Line 1135, Address: 0x1ad5a8, Func Offset: 0x728
	// Line 1136, Address: 0x1ad5b0, Func Offset: 0x730
	// Line 1134, Address: 0x1ad5b4, Func Offset: 0x734
	// Line 1135, Address: 0x1ad5b8, Func Offset: 0x738
	// Line 1137, Address: 0x1ad5c8, Func Offset: 0x748
	// Line 1139, Address: 0x1ad5d0, Func Offset: 0x750
	// Line 1141, Address: 0x1ad5e4, Func Offset: 0x764
	// Line 1139, Address: 0x1ad5e8, Func Offset: 0x768
	// Line 1140, Address: 0x1ad5f4, Func Offset: 0x774
	// Line 1141, Address: 0x1ad600, Func Offset: 0x780
	// Line 1144, Address: 0x1ad604, Func Offset: 0x784
	// Line 1146, Address: 0x1ad60c, Func Offset: 0x78c
	// Line 1152, Address: 0x1ad614, Func Offset: 0x794
	// Line 1153, Address: 0x1ad62c, Func Offset: 0x7ac
	// Line 1154, Address: 0x1ad644, Func Offset: 0x7c4
	// Line 1155, Address: 0x1ad64c, Func Offset: 0x7cc
	// Line 1156, Address: 0x1ad664, Func Offset: 0x7e4
	// Line 1157, Address: 0x1ad66c, Func Offset: 0x7ec
	// Line 1158, Address: 0x1ad670, Func Offset: 0x7f0
	// Line 1159, Address: 0x1ad690, Func Offset: 0x810
	// Line 1158, Address: 0x1ad694, Func Offset: 0x814
	// Line 1159, Address: 0x1ad698, Func Offset: 0x818
	// Line 1162, Address: 0x1ad6b4, Func Offset: 0x834
	// Line 1159, Address: 0x1ad6b8, Func Offset: 0x838
	// Line 1160, Address: 0x1ad6c0, Func Offset: 0x840
	// Line 1161, Address: 0x1ad6cc, Func Offset: 0x84c
	// Line 1162, Address: 0x1ad6d0, Func Offset: 0x850
	// Line 1163, Address: 0x1ad6d4, Func Offset: 0x854
	// Line 1166, Address: 0x1ad6d8, Func Offset: 0x858
	// Line 1176, Address: 0x1ad6e0, Func Offset: 0x860
	// Line 1178, Address: 0x1ad6f8, Func Offset: 0x878
	// Line 1181, Address: 0x1ad70c, Func Offset: 0x88c
	// Line 1182, Address: 0x1ad71c, Func Offset: 0x89c
	// Line 1183, Address: 0x1ad73c, Func Offset: 0x8bc
	// Line 1185, Address: 0x1ad74c, Func Offset: 0x8cc
	// Line 1184, Address: 0x1ad750, Func Offset: 0x8d0
	// Line 1185, Address: 0x1ad754, Func Offset: 0x8d4
	// Line 1187, Address: 0x1ad758, Func Offset: 0x8d8
	// Line 1188, Address: 0x1ad79c, Func Offset: 0x91c
	// Line 1193, Address: 0x1ad7a4, Func Offset: 0x924
	// Line 1194, Address: 0x1ad7b4, Func Offset: 0x934
	// Line 1195, Address: 0x1ad7bc, Func Offset: 0x93c
	// Line 1199, Address: 0x1ad7c4, Func Offset: 0x944
	// Line 1200, Address: 0x1ad7d4, Func Offset: 0x954
	// Line 1201, Address: 0x1ad820, Func Offset: 0x9a0
	// Line 1202, Address: 0x1ad87c, Func Offset: 0x9fc
	// Line 1203, Address: 0x1ad88c, Func Offset: 0xa0c
	// Line 1204, Address: 0x1ad890, Func Offset: 0xa10
	// Line 1206, Address: 0x1ad894, Func Offset: 0xa14
	// Line 1212, Address: 0x1ad89c, Func Offset: 0xa1c
	// Line 1214, Address: 0x1ad8ac, Func Offset: 0xa2c
	// Line 1217, Address: 0x1ad8b0, Func Offset: 0xa30
	// Line 1213, Address: 0x1ad8b4, Func Offset: 0xa34
	// Line 1217, Address: 0x1ad8bc, Func Offset: 0xa3c
	// Line 1222, Address: 0x1ad8d8, Func Offset: 0xa58
	// Line 1223, Address: 0x1ad930, Func Offset: 0xab0
	// Line 1225, Address: 0x1ad950, Func Offset: 0xad0
	// Line 1226, Address: 0x1ad968, Func Offset: 0xae8
	// Line 1228, Address: 0x1ad970, Func Offset: 0xaf0
	// Line 1235, Address: 0x1ad984, Func Offset: 0xb04
	// Line 1236, Address: 0x1ad994, Func Offset: 0xb14
	// Line 1237, Address: 0x1ad9d8, Func Offset: 0xb58
	// Line 1238, Address: 0x1ad9e8, Func Offset: 0xb68
	// Line 1245, Address: 0x1ada30, Func Offset: 0xbb0
	// Line 1247, Address: 0x1ada58, Func Offset: 0xbd8
	// Line 1246, Address: 0x1ada5c, Func Offset: 0xbdc
	// Line 1247, Address: 0x1ada60, Func Offset: 0xbe0
	// Line 1249, Address: 0x1ada64, Func Offset: 0xbe4
	// Line 1250, Address: 0x1adaa8, Func Offset: 0xc28
	// Line 1254, Address: 0x1adab0, Func Offset: 0xc30
	// Line 1256, Address: 0x1adad0, Func Offset: 0xc50
	// Line 1257, Address: 0x1adae0, Func Offset: 0xc60
	// Line 1259, Address: 0x1adae8, Func Offset: 0xc68
	// Line 1260, Address: 0x1adb04, Func Offset: 0xc84
	// Line 1267, Address: 0x1adb08, Func Offset: 0xc88
	// Line 1272, Address: 0x1adbd0, Func Offset: 0xd50
	// Line 1273, Address: 0x1adbdc, Func Offset: 0xd5c
	// Line 1275, Address: 0x1adbe4, Func Offset: 0xd64
	// Line 1273, Address: 0x1adbe8, Func Offset: 0xd68
	// Line 1274, Address: 0x1adbf0, Func Offset: 0xd70
	// Line 1275, Address: 0x1adbf4, Func Offset: 0xd74
	// Line 1277, Address: 0x1adbf8, Func Offset: 0xd78
	// Line 1278, Address: 0x1adc00, Func Offset: 0xd80
	// Line 1279, Address: 0x1adc10, Func Offset: 0xd90
	// Line 1281, Address: 0x1adc18, Func Offset: 0xd98
	// Line 1279, Address: 0x1adc1c, Func Offset: 0xd9c
	// Line 1280, Address: 0x1adc24, Func Offset: 0xda4
	// Line 1281, Address: 0x1adc28, Func Offset: 0xda8
	// Line 1283, Address: 0x1adc2c, Func Offset: 0xdac
	// Line 1284, Address: 0x1adc34, Func Offset: 0xdb4
	// Line 1286, Address: 0x1adc3c, Func Offset: 0xdbc
	// Line 1284, Address: 0x1adc40, Func Offset: 0xdc0
	// Line 1285, Address: 0x1adc48, Func Offset: 0xdc8
	// Line 1286, Address: 0x1adc4c, Func Offset: 0xdcc
	// Line 1287, Address: 0x1adc50, Func Offset: 0xdd0
	// Line 1290, Address: 0x1adc54, Func Offset: 0xdd4
	// Line 1291, Address: 0x1adc98, Func Offset: 0xe18
	// Line 1295, Address: 0x1adca0, Func Offset: 0xe20
	// Line 1296, Address: 0x1adcf4, Func Offset: 0xe74
	// Line 1297, Address: 0x1add04, Func Offset: 0xe84
	// Line 1299, Address: 0x1add0c, Func Offset: 0xe8c
	// Line 1297, Address: 0x1add10, Func Offset: 0xe90
	// Line 1298, Address: 0x1add18, Func Offset: 0xe98
	// Line 1299, Address: 0x1add1c, Func Offset: 0xe9c
	// Line 1301, Address: 0x1add20, Func Offset: 0xea0
	// Line 1306, Address: 0x1add68, Func Offset: 0xee8
	// Func End, Address: 0x1add8c, Func Offset: 0xf0c
	scePrintf("bhEne05_BR00 - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne05_BR01(void)
{

}

// 100% matching!
void bhEne05_BR02(BH_PWORK* epw)
{
    epw->mode0 = 1;
    epw->mode1 = 0;
    epw->mode2 = 0;
    epw->mode3 = 0;
}

// 100% matching!
void bhEne05_Move(BH_PWORK* epw) 
{
    bhEne05_SearchPlayer(epw);
    if (epw->mode1 == 1)
    {
        bhEne05_Brain(epw);
    }

    if ((epw->flg & 4) && !(epw->flg & 2))
    {
        bhEne05_InitDamage(epw);
        EXP0_UC(0x14) = 1;
        epw->flg &= ~4;
        epw->flg &= ~0x40000000;
        EXP0_I(0x78) = 0;
    }

    switch (epw->mode0)
    {
    case 1:
        bhEne05_MoveMode2[epw->mode2](epw);
        break;
        
    case 3:
        bhEne05_DamageMode2[epw->mode2](epw);
        break;
        
    case 4:
        bhEne05_DeadMode2[epw->mode2](epw);
        break;
    }
}

// 100% matching!
void bhEne05_MV00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        if (epw->mtn_no != 3)
        {
            epw->frm_no = 0;
            epw->mtn_no = 3;
            epw->hokan_count = 20;
            epw->hokan_rate = 45875;
            epw->mtn_md &= ~2;
        }
        epw->mtn_add = 65536;
        epw->ct0 = 30;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne05_MV01(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_POINT3 n;
	NJS_POINT3 local_n;
	float rate;    
	float dist;
	float dist2;
	NJS_POINT3 pos2;
	int ang;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        if (epw->mtn_no != 0)
        {
            if (epw->mtn_no == 34) 
            {
                epw->mtn_no = 0;
                epw->hokan_count = 10;
                epw->hokan_rate = 32768;
                epw->frm_no = 0;
            } 
            else 
            {
                epw->mtn_no = 0;
                epw->hokan_count = 10;
                epw->hokan_rate = 32768;
                if (epw->mtn_md & 2)
                {
                    epw->frm_no = 3014656;
                } 
                else
                {
                    epw->frm_no = 983040;
                }
            }
        }
        epw->mtn_md &= ~2;
        epw->mtn_add = 65536;
        epw->ct0 = (int)(100.0f * njRandom()) + 200;
        epw->ct1 = 0;
        epw->ct2 = 0;
        epw->spd = 0.3f;
        epw->mode3++;

    case 1:
        bhEne_AddNullTrans(epw, hu_001);
        if (EXP0_UC(0x14) != 0)
        {
            if ((unsigned char)(bhCheckRoute((NJS_VECTOR*)&epw->px, (NJS_VECTOR*)&plp->px, &pos)) != 255)
            {
                EXP0_F(0x8) = pos.x;
                EXP0_F(0x10) = pos.z;
            } 
            else
            {
                EXP0_F(0x8) = plp->px;
                EXP0_F(0x10) = plp->pz;
            }

            epw->ay += bhEne_DirTarget(epw, EXP0_F(0x8), EXP0_F(0x10), 0x222);
        } 
        else
        {
            pos.x = epw->px - (50.0f * njSin(epw->ay));
            pos.y = epw->py;
            pos.z = epw->pz - (50.0f * njCos(epw->ay));
            if (bhCollisionCheckLine((NJS_VECTOR*)&epw->px, &pos) != NULL) 
            {
                if (epw->ct1 == 0)
                {
                    bhGetHitCollisionNormal(&n);
                    njUnitVector(&n);
                    njUnitMatrix(NULL);
                    njRotateY(NULL, -epw->ay);
                    njCalcVector(NULL, &n, &local_n);
                    
                    if ((int)(10430.381f * acosf(local_n.z)) > 5461)
                    {
                        ang = (local_n.x > 0.0f) ? -1 : 1;
                    } 
                    else
                    {
                        njAddVector(&pos, &n);
                        pos2.x = pos.x + (100.0f * n.z);
                        pos2.z = pos.z - (100.0f * n.x);
                        bhCollisionCheckLine(&pos, &pos2);
                        dist = njSqrt((pos.x - pos2.x) * (pos.x - pos2.x) + (pos.z - pos2.z) * (pos.z - pos2.z));
                        pos2.x = pos.x - (100.0f * n.z);
                        pos2.z = pos.z + (100.0f * n.x);
                        bhCollisionCheckLine(&pos, &pos2);
                
                        if (dist > njSqrt((pos.x - pos2.x) * (pos.x - pos2.x) + (pos.z - pos2.z) * (pos.z - pos2.z)))
                        {
                            ang = -1;
                        }
                        else
                        {
                            ang = 1;
                        }
                    }
                    epw->ct1 = ang;
                }
                
                dist = njSqrt((epw->px - pos.x) * (epw->px - pos.x) + (epw->pz - pos.z) * (epw->pz - pos.z));
                if (dist > 0.0f)
                {
                    rate = 10.0f / dist;
                }
                
                if (rate > 1.0f)
                {
                    rate = 1.0f;
                }
                
                epw->ay = (int)(epw->ay + (rate * (epw->ct1 * 273)));
                epw->ct2 = 0;
            } 
            else
            {
                pos.x = epw->px - (15.0f * njSin(epw->ay));
                pos.y = epw->py;
                pos.z = epw->pz - (15.0f * njCos(epw->ay));
                if (bhCheckWallType((NJS_POINT3*)&pos, 0, epw->ar, 20.0f) != NULL)
                {
                    epw->ay += epw->ct1 * 546;
                    epw->ct2 = 0;
                } 
                else
                {
                    epw->ct2++;
                    if (epw->ct2 > 30)
                    {
                        epw->ct1 = 0;
                    }
                }
            }
        }

        if ((EXP0_UC(0x14) != 0) && (EXP0_F(0x0) < 20.0f) && (epw->flr_no == plp->flr_no))
        {
            epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 1638);
        }

        if (epw->ct0 != 0)
        {
            epw->ct0--;
            break;
        }
        
        epw->ct1 = 0;
        epw->ct0 = 60;
        
        if (EXP0_UC(0x14) == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 0;
            epw->mode3 = 0;
        }

    }
}

// 100% matching!
void bhEne05_MV02(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        if (epw->mtn_no != 1)
        {
            if (epw->mtn_no == 0)
            {
                epw->frm_no = (epw->frm_no / 3) & 0xFFFF0000;
            } 
            else
            {
                epw->frm_no = 655360;
            }
            epw->mtn_no = 1;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
        }
        epw->mtn_md &= ~2;
        epw->mtn_add = 65536;
        epw->spd = 1.2f;
        epw->ayp = epw->ay;
        epw->ct0 = 30;
        epw->mode3++;

    case 1:
        bhAddSpeed(epw, 0);
        
        if ((bhCheckRoute((NJS_POINT3*)&epw->px, (NJS_POINT3*)&plp->px, &pos)) != 0xFF) 
        {
            EXP0_F(0x8) = pos.x;
            EXP0_F(0x10) = pos.z;
        } 
        else
        {
            EXP0_F(0x8) = plp->px;
            EXP0_F(0x10) = plp->pz;
        }
        
        if ((EXP0_UC(0x14) != 0) && ((bhSearchPlayer(epw, 5461) == -1) || (bhEne05_CheckPlyRoute(epw) == 0)))
        {
            epw->ayp = epw->ay + bhEne_DirTarget(epw, EXP0_F(0x8), EXP0_F(0x10), 21845);
            epw->ay += ((short)(epw->ayp - epw->ay) / 4);
        } 
        else
        {
            epw->ay += bhEne_DirTarget(epw, EXP0_F(0x8), EXP0_F(0x10), 546);
        }

        if (epw->ct0 != 0)
        {
            epw->ct0--;
        }
        else if (EXP0_F(0x0) < 15.0f)
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne05_MV03(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        if (epw->mtn_no == 1) 
        {
            epw->mtn_no = 29;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
        }
        
        if (epw->mtn_no == 0)
        {
            if ((epw->frm_no >= 524288) && (epw->frm_no < 1966081))
            {
                epw->mtn_no = 29;
                epw->frm_no = (((epw->frm_no - 524288) * 5) / 22 & 0xFFFF0000U) + 65536;
                epw->hokan_count = 4;
                epw->hokan_rate = 32768;
            }
        } 
        else
        {
            epw->mtn_no = 29;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
        }
        
        epw->ct0 = (epw->mnwP[epw->mtn_no].frm_num - (epw->frm_no / 65536)) - 1;
        epw->ct1 = 0;
        epw->mtn_add = 65536;
        epw->mode3++;
        epw->spd = 1.2f;

    case 1:
        if (epw->frm_no < 983040)
        {
            bhAddSpeed(epw, 0);
            epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 1638);
            epw->ayp = epw->ay;
            bhEne05_DustEffect(epw, 0);
        } 
        else if (epw->frm_no < 1638400)
        {
            epw->spd *= 0.9f;
            epw->px -= epw->spd * njSin(epw->ayp);
            epw->pz -= epw->spd * njCos(epw->ayp);
            epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 273);
        }
        
        if (!(plp->flg & 4))
        {
            if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000))
            {
                if ((epw->frm_no >= 917504) && (epw->frm_no < 1114113)) 
                {
                    bhEne_GetPartsPos(epw, joint_tree[3], &pos);
                    if (bhEne_AttackHitCheck(plp, &pos, 5.0f))
                    {
                        bhEne_SetBloodEffectBurst(plp, 1, plp->djnt_no, (NJS_POINT3*)&plp->dpx, 1);
                        plp->hp -= 20;
                        if ((epw->mdlver == 1) && (njRandom() < 0.4f))
                        {
                            plp->stflg |= 0x80000;
                        }
                        
                        if (plp->hp >= 0)
                        {
                            plp->flg |= 0x10004;
                            plp->stflg |= 0x10000;
                            plp->mode0 = 2;
                            if (abs((short)(epw->ay - plp->ay)) > NJM_DEG_ANG(90.0f))
                            {
                                plp->mode1 = 0;
                            } 
                            else
                            {
                                plp->mode1 = 1;
                            }
                            
                            plp->mode2 = 0;
                            plp->mode3 = 0;
                        }
                        epw->ct1 = 1;
                    }
                }
            }
        }

        if (epw->ct0-- == 0) 
        {
            epw->flg &= ~0x40000000;
            if (epw->ct1 != 0) 
            {
                epw->mode1 = 1;
                epw->mode2 = 16;
                epw->mode3 = 0;
                epw->mtn_no = 7;
                epw->hokan_count = 60;
                epw->hokan_rate = 52428;
                epw->frm_no = 0;
                epw->mtn_add = 65536;
            } 
            else
            {
                epw->mode1 = 1;
                epw->mode2 = 2;
                epw->mode3 = 0;
                epw->mtn_no = 1;
                epw->frm_no = 0;
                epw->hokan_count = 10;
                epw->hokan_rate = 45875;
            }           
        } 
    }
}

// 100% matching!
void bhEne05_MV04(void)
{

}

// 100% matching!
void bhEne05_MV05(BH_PWORK* epw)
{
    NJS_POINT3 pos;
	float dist;

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->flg &= ~0x20;
        epw->mtn_no = 30;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flr_no = -128;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;
        epw->xn = EXP0_F(0x68);
        epw->zn = EXP0_F(0x70);
        epw->ayp = bhArcTan2(epw->px - epw->xn, epw->pz - epw->zn);

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 16;
        if (epw->ct0-- == 0)
        {
            epw->flg |= 0x20;
            epw->flg &= ~0x40000;
            epw->mtn_no = 31;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flg &= ~0x2000000;
            epw->mtn_add = 65536;
            dist = njSqrt((epw->xn - epw->px) * (epw->xn - epw->px) + (epw->zn - epw->pz) * (epw->zn - epw->pz));
            EXP0_F(0x1C) = (dist * -njSin(epw->ayp)) / 18.0f;
            EXP0_F(0x20) = 3.4f;
            EXP0_F(0x24) = (dist * -njCos(epw->ayp)) / 18.0f;
        }
        break;
        
    case 2:
        if (epw->flg & 0x2000000)
        {
            epw->mtn_no = 32;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 4;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
        }
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.5f;

            if (epw->ct0-- == 0)
            {
                epw->mtn_add = 0;
            }
        }
        
        if (!(plp->flg & 4))
        {
            if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000) && (epw->frm_no >= 786432))
            {
                bhEne_GetPartsPos(epw, joint_tree[3], &pos);
                if (bhEne_AttackHitCheck(plp, &pos, 5.0f))
                {
                    bhEne_SetBloodEffectBurst(plp, 3, plp->djnt_no, (NJS_POINT3*)&plp->dpx, 1);
                    plp->flg |= 0x10004;
                    plp->stflg |= 0x10000;
                    plp->hp -= 50;
                    
                    if ((epw->mdlver == 1) && (njRandom() < 0.4f))
                    {
                        plp->stflg |= 0x80000;
                    }
                    
                    if (plp->hp < 0)
                    {
                        *(int*)plp->exp1 &= ~1;
                        plp->mlwP->texP = plp->txp[2];
                        epw->flg |= 0x8000000;
                    } 
                    else
                    {
                        plp->flg |= 0x10004;
                        plp->stflg |= 0x10000;
                        plp->mode0 = 2;
                        
                        if (abs((short)(epw->ay - plp->ay)) > NJM_DEG_ANG(90.0f))
                        {
                            plp->mode1 = 0;
                        } 
                        else
                        {
                            plp->mode1 = 1;
                        }
                        plp->mode2 = 2;
                        plp->mode3 = 0;
                    }
                }
            }
        }
        break;
        
    case 3:
        epw->px += EXP0_F(0x1C);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x1C) *= 0.7f;
        EXP0_F(0x24) *= 0.7f;
        
        if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
        {
            bhEne05_DustEffect(epw, 0);
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_md &= ~2;
            epw->flg &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne05_MV06(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0: 
        if (epw->mtn_no == 0) 
        {
            epw->flg |= 0x40000;
            epw->frm_no = 458752;
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x24) = 0.0f;
        } 
        else if (epw->mtn_no == 1) 
        {
            epw->flg &= ~0x40000;
            epw->frm_no = 458752;
            EXP0_F(0x1C) = (epw->spd * -njSin(epw->ay));
            EXP0_F(0x24) = (epw->spd * -njCos(epw->ay));
        } 
        else if (epw->mtn_no == 7) 
        {
            epw->flg |= 0x40000;
            epw->frm_no = 1441792;
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x24) = 0.0f;
        } 
        else 
        {
            epw->flg |= 0x40000;
            epw->frm_no = 0;
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x24) = 0.0f;
        }
        
        epw->mtn_no = 33;
        epw->mtn_add = 65536;
        epw->hokan_count = 5;
        epw->hokan_rate = 39321;
        epw->mode3++;
        break;
        
    case 1:
        if (epw->frm_no < 1310721)
        {
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x1C) *= 0.93f;
            EXP0_F(0x24) *= 0.93f;
            epw->ayp = bhArcTan2(epw->px - plp->px, epw->pz - plp->pz);
            epw->ay += (short)(epw->ayp - epw->ay) / 16;
            if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f))
            {
                bhEne05_DustEffect(epw, 0);
            }
        } 
        else
        {
            epw->flg |= 0x40000;
        }
        
        if (!(plp->flg & 4))
        {
            if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000))
            {
                if ((epw->frm_no >= 1966080) && (epw->frm_no < 2097153))
                {
                    bhEne_GetPartsPos(epw, joint_tree[3], &pos);
                    if (bhEne_AttackHitCheck(plp, &pos, 5.0f))
                    {
                        bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74508);
                        bhEne_SetBloodEffectBurst(plp, 3, plp->djnt_no, (NJS_POINT3*)&plp->dpx, 1);
                        plp->flg |= 0x10004;
                        plp->stflg |= 0x10000;
                        plp->hp = -1;
                        plp->mode0 = 3;
                        if (abs((short)(epw->ay - plp->ay)) > NJM_DEG_ANG(90.0f))
                        {
                            plp->mode1 = 1;
                        } 
                        else
                        {
                            plp->mode1 = 0;
                        }
                        plp->mode2 = 0;
                        plp->mode3 = 0;
                        *(unsigned int*)plp->exp1 &= ~1;
                        plp->mlwP->texP = plp->txp[2];
                        epw->flg |= 0x8000000;
                    }
                }
            }
        }
        
        if (epw->frm_no == 0)
        {
            if (plp->hp < 0)
            {
                epw->mtn_no = 35;
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
                epw->mode3++;
            } 
            else
            {
                epw->mtn_no = 34;
                epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
                epw->mode3++;
            }
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne05_MV07(BH_PWORK* epw)
{
	float h;
	float t;   
	float dist;

    switch (epw->mode3)
    {
    case 0:
        if (EXP0_I(0x74) != 0)
        {
            if (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x21) < 8)
            {
                rom->etcp[*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x22)].attr |= 0x400000;
                rom->etcp[*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x23)].attr |= 0x400000;
            }
        }
        epw->flr_no = -128;
        epw->flg &= ~0x380000;
        epw->flg |= 0x4040000;
        epw->flg2 |= 1;
        epw->flg &= ~0x20;
        epw->mtn_no = 46;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        epw->ayp = bhArcTan2(epw->px - EXP0_F(0x68), epw->pz - EXP0_F(0x70));

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 16;
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x40000;
            epw->mtn_no = 47;
            epw->frm_no = 0;
            epw->hokan_count = 20;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flg &= ~0x2000000;
            epw->ay = epw->ayp;
            if ((*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x21) >= 0x18) && (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x21) < 33))
            {
                h = 13.0f;
                EXP0_F(0x6C) = (6.0f + epw->py);
            } 
            else
            {
                if (EXP0_F(0x6C) > epw->py)
                {
                    h = (10.0f + EXP0_F(0x6C)) - epw->py;
                } 
                else
                {
                    h = (10.0f + epw->py) - EXP0_F(0x6C);
                }
            }
            
            EXP0_F(0x20) = njSqrt(h);
            t = floorf((EXP0_F(0x20) + njSqrt((EXP0_F(0x20) * EXP0_F(0x20)) - (EXP0_F(0x6C) - epw->py))) / 0.5f);
            if (t < 1.0f)
            {
                t = 1.0f;
            }

            dist = njSqrt((epw->px - EXP0_F(0x68)) * (epw->px - EXP0_F(0x68)) + (epw->pz - EXP0_F(0x70)) * (epw->pz - EXP0_F(0x70)));
            EXP0_F(0x1C) = ((dist * -njSin(epw->ay)) / t);
            EXP0_F(0x24) = ((dist * -njCos(epw->ay)) / t);
            EXP0_F(0x3C) = 0.5f;
            EXP0_F(0x34) = 0.5f;
            EXP0_F(0x44) = 2.0f;
            epw->car = 2.0f;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
        }

        if (epw->flg & 0x2000000)
        {
            epw->flg |= 0x380000;
            EXP0_F(0x40) = 0.1f;
            EXP0_F(0x38) = 0.1f;
            EXP0_F(0x3C) = 5.0f;
            EXP0_F(0x44) = 4.0f;
            epw->flg &= ~0x4000000;
            epw->flg |= 0x20;
            epw->flg2 &= ~1;
            epw->mtn_no = 48;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->mtn_add = 65536;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            epw->py = bhGetGroundPosition((NJS_POINT3*)&epw->px);

            if (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x21) < 8)
            {
                rom->etcp[*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x22)].attr &= ~0x400000;
                rom->etcp[*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x23)].attr &= ~0x400000;
            }
        } 
        else 
        {
            EXP0_F(0x20) -= 0.5f;
            epw->px += EXP0_F(0x1C);            
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
        }
        break;
        
    case 3:
        EXP0_F(0x40) = 2.0f;
        epw->px += EXP0_F(0x1C);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x1C) *= 0.6f;
        EXP0_F(0x24) *= 0.6f;
        
        if (epw->ct0-- == 0)
        {
            if (EXP0_UC(0x14) != 0)
            {
                epw->mode2 = 2;
            } 
            else
            {
                epw->mode2 = 0;
            }
            
            epw->mode1 = 1;
            epw->mode3 = 0;
            EXP0_F(0x34) = 5.0f;
            EXP0_F(0x38) = 2.0f;
            epw->car = 4.0f;
        }
    }
}

// 100% matching!
void bhEne05_MV08(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->flg |= 0x40000;
        epw->mtn_no = 8;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flr_no = -128;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 9;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            epw->mode3++;
            epw->flg &= ~0x40000;
            epw->flg &= ~0x2000000;
            EXP0_F(0x1C) = 0.0f;
            EXP0_F(0x20) = 7.0f;
            EXP0_F(0x24) = 0.0f;
        }
        break;
        
    case 2:
        if (epw->flg & 0x2000000)
        {
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.5f;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            if (EXP0_UC(0x14) != 0)
            {
                epw->mode2 = 2;
            } 
            else
            {
                epw->mode2 = 0;
            }
            epw->mode1 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne05_MV09(BH_PWORK* epw)
{
    float dist;

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->flg &= ~0x20;
        epw->mtn_no = 8;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flr_no = -128;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->mode3++;        
        epw->xn = EXP0_F(0x68);
        epw->zn = EXP0_F(0x70);
        epw->ayp = bhArcTan2(epw->px - epw->xn, epw->pz - epw->zn);

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 16;
        if (epw->ct0-- == 0)
        {
            epw->flg |= 0x20;
            epw->flg &= ~0x40000;
            epw->mtn_no = 9;
            epw->frm_no = 0;
            epw->hokan_count = 0;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flg &= ~0x2000000;
            epw->mtn_add = 65536;

            dist = njSqrt(((epw->xn - epw->px) * (epw->xn - epw->px)) + ((epw->zn - epw->pz) * (epw->zn - epw->pz)));
            EXP0_F(0x1C) = (dist * -njSin(epw->ayp)) / 20.0f;
            EXP0_F(0x20) = 4.4f;
            EXP0_F(0x24) = (dist * -njCos(epw->ayp)) / 20.0f;
        }
        break;
        
    case 2:
        if (epw->flg & 0x2000000)
        {
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 4;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3 += 1;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            break;
        }
        epw->px += EXP0_F(0x1C);
        epw->py += EXP0_F(0x20);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x20) -= 0.5f;
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
        }
        break;
        
    case 3:
        epw->px += EXP0_F(0x1C);
        epw->pz += EXP0_F(0x24);
        EXP0_F(0x1C) *= 0.7f;
        EXP0_F(0x24) *= 0.7f;
        if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
        {
            bhEne05_DustEffect(epw, 0);
        }
        
        if (epw->ct0-- == 0)
        {
            epw->mtn_md &= ~2;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
        break;
    }
}

// 100% matching!
void bhEne05_MV10(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 9;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        epw->flg &= ~0x2000000;
        EXP0_F(0x1C) = 0.0f;
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 0.0f;

    case 1:
        if (epw->flg & 0x2000000)
        {
            epw->mtn_no = 11;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
        } 
        else
        {
            epw->px += EXP0_F(0x1C);
            epw->py += EXP0_F(0x20);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x20) -= 0.5f;            
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            EXP0_UC(0x14) = 1;
        }

    }
}

// 100% matching!
void bhEne05_MV11(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->mtn_no = 35;
        epw->frm_no = 4456448;
        epw->hokan_count = 60;
        epw->hokan_rate = 58982;
        epw->mtn_add = 65536;
        epw->mode3++;
        break;
        
    case 1:
        if (epw->frm_no == 9175040)
        {
            epw->frm_no = 4456448;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
        }
    }
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne05_MV12(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY_F_MOD* mkfP;
    NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x20000000;
        epw->flg &= ~0x2000000;
        epw->flr_no = -128;
        epw->flg &= ~0x380000;
        epw->flg &= ~0x40010;
        epw->flg |= 0x4000000;
        epw->flg |= 0x10000000;

        if (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x22) == 0)
        {
            epw->mtn_no = 44;
        } 
        else
        {
            epw->mtn_no = 49;
        }

        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 45875;
        epw->mtn_add = 65536;
        epw->mtn_md &= ~2;
        epw->mode3++;
        epw->ct0 = 8;
        break;
        
    case 1:
        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px += (EXP0_F(0x68) - epw->px) / epw->ct0;
            epw->pz += (EXP0_F(0x70) - epw->pz) / epw->ct0;
            epw->ct0--;
        }
        
        if (epw->mtn_no == 44)
        {
            if (epw->frm_no == 917504) 
            {
                epw->flg &= ~0x20;
                EXP0_F(0x44) = 2.0f;
                epw->car = 2.0f;
            }
            if (epw->frm_no == 2162688)
            {
                epw->flg |= 0x20;
                EXP0_F(0x44) = 4.0f;
            }
        }
        
        if (epw->mtn_no == 0x31)
        {
            if (epw->frm_no == 655360)
            {
                epw->flg &= ~0x20;
                EXP0_F(0x44) = 2.0f;
                epw->car = 2.0f;
            }
            if (epw->frm_no == 2293760)
            {
                epw->flg |= 0x20;
                EXP0_F(0x44) = 4.0f;
            }
        }
        
        if (epw->frm_no == 0)
        {
            bhEne_GetPartsPos(epw, joint_tree[0], &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            epw->flg |= 0x20;
            epw->mtn_no = 3;
            epw->mode1 = 1;
            
            if (EXP0_UC(0x14) != 0)
            {
                epw->mode2 = 2;
            } 
            else 
            {
                epw->mode2 = 0;
            }
            
            epw->mode3 = 0;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            epw->pxb = epw->px;
            epw->pzb = epw->pz;

            if (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x22) == 0)
            {

                epw->pyb = epw->py = 9.1f + EXP0_F(0x6C);
            } 
            else
            {
                epw->pyb = epw->py = 25.1f + EXP0_F(0x6C);
            }

            epw->flg |= 0x380000;
            epw->flg |= 0x40030;
            epw->flg |= 0x2000000;
            epw->flg &= ~0x4000000;
            epw->flg &= ~0x10000000;
            epw->flg &= ~0x20000000;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            epw->py = bhGetGroundPosition((NJS_POINT3*)&epw->px);
        }
    }
}

// 100% matching!
void bhEne05_MV13(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_MKEY_F_MOD* mkfP;
    NJS_VECTOR trans;

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x20000000;
        epw->flg &= ~0x2000000;
        epw->flr_no = -128;
        epw->flg &= ~0x380000;
        epw->flg &= ~0x40010;
        epw->flg |= 0x4000000;
        epw->flg |= 0x10000000;

        if (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x22) == 0)
        {
            epw->mtn_no = 45;
        } 
        else
        {
            epw->mtn_no = 50;
        }

        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 45875;
        epw->mtn_add = 65536;
        epw->mtn_md &= ~2;
        epw->mode3++;
        epw->ct0 = 8;
        break;
        
    case 1:
        if (epw->ct0 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct0;
            epw->px += (EXP0_F(0x68) - epw->px) / epw->ct0;
            epw->pz += (EXP0_F(0x70) - epw->pz) / epw->ct0;
            epw->ct0--;
        }
        
        if (epw->mtn_no == 45)
        {
            if (epw->frm_no == 983040)
            {
                epw->flg &= ~0x20;
            }
            if (epw->frm_no == 1966080)
            {
                epw->flg |= 0x20;
            }
        }
        
        if (epw->mtn_no == 50) 
        {
            if (epw->frm_no == 983040)
            {
                epw->flg &= ~0x20;
            }
            if (epw->frm_no == 2228224) 
            {
                epw->flg |= 0x20;
            }
        }
        
        if (epw->frm_no == 0)
        {
            bhEne_GetPartsPos(epw, joint_tree[0], &pos);
            epw->px = pos.x;
            epw->py = pos.y;
            epw->pz = pos.z;
            epw->flg |= 0x2000000;
            epw->flg |= 0x20;
            epw->mtn_no = 3;
            epw->mode1 = 1;
            
            if (EXP0_UC(0x14) != 0)
            {
                epw->mode2 = 2;
            } 
            else 
            {
                epw->mode2 = 0;
            }
            
            epw->mode3 = 0;
            mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
            trans.x = mkfP->key[0];
            trans.y = mkfP->key[1];
            trans.z = mkfP->key[2];
            njUnitMatrix(NULL);
            njRotateY(NULL, epw->ay);
            njCalcVector(NULL, &trans, &trans);
            epw->px -= trans.x;
            epw->py -= trans.y;
            epw->pz -= trans.z;
            epw->pxb = epw->px;
            epw->pzb = epw->pz;

            if (*(unsigned char *)(*(int *)(epw->exp0 + 0x74) + 0x22) == 0)
            {

                epw->pyb = epw->py = EXP0_F(0x6C) - 8.9f;
            } 
            else
            {
                epw->pyb = epw->py = EXP0_F(0x6C) - 24.9f;
            }

            epw->flg |= 0x380000;
            epw->flg |= 0x40030;
            epw->flg |= 0x2000000;
            epw->flg &= ~0x4000000;
            epw->flg &= ~0x10000000;
            epw->flg &= ~0x20000000;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            epw->py = bhGetGroundPosition((NJS_POINT3*)&epw->px);
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne05_MV14(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->flg |= 0x78;
        epw->mtn_no = 3;
        epw->frm_no = 0;
        epw->hokan_count = 0;
        epw->mtn_md &= ~2;
        epw->mtn_add = 65536;
        epw->py = bhGetGroundPosition((NJS_POINT3*)&epw->px);
        epw->flr_no = bhCheckFloorNum(epw->py);
        epw->mode3++;
    }
}

// 100% matching!
void bhEne05_MV15(BH_PWORK* epw)
{
    NJS_POINT3 pos;

    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->mtn_no = 2;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 0;
        epw->ct2 = 5;
        epw->mtn_add = 65536;
        epw->mode3++;

    case 1:
        if (epw->ct2 != 0)
        {
            epw->ay += bhEne_DirTarget(epw, plp->px, plp->pz, 273);
            epw->ct2--;
        }
        
        if (!(plp->flg & 4))
        {
            if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000)) 
            {
                if ((epw->frm_no >= 786432) && (epw->frm_no < 983041))
                {
                    bhEne_GetPartsPos(epw, joint_tree[3], &pos);
                    if (bhEne_AttackHitCheck(plp, &pos, 5.0f))
                    {
                        bhEne_SetBloodEffectBurst(plp, 1, plp->djnt_no, (NJS_POINT3*)&plp->dpx, 1);
                        plp->hp -= 20;
                        if ((epw->mdlver == 1) && (njRandom() < 0.4f))
                        {
                            plp->stflg |= 0x80000;
                        }

                        if (plp->hp >= 0)
                        {
                            plp->flg |= 0x10004;
                            plp->stflg |= 0x10000;
                            plp->mode0 = 2;
                            if (abs((short)(epw->ay - plp->ay)) > NJM_DEG_ANG(90.0f))
                            {
                                plp->mode1 = 0;
                            } 
                            else 
                            {
                                plp->mode1 = 1;
                            }
                            plp->mode2 = 0;
                            plp->mode3 = 0;
                        }
                        epw->ct1 = 1;
                    }
                }
            }
        }
        
        if ((epw->frm_no == 1703936) && (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 3640) != 0) && ((epw->ct1 != 0) || (EXP0_F(0x0) < 16.0f)))
        {
            epw->flg &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode2 = 16;
            epw->mode3 = 0;
            epw->mtn_no = 7;
            epw->hokan_count = 20;
            epw->hokan_rate = 52428;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
        }

        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            epw->mtn_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 52428;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
        }
    }
}

// 100% matching!
void bhEne05_MV16(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        if (epw->mtn_no != 7)
        {
            epw->frm_no = 0;
            epw->mtn_no = 7;
            epw->hokan_count = 20;
            epw->hokan_rate = 45875;
            epw->mtn_md &= ~2;
        }
        epw->mtn_add = 65536;
        epw->mode3++;
        epw->ct0 = (int)(20.0f * njRandom()) + 20;
        break;
        
    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
        }
    }
}

// 100% matching!
void bhEne05_MV17(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    
    switch (epw->mode3) 
    {
    case 0:
        epw->flg |= 0x40000;
        epw->mtn_no = 10;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 0;
        epw->mtn_add = 65536;
        epw->mode3++;

    case 1:
        if (!(plp->flg & 4))
        {
            if (!(plp->stflg & 0x30) && !(plp->stflg & 0x80000000))
            {
                if ((epw->frm_no >= 786432) && (epw->frm_no < 983041))
                {
                    bhEne_GetPartsPos(epw, joint_tree[3], &pos);
                    if (bhEne_AttackHitCheck(plp, &pos, 5.0f))
                    {
                        bhEne_SetBloodEffectBurst(plp, 1, plp->djnt_no, (NJS_POINT3*)&plp->dpx, 1);
                        plp->hp -= 15;
                        if ((epw->mdlver == 1) && (njRandom() < 0.4f))
                        {
                            plp->stflg |= 0x80000;
                        }
                        
                        if (plp->hp >= 0)
                        {
                            plp->flg |= 0x10004;
                            plp->stflg |= 0x10000;
                            plp->mode0 = 2;
                            if (abs((short)(epw->ay - plp->ay)) > NJM_DEG_ANG(90.0f))
                            {
                                plp->mode1 = 0;
                            } 
                            else
                            {
                                plp->mode1 = 1;
                            }
                            plp->mode2 = 0;
                            plp->mode3 = 0;
                        }
                        epw->ct1 = 1;
                    }
                }
            }
        }
        if ((epw->ct1 != 0) && (epw->frm_no == 1703936) && (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 3640) != 0))
        {
            epw->flg &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode2 = 16;
            epw->mode3 = 0;
            epw->mtn_no = 7;
            epw->hokan_count = 20;
            epw->hokan_rate = 52428;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
        }

        if (epw->ct0-- == 0)
        {
            epw->flg &= ~0x40000000;
            epw->mode1 = 1;
            epw->mode2 = 1;
            epw->mode3 = 0;
            epw->mtn_no = 0;
            epw->hokan_count = 30;
            epw->hokan_rate = 52428;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
        }
    }
}

// 100% matching!
void bhEne05_Nage(void)
{

}

// 
// Start address: 0x1b1ac0
void bhEne05_Damage(BH_PWORK* epw)
{
	unsigned int fno;
	//_anon1* pDS;
	int down;
	// Line 3092, Address: 0x1b1ac0, Func Offset: 0
	// Line 3097, Address: 0x1b1ad8, Func Offset: 0x18
	// Line 3104, Address: 0x1b1af8, Func Offset: 0x38
	// Line 3105, Address: 0x1b1b20, Func Offset: 0x60
	// Line 3106, Address: 0x1b1b3c, Func Offset: 0x7c
	// Line 3112, Address: 0x1b1b4c, Func Offset: 0x8c
	// Line 3113, Address: 0x1b1b5c, Func Offset: 0x9c
	// Line 3115, Address: 0x1b1b60, Func Offset: 0xa0
	// Line 3117, Address: 0x1b1b68, Func Offset: 0xa8
	// Line 3113, Address: 0x1b1b70, Func Offset: 0xb0
	// Line 3117, Address: 0x1b1b74, Func Offset: 0xb4
	// Line 3120, Address: 0x1b1b88, Func Offset: 0xc8
	// Line 3121, Address: 0x1b1ba8, Func Offset: 0xe8
	// Line 3125, Address: 0x1b1bb8, Func Offset: 0xf8
	// Line 3128, Address: 0x1b1bc0, Func Offset: 0x100
	// Line 3125, Address: 0x1b1bc4, Func Offset: 0x104
	// Line 3128, Address: 0x1b1bcc, Func Offset: 0x10c
	// Line 3133, Address: 0x1b1be8, Func Offset: 0x128
	// Line 3135, Address: 0x1b1bf4, Func Offset: 0x134
	// Line 3136, Address: 0x1b1c00, Func Offset: 0x140
	// Line 3137, Address: 0x1b1c04, Func Offset: 0x144
	// Line 3138, Address: 0x1b1c0c, Func Offset: 0x14c
	// Line 3139, Address: 0x1b1c18, Func Offset: 0x158
	// Line 3140, Address: 0x1b1c38, Func Offset: 0x178
	// Line 3141, Address: 0x1b1c3c, Func Offset: 0x17c
	// Line 3142, Address: 0x1b1c40, Func Offset: 0x180
	// Line 3140, Address: 0x1b1c44, Func Offset: 0x184
	// Line 3141, Address: 0x1b1c4c, Func Offset: 0x18c
	// Line 3142, Address: 0x1b1c58, Func Offset: 0x198
	// Line 3143, Address: 0x1b1c5c, Func Offset: 0x19c
	// Line 3144, Address: 0x1b1c60, Func Offset: 0x1a0
	// Line 3146, Address: 0x1b1c64, Func Offset: 0x1a4
	// Line 3147, Address: 0x1b1c6c, Func Offset: 0x1ac
	// Line 3148, Address: 0x1b1c78, Func Offset: 0x1b8
	// Line 3150, Address: 0x1b1c98, Func Offset: 0x1d8
	// Line 3155, Address: 0x1b1c9c, Func Offset: 0x1dc
	// Line 3150, Address: 0x1b1ca0, Func Offset: 0x1e0
	// Line 3151, Address: 0x1b1ca4, Func Offset: 0x1e4
	// Line 3152, Address: 0x1b1cac, Func Offset: 0x1ec
	// Line 3153, Address: 0x1b1cb4, Func Offset: 0x1f4
	// Line 3154, Address: 0x1b1cbc, Func Offset: 0x1fc
	// Line 3155, Address: 0x1b1cc4, Func Offset: 0x204
	// Line 3157, Address: 0x1b1ce0, Func Offset: 0x220
	// Line 3158, Address: 0x1b1d0c, Func Offset: 0x24c
	// Line 3160, Address: 0x1b1d14, Func Offset: 0x254
	// Line 3163, Address: 0x1b1d34, Func Offset: 0x274
	// Line 3166, Address: 0x1b1d3c, Func Offset: 0x27c
	// Line 3167, Address: 0x1b1d40, Func Offset: 0x280
	// Line 3170, Address: 0x1b1d50, Func Offset: 0x290
	// Line 3171, Address: 0x1b1d60, Func Offset: 0x2a0
	// Line 3172, Address: 0x1b1d68, Func Offset: 0x2a8
	// Line 3178, Address: 0x1b1d70, Func Offset: 0x2b0
	// Line 3180, Address: 0x1b1d90, Func Offset: 0x2d0
	// Line 3181, Address: 0x1b1d94, Func Offset: 0x2d4
	// Line 3182, Address: 0x1b1d9c, Func Offset: 0x2dc
	// Line 3183, Address: 0x1b1da8, Func Offset: 0x2e8
	// Line 3185, Address: 0x1b1dc8, Func Offset: 0x308
	// Line 3186, Address: 0x1b1dcc, Func Offset: 0x30c
	// Line 3184, Address: 0x1b1dd4, Func Offset: 0x314
	// Line 3185, Address: 0x1b1dd8, Func Offset: 0x318
	// Line 3186, Address: 0x1b1ddc, Func Offset: 0x31c
	// Line 3187, Address: 0x1b1df8, Func Offset: 0x338
	// Line 3192, Address: 0x1b1dfc, Func Offset: 0x33c
	// Line 3187, Address: 0x1b1e00, Func Offset: 0x340
	// Line 3188, Address: 0x1b1e04, Func Offset: 0x344
	// Line 3189, Address: 0x1b1e0c, Func Offset: 0x34c
	// Line 3190, Address: 0x1b1e14, Func Offset: 0x354
	// Line 3191, Address: 0x1b1e1c, Func Offset: 0x35c
	// Line 3192, Address: 0x1b1e24, Func Offset: 0x364
	// Line 3194, Address: 0x1b1e40, Func Offset: 0x380
	// Line 3195, Address: 0x1b1e6c, Func Offset: 0x3ac
	// Line 3197, Address: 0x1b1e74, Func Offset: 0x3b4
	// Line 3200, Address: 0x1b1e94, Func Offset: 0x3d4
	// Line 3203, Address: 0x1b1e9c, Func Offset: 0x3dc
	// Line 3204, Address: 0x1b1ea0, Func Offset: 0x3e0
	// Line 3205, Address: 0x1b1eac, Func Offset: 0x3ec
	// Line 3207, Address: 0x1b1eb0, Func Offset: 0x3f0
	// Line 3209, Address: 0x1b1ecc, Func Offset: 0x40c
	// Line 3211, Address: 0x1b1edc, Func Offset: 0x41c
	// Line 3212, Address: 0x1b1ee8, Func Offset: 0x428
	// Line 3214, Address: 0x1b1ef0, Func Offset: 0x430
	// Line 3213, Address: 0x1b1ef4, Func Offset: 0x434
	// Line 3214, Address: 0x1b1ef8, Func Offset: 0x438
	// Line 3215, Address: 0x1b1efc, Func Offset: 0x43c
	// Line 3216, Address: 0x1b1f04, Func Offset: 0x444
	// Line 3217, Address: 0x1b1f0c, Func Offset: 0x44c
	// Line 3218, Address: 0x1b1f14, Func Offset: 0x454
	// Line 3219, Address: 0x1b1f18, Func Offset: 0x458
	// Line 3217, Address: 0x1b1f1c, Func Offset: 0x45c
	// Line 3218, Address: 0x1b1f38, Func Offset: 0x478
	// Line 3220, Address: 0x1b1f3c, Func Offset: 0x47c
	// Line 3222, Address: 0x1b1f50, Func Offset: 0x490
	// Line 3223, Address: 0x1b1f5c, Func Offset: 0x49c
	// Line 3225, Address: 0x1b1f64, Func Offset: 0x4a4
	// Line 3224, Address: 0x1b1f68, Func Offset: 0x4a8
	// Line 3225, Address: 0x1b1f6c, Func Offset: 0x4ac
	// Line 3226, Address: 0x1b1f70, Func Offset: 0x4b0
	// Line 3227, Address: 0x1b1f78, Func Offset: 0x4b8
	// Line 3228, Address: 0x1b1f80, Func Offset: 0x4c0
	// Line 3229, Address: 0x1b1f88, Func Offset: 0x4c8
	// Line 3230, Address: 0x1b1f8c, Func Offset: 0x4cc
	// Line 3228, Address: 0x1b1f90, Func Offset: 0x4d0
	// Line 3229, Address: 0x1b1fac, Func Offset: 0x4ec
	// Line 3231, Address: 0x1b1fb0, Func Offset: 0x4f0
	// Line 3232, Address: 0x1b1fc4, Func Offset: 0x504
	// Line 3234, Address: 0x1b1fcc, Func Offset: 0x50c
	// Line 3233, Address: 0x1b1fd0, Func Offset: 0x510
	// Line 3234, Address: 0x1b1fd4, Func Offset: 0x514
	// Line 3235, Address: 0x1b1fd8, Func Offset: 0x518
	// Line 3236, Address: 0x1b1fe0, Func Offset: 0x520
	// Line 3237, Address: 0x1b1fe8, Func Offset: 0x528
	// Line 3239, Address: 0x1b1ff0, Func Offset: 0x530
	// Line 3237, Address: 0x1b1ff4, Func Offset: 0x534
	// Line 3238, Address: 0x1b2010, Func Offset: 0x550
	// Line 3240, Address: 0x1b2014, Func Offset: 0x554
	// Line 3241, Address: 0x1b2028, Func Offset: 0x568
	// Line 3243, Address: 0x1b2030, Func Offset: 0x570
	// Line 3242, Address: 0x1b2034, Func Offset: 0x574
	// Line 3243, Address: 0x1b2038, Func Offset: 0x578
	// Line 3244, Address: 0x1b203c, Func Offset: 0x57c
	// Line 3245, Address: 0x1b2044, Func Offset: 0x584
	// Line 3246, Address: 0x1b204c, Func Offset: 0x58c
	// Line 3247, Address: 0x1b2054, Func Offset: 0x594
	// Line 3248, Address: 0x1b2058, Func Offset: 0x598
	// Line 3246, Address: 0x1b205c, Func Offset: 0x59c
	// Line 3247, Address: 0x1b2078, Func Offset: 0x5b8
	// Line 3248, Address: 0x1b207c, Func Offset: 0x5bc
	// Line 3252, Address: 0x1b2080, Func Offset: 0x5c0
	// Line 3253, Address: 0x1b2090, Func Offset: 0x5d0
	// Line 3256, Address: 0x1b20a0, Func Offset: 0x5e0
	// Line 3261, Address: 0x1b20b0, Func Offset: 0x5f0
	// Line 3262, Address: 0x1b20d0, Func Offset: 0x610
	// Func End, Address: 0x1b20ec, Func Offset: 0x62c
	scePrintf("bhEne05_Damage - UNIMPLEMENTED!\n");
}

// 100% matching!
void bhEne05_DG00(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 20;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flg |= 0xC00000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->frm_no == 524288)
        {
            bhEne05_DustEffect(epw, 1);
        }
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 17;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        bhEne_AddNullTrans(epw, hu_020);
        break;
        
    case 2:
        bhEne_AddNullTrans(epw, hu_017);
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~0xC00000;
            epw->flg &= ~4;
        }
    }
}

// 100% matching!
void bhEne05_DG01(void)
{

}

// 100% matching!
void bhEne05_DG02(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->mtn_no = 22;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
        }
    }
}

// 100% matching!
void bhEne05_DG03(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg |= 0x40000;
        epw->mtn_no = 23;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
        }
    }
}

// 100% matching!
void bhEne05_DG04(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        if (epw->mtn_no == 2 || epw->mtn_no == 7 || epw->mtn_no == 10)
        {
            epw->mtn_no = 26;
        } 
        else
        {
            epw->mtn_no = 24;
        }

        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
        }
    }
}

// 100% matching!
void bhEne05_DG05(BH_PWORK* epw)
{
    switch (epw->mode3) 
    {      
    case 0:
        if (epw->mtn_no == 2 || epw->mtn_no == 7 || epw->mtn_no == 10) 
        {
            epw->mtn_no = 26;
        } 
        else 
        {
            epw->mtn_no = 25;
        }
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->ct0-- == 0)
        {
            epw->flg &= ~4;
            if (!(epw->type & 1) && (njRandom() < 0.3f) && (bhEne05_CheckJump(epw) != 0))
            {
                epw->mode0 = 1;
                epw->mode1 = 0;
                epw->mode2 = 5;
                epw->mode3 = 0;
                EXP0_I(0x78) = ((int)(10.0f * njRandom()) + 15);
                break;
            }

            if (njRandom() < ((plp->hp > 120) ? 0.5 : 0.75))
            {
                if ((bhEne05_CheckHikkaki(epw) != 0) && (EXP0_F(0x0) < 20.0f) && (bhEne_CheckDirTarget(epw, plp->px, plp->pz, 3640) != 0))
                {
                    epw->flg |= 0x40000000;
                    epw->mode0 = 1;
                    epw->mode1 = 0;
                    epw->mode3 = 0;
                    EXP0_I(0x78) = ((int)(10.0f * njRandom()) + 5);

                    if (epw->mtn_no == 25)
                    {
                        epw->mode2 = 15;
                    } 
                    else
                    {
                        epw->mode2 = 17;
                    }

                    return;
                }
            }

            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
        }
    }
}

// 99.93% matching
void bhEne05_DG06(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 12;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flg |= 0xC00000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        bhEne_AddNullTrans(epw, hu_012);
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 37;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = (20.0f + (30.0f * njRandom()));
            epw->mode3++;
        }
        
        if (epw->frm_no == 655360)
        {
            bhEne05_DustEffect(epw, 1);
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne_AddNullTrans(epw, hu_016);
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
            epw->flg &= ~0xC00000;
        }
    }
}

#pragma divbyzerocheck on

// 99.94% matching
void bhEne05_DG07(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 13;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flg |= 0xC00000;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 6;
        epw->mode3++;

    case 1:
        bhEne_AddNullTransDir(epw, epw->ayp, hu_0135);

        if (epw->ct1 != 0)
        {
            epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
            epw->ct1--;
        }

        if (epw->ct0-- == 0) 
        {
            epw->mtn_no = 38;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = 20.0f + (30.0f * njRandom());
            epw->mode3++;
        }

        if (epw->frm_no == 589824)
        {
            bhEne05_DustEffect(epw, 1);
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 17;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne_AddNullTrans(epw, hu_017);
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~0xC00000;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne05_DG08(BH_PWORK* epw)
{
    NJS_POINT3 pos;    
	float dist;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 14;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        epw->flg &= ~0x80000;

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 8;
        EXP0_F(0x3C) = 0.8f;
        if ((epw->frm_no / 65536) < 16)
        {
            NJS_POINT3 pos;
            dist = njDistanceP2PL((NJS_POINT3*)&epw->px, (NJS_PVECTOR*)(epw->exp0 + 0x48), &pos);
            dist = dist + ((9.0f - dist) / 8.0f);
            epw->px = pos.x + (dist * EXP0_F(0x54));
            epw->pz = pos.z + (dist * EXP0_F(0x5C));
        }
        
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, joint_tree[0], &pos);
            epw->px = pos.x;
            epw->pz = pos.z;
            epw->mtn_no = 5;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_count = 45875;
            epw->mtn_md |= 0x100;
            epw->ct0 = (20.0f + (30.0f * njRandom()));
            epw->mode3++;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->flg |= 0x40000;
            epw->mtn_md &= ~0x100;
            epw->mtn_no = 18;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
            EXP0_F(0x3C) = 5.0f;
            epw->flg |= 0x80000;
        }
    }
}

// 100% matching!
void bhEne05_DG09(BH_PWORK* epw)
{
    NJS_POINT3 pos;    
	float dist;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 15;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 8;
        epw->mode3++;
        epw->flg &= ~0x100000;

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 8;
        EXP0_F(0x3C) = 1.4f;
        if (epw->ct1 != 0)
        {
            NJS_POINT3 pos;
            dist = njDistanceP2PL((NJS_POINT3*)&epw->px, (NJS_PVECTOR*)(epw->exp0 + 0x48), &pos);
            dist = dist + ((16.0f - dist) / epw->ct1);
            epw->px = pos.x + (dist * EXP0_F(0x54));
            epw->pz = pos.z + (dist * EXP0_F(0x5C));
            epw->ct1--;
        }
        
        if (epw->frm_no == 983040)
        {
            bhEne05_DustEffect(epw, 1);
        }
        
        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, joint_tree[0], &pos);
            epw->px = pos.x;
            epw->pz = pos.z;
            epw->mtn_no = 6;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_count = 45875;
            epw->mtn_md |= 0x100;
            epw->ct0 = (20.0f + (30.0f * njRandom()));
            epw->mode3++;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->flg |= 0x40000;
            epw->mtn_md &= ~0x100;
            epw->mtn_no = 19;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0) 
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
            EXP0_F(0x3C) = 5.0f;
            epw->flg |= 0x100000;
        }
    }
}

#pragma divbyzerocheck on

// 99.97% matching
void bhEne05_DG10(BH_PWORK* epw)
{
	NJS_MKEY_F_MOD* mkfP;
	NJS_POINT3 trans;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->flg &= ~0x80000;
        
        EXP0_F(0x1C) = 1.4f * njSin(epw->ayp);
        EXP0_F(0x24) = 1.4f * njCos(epw->ayp);
        EXP0_F(0x20) = 2.0f;
        
        bhEne_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);
        
        epw->mtn_md |= 0x100;
        epw->mtn_no = 41;
        epw->frm_no = 458752;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        
        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        trans.x = mkfP->key[0];
        trans.y = mkfP->key[1];
        trans.z = mkfP->key[2];
        
        njUnitMatrix(NULL);
        njRotateY(NULL, epw->ay);
        njCalcVector(NULL, &trans, &trans);
        
        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;
        
        epw->pxb = epw->px;
        epw->pyb = 5.0f + epw->py;
        epw->pzb = epw->pz;
        
        epw->mtn_add = 65536;
        epw->ct0 = (epw->mnwP[epw->mtn_no].frm_num) - (epw->frm_no / 65536) - 1;
        
        epw->ct1 = 6;
        epw->ct2 = 1;
        
        epw->mode3++;

    case 1:
        if (!(epw->flg & 0x2000000))
        {
            epw->px += EXP0_F(0x1C);            
            epw->pz += EXP0_F(0x24);
            epw->py += EXP0_F(0x20);
            EXP0_F(0x20) -= 0.5f; 
        } 
        else
        {
            bhEne_AddNullTransDir(epw, epw->ayp, hu_040);
            if (epw->ct2 != 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                epw->ct2 = 0;
            }
            
            if (epw->frm_no >= 655360)
            {
                epw->px += EXP0_F(0x1C);
                epw->pz += EXP0_F(0x24);
                
                EXP0_F(0x1C) *= 0.9f;
                EXP0_F(0x24) *= 0.9f;
                
                if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
                {
                    bhEne05_DustEffect(epw, 1);
                }
            }
        }

        if (epw->ct1 != 0)
        {
            epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
            epw->ct1--;
        }
        
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 38;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            
            epw->ct0 = 20.0f + (30.0f * njRandom());
            epw->mode3++;
            
            epw->flg |= 0x2000000;
            epw->flg |= 0x80000;
            
            epw->mtn_md &= ~0x100;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 17;
            epw->frm_no = 0;
            
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne_AddNullTrans(epw, hu_017);
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
        }
    }
}

// 99.95% matching
void bhEne05_DG11(BH_PWORK* epw) 
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 41;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 6;
        epw->flg |= 0xC00000;
        EXP0_F(0x1C) = 1.4f * njSin(epw->ayp);
        EXP0_F(0x24) = 1.4f * njCos(epw->ayp);
        epw->mode3++;
        break;
        
    case 1:
        bhEne_AddNullTransDir(epw, epw->ayp, hu_040);
        if (epw->ct1 != 0)
        {
            epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
            epw->ct1--;
        }
        
        if (epw->frm_no >= 655360)
        {
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x1C) *= 0.9f;
            EXP0_F(0x24) *= 0.9f;
            if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
            {
                bhEne05_DustEffect(epw, 1);
            }
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 38;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = 20.0f + (30.0f * njRandom());
            epw->mode3++;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 17;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne_AddNullTrans(epw, hu_017);
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~0xC00000;
        }
    }
}

// 99.97% matching
void bhEne05_DG12(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->flg |= 0xC00000;
        EXP0_F(0x1C) = 2.0f * njSin(epw->ayp);
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 2.0f * njCos(epw->ayp);
        epw->mtn_no = 41;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 6;
        epw->ct2 = 1;
        epw->mode3++;
        epw->flg &= ~0x2000000;
        epw->flr_no = -1;

    case 1:
        if ((epw->frm_no / 65536) < 10)
        {
            epw->flg &= ~0x2000000;
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
        } 
        else if (!(epw->flg & 0x2000000))
        {
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            epw->py += EXP0_F(0x20);
            EXP0_F(0x20) -= 0.5f;
        } 
        else
        {
            if (epw->ct2 != 0) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                epw->ct2 = 0;
            }
            bhEne_AddNullTransDir(epw, epw->ayp, hu_040);
            if (epw->frm_no >= 655360)
            {
                epw->px += EXP0_F(0x1C);
                epw->pz += EXP0_F(0x24);
                EXP0_F(0x1C) *= 0.9f;
                EXP0_F(0x24) *= 0.9f;
                if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1)) 
                {
                    bhEne05_DustEffect(epw, 1);
                }
            }
        }

        if (epw->ct1 != 0) 
        {

            epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
            epw->ct1--;
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 38;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = 20.0f + (30.0f * njRandom());
            epw->mode3++;
            epw->flg |= 0x2000000;
            epw->flg |= 0x80000;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= 0xFFEFFFFF;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0) 
        {
            epw->mtn_no = 17;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        bhEne_AddNullTrans(epw, hu_017);
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~4;
            epw->flg &= ~0xC00000;
        }
    }
}

// 100% matching!
void bhEne05_DG13(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 21;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->flg |= 0xC00000;
        epw->ayp = epw->ayp + NJM_DEG_ANG(180.0f);
        EXP0_F(0x1C) = -1.4f * njSin(epw->ayp);
        EXP0_F(0x24) = -1.4f * njCos(epw->ayp);
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 6;
        epw->mode3++;

    case 1:

        if (epw->ct1 != 0)
        {
            epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
            epw->ct1--;
        }
        
        bhEne_AddNullTransDir(epw, epw->ayp, hu_021);
        
        if (epw->frm_no >= 655360)
        {
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            EXP0_F(0x1C) *= 0.9f;
            EXP0_F(0x24) *= 0.9f;
            if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
            {
                bhEne05_DustEffect(epw, 1);
            }
        }
        
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 16;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 2:
        bhEne_AddNullTrans(epw, hu_016);
        if (epw->ct0-- == 0)
        {
            epw->mode0 = 1;
            epw->mode1 = 1;
            epw->mode2 = 2;
            epw->mode3 = 0;
            epw->flg &= ~0xC00000;
            epw->flg &= ~4;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne05_ChainDamage(BH_PWORK* epw)
{	
	static char model_list[2] = { 3, 255 };
    NJS_CNK_OBJECT* objP;
    
    objP = epw->mlwP->objP;
    if (EXP0_C(0x80) == 0)
    {
        objP[2].ang[0] = (objP[2].ang[0] + (int)(182.04445f * ((int)(12.0f * njRandom()) + 8)));
        bhEne05_MotionPause(epw, model_list);
        EXP0_C(0x80) = 1;
    }
    else if ((char)EXP0_C(0x80) > 2)
    {
        if (epw->hokan_count < 3)
        {
            epw->hokan_count = 3;
            epw->hokan_rate = 13107;
        }
        bhEne05_SetMotionFlg(epw, 2, 1);
        epw->flg &= ~0x1000000;
        EXP0_C(0x80) = 0;
    }
    else
    {
        EXP0_C(0x80)++;
    }
}

// 100% matching!
void bhEne05_Die(BH_PWORK* epw)
{
    bhEne05_DeadMode2[epw->mode2](epw);
}

// 100% matching!
void bhEne05_DD00(BH_PWORK* epw)
{
    switch (epw->mode3)
    { 
    case 0:
        epw->flg &= ~0x40000;
        epw->flg |= 0xC00000;
        epw->mtn_no = 12;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        break;
        
    case 1:
        if (epw->mtn_no == 12)
        {
            bhEne_AddNullTrans(epw, hu_012);
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 39;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        
        if (epw->frm_no == 589824)
        {
            bhEne05_DustEffect(epw, 1);
        }
        break;
        
    case 2:
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;

    case 3:
        epw->mtn_no = 39;
        epw->frm_no = 0;
        epw->mtn_add = 65536;
        epw->hokan_count = 10;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        epw->mode3++;
        break;
        
    case 4:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = 150.0f * njRandom();
            epw->mode3--;
            epw->flg &= ~0xC00000;
        }
    }
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne05_DD01(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->flg |= 0xC00000;
        epw->mtn_no = 13;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 8;
        epw->mode3 += 1;
        break;
        
    case 1:
        if (epw->mtn_no == 13)
        {
            bhEne_AddNullTransDir(epw, epw->ayp, hu_0135);
            if (epw->ct1 != 0) 
            {
                epw->ay += (short)(epw->ayp - epw->ay) / epw->ct1;
                epw->ct1--;
            }
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 40;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        
        if (epw->frm_no == 589824)
        {
            bhEne05_DustEffect(epw, 1);
        }
        break;
        
    case 2:
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;

    case 3:
        epw->mtn_no = 40;
        epw->frm_no = 0;
        epw->mtn_add = 65536;
        epw->hokan_count = 10;
        epw->hokan_rate = 45875;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
        break;
        
    case 4:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = (150.0f * njRandom());
            epw->mode3--;
            epw->flg &= ~0xC00000;
        }
        break;
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne05_DD02(BH_PWORK* epw)
{
    NJS_POINT3 pos;    
	float dist;
	
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 14;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;
        epw->flg &= ~0x80000;

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 8;
        EXP0_F(0x3C) = 1.1f;
        if ((epw->frm_no / 65536) < 16)
        {
            NJS_POINT3 pos;
            dist = njDistanceP2PL((NJS_POINT3*)&epw->px, (NJS_PVECTOR*)(epw->exp0 + 0x48), &pos);
            dist = dist + ((9.0f - dist) / 8.0f);
            epw->px = pos.x + (dist * EXP0_F(0x54));
            epw->pz = pos.z + (dist * EXP0_F(0x5C));
        }

        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, joint_tree[0], &pos);
            epw->px = pos.x;
            epw->pz = pos.z;
            epw->mtn_no = 27;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_count = 45875;
            epw->mtn_md |= 0x100;
            epw->mode3++;
        }
        break;
        
    case 2:
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;
    }
}

// 100% matching!
void bhEne05_DD03(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    float dist;
    
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 15;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 8;
        epw->mode3++;
        epw->flg &= ~0x100000;

    case 1:
        epw->ay += (short)(epw->ayp - epw->ay) / 8;
        EXP0_F(0x3C) = 1.4f;
        if (epw->ct1 != 0) 
        {
            dist = njDistanceP2PL((NJS_POINT3*)&epw->px, (NJS_PVECTOR*)(epw->exp0 + 0x48), &pos);
            dist = dist + ((16.0f - dist) / epw->ct1);
            epw->px = pos.x + (dist * EXP0_F(0x54));
            epw->pz = pos.z + (dist * EXP0_F(0x5C));
            epw->ct1 -= 1;
        }
        
        if (epw->frm_no == 983040)
        {
            bhEne05_DustEffect(epw, 1);
        }

        if (epw->ct0-- == 0)
        {
            bhEne_GetPartsPos(epw, joint_tree[0], &pos);
            epw->px = pos.x;
            epw->pz = pos.z;
            epw->mtn_no = 28;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_count = 45875;
            epw->mtn_md |= 0x100;
            epw->mode3++;
        }
        break;
        
    case 2:
        bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        epw->mode3++;
    }
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne05_DD04(BH_PWORK* epw)
{
	NJS_MKEY_F_MOD* mkfP; 
	NJS_POINT3 trans;

    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->flg |= 0xC00000;
        epw->flg |= 0x10;
        EXP0_F(0x1C) = 1.4f * njSin(epw->ayp);
        EXP0_F(0x24) = 1.4f * njCos(epw->ayp);
        EXP0_F(0x20) = 2.0f;
        bhEne_GetPartsPos(epw, joint_tree[0], (NJS_POINT3*)&epw->px);
        epw->mtn_md |= 0x100;
        epw->mtn_no = 41;
        epw->frm_no = 458752;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        mkfP = epw->mnwP[epw->mtn_no].md2P->p[0];
        trans.x = mkfP->key[0];
        trans.y = mkfP->key[1];
        trans.z = mkfP->key[2];
        njUnitMatrix(NULL);
        njRotateY(NULL, epw->ay);
        njCalcVector(NULL, &trans, &trans);
        epw->px -= trans.x;
        epw->py -= trans.y;
        epw->pz -= trans.z;
        epw->pxb = epw->px;
        epw->pyb = 5.0f + epw->py;
        epw->pzb = epw->pz;
        epw->ct0 = (epw->mnwP[epw->mtn_no].frm_num - 2) - (epw->frm_no / 65536);
        epw->ct1 = 6;
        epw->ct2 = 1;
        epw->mode3++;
        
    case 1:
        if (epw->ct1 != 0)
        {
            epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
            epw->ct1--;
        }
        
        if (!(epw->flg & 0x2000000))
        {
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            epw->py += EXP0_F(0x20);
            EXP0_F(0x20) -= 0.5f;
        } 
        else
        {
            if (epw->ct2 != 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                epw->ct2 = 0;
            }
            
            bhEne_AddNullTransDir(epw, epw->ayp, hu_040);
            if (epw->frm_no >= 655360)
            {
                epw->px += EXP0_F(0x1C);
                epw->pz += EXP0_F(0x24);
                EXP0_F(0x1C) *= 0.9f;
                EXP0_F(0x24) *= 0.9f;
                if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1)) 
                {
                    bhEne05_DustEffect(epw, 1);
                }
            }
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 38;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            epw->mode3++;
            epw->flg |= 0x2000000;
            epw->flg |= 0x80000;
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 40;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = 150.0f * njRandom();
            epw->mode3--;
            epw->flg &= ~0xC00000;
        }
    }
}

// 100% matching!
void bhEne05_DD05(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->flg |= 0xC00000;
        epw->mtn_no = 41;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 6;
        EXP0_F(0x1C) = 1.4f * njSin(epw->ayp);
        EXP0_F(0x24) = 1.4f * njCos(epw->ayp);
        epw->mode3++;
        break;
        
    case 1:
        if (epw->mtn_no == 41)
        {
            bhEne_AddNullTransDir(epw, epw->ayp, hu_040);
            if (epw->ct1 != 0)
            {
                epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
                epw->ct1--;
            }
            
            if (epw->frm_no >= 655360)
            {
                epw->px += EXP0_F(0x1C);
                epw->pz += EXP0_F(0x24);
                EXP0_F(0x1C) *= 0.9f;
                EXP0_F(0x24) *= 0.9f;
                if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
                {
                    bhEne05_DustEffect(epw, 1);
                }
            }
        }
        
        if (epw->ct0-- == 0)
        {
            if (epw->mtn_no == 41)
            {
                bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            }
            epw->mtn_no = 40;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = 150.0f * njRandom();
            epw->mode3--;
            epw->flg &= ~0xC00000;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne05_DD06(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->mtn_no = 42;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->mode3++;

    case 1:
        if (epw->mtn_no == 42)
        {
            bhEne_AddNullTrans(epw, hu_041);
            if (epw->frm_no == 5439488) 
            {
                bhEne05_DustEffect(epw, 1);
            }
        }
        
        if (epw->ct0-- == 0) 
        {
            if (epw->mtn_no == 42)
            {
                bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            }
            epw->mtn_no = 40;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = 150.0f * njRandom();
            epw->mode3--;
        }
    }
}

#pragma divbyzerocheck on

// 100% matching!
void bhEne05_DD07(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        EXP0_F(0x1C) = 2.0f * njSin(epw->ayp);
        EXP0_F(0x20) = 0.0f;
        EXP0_F(0x24) = 2.0f * njCos(epw->ayp);
        epw->mtn_no = 41;
        epw->frm_no = 0;
        epw->hokan_count = 5;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num;
        epw->ct1 = 6;
        epw->ct2 = 0;
        epw->mode3++;
        epw->flg &= ~0x2000000;
        epw->flr_no = -1;

    case 1:
        if ((epw->frm_no / 65536) < 10)
        {
            epw->flg &= ~0x2000000;
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
        } 
        else if (!(epw->flg & 0x2000000))
        {
            epw->px += EXP0_F(0x1C);
            epw->pz += EXP0_F(0x24);
            epw->py += EXP0_F(0x20);
            EXP0_F(0x20) -= 0.5f;
        } 
        else
        {
            if (epw->ct2 != 0)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                epw->ct2 = 0;
            }
            epw->flr_no = bhCheckFloorNum(epw->py);
            epw->stflg &= ~0x100000;
            bhEne_AddNullTransDir(epw, epw->ayp, hu_040);
            if (epw->frm_no >= 655360)
            {
                epw->px += EXP0_F(0x1C);
                epw->pz += EXP0_F(0x24);
                EXP0_F(0x1C) *= 0.9f;
                EXP0_F(0x24) *= 0.9f;
                if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
                {
                    bhEne05_DustEffect(epw, 1);
                }
            }
        }

        if (epw->ct1 != 0)
        {
            epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
            epw->ct1--;
        }

        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 38;
            epw->frm_no = 0;
            epw->hokan_count = 10;
            epw->hokan_rate = 32768;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
            epw->mode3++;
            epw->flg |= 0x2000000;
            epw->flg |= 0x80000;
            bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_no = 40;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 3:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = 150.0f * njRandom();
            epw->mode3--;
        }
        break;
    }
}

// 100% matching!
void bhEne05_DD08(BH_PWORK* epw)
{
    switch (epw->mode3)
    {
    case 0:
        epw->flg &= ~0x40000;
        epw->flg |= 0xC00000;
        epw->mtn_no = 21;
        epw->frm_no = 0;
        epw->hokan_count = 10;
        epw->hokan_rate = 32768;
        epw->mtn_add = 65536;
        epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 1;
        epw->ct1 = 6;
        epw->ayp = epw->ayp + NJM_DEG_ANG(180.0f);
        EXP0_F(0x1C) = -1.4f * njSin(epw->ayp);
        EXP0_F(0x24) = -1.4f * njCos(epw->ayp);
        epw->mode3++;
        break;
        
    case 1:
        if (epw->mtn_no == 21)
        {
            bhEne_AddNullTransDir(epw, epw->ayp, hu_021);
            if (epw->ct1 != 0)
            {
                epw->ay += ((short)(epw->ayp - epw->ay) / epw->ct1);
                epw->ct1--;
            }
            
            if (epw->frm_no >= 655360)
            {
                epw->px += EXP0_F(0x1C);
                epw->pz += EXP0_F(0x24);
                EXP0_F(0x1C) *= 0.9f;
                EXP0_F(0x24) *= 0.9f;
                if ((njScalor((NJS_VECTOR*)(epw->exp0 + 0x1C)) > 0.6f) && (epw->ct0 & 1))
                {
                    bhEne05_DustEffect(epw, 1);
                }
            }
        }

        if (epw->ct0-- == 0)
        {
            if (epw->mtn_no == 21)
            {
                bhEne_BloodPool(epw, (NJS_POINT3*)&epw->px, epw->ay, &BloodParam);
            }
            epw->mtn_no = 39;
            epw->frm_no = 0;
            epw->mtn_add = 65536;
            epw->hokan_count = 10;
            epw->hokan_rate = 45875;
            epw->ct0 = epw->mnwP[epw->mtn_no].frm_num - 2;
            epw->mode3++;
        }
        break;
        
    case 2:
        if (epw->ct0-- == 0)
        {
            epw->mtn_add = 0;
            epw->ct0 = (150.0f * njRandom());
            epw->mode3 -= 1;
            epw->flg &= ~0xC00000;
        }
    }
}

#pragma divbyzerocheck off

// 100% matching!
void bhEne05_SearchPlayer(BH_PWORK* epw)
{
	int wk;
	float dx;
	float dz;
	NJS_POINT3 p1;    
	NJS_POINT3 p2;

    dx = epw->px - plp->px;
    dz = epw->pz - plp->pz;
    EXP0_F(0x0) = njSqrt(dx * dx + dz * dz);
    if (fabsf(epw->py - plp->py) < 30.0f)
    {
        wk = bhSearchPlayer(epw, 21845);
        if (wk != -1)
        {
            p1.x = epw->px;
            p1.y = 15.0f + epw->py;
            p1.z = epw->pz;
            p2.x = plp->px;
            p2.y = 15.0f + plp->py;
            p2.z = plp->pz;
            if (bhCollisionCheckLine2(&p1, &p2, 17408, -1) == NULL)
            {
                EXP0_I(0x4) = wk;
                EXP0_UC(0x14) = 1;               
                EXP0_F(0x8) = plp->px;
                EXP0_F(0xC) = plp->py;
                EXP0_F(0x10) = plp->pz;
                epw->ct3 = 0;
                return;
            }
        }
    }
    
    if (EXP0_UC(0x14) != 0)
    {
        if (++epw->ct3 > 90)
        {
            EXP0_UC(0x14) = 0;
            epw->ct3 = 0;
        }
    }
}

// 100% matching!
void bhEne05_MotionPause(BH_PWORK* epw, char* parts)
{
    O_WORK* owk;

    owk = epw->mlwP->owP;

    while (*parts != -1)
    {
        owk[*parts].flg |= 2;
        parts++;
    }
}

// 98.09% matching
void bhEne05_SetMotionFlg(BH_PWORK* epw, unsigned int flg, unsigned char mode)
{
	O_WORK* owk;
	unsigned int onum;
   
    owk = epw->mlwP->owP;
    onum = epw->mlwP->obj_num;
    while (onum != 0)
    {
        switch (mode)
        {
        case 0:
            owk->flg |= flg;
            break;
        case 1:
            owk->flg &= ~flg;
            break;
        case 2:
            owk->flg ^= flg;
            break;
        }
        onum--;
        owk++;
    }     
}

// 100% matching!
void bhEne05_FixedLegPos(BH_PWORK* epw)
{
    int fno;
    NJS_POINT3 ret;

    if ((epw->flg & 0x40000) && (epw->mnwP == epw->mnwPb))
    {
        fno = epw->frm_no / 65536;

        switch (epw->mtn_no) 
        {
        case 8:
        case 30:
            if (epw->mtn_md & 2)
            {
                if (fno < 10)
                {
                    EXP0_I(0x7C) = (int)joint_tree[1];
                } 
                else
                {
                    EXP0_I(0x7C) = (int)joint_tree[2];
                }
            } 
            else
            {
                if (fno < 10)
                {
                    EXP0_I(0x7C) = (int)joint_tree[2];
                } 
                else
                {
                    EXP0_I(0x7C) = (int)joint_tree[1];
                }
            }                       
            break;

        case 46:
            EXP0_I(0x7C) = (int)joint_tree[1];            
            break;

        case 22:
            if (fno < 17)
            {
                EXP0_I(0x7C) = (int)joint_tree[1];
            } 
            else
            {
                EXP0_I(0x7C) = (int)joint_tree[2];
            }            
            break;

        case 23:
            break;

        case 29:
            if (epw->mtn_md & 2)
            {
                if (fno < 6)
                {
                    EXP0_I(0x7C) = (int)joint_tree[9];
                } 
                else
                {
                    EXP0_I(0x7C) = (int)joint_tree[8];
                }
            } 
            else 
            {
                if (fno < 6)
                {
                    EXP0_I(0x7C) = (int)joint_tree[8];
                } 
                else
                {
                    EXP0_I(0x7C) = (int)joint_tree[9];
                }
            }            
            break;

    case 33:
        if ((fno <= 15) || (fno >= 41))
        {
            EXP0_I(0x7C) = (int)joint_tree[8];
        }
        else if (fno < 41)
        {
            EXP0_I(0x7C) = (int)joint_tree[9];
        }
        break;

        case 34:
            EXP0_I(0x7C) = (int)joint_tree[8];            
            break;

        case 18:
            if (fno < 15)
            {
                EXP0_I(0x7C) = (int)joint_tree[5];
            } 
            else
            {
                EXP0_I(0x7C) = (int)joint_tree[8];
            }
            
            break;

        case 19:
            if (fno < 15)
            {
                EXP0_I(0x7C) = (int)(joint_tree[0]);
            } 
            else if (fno < 42)
            {
                EXP0_I(0x7C) = (int)joint_tree[9];
            } 
            else
            {
                EXP0_I(0x7C) = (int)joint_tree[8];
            }
            
            break;

        case 2:
            EXP0_I(0x7C) = (int)joint_tree[8];
            
            break;

        case 7:
        case 10:
            EXP0_I(0x7C) = (int)joint_tree[9];            
            break;
        }

        if (EXP0_I(0x7C) != 0) {
            bhCalcFixOffset(epw, (char*)EXP0_I(0x7C), 0, &ret);
            epw->px -= ret.x;
            epw->pz -= ret.z;
        }
    }
}

// 100% matching!
void bhEne05_CheckWall(BH_PWORK* epw)
{
	NJS_VECTOR trans;
	NJS_POINT3 p1;
	NJS_POINT3 p2;  
	NJS_CNK_OBJECT* objP;
    
    objP = epw->mlwP->objP;
    EXP0_F(0x38) += ((EXP0_F(0x40) - EXP0_F(0x38)) / 8.0f);
    epw->ar = EXP0_F(0x38);
    
    if (epw->flg & 0x100000)
    {
        if (epw->flg & 0x800000)
        {
            bhEne_GetPartsPos(epw, joint_tree[3], &p1);
            
            trans.x = p1.x - epw->px;
            trans.y = 0.0f;
            trans.z = p1.z - epw->pz;
            
            epw->px += trans.x;
            epw->pz += trans.z;
            
            bhCheckWall(epw);
            
            epw->px -= trans.x;
            epw->pz -= trans.z;
        }
        
        if (epw->flg & 0x400000)
        {
            bhEne_GetPartsPos(epw, joint_tree[4], &p1);
            
            trans.x = p1.x - epw->px;
            trans.y = 0.0f;
            trans.z = p1.z - epw->pz;
            
            epw->px += trans.x;           
            epw->pz += trans.z;
            
            bhCheckWall(epw);
            
            epw->px -= trans.x;
            epw->pz -= trans.z;
        }
        
        bhEne_GetPartsPos(epw, joint_tree[6], &p1);
        
        trans.x = p1.x - epw->px;        
        trans.y = 0.0f;
        trans.z = p1.z - epw->pz;
        
        epw->px += trans.x;
        epw->pz += trans.z;
        bhCheckWall(epw);
        
        epw->px -= trans.x;
        epw->pz -= trans.z;
        
        bhEne_GetPartsPos(epw, joint_tree[7], &p1);
        
        trans.x = p1.x - epw->px;
        trans.y = 0.0f;
        trans.z = p1.z - epw->pz;
        
        epw->px += trans.x;
        epw->pz += trans.z;
        
        bhCheckWall(epw);
        
        epw->px -= trans.x;
        epw->pz -= trans.z;
    }
    if (epw->flg & 0x80000)
    {
        bhEne_GetPartsPos(epw, joint_tree[5], &p1);
        
        trans.x = p1.x - epw->px;
        trans.y = p1.y - epw->py;
        trans.z = p1.z - epw->pz;
        
        epw->px = p1.x;
        epw->pz = p1.z;
        
        bhCheckWall(epw);
        
        epw->px -= trans.x;
        epw->pz -= trans.z;
    }
    
    if (epw->flg & 0x200000)
    {
        bhEne_GetPartsPos(epw, joint_tree[1], &p1);
        bhEne_GetPartsPos(epw, joint_tree[2], &p2);
        
        trans.x = ((p1.x + p2.x) / 2.0f) - epw->px;
        trans.y = 0.0f;
        trans.z = ((p1.z + p2.z) / 2.0f) - epw->pz;
        
        epw->px += trans.x;
        epw->pz += trans.z;
        
        bhCheckWall(epw);
        
        epw->px -= trans.x;
        epw->pz -= trans.z;
    }
    
    EXP0_F(0x34) += ((EXP0_F(0x3C) - EXP0_F(0x34)) / 8.0f);
    epw->ar = EXP0_F(0x34);
    
    trans.x = objP->pos[0];
    trans.y = 0.0f;
    trans.z = objP->pos[2];
    
    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &trans, &trans);
    
    epw->px += trans.x;
    epw->pz += trans.z;
    
    bhCheckWall(epw);
    
    epw->px -= trans.x;
    epw->pz -= trans.z;
}

// 100% matching!
int bhEne05_CheckLeaningWall(BH_PWORK* epw, int flg)
{
    NJS_VECTOR vec;
    NJS_POINT3 pos1;
    NJS_POINT3 pos2;
    ATR_WORK* hp;
    NJS_POINT3 n;

    vec.x = 0.0f;
    vec.y = 1.0f;
    vec.z = (flg != 0) ? -16.0f : 12.0f;

    njUnitMatrix(NULL);
    njRotateY(NULL, epw->ay);
    njCalcVector(NULL, &vec, &vec);

    pos1.x = epw->px;
    pos1.y = 1.0f + epw->py;
    pos1.z = epw->pz;
    
    pos2.x = epw->px + vec.x;
    pos2.y = 1.0f + epw->py;
    pos2.z = epw->pz + vec.z;

    hp = bhCollisionCheckLine2(&pos1, &pos2, epw->flg, epw->flr_no);
    if ((hp != NULL) && !(hp->attr & 8)) 
    {   
        bhGetHitCollisionNormal(&n);
        njUnitVector(&n);
        njUnitVector(&vec);  
        
        EXP0_F(0x48) = pos2.x;
        EXP0_F(0x4c) = pos2.y;
        EXP0_F(0x50) = pos2.z;
        
        EXP0_F(0x54) = n.x;
        EXP0_F(0x58) = n.y;
        EXP0_F(0x5c) = n.z;
    
        if (njInnerProduct(&vec, &n) < njCos(NJM_DEG_ANG(145.0f)))
        {    
            if (flg != 0)
            {
                epw->ayp = bhArcTan2(n.x, n.z);
            }
            else
            {
                epw->ayp = bhArcTan2(-n.x, -n.z);
            }
            return 1;
        }
    }
    return 0;
}

// 100% matching!
void bhEne05_FloorCollision(BH_PWORK* epw)
{
	NJS_POINT3 n;
	ATR_WORK* hp;
	NJS_POINT3 pos;

    if (!(epw->flg & 0x2000000))
    {
        if (EXP0_F(0x20) > 0.0f)
        {
            pos.x = epw->px;
            pos.y = 20.0f + epw->py;
            pos.z = epw->pz;
            if (bhCollisionCheckLine2((NJS_POINT3*)&epw->px, &pos, epw->flg, epw->flr_no) != NULL)
            {
                epw->py = pos.y - 20.0f;
            }
        }
        
        hp = bhCollisionCheckLine2((NJS_POINT3*)&epw->pxb, (NJS_POINT3*)&epw->px, epw->flg, epw->flr_no);
        if ((hp != NULL) && ((hp->type == 0) || (hp->type == 7)))
        {
            bhGetHitCollisionNormal(&n);
            njUnitVector(&n);
            if (n.y > 0.9f)
            {
                epw->flg |= 0x2000000;
                if (hp->type == 0)
                {                    
                    epw->py = hp->py + (hp->h ? hp->h : rom->h);
                }
                
                if (hp->type == 7)
                {
                    epw->py = hp->py;
                }
            }
        }
    }
}

// 100% matching!
void bhEne05_SetWeponAtr(BH_PWORK* epw)
{
    O_WORK* owk1;
    O_WORK* owk2;

    owk1 = epw->mlwP->owP;
    epw->watr.c1.x = owk1[4].mtx[12];
    epw->watr.c1.y = owk1[4].mtx[13];
    epw->watr.c1.z = owk1[4].mtx[14];

    owk2 = epw->mlwP->owP;
    epw->watr.c2.x = (owk2[23].mtx[12] + owk2[27].mtx[12]) / 2.0f;
    epw->watr.c2.y = (owk2[23].mtx[13] + owk2[27].mtx[13]) / 2.0f;
    epw->watr.c2.z = (owk2[23].mtx[14] + owk2[27].mtx[14]) / 2.0f;
    
    epw->watr.r = 4.0f;
}

// 
// Start address: 0x1b6f10
void bhEne05_InitDamage(BH_PWORK* epw)
{
	//_anon6* hp;
	//_anon6* hp;
	int DamageAngle;
	// Line 5464, Address: 0x1b6f10, Func Offset: 0
	// Line 5468, Address: 0x1b6f28, Func Offset: 0x18
	// Line 5475, Address: 0x1b6f48, Func Offset: 0x38
	// Line 5476, Address: 0x1b6f70, Func Offset: 0x60
	// Line 5480, Address: 0x1b6f94, Func Offset: 0x84
	// Line 5486, Address: 0x1b6f9c, Func Offset: 0x8c
	// Line 5489, Address: 0x1b6fb4, Func Offset: 0xa4
	// Line 5490, Address: 0x1b6fd4, Func Offset: 0xc4
	// Line 5494, Address: 0x1b6fe4, Func Offset: 0xd4
	// Line 5497, Address: 0x1b6fec, Func Offset: 0xdc
	// Line 5494, Address: 0x1b6ff0, Func Offset: 0xe0
	// Line 5497, Address: 0x1b6ff8, Func Offset: 0xe8
	// Line 5502, Address: 0x1b7014, Func Offset: 0x104
	// Line 5505, Address: 0x1b701c, Func Offset: 0x10c
	// Line 5507, Address: 0x1b7044, Func Offset: 0x134
	// Line 5509, Address: 0x1b7050, Func Offset: 0x140
	// Line 5511, Address: 0x1b7060, Func Offset: 0x150
	// Line 5513, Address: 0x1b7074, Func Offset: 0x164
	// Line 5515, Address: 0x1b7084, Func Offset: 0x174
	// Line 5516, Address: 0x1b708c, Func Offset: 0x17c
	// Line 5517, Address: 0x1b7090, Func Offset: 0x180
	// Line 5518, Address: 0x1b7098, Func Offset: 0x188
	// Line 5519, Address: 0x1b70a8, Func Offset: 0x198
	// Line 5520, Address: 0x1b70ac, Func Offset: 0x19c
	// Line 5524, Address: 0x1b70b4, Func Offset: 0x1a4
	// Line 5526, Address: 0x1b70bc, Func Offset: 0x1ac
	// Line 5528, Address: 0x1b70cc, Func Offset: 0x1bc
	// Line 5529, Address: 0x1b70ec, Func Offset: 0x1dc
	// Line 5532, Address: 0x1b70fc, Func Offset: 0x1ec
	// Line 5533, Address: 0x1b7100, Func Offset: 0x1f0
	// Line 5532, Address: 0x1b7104, Func Offset: 0x1f4
	// Line 5533, Address: 0x1b7114, Func Offset: 0x204
	// Line 5535, Address: 0x1b711c, Func Offset: 0x20c
	// Line 5538, Address: 0x1b7124, Func Offset: 0x214
	// Line 5541, Address: 0x1b7138, Func Offset: 0x228
	// Line 5543, Address: 0x1b7190, Func Offset: 0x280
	// Line 5545, Address: 0x1b71ac, Func Offset: 0x29c
	// Line 5547, Address: 0x1b71b4, Func Offset: 0x2a4
	// Line 5548, Address: 0x1b71c4, Func Offset: 0x2b4
	// Line 5549, Address: 0x1b71d4, Func Offset: 0x2c4
	// Line 5550, Address: 0x1b71d8, Func Offset: 0x2c8
	// Line 5553, Address: 0x1b71e0, Func Offset: 0x2d0
	// Line 5554, Address: 0x1b71e8, Func Offset: 0x2d8
	// Line 5556, Address: 0x1b71f8, Func Offset: 0x2e8
	// Line 5557, Address: 0x1b7200, Func Offset: 0x2f0
	// Line 5564, Address: 0x1b7204, Func Offset: 0x2f4
	// Line 5570, Address: 0x1b7220, Func Offset: 0x310
	// Line 5571, Address: 0x1b7250, Func Offset: 0x340
	// Line 5574, Address: 0x1b726c, Func Offset: 0x35c
	// Line 5571, Address: 0x1b7278, Func Offset: 0x368
	// Line 5574, Address: 0x1b727c, Func Offset: 0x36c
	// Line 5575, Address: 0x1b7288, Func Offset: 0x378
	// Line 5577, Address: 0x1b7290, Func Offset: 0x380
	// Line 5578, Address: 0x1b72b0, Func Offset: 0x3a0
	// Line 5580, Address: 0x1b72b4, Func Offset: 0x3a4
	// Line 5579, Address: 0x1b72bc, Func Offset: 0x3ac
	// Line 5578, Address: 0x1b72c0, Func Offset: 0x3b0
	// Line 5584, Address: 0x1b72c4, Func Offset: 0x3b4
	// Line 5585, Address: 0x1b72cc, Func Offset: 0x3bc
	// Line 5586, Address: 0x1b72dc, Func Offset: 0x3cc
	// Line 5593, Address: 0x1b72e0, Func Offset: 0x3d0
	// Line 5594, Address: 0x1b72f4, Func Offset: 0x3e4
	// Line 5595, Address: 0x1b7304, Func Offset: 0x3f4
	// Line 5599, Address: 0x1b7310, Func Offset: 0x400
	// Line 5600, Address: 0x1b7318, Func Offset: 0x408
	// Line 5601, Address: 0x1b731c, Func Offset: 0x40c
	// Line 5602, Address: 0x1b7320, Func Offset: 0x410
	// Line 5607, Address: 0x1b7330, Func Offset: 0x420
	// Line 5610, Address: 0x1b7338, Func Offset: 0x428
	// Line 5612, Address: 0x1b7344, Func Offset: 0x434
	// Line 5613, Address: 0x1b7358, Func Offset: 0x448
	// Line 5614, Address: 0x1b7364, Func Offset: 0x454
	// Line 5618, Address: 0x1b7370, Func Offset: 0x460
	// Line 5619, Address: 0x1b7374, Func Offset: 0x464
	// Line 5620, Address: 0x1b7378, Func Offset: 0x468
	// Line 5623, Address: 0x1b737c, Func Offset: 0x46c
	// Line 5618, Address: 0x1b7380, Func Offset: 0x470
	// Line 5619, Address: 0x1b7388, Func Offset: 0x478
	// Line 5620, Address: 0x1b7394, Func Offset: 0x484
	// Line 5621, Address: 0x1b7398, Func Offset: 0x488
	// Line 5622, Address: 0x1b739c, Func Offset: 0x48c
	// Line 5623, Address: 0x1b73a0, Func Offset: 0x490
	// Line 5626, Address: 0x1b73ac, Func Offset: 0x49c
	// Line 5628, Address: 0x1b73bc, Func Offset: 0x4ac
	// Line 5629, Address: 0x1b73c0, Func Offset: 0x4b0
	// Line 5630, Address: 0x1b73d0, Func Offset: 0x4c0
	// Line 5632, Address: 0x1b73e8, Func Offset: 0x4d8
	// Line 5634, Address: 0x1b73f0, Func Offset: 0x4e0
	// Line 5635, Address: 0x1b740c, Func Offset: 0x4fc
	// Line 5638, Address: 0x1b7410, Func Offset: 0x500
	// Line 5640, Address: 0x1b742c, Func Offset: 0x51c
	// Line 5641, Address: 0x1b7440, Func Offset: 0x530
	// Line 5651, Address: 0x1b7448, Func Offset: 0x538
	// Line 5652, Address: 0x1b7478, Func Offset: 0x568
	// Line 5655, Address: 0x1b7494, Func Offset: 0x584
	// Line 5652, Address: 0x1b74a0, Func Offset: 0x590
	// Line 5655, Address: 0x1b74a4, Func Offset: 0x594
	// Line 5656, Address: 0x1b74b0, Func Offset: 0x5a0
	// Line 5658, Address: 0x1b74b8, Func Offset: 0x5a8
	// Line 5659, Address: 0x1b74d8, Func Offset: 0x5c8
	// Line 5660, Address: 0x1b74dc, Func Offset: 0x5cc
	// Line 5661, Address: 0x1b74e0, Func Offset: 0x5d0
	// Line 5659, Address: 0x1b74e4, Func Offset: 0x5d4
	// Line 5660, Address: 0x1b74e8, Func Offset: 0x5d8
	// Line 5668, Address: 0x1b74ec, Func Offset: 0x5dc
	// Line 5669, Address: 0x1b7500, Func Offset: 0x5f0
	// Line 5673, Address: 0x1b7504, Func Offset: 0x5f4
	// Line 5675, Address: 0x1b7508, Func Offset: 0x5f8
	// Func End, Address: 0x1b7524, Func Offset: 0x614
	scePrintf("bhEne05_InitDamage - UNIMPLEMENTED!\n");
}

// 96.81% matching
void bhEne05_WaterEffect(BH_PWORK* epw)
{
	EN05_WE_WORK* we;
	EN05_WATER_EFFECT_WORK* wp;
	unsigned int fno;
	NJS_POINT3 ofp;    
	int i;

    wp = WaterEffectTbl;
    fno = epw->frm_no / 65536;
    
    if (epw->mnwP != epw->mnwPb)
    {
        return;
    }
    
    while (wp->mtn_no != -1)
    {
        if (epw->mtn_no == wp->mtn_no)
        {
            we = wp->we;
            i = 0;
            while (i < wp->num)
            {
                if (we->frm_no == fno)
                {
                    ofp.x = we->ofx;
                    ofp.z = we->ofz;
                    
                    njUnitMatrix(NULL);
                    njRotateY(NULL, epw->ay);
                    njCalcVector(NULL, &ofp, &ofp);
                    
                    ofp.x += epw->px;
                    ofp.z += epw->pz;
                    ofp.y = epw->py;
                    
                    switch (we->size)
                    {
                    case 0:
                        bhSetWaterSplash2(epw, &ofp, 1, 1.5f, 1.0f, 1.5f);
                        break;
                    case 1:
                        bhSetWaterSplash2(epw, &ofp, 1, 2.0f, 1.5f, 2.0f);
                        break;
                    case 2:
                        bhSetWaterSplash2(epw, &ofp, 1, 2.0f, 3.5f, 2.0f);
                        break;
                    }
                    
                    sys->ef.id = 108;
                    sys->ef.flg = 1;
                    
                    sys->ef.px = epw->px;
                    sys->ef.py = epw->py;
                    sys->ef.pz = epw->pz;
                    
                    sys->ef.sx = 1.0f;
                    sys->ef.sy = 1.0f;
                    sys->ef.sz = 1.0f;
                    bhSetEffectTb(&sys->ef, NULL, NULL, (we->size * 5) + 10);
                }
                we++;
                i++;
            }
        }
        wp++;
    }
}

// 100% matching!
void bhEne05_PlayerControl(BH_PWORK* epw)
{
	O_WORK* owk;
	NJS_POINT3 pos;
	NJS_POINT3 vec; 
	int eno;

    owk = &plp->mlwP->owP[3];
    pos.x = njRandom() - 0.5f;
    pos.y = 2.0f + (2.0f * njRandom());
    pos.z = njRandom() - 0.5f;
    njCalcPoint(&owk->mtx, &pos, &pos);
    vec.x = owk->mtx[4];
    vec.y = owk->mtx[5];
    vec.z = owk->mtx[6];

    switch ((int)(8.0f * njRandom()))
    {
    case 0:
        bhEne_SetBloodEffect4(&pos, &vec, 0, 0, 0);
        break;
        
    case 1:
        bhEne_SetBloodEffect4(&pos, &vec, 0, 1, 1);
        break;
        
    case 2:
        sys->ef.id = 259;
        sys->ef.flg = 1;
        sys->ef.type = 0;
        sys->ef.px = pos.x;
        sys->ef.py = pos.y;
        sys->ef.pz = pos.z;
        sys->ef.sx = 0.5f;
        sys->ef.sy = 0.5f;
        sys->ef.sz = 0.5f;
        eno = bhSetEffectTb(&sys->ef, NULL, NULL, 0);
        if (eno != -1)
        {
            (&eff[eno])->stflg |= 0x20;
            (&eff[eno])->txp[0] = epw->mlwP->texP;
            (&eff[eno])->tex_id = 2;
        }
    }
}

// 100% matching!
int bhEne05_CheckJump(BH_PWORK* epw)
{
    NJS_POINT3 pos;
    NJS_POINT3 vec;
    int ang;
    int i;
    int j;
    BH_PWORK* epp;
    float ln;
    float dist;
    ATR_WORK* hp;

    hp = bhEne_CheckEventAtr(epw->flr_no, epw->px, epw->pz, 5, 32, 32);
    if (hp != 0)
    {
        return 0;
    }
        
    hp = bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 5, 33, 33);
    if (hp != 0)
    {
        return 0;
    }
        
    switch (plp->mode2)
    {
    case 3:
        switch (PEXP0_I(0x14))
        {
        case 0: 
            dist = 8.0f;
            break;
            
        case 1: 
            dist = 7.0f;
            break;
            
        case 2: 
            dist = 6.0f;
            break;
        }
        break;
        
    case 6:
        switch (PEXP0_I(0x14))
        {
        case 0: 
            dist = 25.0f;
            break;
            
        case 1: 
            dist = 23.0f;
            break;
            
        case 2: 
            dist = 20.0f;
            break;
        }
        break;  
        
    case 9:
    case 12:
        dist = -10.0f;
        break;
        
    default:
        dist = 0.0f;
        break;
    }

    pos.x = plp->px - dist * njSin(plp->ay);
    pos.y = plp->py;
    pos.z = plp->pz - dist * njCos(plp->ay);

    dist = njSqrt((epw->px - pos.x) * (epw->px - pos.x) + (epw->pz - pos.z) * (epw->pz - pos.z));
    if (dist > 50.0f || dist < 30.0f)
    {
        return 0;
    }
        
    ang = bhArcTan2(epw->px - pos.x, epw->pz - pos.z) + NJM_DEG_ANG(90.0f);

    EXP0_F(0x68) = pos.x - 7.0f * njSin(ang);
    EXP0_F(0x6c) = pos.y;
    EXP0_F(0x70) = pos.z - 7.0f * njCos(ang);

    ang = (short)(bhArcTan2(epw->px - EXP0_F(0x68), epw->pz - EXP0_F(0x70)) - epw->ay);
    if (ang > NJM_DEG_ANG(25.0f) || ang < -NJM_DEG_ANG(25.0f))
    {
        return 0;
    }
        
    hp = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, (NJS_VECTOR*)(epw->exp0 + 0x68));
    if (hp != 0)
    {
        return 0;
    }
        
    vec.x = (EXP0_F(0x68) - epw->px) * 0.1f;
    vec.y = (EXP0_F(0x6C) - epw->py) * 0.1f;
    vec.z = (EXP0_F(0x70) - epw->pz) * 0.1f;
    pos.x = epw->px;
    pos.y = epw->py;
    pos.z = epw->pz;

    for (i = 0; i <= 10; i++)
    {
        hp = bhCheckWallType(&pos, 0, 2.0f, 25.0f);
        if (hp != 0)
        {
            return 0;
        }
            
        for (j = 0, epp = ene; j < sys->ewk_n; j++, epp++)
        {
            if ((epw != epp) &&
                (epp->flg & 0x1) &&
                (epp->flg & 0x8) &&
                !(epp->flg & 0x2))            
            {
                ln = njSqrt((epp->px - pos.x) * (epp->px - pos.x) + (epp->pz - pos.z) * (epp->pz - pos.z));
                if (ln < epw->car + epp->car)
                {
                    return 0;
                }
                    
            }
        }

        njAddVector(&pos, &vec);
    }

    return 1;
}

// 100% matching!
int bhEne05_CheckBackAttack(BH_PWORK* epw) 
{
	NJS_POINT3 pos;
	NJS_POINT3 vec;
	int i;
	int j;
	BH_PWORK* epp; 
	float ln;
	ATR_WORK* hp; 

    hp = bhEne_CheckEventAtr(epw->flr_no, epw->px, epw->pz, 5, 32, 32);
    if (hp != NULL)
    {
        return 0;
    } 
    
    hp = bhEne_CheckEventAtr(plp->flr_no, plp->px, plp->pz, 5, 33, 33);
    if (hp != NULL)
    {
        return 0;
    } 
    
    if (bhEne_CheckDirTarget(plp, epw->px, epw->pz, 3640) == 0)
    {
        return 0;
    } 

    epp = (BH_PWORK*)EXP0_I(0x60);
    if ((epp != NULL) && (bhEne_CheckDirTarget(plp, epp->px, epp->pz, 10922) == 0))
    {
        return 0;
    }

    EXP0_F(0x68) = plp->px - (10.0f * njSin(epw->ay));
    EXP0_F(0x6C) = plp->py;
    EXP0_F(0x70) = plp->pz - (10.0f * njCos(epw->ay));

    hp = bhCollisionCheckLine((NJS_VECTOR*)&epw->px, (NJS_VECTOR*)(epw->exp0 + 0x68));
    if (hp != 0)
    {
        return 0;
    }

    vec.x = 0.1f * (EXP0_F(0x68) - epw->px);
    vec.y = 0.1f * (EXP0_F(0x6C) - epw->py);
    vec.z = 0.1f * (EXP0_F(0x70) - epw->pz);

    pos.x = epw->px;
    pos.y = epw->py;
    pos.z = epw->pz;

    for (i = 0; i <= 10; i++)
    {
        BH_PWORK* epp;
        hp = bhCheckWallType(&pos, 0, 2.0f, 40.0f);
        if (hp != NULL)
        {
            return 0;
        }
        
        for (j = 0, epp = ene; j < sys->ewk_n; j++, epp++)
        {
            if ((epw != epp) &&
                (epp->flg & 0x1) &&
                (epp->flg & 0x8) &&
                !(epp->flg & 0x2))
            {
                ln = njSqrt((epp->px - pos.x) * (epp->px - pos.x) + (epp->pz - pos.z) * (epp->pz - pos.z));
                if (ln < epw->car + epp->car)
                {
                    return 0;
                }                
            }
        }
    
        njAddVector(&pos, &vec);
    }

    return 1;
}

// 100% matching!
int bhEne05_CheckHikkaki(BH_PWORK* epw)
{
    NJS_POINT3 pos1;
    NJS_POINT3 pos2;
 
    pos1.x = epw->px;
    pos1.y = 10.0f + epw->py;
    pos1.z = epw->pz;
    
    pos2.x = plp->px;
    pos2.y = 10.0f + plp->py;
    pos2.z = plp->pz;

    return (bhCollisionCheckLine3(&pos1, &pos2, 17408, epw->flr_no) != NULL) ? 0 : 1;
}

// 99.84% matching
int bhEne05_CheckPlyRoute(BH_PWORK* epw)
{
	NJS_POINT3 pos;
	NJS_POINT3 vec;
	int i;    
	ATR_WORK* hp;

    pos.x = epw->px;
    pos.y = epw->py;
    pos.z = epw->pz;
    
    if (bhCollisionCheckLine3((NJS_VECTOR*)&plp->px, &pos, 17408, epw->flr_no) != NULL)
    {
        return 0;
    }
    
    vec.x = 0.1f * (plp->px - epw->px);
    vec.y = 0.1f * (plp->py - epw->py);
    vec.z = 0.1f * (plp->pz - epw->pz);
    pos.x = epw->px;
    pos.y = epw->py;
    pos.z = epw->pz;
 
    for (i = 0; 10 >= i; i++)
    {
        if (bhCheckWallType(&pos, 0, 2.0f, 25.0f) != NULL)
        {
            return 0;
        }
    
        njAddVector(&pos, &vec);
    }
    
    return 1;
}

// 100% matching!
void bhEne05_HitMark(BH_PWORK* epw)
{
	int i;
	BLOOD_TBL* blp;
	NJS_POINT3 ofp;    
	int range;

    range = 0;

    if (epw->comb_flg & 4)
    {
        blp = &BloodTblF[epw->djnt_no];

    } 
    else
    {
        blp = &BloodTblR[epw->djnt_no];
    }
    
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
       
    if (DmgReact[epw->wpnr_no].type[range] >= 0)
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        
        ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);

        switch (epw->wpnr_no)
        {
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
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 1) && (blp->flg == 0))
    {
        for (i = 0; i < 4; i++)
        {
            ofp.x = blp->ofp.x;
            ofp.y = blp->ofp.y;
            ofp.z = blp->ofp.z;
            
            ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
            ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
            ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);

            bhEne_SetFireEffect(epw, epw->djnt_no, (NJS_POINT3*)&ofp, 0.5f + (0.5f * njRandom()), (int)(40.0f * njRandom()) + 20);
        } 
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 2))
    {
        ofp.x = blp->ofp.x;
        ofp.y = blp->ofp.y;
        ofp.z = blp->ofp.z;
        
        ofp.x += (blp->rx * njRandom()) - (blp->rx / 2.0f);
        ofp.y += (blp->ry * njRandom()) - (blp->ry / 2.0f);
        ofp.z += (blp->rz * njRandom()) - (blp->rz / 2.0f);
        
        bhEne_SetAcidEffect(epw, epw->djnt_no, (NJS_POINT3*) &ofp, 2.0f);
    }
    
    if ((DmgReact[epw->wpnr_no].exef & 4))
    {
        npSetAllMatColor(epw->mlwP->objP, epw->mlwP->obj_num, 0xFF201010U);
        epw->mdflg |= 0x400;
    }
}

// 100% matching!
void bhEne05_DustEffect(BH_PWORK* epw, int unk) // signature different from DWARF
{

}

// 100% matching!
void bhEne05_CallSE(BH_PWORK* epw) 
{
    int fno;
    
    if (epw->mnwP == epw->mnwPb)
    {
        fno = epw->frm_no / 65536;
        switch (epw->mtn_no)
        {
        case 0:
            if ((fno == 0) || (fno == 30))
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74499);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8979);
                }
            }
            break;
            
        case 1:
            if ((fno == 6) || (fno == 17))
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74500);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8979);
                }
            }
            break;
            
        case 29:
            if (fno == 14)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74503);
            }
            break;
            
        case 31:
        case 9:
        case 47:       
            if (fno == 0) 
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74501);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8979);
                }
            }
            break;
            
        case 32:
        case 11:
        case 48:
            if (fno == 0)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74502);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8979);
                }
            }
            break;
            
        case 33:
            if (fno == 28) 
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74503);
            }
            break;
            
        case 2:
        case 10:
            if (fno == 10)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 74503);
            }
            break;
            
        case 20:
            if (fno == 8)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }
            }
            break;
            
        case 12:
            if (fno == 10)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }
            }
            break;
            
        case 13:
            if (fno == 9)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }
            }
            break;
            
        case 14:
            if (fno == 16)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8976);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }                
            }
            break;
            
        case 15:
            if (fno == 3)
            {
                bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
            }
            if (fno == 15)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8976);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }    
            }
            break;
            
        case 41:
            if ((epw->flg & 0x2000000) && (fno == 10))
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }    
            }
            break;
            
        case 42:
            if (fno == 67)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }  
            }
            break;
            
        case 21:
            if (fno == 9)
            {
                if (!(epw->stflg & 0x100000))
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8975);
                } 
                else
                {
                    bhEne_CallSE(epw, (NJS_POINT3*)&epw->px, 8980);
                }  
            }
            break;
        }
    }
}
