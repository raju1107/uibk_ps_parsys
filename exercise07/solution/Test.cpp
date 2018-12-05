#include <gtest/gtest.h>
#include "Stencil.h"

double epsilon = 0.5;


//First and last element is overwritten with boundaries
std::vector<double> seqIn1D;
std::vector<double> seqOut1D;
std::vector<int> seqBounds1D;


//First and last element is overwritten with boundaries
std::vector<double> parIn1D;
std::vector<double> parOut1D;
std::vector<int> parBounds1D;


//First and last row and left-/rightmost element is overwritten with boundaries
std::vector<double> seqIn2D;
std::vector<double> seqOut2D;
std::vector<int> seqBounds2D;

//First and last row and left-/rightmost element is overwritten with boundaries
std::vector<double> parIn2D;
std::vector<double> parOut2D;
std::vector<int> parBounds2D;


//First and last row and left-/rightmost element is overwritten with boundaries
std::vector<double> seqIn3D;
std::vector<double> seqOut3D;
std::vector<int> seqBounds3D;

//First and last row and left-/rightmost element is overwritten with boundaries
std::vector<double> parIn3D;
std::vector<double> parOut3D;
std::vector<int> parBounds3D;


TEST(OneDim, Sequential) {
    seqIn1D.assign(6,1.0);
    seqOut1D.assign(6,1.0);
    seqBounds1D.assign(2,2);
    std::vector<double> check = {2,1.5,1,1,1.5,2};
    setBoundaries(1,seqIn1D.size(),seqBounds1D,seqIn1D);
    setBoundaries(1,seqOut1D.size(),seqBounds1D,seqOut1D);
    jacobi1DSeq(seqBounds1D,epsilon,&seqIn1D,&seqOut1D);
    EXPECT_TRUE(seqOut1D == check);
}

TEST(OneDim, Parallel) {
    parIn1D.assign(6,1.0);
    parOut1D.assign(6,1.0);
    parBounds1D.assign(2,2);
    std::vector<double> check = {2,1.5,1,1,1.5,2};
    setBoundaries(1,parIn1D.size(),parBounds1D,parIn1D);
    setBoundaries(1,parOut1D.size(),parBounds1D,parOut1D);
    jacobi1DPar(parBounds1D,epsilon,&parIn1D,&parOut1D);
    EXPECT_TRUE(parOut1D == check);
}


TEST(TwoDim, Sequential) {
    seqIn2D.assign(16,1.0);
    seqOut2D.assign(16,1.0);
    seqBounds2D.assign(4,2);
    std::vector<double> check = {2.0,2.0,2.0,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,2.0,2.0,2.0};
    setBoundaries(2,4,seqBounds2D,seqIn2D);
    setBoundaries(2,4,seqBounds2D,seqOut2D);
    jacobi2DSeq(seqBounds2D,epsilon,4,&seqIn2D,&seqOut2D);
    EXPECT_TRUE(seqOut2D == check);
}

TEST(TwoDim, Parallel) {
    parIn2D.assign(16,1.0);
    parOut2D.assign(16,1.0);
    parBounds2D.assign(4,2);
    std::vector<double> check = {2.0,2.0,2.0,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,2.0,2.0,2.0};
    setBoundaries(2,4,parBounds2D,parIn2D);
    setBoundaries(2,4,parBounds2D,parOut2D);
    jacobi2DPar(parBounds2D,epsilon,4,&parIn2D,&parOut2D);
    EXPECT_TRUE(parOut2D == check);
}


TEST(ThreeDim, Sequential) {
    seqIn3D.assign(64,1.0);
    seqOut3D.assign(64,1.0);
    seqBounds3D.assign(6,2);
    std::vector<double> check = {2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0};
    setBoundaries(3,4,seqBounds3D,seqIn3D);
    setBoundaries(3,4,seqBounds3D,seqOut3D);
    jacobi3DSeq(seqBounds3D,epsilon,4,&seqIn3D,&seqOut3D);
    EXPECT_TRUE(seqOut3D == check);
}

TEST(ThreeDim, Parallel) {
    parIn3D.assign(64,1.0);
    parOut3D.assign(64,1.0);
    parBounds3D.assign(6,2);
    std::vector<double> check = {2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,1.5,1.5,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0,
                                 2.0,2.0,2.0,2.0};
    setBoundaries(3,4,parBounds3D,parIn3D);
    setBoundaries(3,4,parBounds3D,parOut3D);
    jacobi3DPar(parBounds3D,epsilon,4,&parIn3D,&parOut3D);
    EXPECT_TRUE(parOut3D == check);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
