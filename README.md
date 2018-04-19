[![Binder](https://mybinder.org/badge.svg)](https://mybinder.org/v2/gh/mlund/particletracking/master)

# Particle Tracking

This lab is based on two [Jupyter Notebooks](http://jupyter.org):
- `track.ipynb`: Notebook for analysing trajectories from mechanical particle simulator using image analysis;
- `mc/montecarlo.ipynb`: Notebook for running MC simulations of a model system of the mechanical particle simulator.

## Prerequisites

- No prior knowledge in Python is required, but familiarity with programming concepts is helpful.
- A laptop connected to the internet (eduroam, for example) and running Unix, MacOS, or Windows and with Anaconda installed, see below.

If you have little experience with Python or shell programming, the following two tutorials may be helpful:

- https://swcarpentry.github.io/shell-novice
- https://swcarpentry.github.io/python-novice-inflammation

## Preparation before the lab

1. Install [miniconda3](https://conda.io/miniconda.html).
2. [Download](https://github.com/mlund/particletracking/archive/master.zip) the lab material
   (this github repository) and unzip.
3. Install and activate the `particletracking` environment described by the file [`environment.yml`](/environment.yml)
   by running the following in a terminal:

   ```bash
   conda env create -f environment.yml
   source activate particletracking
   ```
Instructions for Windows: 
1. Install [miniconda3](https://conda.io/miniconda.html).
2. [Download](https://github.com/mlund/particletracking/archive/master.zip) the lab material (this github repository)
   and unzip.
3. Open the `anaconda prompt` from the start menu.
4. Navigate to the folder where the course material has been unzipped (_e.g._ using `cd` to change directory
   and `dir` to list files in a folder).
5. Install and activate the `particletracking` environment described by the file [`environment.yml`](/environment.yml)
   by running the following in the `anaconda prompt`:

   ```bash
   conda env create -f environment.yml
   activate particletracking
   ```
[Further Information](https://conda.io/docs/user-guide/tasks/manage-environments.html#creating-an-environment-from-an-environment-yml-file)

## How to launch the notebooks

~~~ bash
jupyter-notebook track.ipynb
jupyter-notebook mc/montecarlo.ipynb
~~~
