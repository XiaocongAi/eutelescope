// -*- C++ -*-
/*
 *   This source code is part of the Eutelescope package of Marlin.
 *   You are free to use this source files for your own development as
 *   long as it stays in a public research context. You are not
 *   allowed to use it for commercial purpose. You must put this
 *   header with author names in all development based on this file.
 *
 */

#ifndef EUTELPSEUDO1DHISTOGRAM_H
#define EUTELPSEUDO1DHISTOGRAM_H 1

// system includes <>
#include <iostream>
#include <cmath>


namespace eutelescope {

  //! Simple class with a 1D histogram-like array w/o any display features
  /*! This very simple class has been copied and integrated with some
   *  missing features from the MarlinUtil package PseudoHistogram
   *  class. This is nothing else than a 1D histogram with an uniform
   *  binning of the x axis.
   *
   *  The main advantage of this histogram with respect to a real
   *  histogram (from an histogramming package like AIDA or ROOT) is
   *  clear for all the applications in which a display of the
   *  histogram is not needed. In these case in fact, using a such
   *  light weigth object is better than linking agaist a full
   *  histogramming package.
   *
   *  Original files: src/PseudoHistogram.cc include/PseudoHistogram.h
   *  in the MarlinUtil package were written by O. Wendt (DESY)
   *
   *  @author Antonio Bulgheroni, INFN <mailto:antonio.bulgheroni@gmail.com>
   *  @version $Id: EUTelPseudo1DHistogram.h,v 1.1 2007-04-02 14:17:39 bulgheroni Exp $
   */ 
  
  class EUTelPseudo1DHistogram {
    
  public:
    
    //! Constructor with number of bins and lower and upper boundaries
    /*! This is the default constructor. 
     *
     *  @param noOfBins : number of bins in the histogram. Over- and
     *  underflow bin are created additionally.  
     *  
     *  @param min : smallest value in the histogram 
     *
     *  @param max : largest value in the histogram
     */
    EUTelPseudo1DHistogram(int noOfBins, double min, double max);
    
    //! Destructor
    ~EUTelPseudo1DHistogram();
  
    //! Clear content
    /*! This method is used to reset the pseudo histogram content
     *  leaving unchanged the binning.
     */ 
    void clearContent();

    //! Fill the pseudo-histogram with a value x and a statistical weight w.
    /*! This is the typical filling method. 
     * @param x : value to fill in the histogram
     * @param w : weight of the value x
     */
    void fill(double x, double w);

    /**
     * Find the bin containing x
     *
     * @param x : value on the x axis
     * 
     * @return the bin containing @c x
     */
    int findBin(double x);
    
    /**
     * Returns content of bin
     *
     * @param bin : number of the bin
     */
    double getBinContent(int bin);
    
    /**
     * Returns number of entries in bin
     *
     * @param bin : number of the bin
     */
    int getNumberOfEntries(int bin);
    
    /**
     * Checks if bin is in range of the pseudo-histogram (over- and underflow bins are
     * taken into account)
     *
     * @param bin : number of the bin
     */
    bool isInRange(int bin);
    
    /**
     * Returns the weighted sum of the pseudo-histogram within startbin and
     * endbin
     *
     * @param startbin : number of the start bin for the integral
     * @param endbin   : number of the end bin for the integral
     */
    double integral(int startbin, int endbin);
    
    /**
     *    Prints content of the pseudo-histogram on the standard output 
     */
    void printContent();
    
    /**
     *  Get the number of bin
     *
     *  @return the number of bins 
     */ 
    int getNumberOfBins();
    
    /**
     *  Get the bin center
     *
     *  @param index the bin index
     *
     *  @return the bin center
     */
    double getBinCenter(int index);
    
  private:
    int _FullNumberOfBins; // number of bins plus the over- and undeflow bin
    int _NumberOfBins; // number of bins without the over- and undeflow bin
    double _MinValue;
    double _MaxValue;
    double _BinWidth;
    int* _NOfEntries;
    double* _Content;
    double* _UpperIntervalLimit;
    
  };
  
}

#endif
