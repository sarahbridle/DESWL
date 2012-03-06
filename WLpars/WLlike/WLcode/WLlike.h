#include "basic_cosmology.h"

/*
WLlike.h

Created by SLB 3 Mar 2012 for discussion at the WLWG Parameter Estimation telecon on Wed 14th March.
This is currently a tidied up paste of the pseudo-code and some of the pseudo-headers on the WLWG Parameter Estimation subgroup wiki.
This might all be re-written in another language, format etc etc depending on discussion at the telecon.

Defines the top level WL-specific likelihood quantities and functions.
*/

/**
 * A structure containing all WL nuisance parameters - all tbc
**/
typedef struct WL_nuisance_params {
	// tbc	
} WL_nuisance_params;

/**
 * A structure containing the WL data points being used for cosmology
 * These might be the actual observations, or a set of predictions for the observations
**/
typedef struct WL_data {
	int n_tomo; /**< The number of tomographic bins */
	int n_scale; /**< The number of data points per z bin e.g. the number of theta values or number of ell values*/
	int n; /**< The number of values in data */
	float *scale_values; /**< A pointer to the abscissa of the scale values e.g. the theta values or ell values */
	float *data; /**< The main pointer to the data */
} WL_data_observed;

/**
 * A structure containing window functions to convert from basic WL statistics (e.g. Cls) to the observed WL data points (e.g. two point correlation function)
**/
typedef struct WL_data_window_fns {
	// tbc	
} WL_data_window_fns;

/**
 * A structure containing the covariance matrix between WL data points
**/
typedef struct WL_covmat {
	// tbc	
} WL_covmat;

/** 
 * Calculate the WL likelihood from the WL data for a given cosmological and nuisance parameter model
 * \param dark_matter_statistics_of_k_z Basic cosmological statistics e.g. power spectrum
 * \param DA_of_z1_z2 Angular diameter distances between two redshifts
 * \param n_of_z_i Number of galaxies as a function of z in each tomographic z bin
 * \param cosmological_params The cosmological parameter values
 * \param WL_nuisance_params The WL nuisance parameters
 * \param WL_data_window_fns Window functions to convert from e.g. Cls to e.g. correlation functions
 * \param WL_data_observed The WL data being used to constrain cosmology
 * \param WL_covmat_used The covariance of all the WL data points
**/
float WL_likelihood_wrapper(matter_statistics_of_k_z * dark_matter_statistics_of_k_z, fn_of_z1_z2 * DA_of_z1_z2, n_of_z_i * n_of_z_i_fid, cosmological_params * cosmological_params_trial, WL_nuisance_params * WL_nuisance_params_trial, WL_data_window_fns * WL_data_window_fns_used, WL_data * WL_data_observed, WL_covmat * WL_covmat_used );

/** 
 * Compute the predicted WL data for a given cosmological and nuisance parameter model
 * \param dark_matter_statistics_of_k_z Basic cosmological statistics e.g. power spectrum
 * \param DA_of_z1_z2 Angular diameter distances between two redshifts
 * \param n_of_z_i Number of galaxies as a function of z in each tomographic z bin
 * \param cosmological_params The cosmological parameter values
 * \param WL_nuisance_params The WL nuisance parameters
 * \param WL_data_window_fns Window functions to convert from e.g. Cls to e.g. correlation functions
**/
WL_data *  WL_compute_data_predicted(matter_statistics_of_k_z * dark_matter_statistics_of_k_z, fn_of_z1_z2 * DA_of_z1_z2, n_of_z_i * n_of_z_i_fid, cosmological_params * cosmological_params_trial, WL_nuisance_params * WL_nuisance_params_trial, WL_data_window_fns * WL_data_window_fns_used);

/** 
 * Compare observed and predicted WL statistics taking into account full covariance matrix
 * \param WL_data_predicted The predicted WL data points for this cosmological and nuisance model
 * \param WL_data_observed The observed WL data
 * \param WL_covmat_used The covariance matrix we are using
**/
float WL_likelihood_function(WL_data * WL_data_predicted, WL_data *  WL_data_observed, WL_covmat * WL_covmat_used);

/** 
 * Compute the WL statistics e.g. the basic 2pt functions
 * \param total_matter_statistics_of_k_z Basic cosmological statistics including e.g. baryons
 * \param DA_of_z1_z2 Angular diameter distances between two redshifts
 * \param n_of_z_i_unc Number of galaxies as a function of z in each tomographic z bin, for this nuisance parameter model
 * \param WL_data_window_fns Window functions to convert from e.g. Cls to e.g. correlation functions
**/
WL_data * WL_compute_statistics_clean(matter_statistics_of_k_z * total_matter_statistics_of_k_z, fn_of_z1_z2 * DA_of_z1_z2, n_of_z_i * n_of_z_i_unc, WL_data_window_fns * WL_data_window_fns_used);





