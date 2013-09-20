
#include "MultiGraph.h"

#include "TList.h"
#include "TGraph.h"
#include "TPad.h"
#include "TPaveStats.h"


ClassImp(rh::MultiGraph)

namespace rh {

using namespace std;

MultiGraph::MultiGraph() : TMultiGraph()
{
}

MultiGraph::MultiGraph(string name, string title) : TMultiGraph(name.c_str(), title.c_str())
{
}


void MultiGraph::SetHistogram(TH1F* h)
{
   fHistogram = h;
}


void MultiGraph::Draw(Option_t* chopt)
{
   TMultiGraph::Draw(chopt);
   gPad->Update();

   TIter  next(GetListOfGraphs());
   UShort_t iStat = 0;

   while ( TGraph *iGraph = (TGraph*) next() )
   {
      if ( iGraph->GetN() <= 0) continue;

      TPaveStats *stats = (TPaveStats*) iGraph->FindObject("stats");

      if (stats) {
         stats->SetLineColor(iGraph->GetMarkerColor());
         stats->SetLineWidth(2);
         stats->SetX1NDC(0.80);
         stats->SetY1NDC(0.81 - iStat*0.18);
         stats->SetX2NDC(0.99);
         stats->SetY2NDC(0.99 - iStat*0.18);

         iStat++;
      }
   }
}

}
