#include "basic_cosmology.h"

/*
Created by SLB 3 Mar 2012 for discussion at the WLWG Parameter Estimation telecon on Wed 14th March.
This is currently a tidied up paste of the pseudo-code and some of the pseudo-headers on the WLWG Parameter Estimation subgroup wiki.
This might all be re-written in another language, format etc etc depending on discussion at the telecon.
*/


/**
 * Compute WL likelihood from basic cosmological functions, nuisance parameters and observations 
**/
float WL_likelihood_wrapper(matter_statistics_of_k_z * dark_matter_statistics_of_k_z, fn_of_z1_z2 * DA_of_z1_z2, n_of_z_i * n_of_z_i_fid, cosmological_params * cosmological_params_trial, WL_nuisance_params * WL_nuisance_params_trial, WL_data_window_fns * WL_data_window_fns_used, WL_data * WL_data_observed, WL_covmat * WL_covmat_used) {

     // Predict WL data vector from basic cosmological functions and nuisance parameters
     WL_data * WL_data_predicted = WL_compute_data_predicted(dark_matter_statistics_of_k_z, DA_of_z1_z2, n_of_z_i, cosmological_params, WL_nuisance_params, WL_data_window_fns);

     // Compare observed and predicted data using covariance matrix 
	WL_log_like = WL_likelihood_function(WL_data_predicted, WL_data_observed, WL_covmat_used);
	
	return WL_log_like;

}

/** 
 * Predict the WL data vector from basic cosmological functions and nuisance parameters
**/
WL_data * WL_compute_data_predicted(matter_statistics_of_k_z * dark_matter_statistics_of_k_z, fn_of_z1_z2 * DA_of_z1_z2, n_of_z_i * n_of_z_i_fid, cosmological_params * cosmological_params_trial, WL_nuisance_params * WL_nuisance_params_trial, WL_data_window_fns * WL_data_window_fns_used) {

	// Separate out the WL nuisance parameters into different types
	// Still to be written!!!
	//[baryon_params, photoz_unc_params, IA_params, shear_calib_params] = WL_parse_nuisance_params(WL_nuisance_params);

	// Modify the dark matter predicted statistics (e.g. PkNL) by the baryon prescription 
	// Still to be written!!!
	//matter_statistics_of_k_z * total_matter_statistics_of_k_z = Pk_add_baryons(dark_matter_statistics_of_k_z, baryon_params, cosmological_params);

	// Modify the tomographic bin source z distributions by the photoz uncertainty parameters
	// Still to be written!!!
	//n_of_z_i * n_of_z_i_unc = n_of_z_add_photoz_unc(n_of_z_i, photoz_calib_errors);

	// Compute the basic lensing statistics ignoring systematics e.g. the standard Cls calculation 
	WL_data * WL_statistics_clean = WL_compute_statistics_clean(total_matter_statistics_of_k_z, DA_of_z1_z2, n_of_z_i_unc, WL_data_window_fns);

	// Compute the intrinsic alignment contribution to the basic lensing statistics e.g. Cls
	// Still to be written!!!
	//WL_data * IA_statistics = compute_IA_statistics(total_matter_statistics_of_k_z, DA_of_z1_z2, n_of_z_i_unc, IA_params);
 	//WL_data * IA_statistics = WL_data_create(); // Creates an array of zeros. This is a dummy placeholder!!!
	
	// Add up the clean lensing and IA terms
	// Still to be written!!!
	//WL_data * WL_and_IA_statistics = WL_add_statistics(WL_statistics_clean, IA_statistics);

	// Modify the total lensing statistic so far (e.g. Cls = Cls_lensing + Cls_IA) by the shear calibration uncertainties
	// Still to be written!!!
	//WL_data * WL_statistics_total = WL_apply_shear_calib(WL_and_IA_statistics, shear_calib_params);

	//return WL_statistics_total;
	return WL_statistics_clean; // This is a placeholder for WL_statistics_total

}

/** 
 * Compare observed and predicted WL statistics taking into account full covariance matrix
**/
float WL_likelihood_function(WL_data * WL_data_predicted, WL_data *  WL_data_observed, WL_covmat * WL_covmat_used) {

	// Compute the chisq between observed and predicted
	// Still to be written!!!
	// float chisq = (WL_data_predicted - WL_data_observed)^T WL_covmat_used^-1 (WL_data_predicted - WL_data_observed);
	float chisq = 0.0; // dummy entry!!!

	// Convert the chisq into log(likelihood)
	float WL_log_like = -chisq / 2.0;
	// NB. Should add in prefactors depending on covariance matrix etc here one day
	
	return WL_log_like;
	
}

/** 
 * Compute the WL statistics e.g. the basic 2pt functions
**/
WL_data * WL_compute_statistics_clean(matter_statistics_of_k_z * total_matter_statistics_of_k_z, fn_of_z1_z2 * DA_of_z1_z2, n_of_z_i * n_of_z_i_unc, WL_data_window_fns * WL_data_window_fns_used) {

	// Extract out the relevant components of the matter (including baryons) statistics structure e.g. the matter power spectrum
	// Still to be written!!!
	// total_PkNL_of_k_z = parse_matter_statistics(total_matter_statistics_of_k_z);

	// Calculate lensing Cls from the matter power spectrum provided 
	// Still to be written!!!
	//WL_Cls_clean = WL_compute_Cls_clean(total_PkNL_of_k_z, DA_of_z1_z2, n_of_z_i_unc);

	// Convert from Cls to whatever 2pt function is being used by weighting the Cls by one window function per data point
	// Still to be written!!!
	//WL_shear2pt_clean = WL_Cls_to_shear2pt(WL_Cls_clean, WL_data_window_fns);

	// Concatenate all the WL data into one variable
	// This will get more complicated if/when we add in other statistics e.g. shear-position correlations
	//WL_statistics_clean = WL_shear2pt_clean;
	
	WL_data * WL_statistics_clean = WL_data_create(); // Creates an array of zeros. This is a dummy placeholder!!!
	
	return WL_statistics_clean;

}

// Still to be written!!!
// Separate out the WL nuisance parameters into different types
//[baryon_params, photoz_unc_params, IA_params, shear_calib_params] = WL_parse_nuisance_params(WL_nuisance_params);

	// Still to be written!!!
	// Calculate lensing Cls from the matter power spectrum provided 
	//WL_Cls_clean = WL_compute_Cls_clean(total_PkNL_of_k_z, DA_of_z1_z2, n_of_z_i_unc);

	// Still to be written!!!
	// Convert from Cls to whatever 2pt function is being used by weighting the Cls by one window function per data point
	//WL_shear2pt_clean = WL_Cls_to_shear2pt(WL_Cls_clean, WL_data_window_fns);

/** 
 * Create an array of zeros in the shape of the WL_data 
**/
WL_data * WL_data_create() {
	
	
};
