#include "H2F.h"

ClassImp(rh::H2F)

namespace rh {

using namespace std;


H2F::H2F() : TH2F()
{
}


H2F::H2F(string name, string title, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup, string options) :
   TH2F(name.c_str(), title.c_str(), nbinsx, xlow, xup, nbinsy, ylow, yup)
{
   SetOption(options.c_str());
}

}
