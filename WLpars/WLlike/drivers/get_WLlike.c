#include "basic_cosmology.h"
#include "WLlike.h"

int main(int argc, char * argv[]){
	// This is an excessively verbose demo of the DES WL likelihood code

	// Tell everyone what is going on 
	printf("Welcome to a demo of the DES WL likelihood code\n");
	printf("This code starts from some input measurements e.g. 2 point functions\n");
	printf("and basic cosmological quantities for a given cosmological model\n");
	printf("and returns the likelihood of the data given the model.\n");
	
	// Read in inputs to the WL likelihood code from a fits file
	printf("Reading in basic cosmological quantities and data...\n");
	printf("Read basic cosmological quantities and data.\n");
	
	// Call the WL likelihood wrapper
	printf("Calculating WL likelihood...\n");
	float WL_log_like = WL_likelihood_wrapper(dark_matter_statistics_of_k_z, DA_of_z1_z2, n_of_z_i, cosmological_params, WL_nuisance_params, WL_data_window_fns, WL_data_observed, WL_covmat_used );
	printf("Calculated WL likelihood.\n");
	
	// Write the result to the screen
	printf("log WL likelihood = %20.10g\n", WL_log_like);
	
	// Tidy up
	printf("Bye.\n");
	
}