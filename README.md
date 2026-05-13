# Enhancement FrodoKEM Final Report

Repository นี้รวบรวมไฟล์รายงานสรุปผลการศึกษา แนวคิด Hybrid PQC--QKD สำหรับ FrodoKEM, supplementary files ที่ใช้อ้างอิง และ source code ต้นแบบระดับ toy model สำหรับการทดลอง LWE/FrodoKEM ขนาดเล็ก

## โครงสร้างไฟล์

- `Final Report/final_report.tex` คือไฟล์ LaTeX หลักของรายงาน
- `Final Report/final_report.pdf` คือไฟล์ PDF ที่ export แล้ว
- `Final Report/Supplementary Files/` คือเอกสารประกอบที่ถูกจัดชื่อเป็นลำดับ `S01` ถึง `S12`
- `Final Report/supplementary_files_manifest.md` คือ manifest ของ supplementary files
- `FrodoKEM_Ekert/` คือ source code ต้นแบบและเวอร์ชันทดลอง
- `ProjectSource/` คือเอกสารและรายงานระหว่างการศึกษา
- `ReportStyleTemplate/` คือรายงานตัวอย่างที่ใช้ดูแนวทางรูปแบบรายงาน

## การ build รายงาน

รายงานใช้ XeLaTeX และฟอนต์ `TH Sarabun New`

```bash
cd "Final Report"
xelatex -interaction=nonstopmode -halt-on-error final_report.tex
xelatex -interaction=nonstopmode -halt-on-error final_report.tex
```

ผลลัพธ์หลักคือ `Final Report/final_report.pdf`

## Supplementary Files

ไฟล์ประกอบรายงานถูกจัดเก็บใน `Final Report/Supplementary Files/` และอ้างอิงในรายงานด้วยรหัส `S01`--`S12` เพื่อให้ตรวจสอบที่มาของเนื้อหาได้ง่าย รายละเอียดแต่ละไฟล์ดูได้ใน `Final Report/supplementary_files_manifest.md`

## Source Code Prototype

source code ต้นแบบอยู่ใน `FrodoKEM_Ekert/` โดยเวอร์ชันที่ใช้เป็นฐานอ้างอิงหลักในรายงานคือ

```text
FrodoKEM_Ekert/qbuild_status/
```

ตัวอย่างการ build:

```bash
cd "FrodoKEM_Ekert/qbuild_status"
make clean
make
```

ไฟล์ executable ที่ build ได้ เช่น `frodo_test` ถูก ignore จาก Git เพื่อไม่ให้ปะปนกับ source code

## หมายเหตุสำหรับการส่งขึ้น GitHub

หลังสร้าง repository บน GitHub แล้ว สามารถเชื่อม remote และ push ได้ด้วยคำสั่งลักษณะนี้

```bash
git remote add origin <GITHUB_REPOSITORY_URL>
git push -u origin main
```

ให้แทน `<GITHUB_REPOSITORY_URL>` ด้วยลิงก์ repository จริง

