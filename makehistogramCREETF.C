#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TChain.h>
void makehistogramCREETF() {
    // Abre el archivo ROOT de entrada
    TChain *chain_new = new TChain("XCDF", "");
    chain_new->Add("/lustre/hawcz01/scratch/userspace/tcapistran/CREnergyMLT/ModelTFAddNN/RUNS/combined/run005481.root");
    chain_new->Add("/lustre/hawcz01/scratch/userspace/tcapistran/CREnergyMLT/ModelTFAddNN/RUNS/combined/run005481_1.root");

    // Crea un histograma
    //TH1F *hist = new TH1F("histogram_recEnergy", "histogram_recEnergy", 22, 3.0, 6.5);  // Ajusta los parámetros según tus necesidades
    TH1F *hist = new TH1F("histogram_recEnergy", "histogram_recEnergy", 22, 2.0, 6.4);
    // Llena el histograma con los datos de la rama "energy"
    //TF NN
    chain_new->Draw("rec.tfout >> histogram_recEnergy","(rec.angleFitStatus==0)&&(rec.coreFitStatus==0)&&(rec.nHit>75)&&(1.0*rec.nChAvail>0.0)&&(rec.CxPE40XnCh>=40)&&(rec.coreFiduScale>0)&&(1.0*rec.nHit/rec.nChAvail>=0.2)&&(rec.zenithAngle>0.0)&&(rec.zenithAngle*180.0<35.0*TMath::Pi())&&(!(rec.mlout>6&&800<=rec.nHit))");

    // Guarda el histograma en un nuevo archivo ROOT
    TFile *output_file = new TFile("histogram_run005481.root", "RECREATE");
    hist->Write();
    output_file->Close();

    // Cierra el archivo de entrada
    chain_new->Close();
}

