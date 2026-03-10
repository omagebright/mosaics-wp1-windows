# MOSAICS WP1 — Windows Native Build

**Monte Carlo Sampling Algorithms for Computational Structural Biology**

Pre-compiled Windows binary and source code for Work Package 1 of the [MOSAICS](https://www.cs.ox.ac.uk/mosaics/) tutorial by Prof. Peter Minary (University of Oxford, Department of Computer Science).

MOSAICS = **M**ethodologies for **O**ptimization and **SA**mpling **I**n **C**omputational **S**tudies

## What is This?

WP1 teaches the foundational sampling algorithms used in MOSAICS through 1D toy models:

- **Standard Markov Chain Monte Carlo (MCMC)** — the Metropolis algorithm
- **Parallel Tempering Monte Carlo (PTMC)** — multi-canonical sampling to overcome energy barriers
- **Equi-Energy Monte Carlo (EEMC)** — energy-disk-based enhanced sampling

These algorithms are the building blocks for modeling protein, DNA, and RNA conformational landscapes, the core techniques behind MOSAICS' ability to rapidly generate biomolecular structures.

## Quick Start (Windows)

No installation required. Just download and run:

```powershell
# Clone the repo
git clone https://github.com/omagebright/mosaics-wp1-windows.git
cd mosaics-wp1-windows

# Run with the example input
cd examples
..\bin\mcmc.exe input > output.txt
```

This generates 5 output files in the `examples/` directory:
- `esurf` — Energy surface E(L)
- `adist` — Analytical (exact) probability distribution
- `ndist` — Numerical (simulated) probability distribution
- `energy` — Energy trace per replica over MC steps
- `convd` — Convergence metric |P_analytical - P_numerical| over time

## Input File Parameters

Edit the `input` file to control the simulation:

```
~sim_gen_def[
   \method{PT}              # PT: Parallel Tempering, EEMC: Equi-Energy MC
   \energy_surface{DWP}     # DWP: Double Well Potential, RFP: Random Fourier
   \replica_number{1}       # 1 = standard MC, >1 = multi-canonical
   \total_step_mc{100000}   # Total Monte Carlo iterations
   \local_step_md{10}       # Gradient steps per MC proposal
   \time_step_md{0.02}      # Time step per gradient step
   \statistics_freq{1000}   # Output frequency
   \prob_eemc_jump{0.15}    # Probability of replica exchange
   \temperature{1.0}        # Base temperature (lower = harder)
   \energy_gap{1.1}         # Temperature ladder spacing
   \random_seed{-2039480938l}
]
```

## Suggested Experiments

### 1. Standard MC on Easy Double Well (T=1.0)
```
\method{PT}  \replica_number{1}  \temperature{1.0}  \energy_surface{DWP}
```
Both wells should be sampled. ndist matches adist.

### 2. Standard MC on Hard Double Well (T=0.4)
```
\method{PT}  \replica_number{1}  \temperature{0.4}  \energy_surface{DWP}
```
Chain gets trapped in one well. ndist shows only one peak.

### 3. Parallel Tempering Rescues Sampling (T=0.4, 4 replicas)
```
\method{PT}  \replica_number{4}  \temperature{0.4}  \energy_surface{DWP}
```
Both wells sampled again! PT overcomes the energy barrier.

### 4. Random Fourier Potential (complex landscape)
```
\method{PT}  \replica_number{4}  \temperature{0.5}  \energy_surface{RFP}
```
Multiple irregular wells — harder to sample, tests algorithm limits.

## Plotting Results (Python)

```python
import numpy as np
import matplotlib.pyplot as plt

# Energy surface
esurf = np.loadtxt('esurf')
plt.figure(figsize=(10, 4))
plt.plot(esurf[:,0], esurf[:,1], 'k-', linewidth=2)
plt.xlabel('Position (L)'); plt.ylabel('Energy E(L)')
plt.title('Double Well Potential'); plt.grid(True)
plt.savefig('energy_surface.png', dpi=150)

# Analytical vs Numerical distribution
adist = np.loadtxt('adist')
ndist = np.loadtxt('ndist')
plt.figure(figsize=(10, 4))
plt.plot(adist[:,0], adist[:,1], 'b-', linewidth=2, label='Analytical')
plt.plot(ndist[:,0], ndist[:,1], 'r--', linewidth=2, label='Numerical (MCMC)')
plt.xlabel('Position (L)'); plt.ylabel('Probability')
plt.title('Distribution Comparison'); plt.legend(); plt.grid(True)
plt.savefig('distribution_comparison.png', dpi=150)

# Convergence
convd = np.loadtxt('convd')
plt.figure(figsize=(10, 4))
plt.plot(convd[:,0], convd[:,1], 'g-', linewidth=1.5)
plt.xlabel('MC Steps'); plt.ylabel('|P_analytical - P_numerical|')
plt.title('Convergence'); plt.grid(True)
plt.savefig('convergence.png', dpi=150)
plt.show()
```

## Building from Source

Requirements: `g++` (MinGW-w64 recommended for Windows)

```powershell
cd source
g++ -I. -o ..\bin\mcmc.exe mcmc.cpp ran1.cpp mb.cpp potentials.cpp statistics.cpp partition.cpp output.cpp title.cpp utillib.cpp parse_input.cpp -lm
```

The source includes Windows compatibility patches (`standard.h`) for POSIX functions (`drand48`, `strncasecmp`).

## Energy Functions

### Double Well Potential (DWP)
```
E(L) = 8 * (L² - 1)² 
```
Two symmetric wells at L = ±1, barrier height = 8 at L = 0.

### Random Fourier Potential (RFP)
```
E(L) = Σᵢ c(i) * sin(i * 2π * L / 10),  i = 1..20
```
Irregular landscape with multiple local minima.

## Why This Matters

These sampling algorithms are foundational to:
- **Protein structure prediction** — exploring conformational space efficiently
- **Drug discovery** — sampling binding poses and affinities
- **CRISPR-Cas9 research** — generating structural variants for off-target prediction
- **RNA modeling** — optimizing riboswitch and non-coding RNA structures

MOSAICS uses these algorithms combined with natural degrees of freedom (torsion angles, hierarchical moves) to model real biomolecular systems at speeds orders of magnitude faster than traditional MD.

## Credits

- **MOSAICS Software:** Prof. Peter Minary, University of Oxford
- **Original Tutorial:** Oxford Doctoral Training Centre in Computational Biology
- **Windows Port & Compatibility Patches:** Dr. Folorunsho Bright Omage (University of Oxford, Dept. of Computer Science)
- **References:**
  - Sim, Levitt, Minary (2012). Modeling and design by hierarchical natural moves. *PNAS* 109(8):2890-2895
  - Geyer (1991). Parallel Tempering Monte Carlo. *Proc. 23rd Symp. Interface*
  - Metropolis et al. (1953). Equations of state calculations by fast computing machines. *J. Chem. Phys.* 21:1087-1092
  - Minary and Levitt (2006). Discussion of the equi-energy sampler. *Ann. Stat.* 34:1636-1641

## License

Educational use. MOSAICS source code copyright Peter Minary. Windows compatibility patches by Bright Omage.

## Links

- [MOSAICS Website](https://www.cs.ox.ac.uk/mosaics/)
- [Tutorial Page](https://www.cs.ox.ac.uk/mosaics/tutorials/tutorial.html)
- [Video Tutorial](https://youtube.com/@brightomage) *(coming soon)*
