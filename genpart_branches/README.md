
## VBSZZH Genpart

This repository contains a C++ script, `VBSZZH_genpart.C`, which is part of a larger project focused on the analysis of Vector Boson Scattering (VBS) and Zh production. This script specifically deals with the generation of particle branches for different event types.

## Overview

The `VBSZZH_genpart.C` script is designed to perform a specific task in the data analysis pipeline of High Energy Physics (HEP) research. It is used to generate particle branches for different event types in the context of VBS and Zh production.

## Functionality

The script reads data from a ROOT file, which is a standard file format in HEP research. It then applies a series of operations to the data, specifically targeting events where the Higgs boson decays into bb and ZZ particles.

The script uses the ROOT data analysis framework, which is widely used in particle physics for data processing, statistical analysis, and data visualization. It creates several histograms for different variables of interest, such as the jet pt, eta, and phi.

The output of the script is a ROOT file containing the histograms of the variables of interest. This file can be used for further analysis or for producing plots.

## Usage

To use this script, you need to have the ROOT framework installed on your system. You can then run the script on your data file using the following command:

```bash
root -l VBSZZH_genpart.C
```

Please note that this script is part of a larger data analysis pipeline and may require specific data formats and structures to function correctly.

## About the Author

The script is developed by Eslam Zenhom, a data analyst with a background in High Energy Physics. With experience in data analysis, statistical modeling, and programming, I am skilled in transforming complex data into meaningful insights.


