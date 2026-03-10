# MOSAICS Tutorial — Complete Package with Windows Support

**Advanced Monte Carlo Sampling Algorithms for Computational Structural Biology**

Complete tutorial materials for the [MOSAICS](https://www.cs.ox.ac.uk/mosaics/) framework by Prof. Peter Minary (University of Oxford, Department of Computer Science).

MOSAICS = **M**ethodologies for **O**ptimization and **SA**mpling **I**n **C**omputational **S**tudies

## Repository Contents

```
├── case_study.pdf          # Tutorial overview and theoretical background (PDF)
├── WP1/                    # Work Package 1: Sampling Algorithms (1D models)
│   ├── bin/mcmc.exe        # Pre-compiled Windows binary
│   ├── source/             # C++ source (Windows-patched)
│   └── examples/input      # Example input file
├── WP2/                    # Work Package 2: Molecular Simulations (DNA/RNA)
│   └── examples/           # 6-base RNA loop + 3-base-pair DNA systems
├── WP3/                    # Work Package 3: Stochastic Optimization
│   └── examples/           # Optimization protocols for WP2 systems
├── WP4/                    # Work Package 4: Riboswitch Modeling (2CKY)
│   └── examples/           # Real RNA riboswitch structure optimization
└── ANALYSE/                # Analysis tools (Perl scripts for RMSD, energy)
```

## Work Packages Overview

| WP | Topic | Problem Addressed | Binary Needed |
|----|-------|-------------------|---------------|
| **WP1** | MCMC, Parallel Tempering, EEMC | Energy surface problem | `mcmc.exe` (included) |
| **WP2** | Natural moves on DNA/RNA | Dimensionality problem | `mosaics.x` (see below) |
| **WP3** | Simulated annealing optimization | Combined approach | `mosaics.x` (see below) |
| **WP4** | Riboswitch conformational search | Real-world application | `mosaics.x` (see below) |

## Quick Start — WP1 (Windows, No Installation Required)

```powershell
git clone https://github.com/omagebright/mosaics-wp1-windows.git
cd mosaics-wp1-windows\WP1\examples
..\bin\mcmc.exe input > output.txt
```

Output files generated:
- `esurf` — Energy surface E(L)
- `adist` — Analytical probability distribution
- `ndist` — Numerical (simulated) probability distribution
- `energy` — Energy trace per replica
- `convd` — Convergence metric over MC steps

## WP1 Input Parameters

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

### Experiment 1: Standard MC — Easy (T=1.0)
```
\method{PT}  \replica_number{1}  \temperature{1.0}  \energy_surface{DWP}
```
Both wells sampled correctly. ndist matches adist.

### Experiment 2: Standard MC — Hard (T=0.4)
```
\method{PT}  \replica_number{1}  \temperature{0.4}  \energy_surface{DWP}
```
Chain trapped in one well. The energy surface problem in action.

### Experiment 3: Parallel Tempering Rescues Sampling
```
\method{PT}  \replica_number{4}  \temperature{0.4}  \energy_surface{DWP}
```
Both wells sampled again. Multi-canonical sampling overcomes the barrier.

### Experiment 4: Complex Landscape
```
\method{PT}  \replica_number{4}  \temperature{0.5}  \energy_surface{RFP}
```
Random Fourier potential with many irregular wells. Tests algorithm limits.

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
plt.savefig('distribution.png', dpi=150)

# Convergence
convd = np.loadtxt('convd')
plt.figure(figsize=(10, 4))
plt.plot(convd[:,0], convd[:,1], 'g-', linewidth=1.5)
plt.xlabel('MC Steps'); plt.ylabel('|P_analytical - P_numerical|')
plt.title('Convergence'); plt.grid(True)
plt.savefig('convergence.png', dpi=150)
plt.show()
```

## WP2-4: Running the Full MOSAICS Software

Work Packages 2-4 require the full MOSAICS binary (`mosaics.x`), which operates on real molecular structures (DNA, RNA, proteins). The MOSAICS source code is available from the [official website](https://www.cs.ox.ac.uk/mosaics/).

**On Linux/WSL:**
```bash
# Download and compile MOSAICS
cd source/compile/serial
make clean && make

# Link binary and databases to WP directories
cd WP2/examples
ln -s ../../MOSAICS/version.3.9.1_bgq/examples/mosaics.x mosaics.x
ln -s ../../TOPPOT/top_database/ top_database
ln -s ../../TOPPOT/pot_database/ pot_database
```

**Topology and potential databases** (required for WP2-4) can be downloaded separately from the MOSAICS website.

## Building WP1 from Source (Windows)

Requirements: `g++` (MinGW-w64 recommended)

```powershell
cd WP1\source
g++ -I. -o ..\bin\mcmc.exe mcmc.cpp ran1.cpp mb.cpp potentials.cpp statistics.cpp partition.cpp output.cpp title.cpp utillib.cpp parse_input.cpp -lm
```

The source includes Windows compatibility patches for POSIX functions (`drand48`, `strncasecmp`, `M_PI`).

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
Irregular landscape with multiple local minima using random coefficients.

## The Two Fundamental Problems

These tutorials address the two core challenges in computational structural biology:

1. **The Energy Surface Problem** (WP1, WP3): Energy landscapes contain deep local minima separated by high barriers, trapping simulations in single conformational states.

2. **The Dimensionality Problem** (WP2, WP4): Biomolecules have enormous numbers of degrees of freedom, making exhaustive Cartesian sampling impossible. MOSAICS uses natural degrees of freedom (torsion angles, hierarchical moves) to reduce dimensionality.

## Applications

These sampling and optimization algorithms are foundational to:
- **Protein structure prediction** — exploring conformational space efficiently
- **Drug discovery** — sampling binding poses and affinities
- **CRISPR-Cas9 research** — generating structural variants for off-target activity prediction
- **RNA modeling** — optimizing riboswitch and non-coding RNA structures

## Credits

- **MOSAICS Software:** Prof. Peter Minary, University of Oxford
- **Tutorial Design:** Oxford Doctoral Training Centre in Computational Biology
- **Windows Port:** Dr. Folorunsho Bright Omage (University of Oxford, Dept. of Computer Science)

## References

- Sim, Levitt, Minary (2012). Modeling and design by hierarchical natural moves. *PNAS* 109(8):2890-2895
- Geyer (1991). Parallel Tempering Monte Carlo. *Proc. 23rd Symp. Interface*
- Metropolis et al. (1953). Equations of state calculations by fast computing machines. *J. Chem. Phys.* 21:1087-1092
- Minary and Levitt (2006). Discussion of the equi-energy sampler. *Ann. Stat.* 34:1636-1641
- Minary and Levitt (2008). Probing protein fold space with a simplified model. *J. Mol. Biol.* 375:920-933
- Minary and Levitt (2010). Conformational optimization with natural degrees of freedom. *J. Comp. Biol.* 17:993-1010

## Links

- [MOSAICS Website](https://www.cs.ox.ac.uk/mosaics/)
- [Original Tutorial](https://www.cs.ox.ac.uk/mosaics/tutorials/tutorial.html)
- [Video Tutorial](https://youtube.com/@brightomage) *(coming soon)*

## License

Educational use. MOSAICS source code copyright Peter Minary. Windows compatibility patches by Folorunsho Bright Omage.
