#!/bin/env python

import plottery_wrapper as p

p.dump_plot(
        fnames = [
            "background.root",
            ],
        sig_fnames=[
           "sig_VBSOSWWH.root","sig_VBSWWH.root", "sig_VBSWZH.root","sig_VBSZZH.root",
            ],
        dirname="cut1_6.5",

        legend_labels=[
            "Background",
            ],
        signal_labels=[
            "VBSOSWWH", "VBSWWH","VBSWZH","VBSZZH",
            ],

        extraoptions={
            "nbins":180,
            "signal_scale": "auto",
            },
        )
