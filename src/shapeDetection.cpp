#include "shapeDetection.h"

int detectCircle(ofPixels search, ofImage templ){

	unsigned char* search_p = search.getPixels();
	unsigned char* templ_p = search.getPixels();

	float minSAD = 10;
	float SAD = 0;

	int sw = search.getWidth();
	int sh = search.getHeight();

	int tw = templ.getWidth();
	int th = templ.getHeight();

	// loop through the search image
	for ( int x = 0; x <= sh - th; x++ ) {
	    for ( int y = 0; y <= sw - th; y++ ) {
	        SAD = 0.0;
	 
	        // loop through the template image
	 
	        for ( int j = 0; j < tw; j++ )
	            for ( int i = 0; i < th; i++ ) {
	 
	                int p_SearchIMG = search_p[(x+i)*sw + y+j];
	                int p_TemplateIMG = templ_p[i*tw + j];
	 
	                SAD += abs( p_SearchIMG - p_TemplateIMG );
	            }
	 
	        // save the best found position 
	        if ( minSAD > SAD ) { 
	            minSAD = SAD;
	            // give me min SAD
	            cout << "x: " << x << " y: " << y << " SAD: " << SAD << endl;
	            //position.bestRow = x;
	            //position.bestCol = y;
	            //position.bestSAD = SAD;
	        }
	    }
	}

}