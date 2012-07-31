#include <iostream>
#include <cstdio>
#define DICETYPES 5
#define NDICE 4*6*8*12
#define SUM 4*6*8*12*20+1

using namespace std;

int side[] = {4,6,8,12,20};
int maxdice[] = {1,4,4*6,4*6*8,4*6*8*12};

double diceprobs[DICETYPES][NDICE+1][SUM];

int main() {
    double condprobs[DICETYPES][SUM];
    // Initialize
    for (int i = 0; i < DICETYPES; ++i) {
        for (int j = 0; j < NDICE+1; ++j) {
            for (int k = 0; k < SUM; ++k) {
                diceprobs[i][j][k] = 0.;
            }
        }
        for (int j = 0; j < SUM; ++j) {
            condprobs[i][j] = 0.;
        }
    }
    cout << "Done init" << endl;
    // Generate the probabilities of rolling z with y+1 x-sided dice in diceprobs[x][y][z]
    for (int i = 0; i < DICETYPES; ++i) {
        for (int j = 0; j < side[i]; ++j) diceprobs[i][1][j+1] = 1./side[i];
        for (int j = 2; j <= maxdice[i]; ++j) {
            for (int k = 1; k <= j*side[i]; ++k) {
                for (int l = 1; l <= side[i]; ++l) {
                    diceprobs[i][j][k+l] += diceprobs[i][j-1][k]/side[i];
                }
            }
        }
    }
    cout << "Done prob generation" << endl;

    // Generate conditional probabilities based on diceprobs
    for (int i = 1; i <= side[0]; ++i) condprobs[0][i] = 1./side[0];
    for (int i = 1; i < DICETYPES; ++i) {
        for (int j = 1; j <= maxdice[i]; ++j) {
            for (int k = 1; k <= side[i]*maxdice[i]; ++k) {
                condprobs[i][k] += condprobs[i-1][j]*diceprobs[i][j][k];
            }
        }
    }
    cout << "Done conditional prob generation" << endl;

    // Calculate mean
    double mu = 0.;
    for (int i = 0; i < SUM; ++i) {
        mu += condprobs[DICETYPES-1][i]*i;
    }
    // Calculate variance
    double sigma = 0.;
    for (int i = 0; i < SUM; ++i) {
        sigma += condprobs[DICETYPES-1][i]*(mu-i)*(mu-i);
    }

    printf("Mean: %.4f\n", mu);
    printf("Variance: %.4f\n", sigma);
    return 0;
}
