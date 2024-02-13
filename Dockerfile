# Build and run:
#
#   docker build -t particletracking - < Dockerfile
#   docker run -it -p 8888:8888 particletracking
#   (copy-paste generated url into browser)
#
# What is installed?
#
# - Based on jupyter/scipy - https://jupyter-docker-stacks.readthedocs.io/en/latest/using/selecting.html
#
ARG OWNER=jupyter
ARG BASE_CONTAINER=jupyter/scipy-notebook:lab-4.0.7
FROM $BASE_CONTAINER

LABEL maintainer="the tracker"

# Fix: https://github.com/hadolint/hadolint/wiki/DL4006
# Fix: https://github.com/koalaman/shellcheck/wiki/SC3014
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

USER ${NB_UID}
RUN mamba install --quiet --yes \
    'black' \
    'cryptography' \
    'faunus=2' \
    'ffmpeg' \
    'isort' \
    'pandas=1' \
    'pims=0.6' \
    'ruff' \
    'trackpy=0.6' &&\
    mamba clean --all -f -y && \
    fix-permissions "${CONDA_DIR}" && \
    fix-permissions "/home/${NB_USER}"

RUN pip install --no-input mdtraj
RUN git clone https://github.com/mlund/particletracking.git

