/**
basic_cosmology.h
This is a temporary file that will hopefully all be replaced by the TCP group

Rough draft on 14 Feb 2010 by SLB, to get the discussion started. 
All this will undoubtedly change as we discuss at the telecon, iterate with the photoz WG and think through the other interfaces.
Written roughly as a doxygen c header file but this is not yet discussed or decided.

Defines the default basic cosmological information we need for WL calculations and probably others
**/

/**
 * matter_statistics_of_k_z
 * A structure containing the matter statistics we might need
 * zs are the redshift values at which the statistics are provided
 * nz is the number of values in zs
 * ks are the comoving wavenumber values at which the statistics are provided
 * nk is the number of values in ks
 * pk is the matter power spectrum as a function of ks and zs
**/
typedef struct matter_statistics_of_k_z {
	// tbc
} matter_statistics_of_k_z;

/**
 * fn_of_z1_z2
 * A structure containing the angular diameter distances between pairs of redshifts
 * zs are the redshift values at which the angular diameter distances are provided
 * DA is a 2d grid of angular diameter distances between pairs of redshifts
**/
typedef struct fn_of_z1_z2 {
	// tbc
} fn_of_z1_z2;

/**
 * n_of_z_i 
 * A structure containing the number of galaxies as a function of redshift for each tomographic bin
**/
typedef struct n_of_z_i  {
	// tbc
} n_of_z_i ;

/**
 * cosmological_params
... (ideally this wouldn't be here and we could just use power spectra (which contains the growth info) and angular diameter distances) Format tbd
**/
typedef struct cosmological_params {
	// tbc
} cosmological_params;



	// Still to be written!!!
	// total_PkNL_of_k_z = parse_matter_statistics(total_matter_statistics_of_k_z);

// Still to be written!!!
// matter_statistics_of_k_z * dark_matter_statistics_of_k_z = matter_statistics_of_k_z_create(nk_matter, nz_matter);

// Still to be written!!!
//fn_of_z1_z2 * DA_of_z1_z2 = fn_of_z1_z2_create(nz_DA, nz_DA);

// Still to be written!!!
//n_of_z_i * n_of_z_i_fid = n_of_z_i_create(n_tomo, nz_n_of_z); 

// Still to be written!!!
//cosmological_params * cosmological_params_trial = cosmological_params_create();











