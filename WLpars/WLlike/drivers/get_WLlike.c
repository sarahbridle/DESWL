#include "basic_cosmology.h"
#include "WLlike.h"

int main(int argc, char * argv[]){
	// This is an excessively verbose demo of the DES WL likelihood code

	// Tell everyone what is going on 
	printf("Welcome to a demo of the DES WL likelihood code\n");
	printf("This code starts from some input measurements e.g. 2 point functions\n");
	printf("and basic cosmological quantities for a given cosmological model\n");
	printf("and returns the likelihood of the data given the model.\n");
	
	// Read in inputs to the WL likelihood code - these should all come from TCP code?
	printf("Making up basic cosmological quantities...\n");
	// This is a placeholder for now!!! It just creates arrays of zeros.
	//
	// Create space to hold the matter statistics e.g. dark matter power spectrum
	int nk_matter = 100;
	int nz_matter = 10;
	matter_statistics_of_k_z * dark_matter_statistics_of_k_z = matter_statistics_of_k_z_create(nk_matter, nz_matter);
	//
	// Create space to hold the angular diameter distances 
	int nz_DA = 10000;
	fn_of_z1_z2 * DA_of_z1_z2 = fn_of_z1_z2_create(nz_DA, nz_DA);
	// 
	// Create space to hold the n(z)s
	int n_tomo = 10;
	int nz_n_of_z = 100;
	n_of_z_i * n_of_z_i_fid = n_of_z_i_create(n_tomo, nz_n_of_z); 
	//
	// Create space to hold the cosmological parameters
	cosmological_params * cosmological_params_trial = cosmological_params_create();
	//
	// Create space to hold the nuisance parameters
	WL_nuisance_params * WL_nuisance_params_trial = WL_nuisance_params_create();
	printf("Made up basic cosmological quantities and data.\n");
	
	// Read in the observed WL data from fits files
	printf("Reading in WL data from fits files...\n");
	WL_data_window_fns * WL_data_window_fns_used = WL_data_window_fns_read_fits(WL_windows_file);
	WL_data * WL_data_observed = WL_data_read_fits(WL_data_file);
	WL_covmat * WL_covmat_used = WL_covmat_read_fits(WL_covmat_file);	
	printf("Read WL data from fits files.\n");
	
	// Call the WL likelihood wrapper
	printf("Calculating WL likelihood...\n");
	float WL_log_like = WL_likelihood_wrapper(dark_matter_statistics_of_k_z, DA_of_z1_z2, n_of_z_i_fid, cosmological_params_trial, WL_nuisance_params_trial, WL_data_window_fns, WL_data_observed, WL_covmat_used );
	printf("Calculated WL likelihood.\n");
	
	// Write the result to the screen
	printf("log WL likelihood = %20.10g\n", WL_log_like);
	
	// Tidy up
	printf("Bye.\n");
	
}