#include <iostream>
using namespace std;
#define matrixSize 5

class Array {
private:
    int PrivateArr[matrixSize];
public:
    friend void setMatrix(Array Matrix[]);
    friend void coutMatrix(Array Matrix[]);
    friend void findArithmeticMean(Array *Matr);
    friend void sortArray(Array  temporaryArray[], int matrixCursor);
    int operator [] (int row){
         return PrivateArr[row];
     }
};

void sortArray(Array  temporaryArray[], int matrixCursor)
{
    for (int row = 0; row < matrixCursor; row++)
    {
        for (int BlockSizeIter = 1; BlockSizeIter < matrixCursor; BlockSizeIter *= 2)
        {
            for (int BlockIter = 0; BlockIter < matrixCursor - BlockSizeIter; BlockIter += 2 * BlockSizeIter)
            {
                int LeftBlockIter = 0;
                int RightBlockIter = 0;
                int LeftBorder = BlockIter;
                int MidBorder = BlockIter + BlockSizeIter;
                int RightBorder = BlockIter + 2 * BlockSizeIter;
                RightBorder = (RightBorder < matrixCursor) ? RightBorder : matrixCursor;
                int* SortedBlock = new int[RightBorder - LeftBorder];

                while (LeftBorder + LeftBlockIter < MidBorder && MidBorder + RightBlockIter < RightBorder)
                {
                    if (temporaryArray[row].PrivateArr[LeftBorder + LeftBlockIter] > temporaryArray[row].PrivateArr[MidBorder + RightBlockIter])
                    {
                        SortedBlock[LeftBlockIter + RightBlockIter] = temporaryArray[row].PrivateArr[LeftBorder + LeftBlockIter];
                        LeftBlockIter++;
                    }
                    else
                    {
                        SortedBlock[LeftBlockIter + RightBlockIter] = temporaryArray[row].PrivateArr[MidBorder + RightBlockIter];
                        RightBlockIter++;
                    }
                }
                while (LeftBorder + LeftBlockIter < MidBorder)
                {
                    SortedBlock[LeftBlockIter + RightBlockIter] = temporaryArray[row].PrivateArr[LeftBorder + LeftBlockIter];
                    LeftBlockIter++;
                }
                while (MidBorder + RightBlockIter < RightBorder)
                {
                    SortedBlock[LeftBlockIter + RightBlockIter] = temporaryArray[row].PrivateArr[MidBorder + RightBlockIter];
                    RightBlockIter++;
                }

                for (int MergeIter = 0; MergeIter < LeftBlockIter + RightBlockIter; MergeIter++)
                {
                    temporaryArray[row].PrivateArr[LeftBorder + MergeIter] = SortedBlock[MergeIter];
                }
                delete SortedBlock;

            }

        }
    }
}
void setMatrix(Array Matrix[]) {
        for (int row = 0; row <matrixSize ; row++) {
            for (int column = 0; column <matrixSize ; column++) {
                cout << "Enter array element ¹" << column + 1 << endl;
                cin>>Matrix[row].PrivateArr[column];
            }
        }
}
void coutMatrix(Array Matrix[]){
    for (int row = 0; row <matrixSize ; row++) {
        for (int column = 0; column <matrixSize ; column++) {
            cout<<Matrix[row].PrivateArr[column]<<"     ";
        }
        cout<<"\n\n";
    }
}
void findArithmeticMean(Array *Matr){
    int matrixCursor = 0;
    float res=1;
    for (int k = 0,r=1; k < matrixSize-1 ; k++,r++) {
        matrixCursor = 0;
        float s = 0;
        cout<<"Product of elements ";
        for (int l = 0; l < matrixSize - k - 1 ; l++) {
            s+=Matr[l][k];
            cout<<Matr[l][k]<<"  ";
            matrixCursor++;
        }
        if (matrixCursor != 0) {
            s /= matrixCursor;
            cout<<" === "<<s<<endl;
        }
        res*=s;
    }
    cout<<"F(findArithmeticMean)= "<<res<<endl;
}

int main(){
    Array Matrix[matrixSize];
    cout<<"\t\tInput matrix"<<endl;
    setMatrix(Matrix);
    cout<<"\t\tOutput not-sorted matrix"<<endl;
    coutMatrix(Matrix);
    cout<<"\n\n\n";

    cout<<"\t\tOutPut sorted matrix"<<endl;
    sortArray(Matrix,matrixSize);

    coutMatrix(Matrix);
    cout<<"\t\tOutPut Fi(Aij)"<<endl;
    findArithmeticMean(Matrix);
    return 0;
}
