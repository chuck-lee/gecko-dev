
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */


#ifndef SkComposeShader_DEFINED
#define SkComposeShader_DEFINED

#include "SkShader.h"

class SkXfermode;

///////////////////////////////////////////////////////////////////////////////////////////

/** \class SkComposeShader
    This subclass of shader returns the coposition of two other shaders, combined by
    a xfermode.
*/
class SK_API SkComposeShader : public SkShader {
public:
    /** Create a new compose shader, given shaders A, B, and a combining xfermode mode.
        When the xfermode is called, it will be given the result from shader A as its
        "dst", and the result of from shader B as its "src".
        mode->xfer32(sA_result, sB_result, ...)
        @param shaderA  The colors from this shader are seen as the "dst" by the xfermode
        @param shaderB  The colors from this shader are seen as the "src" by the xfermode
        @param mode     The xfermode that combines the colors from the two shaders. If mode
                        is null, then SRC_OVER is assumed.
    */
    SkComposeShader(SkShader* sA, SkShader* sB, SkXfermode* mode = NULL);
    virtual ~SkComposeShader();

    virtual bool setContext(const SkBitmap&, const SkPaint&,
                            const SkMatrix&) SK_OVERRIDE;
    virtual void endContext() SK_OVERRIDE;
    virtual void shadeSpan(int x, int y, SkPMColor[], int count) SK_OVERRIDE;

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(SkComposeShader)

protected:
    SkComposeShader(SkReadBuffer& );
    virtual void flatten(SkWriteBuffer&) const SK_OVERRIDE;

private:

    SkShader*   fShaderA;
    SkShader*   fShaderB;
    SkXfermode* fMode;

    typedef SkShader INHERITED;
};

#endif
