#include "H2I.h"


ClassImp(rh::H2I)

namespace rh {

using namespace std;


H2I::H2I() : TH2I()
{
}


H2I::H2I(string name, string title, Int_t nbinsx, Double_t xlow, Double_t xup, Int_t nbinsy, Double_t ylow, Double_t yup, string options) :
   TH2I(name.c_str(), title.c_str(), nbinsx, xlow, xup, nbinsy, ylow, yup)
{
   SetOption(options.c_str());
}

}
