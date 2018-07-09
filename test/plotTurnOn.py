from optparse import OptionParser
import ROOT as rt
from array import *
import os
import random
import sys
import math

def setStyle():
    rt.gStyle.SetOptStat(0)
    rt.gStyle.SetOptFit(0000)
    rt.gStyle.SetOptTitle(0)
    rt.gStyle.SetPaintTextFormat("1.2g")
    #rt.gStyle.SetPalette()
    rt.gStyle.SetNumberContours(999)
    rt.gROOT.SetBatch()
    rt.RooMsgService.instance().setGlobalKillBelow(rt.RooFit.FATAL)
    
    rt.gStyle.SetStatY(1.9)
    rt.gStyle.SetStatX(1.9)
    rt.gStyle.SetStatW(0.1)
    rt.gStyle.SetStatH(0.1)


if __name__ == '__main__':
    parser = OptionParser()
    parser.add_option('-d','--dir',dest="outDir",default="DoubleB_Efficiencies",type="string",
                  help="Output directory to store results")
    parser.add_option('-l','--lumi',dest="lumi", default=300.,type="float",
                  help="integrated luminosity in pb^-1")
    parser.add_option('--numerator',dest="numerator",default="demo/histoDir/recoAK8pT_DoubleBTrig_np4",type="string", 
                  help="numerator trigger")
    parser.add_option('--denominator',dest="denominator",default="demo/histoDir/recoAK8pT",type="string",
                  help="denominator trigger")
    parser.add_option('-i',dest="inputFile",default="AnalysisOutput_DoubleB.root",type="string",
                  help="denominator trigger")


    
    (options,args) = parser.parse_args()
     


    tfile = rt.TFile.Open(options.inputFile,'read')

    num = tfile.Get(options.numerator)
    denom = tfile.Get(options.denominator)

    print "num.GetNbinsX(): ", num.GetNbinsX()
    print "denom.GetNbinsX(): ", denom.GetNbinsX()

    # rebin
    num.Rebin(2)
    denom.Rebin(2)
     
    setStyle()
    c = rt.TCanvas("c_"+options.numerator.split('/')[-1],"c_"+options.numerator.split('/')[-1],500,400)
    c.SetRightMargin(0.15)

    pEff = rt.TEfficiency(num, denom)
    pEff.SetName('eff_'+options.numerator.split('/')[-1])
    if 'recoAK8pT' in options.numerator:
	xaxisTitle = "p_{T} (GeV)"
    elif 'recoAK8csv' in options.numerator:
        xaxisTitle = "CSV"
    elif 'recoAK8DoubleB' in options.numerator:
        xaxisTitle = "DoubleB"
    elif 'recoAK8Maxcsv' in options.numerator:
        xaxisTitle = "CSV"
    elif 'recoAK8MaxDoubleB' in options.numerator:
        xaxisTitle = "DoubleB"
    
    pEff.SetTitle("efficiency;%s;efficiency"%xaxisTitle)
    
    pEff.SetMarkerSize(0.8)
    pEff.SetMarkerStyle(20)
    pEff.Draw("apez")
    
    rt.gPad.Update()        
    pEff.GetPaintedGraph().SetMarkerStyle(8)
    pEff.GetPaintedGraph().SetMarkerSize(20)        
    pEff.GetPaintedGraph().SetMinimum(0)
    pEff.GetPaintedGraph().SetMaximum(1.1)
    pEff.GetPaintedGraph().GetXaxis().SetTitle('Wide m_{jj}')
    
    rt.gPad.Update()      
    l = rt.TLatex()
    l.SetTextAlign(11)
    l.SetTextSize(0.045)
    l.SetTextFont(42)
    l.SetNDC()
    l.DrawLatex(0.12,0.92,"CMS preliminary")
#    l.DrawLatex(0.6,0.92,"13 TeV (%.1f fb^{-1})"%(options.lumi/1000.))
    l.SetTextFont(52)
    #l.DrawLatex(0.7,0.75,"R^{2} > %.2f"%yCut)
    l.SetTextSize(0.02)
    l.SetTextFont(42)        

    c.Print(options.outDir+"/"+"HltEff_" + options.numerator.split('/')[-1] + ".pdf")
    c.Print(options.outDir+"/"+"HltEff_" + options.numerator.split('/')[-1] + ".C")


    rootFile = rt.TFile.Open('HltEff.root','update')
    tdirectory = rootFile.GetDirectory('HltEff')
    if tdirectory==None:
        rootFile.mkdir('HltEff')
        tdirectory = rootFile.GetDirectory('HltEff')
    
    tdirectory.cd()
    pEff.Write()
    c.Write()
