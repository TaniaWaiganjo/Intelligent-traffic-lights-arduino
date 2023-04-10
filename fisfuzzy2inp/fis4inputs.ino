//***********************************************************************
// Matlab .fis to arduino C converter v2.0.1.25122016                   
//     
//***********************************************************************

#include "fis_header.h"

// Number of inputs to the fuzzy inference system
const int fis_gcI = 8;
// Number of outputs to the fuzzy inference system
const int fis_gcO = 2;
// Number of rules to the fuzzy inference system
const int fis_gcR = 18;

FIS_TYPE g_fisInput[fis_gcI];
FIS_TYPE g_fisOutput[fis_gcO];

// Setup routine runs once when you press reset:
void setup()
{
    // initialize the Analog pins for input.
    // Pin mode for Input: queueLengthA
    pinMode(0 , INPUT);
    // Pin mode for Input: waitTimeA
    pinMode(1 , INPUT);
    // Pin mode for Input: queueLengthB
    pinMode(2 , INPUT);
    // Pin mode for Input: waitTimeB
    pinMode(3 , INPUT);
    // Pin mode for Input: queueLenghtC
    pinMode(4 , INPUT);
    // Pin mode for Input: waitTimeC
    pinMode(5 , INPUT);
    // Pin mode for Input: queueLengthD
    pinMode(6 , INPUT);
    // Pin mode for Input: waitTimeD
    pinMode(7 , INPUT);


    // initialize the Analog pins for output.
    // Pin mode for Output: priority
    pinMode(8 , OUTPUT);
    // Pin mode for Output: output2
    pinMode(9 , OUTPUT);

}

// Loop routine runs over and over again forever:
void loop()
{
    // Read Input: queueLengthA
    g_fisInput[0] = analogRead(0);
    // Read Input: waitTimeA
    g_fisInput[1] = analogRead(1);
    // Read Input: queueLengthB
    g_fisInput[2] = analogRead(2);
    // Read Input: waitTimeB
    g_fisInput[3] = analogRead(3);
    // Read Input: queueLenghtC
    g_fisInput[4] = analogRead(4);
    // Read Input: waitTimeC
    g_fisInput[5] = analogRead(5);
    // Read Input: queueLengthD
    g_fisInput[6] = analogRead(6);
    // Read Input: waitTimeD
    g_fisInput[7] = analogRead(7);

    g_fisOutput[0] = 0;
    g_fisOutput[1] = 0;

    fis_evaluate();

    // Set output vlaue: priority
    analogWrite(8 , g_fisOutput[0]);
    // Set output vlaue: output2
    analogWrite(9 , g_fisOutput[1]);

}

//***********************************************************************
// Support functions for Fuzzy Inference System                          
//***********************************************************************
// Gaussian Member Function
FIS_TYPE fis_gaussmf(FIS_TYPE x, FIS_TYPE* p)
{
    FIS_TYPE s = p[0], c = p[1];
    FIS_TYPE t = (x - c) / s;
    return exp(-(t * t) / 2);
}

// Triangular Member Function
FIS_TYPE fis_trimf(FIS_TYPE x, FIS_TYPE* p)
{
    FIS_TYPE a = p[0], b = p[1], c = p[2];
    FIS_TYPE t1 = (x - a) / (b - a);
    FIS_TYPE t2 = (c - x) / (c - b);
    if ((a == b) && (b == c)) return (FIS_TYPE) (x == a);
    if (a == b) return (FIS_TYPE) (t2*(b <= x)*(x <= c));
    if (b == c) return (FIS_TYPE) (t1*(a <= x)*(x <= b));
    t1 = min(t1, t2);
    return (FIS_TYPE) max(t1, 0);
}

FIS_TYPE fis_min(FIS_TYPE a, FIS_TYPE b)
{
    return min(a, b);
}

FIS_TYPE fis_max(FIS_TYPE a, FIS_TYPE b)
{
    return max(a, b);
}

FIS_TYPE fis_array_operation(FIS_TYPE *array, int size, _FIS_ARR_OP pfnOp)
{
    int i;
    FIS_TYPE ret = 0;

    if (size == 0) return ret;
    if (size == 1) return array[0];

    ret = array[0];
    for (i = 1; i < size; i++)
    {
        ret = (*pfnOp)(ret, array[i]);
    }

    return ret;
}


//***********************************************************************
// Data for Fuzzy Inference System                                       
//***********************************************************************
// Pointers to the implementations of member functions
_FIS_MF fis_gMF[] =
{
    fis_gaussmf, fis_trimf
};

// Count of member function for each Input
int fis_gIMFCount[] = { 3, 3, 3, 3, 3, 3, 3, 3 };

// Count of member function for each Output 
int fis_gOMFCount[] = { 3, 3 };

// Coefficients for the Input Member Functions
FIS_TYPE fis_gMFI0Coeff1[] = { 3.893, 1.665e-16 };
FIS_TYPE fis_gMFI0Coeff2[] = { 3.893, 11 };
FIS_TYPE fis_gMFI0Coeff3[] = { 3.893, 22 };
FIS_TYPE* fis_gMFI0Coeff[] = { fis_gMFI0Coeff1, fis_gMFI0Coeff2, fis_gMFI0Coeff3 };
FIS_TYPE fis_gMFI1Coeff1[] = { 42.47, -8.882e-16 };
FIS_TYPE fis_gMFI1Coeff2[] = { 42.47, 120 };
FIS_TYPE fis_gMFI1Coeff3[] = { 42.47, 240 };
FIS_TYPE* fis_gMFI1Coeff[] = { fis_gMFI1Coeff1, fis_gMFI1Coeff2, fis_gMFI1Coeff3 };
FIS_TYPE fis_gMFI2Coeff1[] = { 3.893, 1.665e-16 };
FIS_TYPE fis_gMFI2Coeff2[] = { 3.893, 11 };
FIS_TYPE fis_gMFI2Coeff3[] = { 3.893, 22 };
FIS_TYPE* fis_gMFI2Coeff[] = { fis_gMFI2Coeff1, fis_gMFI2Coeff2, fis_gMFI2Coeff3 };
FIS_TYPE fis_gMFI3Coeff1[] = { 42.47, -8.882e-16 };
FIS_TYPE fis_gMFI3Coeff2[] = { 42.47, 120 };
FIS_TYPE fis_gMFI3Coeff3[] = { 42.47, 240 };
FIS_TYPE* fis_gMFI3Coeff[] = { fis_gMFI3Coeff1, fis_gMFI3Coeff2, fis_gMFI3Coeff3 };
FIS_TYPE fis_gMFI4Coeff1[] = { 3.893, 1.665e-16 };
FIS_TYPE fis_gMFI4Coeff2[] = { 3.893, 11 };
FIS_TYPE fis_gMFI4Coeff3[] = { 3.893, 22 };
FIS_TYPE* fis_gMFI4Coeff[] = { fis_gMFI4Coeff1, fis_gMFI4Coeff2, fis_gMFI4Coeff3 };
FIS_TYPE fis_gMFI5Coeff1[] = { 42.47, -8.882e-16 };
FIS_TYPE fis_gMFI5Coeff2[] = { 42.47, 120 };
FIS_TYPE fis_gMFI5Coeff3[] = { 42.47, 240 };
FIS_TYPE* fis_gMFI5Coeff[] = { fis_gMFI5Coeff1, fis_gMFI5Coeff2, fis_gMFI5Coeff3 };
FIS_TYPE fis_gMFI6Coeff1[] = { 3.893, 1.665e-16 };
FIS_TYPE fis_gMFI6Coeff2[] = { 3.893, 11 };
FIS_TYPE fis_gMFI6Coeff3[] = { 3.893, 22 };
FIS_TYPE* fis_gMFI6Coeff[] = { fis_gMFI6Coeff1, fis_gMFI6Coeff2, fis_gMFI6Coeff3 };
FIS_TYPE fis_gMFI7Coeff1[] = { 42.47, -8.882e-16 };
FIS_TYPE fis_gMFI7Coeff2[] = { 42.47, 120 };
FIS_TYPE fis_gMFI7Coeff3[] = { 42.47, 240 };
FIS_TYPE* fis_gMFI7Coeff[] = { fis_gMFI7Coeff1, fis_gMFI7Coeff2, fis_gMFI7Coeff3 };
FIS_TYPE** fis_gMFICoeff[] = { fis_gMFI0Coeff, fis_gMFI1Coeff, fis_gMFI2Coeff, fis_gMFI3Coeff, fis_gMFI4Coeff, fis_gMFI5Coeff, fis_gMFI6Coeff, fis_gMFI7Coeff };

// Coefficients for the Output Member Functions
FIS_TYPE fis_gMFO0Coeff1[] = { -0.416666666666667, 0, 0.416666666666667 };
FIS_TYPE fis_gMFO0Coeff2[] = { 0.0833333333333333, 0.5, 0.916666666666667 };
FIS_TYPE fis_gMFO0Coeff3[] = { 0.583333333333333, 1, 1.41666666666667 };
FIS_TYPE* fis_gMFO0Coeff[] = { fis_gMFO0Coeff1, fis_gMFO0Coeff2, fis_gMFO0Coeff3 };
FIS_TYPE fis_gMFO1Coeff1[] = { -0.416666666666667, 0, 0.416666666666667 };
FIS_TYPE fis_gMFO1Coeff2[] = { 0.0833333333333333, 0.5, 0.916666666666667 };
FIS_TYPE fis_gMFO1Coeff3[] = { 0.583333333333333, 1, 1.41666666666667 };
FIS_TYPE* fis_gMFO1Coeff[] = { fis_gMFO1Coeff1, fis_gMFO1Coeff2, fis_gMFO1Coeff3 };
FIS_TYPE** fis_gMFOCoeff[] = { fis_gMFO0Coeff, fis_gMFO1Coeff };

// Input membership function set
int fis_gMFI0[] = { 0, 0, 0 };
int fis_gMFI1[] = { 0, 0, 0 };
int fis_gMFI2[] = { 0, 0, 0 };
int fis_gMFI3[] = { 0, 0, 0 };
int fis_gMFI4[] = { 0, 0, 0 };
int fis_gMFI5[] = { 0, 0, 0 };
int fis_gMFI6[] = { 0, 0, 0 };
int fis_gMFI7[] = { 0, 0, 0 };
int* fis_gMFI[] = { fis_gMFI0, fis_gMFI1, fis_gMFI2, fis_gMFI3, fis_gMFI4, fis_gMFI5, fis_gMFI6, fis_gMFI7};

// Output membership function set
int fis_gMFO0[] = { 1, 1, 1 };
int fis_gMFO1[] = { 1, 1, 1 };
int* fis_gMFO[] = { fis_gMFO0, fis_gMFO1};

// Rule Weights
FIS_TYPE fis_gRWeight[] = { 0.7, 0.7, 0.7, 0.7, 0.7, 0.8, 0.7, 0.9, 1, 0.7, 0.7, 0.7, 0.7, 0.7, 0.8, 0.7, 0.9, 1 };

// Rule Type
int fis_gRType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Rule Inputs
int fis_gRI0[] = { 1, 1, 0, 0, 0, 0, 0, 0 };
int fis_gRI1[] = { 2, 1, 0, 0, 0, 0, 0, 0 };
int fis_gRI2[] = { 3, 1, 0, 0, 0, 0, 0, 0 };
int fis_gRI3[] = { 1, 2, 0, 0, 0, 0, 0, 0 };
int fis_gRI4[] = { 2, 2, 0, 0, 0, 0, 0, 0 };
int fis_gRI5[] = { 3, 2, 0, 0, 0, 0, 0, 0 };
int fis_gRI6[] = { 1, 3, 0, 0, 0, 0, 0, 0 };
int fis_gRI7[] = { 2, 3, 0, 0, 0, 0, 0, 0 };
int fis_gRI8[] = { 3, 3, 0, 0, 0, 0, 0, 0 };
int fis_gRI9[] = { 0, 0, 1, 1, 0, 0, 0, 0 };
int fis_gRI10[] = { 0, 0, 2, 1, 0, 0, 0, 0 };
int fis_gRI11[] = { 0, 0, 3, 1, 0, 0, 0, 0 };
int fis_gRI12[] = { 0, 0, 1, 2, 0, 0, 0, 0 };
int fis_gRI13[] = { 0, 0, 2, 2, 0, 0, 0, 0 };
int fis_gRI14[] = { 0, 0, 3, 2, 0, 0, 0, 0 };
int fis_gRI15[] = { 0, 0, 1, 3, 0, 0, 0, 0 };
int fis_gRI16[] = { 0, 0, 2, 3, 0, 0, 0, 0 };
int fis_gRI17[] = { 0, 0, 3, 3, 0, 0, 0, 0 };
int* fis_gRI[] = { fis_gRI0, fis_gRI1, fis_gRI2, fis_gRI3, fis_gRI4, fis_gRI5, fis_gRI6, fis_gRI7, fis_gRI8, fis_gRI9, fis_gRI10, fis_gRI11, fis_gRI12, fis_gRI13, fis_gRI14, fis_gRI15, fis_gRI16, fis_gRI17 };

// Rule Outputs
int fis_gRO0[] = { 1, 0 };
int fis_gRO1[] = { 1, 0 };
int fis_gRO2[] = { 2, 0 };
int fis_gRO3[] = { 1, 0 };
int fis_gRO4[] = { 2, 0 };
int fis_gRO5[] = { 3, 0 };
int fis_gRO6[] = { 2, 0 };
int fis_gRO7[] = { 3, 0 };
int fis_gRO8[] = { 3, 0 };
int fis_gRO9[] = { 1, 0 };
int fis_gRO10[] = { 1, 0 };
int fis_gRO11[] = { 2, 0 };
int fis_gRO12[] = { 1, 0 };
int fis_gRO13[] = { 2, 0 };
int fis_gRO14[] = { 3, 0 };
int fis_gRO15[] = { 2, 0 };
int fis_gRO16[] = { 3, 0 };
int fis_gRO17[] = { 3, 0 };
int* fis_gRO[] = { fis_gRO0, fis_gRO1, fis_gRO2, fis_gRO3, fis_gRO4, fis_gRO5, fis_gRO6, fis_gRO7, fis_gRO8, fis_gRO9, fis_gRO10, fis_gRO11, fis_gRO12, fis_gRO13, fis_gRO14, fis_gRO15, fis_gRO16, fis_gRO17 };

// Input range Min
FIS_TYPE fis_gIMin[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

// Input range Max
FIS_TYPE fis_gIMax[] = { 22, 240, 22, 240, 22, 240, 22, 240 };

// Output range Min
FIS_TYPE fis_gOMin[] = { 0, 0 };

// Output range Max
FIS_TYPE fis_gOMax[] = { 1, 1 };

//***********************************************************************
// Data dependent support functions for Fuzzy Inference System           
//***********************************************************************
FIS_TYPE fis_MF_out(FIS_TYPE** fuzzyRuleSet, FIS_TYPE x, int o)
{
    FIS_TYPE mfOut;
    int r;

    for (r = 0; r < fis_gcR; ++r)
    {
        int index = fis_gRO[r][o];
        if (index > 0)
        {
            index = index - 1;
            mfOut = (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
        }
        else if (index < 0)
        {
            index = -index - 1;
            mfOut = 1 - (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
        }
        else
        {
            mfOut = 0;
        }

        fuzzyRuleSet[0][r] = fis_min(mfOut, fuzzyRuleSet[1][r]);
    }
    return fis_array_operation(fuzzyRuleSet[0], fis_gcR, fis_max);
}

FIS_TYPE fis_defuzz_centroid(FIS_TYPE** fuzzyRuleSet, int o)
{
    FIS_TYPE step = (fis_gOMax[o] - fis_gOMin[o]) / (FIS_RESOLUSION - 1);
    FIS_TYPE area = 0;
    FIS_TYPE momentum = 0;
    FIS_TYPE dist, slice;
    int i;

    // calculate the area under the curve formed by the MF outputs
    for (i = 0; i < FIS_RESOLUSION; ++i){
        dist = fis_gOMin[o] + (step * i);
        slice = step * fis_MF_out(fuzzyRuleSet, dist, o);
        area += slice;
        momentum += slice*dist;
    }

    return ((area == 0) ? ((fis_gOMax[o] + fis_gOMin[o]) / 2) : (momentum / area));
}

//***********************************************************************
// Fuzzy Inference System                                                
//***********************************************************************
void fis_evaluate()
{
    FIS_TYPE fuzzyInput0[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput1[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput2[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput3[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput4[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput5[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput6[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput7[] = { 0, 0, 0 };
    FIS_TYPE* fuzzyInput[fis_gcI] = { fuzzyInput0, fuzzyInput1, fuzzyInput2, fuzzyInput3, fuzzyInput4, fuzzyInput5, fuzzyInput6, fuzzyInput7, };
    FIS_TYPE fuzzyOutput0[] = { 0, 0, 0 };
    FIS_TYPE fuzzyOutput1[] = { 0, 0, 0 };
    FIS_TYPE* fuzzyOutput[fis_gcO] = { fuzzyOutput0, fuzzyOutput1, };
    FIS_TYPE fuzzyRules[fis_gcR] = { 0 };
    FIS_TYPE fuzzyFires[fis_gcR] = { 0 };
    FIS_TYPE* fuzzyRuleSet[] = { fuzzyRules, fuzzyFires };
    FIS_TYPE sW = 0;

    // Transforming input to fuzzy Input
    int i, j, r, o;
    for (i = 0; i < fis_gcI; ++i)
    {
        for (j = 0; j < fis_gIMFCount[i]; ++j)
        {
            fuzzyInput[i][j] =
                (fis_gMF[fis_gMFI[i][j]])(g_fisInput[i], fis_gMFICoeff[i][j]);
        }
    }

    int index = 0;
    for (r = 0; r < fis_gcR; ++r)
    {
        if (fis_gRType[r] == 1)
        {
            fuzzyFires[r] = FIS_MAX;
            for (i = 0; i < fis_gcI; ++i)
            {
                index = fis_gRI[r][i];
                if (index > 0)
                    fuzzyFires[r] = fis_min(fuzzyFires[r], fuzzyInput[i][index - 1]);
                else if (index < 0)
                    fuzzyFires[r] = fis_min(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                else
                    fuzzyFires[r] = fis_min(fuzzyFires[r], 1);
            }
        }
        else
        {
            fuzzyFires[r] = FIS_MIN;
            for (i = 0; i < fis_gcI; ++i)
            {
                index = fis_gRI[r][i];
                if (index > 0)
                    fuzzyFires[r] = fis_max(fuzzyFires[r], fuzzyInput[i][index - 1]);
                else if (index < 0)
                    fuzzyFires[r] = fis_max(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                else
                    fuzzyFires[r] = fis_max(fuzzyFires[r], 0);
            }
        }

        fuzzyFires[r] = fis_gRWeight[r] * fuzzyFires[r];
        sW += fuzzyFires[r];
    }

    if (sW == 0)
    {
        for (o = 0; o < fis_gcO; ++o)
        {
            g_fisOutput[o] = ((fis_gOMax[o] + fis_gOMin[o]) / 2);
        }
    }
    else
    {
        for (o = 0; o < fis_gcO; ++o)
        {
            g_fisOutput[o] = fis_defuzz_centroid(fuzzyRuleSet, o);
        }
    }
}
