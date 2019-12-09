#pragma once

#include <string>

#include "define.h"

namespace mcpe_viz {

    // all user options are stored here
    class Control {
    public:
        std::string dirLeveldb;
        std::string fnOutputBase;
        std::string fnCfg;
        std::string fnXml;
        std::string fnLog;
        std::string fnGeoJSON;
        std::string fnHtml;
        std::string fnJs;

        // per-dimension filenames
        std::string fnLayerTop[kDimIdCount];
        std::string fnLayerBiome[kDimIdCount];
        std::string fnLayerHeight[kDimIdCount];
        std::string fnLayerHeightGrayscale[kDimIdCount];
        std::string fnLayerHeightAlpha[kDimIdCount];
        std::string fnLayerBlockLight[kDimIdCount];
        std::string fnLayerSkyLight[kDimIdCount];
        std::string fnLayerSlimeChunks[kDimIdCount];
        std::string fnLayerGrass[kDimIdCount];
        std::string fnLayerShadedRelief[kDimIdCount];
        std::string fnLayerRaw[kDimIdCount][MAX_BLOCK_HEIGHT + 1];

        bool doDetailParseFlag;
        int32_t doMovie;
        int32_t doSlices;
        int32_t doGrid;
        int32_t doHtml;
        int32_t doTiles;
        int32_t doImageBiome;
        int32_t doImageGrass;
        int32_t doImageHeightCol;
        int32_t doImageHeightColGrayscale;
        int32_t doImageHeightColAlpha;
        int32_t doImageLightBlock;
        int32_t doImageLightSky;
        int32_t doImageSlimeChunks;
        int32_t doImageShadedRelief;
        bool autoTileFlag;
        bool noForceGeoJSONFlag;
        bool shortRunFlag;
        bool colorTestFlag;
        bool verboseFlag;
        bool quietFlag;
        int32_t movieX, movieY, movieW, movieH;

        bool doFindImages;
        std::string dirFindImagesIn;
        std::string dirFindImagesOut;

        int32_t heightMode;

        int32_t tileWidth;
        int32_t tileHeight;

        bool fpLogNeedCloseFlag;
        FILE *fpLog;

        // this is the BloomFilterPolicy bits, set to 0 to disable filter
        int32_t leveldbFilter = 10;
        // this is the block_size used by leveldb
        int32_t leveldbBlockSize = 4096;

        Control() {
            init();
        }

        ~Control() {
            if (fpLogNeedCloseFlag) {
                if (fpLog != nullptr) {
                    fclose(fpLog);
                }
            }
        }

        void init() {
            dirLeveldb = "";
            fnXml = "";
            fnOutputBase = "";
            fnLog = "";
            fnGeoJSON = "";
            fnHtml = "";
            fnJs = "";
            doDetailParseFlag = false;

            doMovie = kDoOutputNone;
            doSlices = kDoOutputNone;
            doGrid = kDoOutputNone;
            doHtml = 0;
            doTiles = 0;
            doImageBiome = kDoOutputNone;
            doImageGrass = kDoOutputNone;
            doImageHeightCol = kDoOutputNone;
            doImageHeightColGrayscale = kDoOutputNone;
            doImageHeightColAlpha = kDoOutputNone;
            doImageLightBlock = kDoOutputNone;
            doImageLightSky = kDoOutputNone;
            doImageSlimeChunks = kDoOutputNone;
            doImageShadedRelief = kDoOutputNone;
            noForceGeoJSONFlag = false;

            autoTileFlag = false;
            // todobig - reasonable default? strike a balance between speed/# of files
            tileWidth = 1024;
            tileHeight = 1024;

            doFindImages = false;
            dirFindImagesIn = "";
            dirFindImagesOut = "";

            shortRunFlag = false;
            colorTestFlag = false;
            verboseFlag = false;
            quietFlag = false;
            movieX = movieY = movieW = movieH = 0;
            fpLogNeedCloseFlag = false;
            fpLog = stdout;

            leveldbFilter = 10;
            leveldbBlockSize = 4096;

            // todo - cmdline option for this?
            heightMode = kHeightModeTop;

            for (int32_t did = 0; did < kDimIdCount; did++) {
                fnLayerTop[did] = "";
                fnLayerBiome[did] = "";
                fnLayerHeight[did] = "";
                fnLayerHeightGrayscale[did] = "";
                fnLayerHeightAlpha[did] = "";
                fnLayerBlockLight[did] = "";
                fnLayerSkyLight[did] = "";
                fnLayerSlimeChunks[did] = "";
                fnLayerShadedRelief[did] = "";
                fnLayerGrass[did] = "";
                for (int32_t i = 0; i <= MAX_BLOCK_HEIGHT; i++) {
                    fnLayerRaw[did][i] = "";
                }
            }
        }

        void setupOutput();
    };

    extern Control control;
}