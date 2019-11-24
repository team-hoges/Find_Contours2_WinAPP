#!/usr/bin/env python
# -*- coding: utf-8 -*-

# pyinstaller --onefile pdfcrop.py

import os
import numpy as np
import cv2 as cv
import pdf2image


def main():
    # popplerへの環境変数PATHを一時的に付与 ###################################
    poppler_path = os.path.join(os.getcwd(), "poppler-0.68.0", "bin")
    os.environ["PATH"] += os.pathsep + poppler_path

    # pdf2imageを用いてPDFファイルを画像へ変換 ################################
    filepath = os.path.abspath(os.path.dirname(__file__))
    filepath = os.path.join(filepath, "pdf", "template.pdf")

    pdfimages = pdf2image.convert_from_path(filepath)

    # 読み込んだ画像はRGB形式のためBRGへ変換し画面表示 #########################
    cvimage = np.asarray(pdfimages[0])
    cvimage = cv.cvtColor(cvimage, cv.COLOR_RGB2BGR)
    cvimage = cv.resize(cvimage, (480, 640))

    cv.imshow("pdf2image sample", cvimage)

    cv.waitKey(-1)


if __name__ == '__main__':
    main()
