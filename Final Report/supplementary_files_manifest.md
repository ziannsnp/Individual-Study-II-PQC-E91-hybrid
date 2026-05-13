# Supplementary Files Manifest

This manifest maps the supplementary-file IDs used in `final_report.tex` to the renamed PDF files placed in `Final Report/Supplementary Files`.

For formal submission, include this manifest together with:

- `final_report.tex`
- `final_report.pdf`
- the `Supplementary Files/` folder
- the source-code package or Git repository for the prototype code

Suggested Git submission metadata:

- Repository URL: `<to be filled before submission>`
- Commit hash: `<to be filled before submission>`
- Release tag: `<optional>`

| ID | Renamed supplementary PDF | Original file copied from `ProjectSource` | Purpose |
|---|---|---|---|
| S01 | `Supplementary Files/S01_BB84_QKD.pdf` | `BB84_Unbreakable_Quantum_Security.pdf` | BB84/QKD overview and security intuition |
| S02 | `Supplementary Files/S02_BB84_Foundation.pdf` | `Quantum_Security_BB84_Protocol_Foundation.pdf.pdf` | BB84 basis exchange, QBER, and privacy amplification |
| S03 | `Supplementary Files/S03_E91_QKD.pdf` | `Ekert_E91_Entangled_QKD.pdf` | E91 and entanglement-based QKD |
| S04 | `Supplementary Files/S04_Quantum_Networks.pdf` | `Quantum_Networks_Entanglement_Architecture.pdf` | Quantum-network and entanglement architecture context |
| S05 | `Supplementary Files/S05_PQC_LWE.pdf` | `Post-Quantum_Standards_Lattices_and_LWE.pdf` | PQC, lattice cryptography, and LWE foundation |
| S06 | `Supplementary Files/S06_Enhanced_FrodoKEM.pdf` | `EnhancementFrodoKEM.pdf` | Proposed E91-derived masked-salting protocol |
| S07 | `Supplementary Files/S07_Quantum_Lattice.pdf` | `Quantum_Lattice_Convergence.pdf.pdf` | Hybrid QKD/PQC narrative and matrix uniformity discussion |
| S08 | `Supplementary Files/S08_FrodoKEM_Changes.pdf` | `รายงานสรปการเปลยนแปลง FrodoKEM.pdf` | FrodoKEM original vs v2 change summary |
| S09 | `Supplementary Files/S09_FrodoKEM_ChangesB.pdf` | `รายงานสรปการเปลยนแปลง FrodoKEM 2.pdf` | Additional FrodoKEM original vs v2 change summary |
| S10 | `Supplementary Files/S10_Security_Testing.pdf` | `รายงานสรปแนวทางการทดสอบความปลอดภย FrodoKEM v2.pdf` | Three-phase security testing methodology |
| S11 | `Supplementary Files/S11_Testing_Presentation.pdf` | `รายงานสรุปแนวทางการทดสอบและจัดทำ presentation.pdf` | Testing summary and presentation preparation |
| S12 | `Supplementary Files/S12_Basis_Distortion.pdf` | `รายงานแนวทางเพมเตม ระยะท 4.pdf` | Phase 4 basis distortion and M=0 vs M!=0 analysis |

Prototype source code note:

The prototype code is not a PDF supplementary file. It should be submitted separately as a Git repository or versioned archive containing the `FrodoKEM_Ekert` prototype source tree, with a commit hash or release tag recorded above.
