static PyObject* pyopencv_cv_Canny(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_apertureSize = NULL;
    int apertureSize=3;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "image", "threshold1", "threshold2", "edges", "apertureSize", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:Canny", (char**)keywords, &pyobj_image, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_apertureSize, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to_safe(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to_safe(pyobj_apertureSize, apertureSize, ArgInfo("apertureSize", 0)) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(image, edges, threshold1, threshold2, apertureSize, L2gradient));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_apertureSize = NULL;
    int apertureSize=3;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "image", "threshold1", "threshold2", "edges", "apertureSize", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:Canny", (char**)keywords, &pyobj_image, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_apertureSize, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to_safe(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to_safe(pyobj_apertureSize, apertureSize, ArgInfo("apertureSize", 0)) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(image, edges, threshold1, threshold2, apertureSize, L2gradient));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dx = NULL;
    Mat dx;
    PyObject* pyobj_dy = NULL;
    Mat dy;
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "dx", "dy", "threshold1", "threshold2", "edges", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:Canny", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to_safe(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(dx, dy, edges, threshold1, threshold2, L2gradient));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dx = NULL;
    UMat dx;
    PyObject* pyobj_dy = NULL;
    UMat dy;
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;

    const char* keywords[] = { "dx", "dy", "threshold1", "threshold2", "edges", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:Canny", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_threshold1, &pyobj_threshold2, &pyobj_edges, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to_safe(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(cv::Canny(dx, dy, edges, threshold1, threshold2, L2gradient));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Canny");

    return NULL;
}

static PyObject* pyopencv_cv_EMD(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_signature1 = NULL;
    Mat signature1;
    PyObject* pyobj_signature2 = NULL;
    Mat signature2;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_cost = NULL;
    Mat cost;
    PyObject* pyobj_lowerBound = NULL;
    Ptr<float> lowerBound;
    PyObject* pyobj_flow = NULL;
    Mat flow;
    float retval;

    const char* keywords[] = { "signature1", "signature2", "distType", "cost", "lowerBound", "flow", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:EMD", (char**)keywords, &pyobj_signature1, &pyobj_signature2, &pyobj_distType, &pyobj_cost, &pyobj_lowerBound, &pyobj_flow) &&
        pyopencv_to_safe(pyobj_signature1, signature1, ArgInfo("signature1", 0)) &&
        pyopencv_to_safe(pyobj_signature2, signature2, ArgInfo("signature2", 0)) &&
        pyopencv_to_safe(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to_safe(pyobj_cost, cost, ArgInfo("cost", 0)) &&
        pyopencv_to_safe(pyobj_lowerBound, lowerBound, ArgInfo("lowerBound", 1)) &&
        pyopencv_to_safe(pyobj_flow, flow, ArgInfo("flow", 1)) )
    {
        ERRWRAP2(retval = cv::wrapperEMD(signature1, signature2, distType, cost, lowerBound, flow));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(lowerBound), pyopencv_from(flow));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_signature1 = NULL;
    UMat signature1;
    PyObject* pyobj_signature2 = NULL;
    UMat signature2;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_cost = NULL;
    UMat cost;
    PyObject* pyobj_lowerBound = NULL;
    Ptr<float> lowerBound;
    PyObject* pyobj_flow = NULL;
    UMat flow;
    float retval;

    const char* keywords[] = { "signature1", "signature2", "distType", "cost", "lowerBound", "flow", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:EMD", (char**)keywords, &pyobj_signature1, &pyobj_signature2, &pyobj_distType, &pyobj_cost, &pyobj_lowerBound, &pyobj_flow) &&
        pyopencv_to_safe(pyobj_signature1, signature1, ArgInfo("signature1", 0)) &&
        pyopencv_to_safe(pyobj_signature2, signature2, ArgInfo("signature2", 0)) &&
        pyopencv_to_safe(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to_safe(pyobj_cost, cost, ArgInfo("cost", 0)) &&
        pyopencv_to_safe(pyobj_lowerBound, lowerBound, ArgInfo("lowerBound", 1)) &&
        pyopencv_to_safe(pyobj_flow, flow, ArgInfo("flow", 1)) )
    {
        ERRWRAP2(retval = cv::wrapperEMD(signature1, signature2, distType, cost, lowerBound, flow));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(lowerBound), pyopencv_from(flow));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("EMD");

    return NULL;
}

static PyObject* pyopencv_cv_GaussianBlur(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_sigmaX = NULL;
    double sigmaX=0;
    PyObject* pyobj_sigmaY = NULL;
    double sigmaY=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "sigmaX", "dst", "sigmaY", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:GaussianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_sigmaX, &pyobj_dst, &pyobj_sigmaY, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_sigmaX, sigmaX, ArgInfo("sigmaX", 0)) &&
        pyopencv_to_safe(pyobj_sigmaY, sigmaY, ArgInfo("sigmaY", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_sigmaX = NULL;
    double sigmaX=0;
    PyObject* pyobj_sigmaY = NULL;
    double sigmaY=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "sigmaX", "dst", "sigmaY", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:GaussianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_sigmaX, &pyobj_dst, &pyobj_sigmaY, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_sigmaX, sigmaX, ArgInfo("sigmaX", 0)) &&
        pyopencv_to_safe(pyobj_sigmaY, sigmaY, ArgInfo("sigmaY", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::GaussianBlur(src, dst, ksize, sigmaX, sigmaY, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("GaussianBlur");

    return NULL;
}

static PyObject* pyopencv_cv_HoughCircles(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_circles = NULL;
    Mat circles;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_dp = NULL;
    double dp=0;
    PyObject* pyobj_minDist = NULL;
    double minDist=0;
    PyObject* pyobj_param1 = NULL;
    double param1=100;
    PyObject* pyobj_param2 = NULL;
    double param2=100;
    PyObject* pyobj_minRadius = NULL;
    int minRadius=0;
    PyObject* pyobj_maxRadius = NULL;
    int maxRadius=0;

    const char* keywords[] = { "image", "method", "dp", "minDist", "circles", "param1", "param2", "minRadius", "maxRadius", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:HoughCircles", (char**)keywords, &pyobj_image, &pyobj_method, &pyobj_dp, &pyobj_minDist, &pyobj_circles, &pyobj_param1, &pyobj_param2, &pyobj_minRadius, &pyobj_maxRadius) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_dp, dp, ArgInfo("dp", 0)) &&
        pyopencv_to_safe(pyobj_minDist, minDist, ArgInfo("minDist", 0)) &&
        pyopencv_to_safe(pyobj_param1, param1, ArgInfo("param1", 0)) &&
        pyopencv_to_safe(pyobj_param2, param2, ArgInfo("param2", 0)) &&
        pyopencv_to_safe(pyobj_minRadius, minRadius, ArgInfo("minRadius", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) )
    {
        ERRWRAP2(cv::HoughCircles(image, circles, method, dp, minDist, param1, param2, minRadius, maxRadius));
        return pyopencv_from(circles);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_circles = NULL;
    UMat circles;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_dp = NULL;
    double dp=0;
    PyObject* pyobj_minDist = NULL;
    double minDist=0;
    PyObject* pyobj_param1 = NULL;
    double param1=100;
    PyObject* pyobj_param2 = NULL;
    double param2=100;
    PyObject* pyobj_minRadius = NULL;
    int minRadius=0;
    PyObject* pyobj_maxRadius = NULL;
    int maxRadius=0;

    const char* keywords[] = { "image", "method", "dp", "minDist", "circles", "param1", "param2", "minRadius", "maxRadius", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:HoughCircles", (char**)keywords, &pyobj_image, &pyobj_method, &pyobj_dp, &pyobj_minDist, &pyobj_circles, &pyobj_param1, &pyobj_param2, &pyobj_minRadius, &pyobj_maxRadius) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_dp, dp, ArgInfo("dp", 0)) &&
        pyopencv_to_safe(pyobj_minDist, minDist, ArgInfo("minDist", 0)) &&
        pyopencv_to_safe(pyobj_param1, param1, ArgInfo("param1", 0)) &&
        pyopencv_to_safe(pyobj_param2, param2, ArgInfo("param2", 0)) &&
        pyopencv_to_safe(pyobj_minRadius, minRadius, ArgInfo("minRadius", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) )
    {
        ERRWRAP2(cv::HoughCircles(image, circles, method, dp, minDist, param1, param2, minRadius, maxRadius));
        return pyopencv_from(circles);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HoughCircles");

    return NULL;
}

static PyObject* pyopencv_cv_HoughLines(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_srn = NULL;
    double srn=0;
    PyObject* pyobj_stn = NULL;
    double stn=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=CV_PI;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "srn", "stn", "min_theta", "max_theta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:HoughLines", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_srn, &pyobj_stn, &pyobj_min_theta, &pyobj_max_theta) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_srn, srn, ArgInfo("srn", 0)) &&
        pyopencv_to_safe(pyobj_stn, stn, ArgInfo("stn", 0)) &&
        pyopencv_to_safe(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to_safe(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) )
    {
        ERRWRAP2(cv::HoughLines(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_srn = NULL;
    double srn=0;
    PyObject* pyobj_stn = NULL;
    double stn=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=CV_PI;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "srn", "stn", "min_theta", "max_theta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:HoughLines", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_srn, &pyobj_stn, &pyobj_min_theta, &pyobj_max_theta) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_srn, srn, ArgInfo("srn", 0)) &&
        pyopencv_to_safe(pyobj_stn, stn, ArgInfo("stn", 0)) &&
        pyopencv_to_safe(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to_safe(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) )
    {
        ERRWRAP2(cv::HoughLines(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HoughLines");

    return NULL;
}

static PyObject* pyopencv_cv_HoughLinesP(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_minLineLength = NULL;
    double minLineLength=0;
    PyObject* pyobj_maxLineGap = NULL;
    double maxLineGap=0;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "minLineLength", "maxLineGap", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:HoughLinesP", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_minLineLength, &pyobj_maxLineGap) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_minLineLength, minLineLength, ArgInfo("minLineLength", 0)) &&
        pyopencv_to_safe(pyobj_maxLineGap, maxLineGap, ArgInfo("maxLineGap", 0)) )
    {
        ERRWRAP2(cv::HoughLinesP(image, lines, rho, theta, threshold, minLineLength, maxLineGap));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_minLineLength = NULL;
    double minLineLength=0;
    PyObject* pyobj_maxLineGap = NULL;
    double maxLineGap=0;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "minLineLength", "maxLineGap", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:HoughLinesP", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_minLineLength, &pyobj_maxLineGap) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_minLineLength, minLineLength, ArgInfo("minLineLength", 0)) &&
        pyopencv_to_safe(pyobj_maxLineGap, maxLineGap, ArgInfo("maxLineGap", 0)) )
    {
        ERRWRAP2(cv::HoughLinesP(image, lines, rho, theta, threshold, minLineLength, maxLineGap));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HoughLinesP");

    return NULL;
}

static PyObject* pyopencv_cv_HoughLinesPointSet(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_point = NULL;
    Mat point;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_lines_max = NULL;
    int lines_max=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_min_rho = NULL;
    double min_rho=0;
    PyObject* pyobj_max_rho = NULL;
    double max_rho=0;
    PyObject* pyobj_rho_step = NULL;
    double rho_step=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=0;
    PyObject* pyobj_theta_step = NULL;
    double theta_step=0;

    const char* keywords[] = { "point", "lines_max", "threshold", "min_rho", "max_rho", "rho_step", "min_theta", "max_theta", "theta_step", "lines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOOOOO|O:HoughLinesPointSet", (char**)keywords, &pyobj_point, &pyobj_lines_max, &pyobj_threshold, &pyobj_min_rho, &pyobj_max_rho, &pyobj_rho_step, &pyobj_min_theta, &pyobj_max_theta, &pyobj_theta_step, &pyobj_lines) &&
        pyopencv_to_safe(pyobj_point, point, ArgInfo("point", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_lines_max, lines_max, ArgInfo("lines_max", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_min_rho, min_rho, ArgInfo("min_rho", 0)) &&
        pyopencv_to_safe(pyobj_max_rho, max_rho, ArgInfo("max_rho", 0)) &&
        pyopencv_to_safe(pyobj_rho_step, rho_step, ArgInfo("rho_step", 0)) &&
        pyopencv_to_safe(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to_safe(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) &&
        pyopencv_to_safe(pyobj_theta_step, theta_step, ArgInfo("theta_step", 0)) )
    {
        ERRWRAP2(cv::HoughLinesPointSet(point, lines, lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_point = NULL;
    UMat point;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_lines_max = NULL;
    int lines_max=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_min_rho = NULL;
    double min_rho=0;
    PyObject* pyobj_max_rho = NULL;
    double max_rho=0;
    PyObject* pyobj_rho_step = NULL;
    double rho_step=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=0;
    PyObject* pyobj_theta_step = NULL;
    double theta_step=0;

    const char* keywords[] = { "point", "lines_max", "threshold", "min_rho", "max_rho", "rho_step", "min_theta", "max_theta", "theta_step", "lines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOOOOO|O:HoughLinesPointSet", (char**)keywords, &pyobj_point, &pyobj_lines_max, &pyobj_threshold, &pyobj_min_rho, &pyobj_max_rho, &pyobj_rho_step, &pyobj_min_theta, &pyobj_max_theta, &pyobj_theta_step, &pyobj_lines) &&
        pyopencv_to_safe(pyobj_point, point, ArgInfo("point", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_lines_max, lines_max, ArgInfo("lines_max", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_min_rho, min_rho, ArgInfo("min_rho", 0)) &&
        pyopencv_to_safe(pyobj_max_rho, max_rho, ArgInfo("max_rho", 0)) &&
        pyopencv_to_safe(pyobj_rho_step, rho_step, ArgInfo("rho_step", 0)) &&
        pyopencv_to_safe(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to_safe(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) &&
        pyopencv_to_safe(pyobj_theta_step, theta_step, ArgInfo("theta_step", 0)) )
    {
        ERRWRAP2(cv::HoughLinesPointSet(point, lines, lines_max, threshold, min_rho, max_rho, rho_step, min_theta, max_theta, theta_step));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HoughLinesPointSet");

    return NULL;
}

static PyObject* pyopencv_cv_HoughLinesWithAccumulator(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_srn = NULL;
    double srn=0;
    PyObject* pyobj_stn = NULL;
    double stn=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=CV_PI;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "srn", "stn", "min_theta", "max_theta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:HoughLinesWithAccumulator", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_srn, &pyobj_stn, &pyobj_min_theta, &pyobj_max_theta) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_srn, srn, ArgInfo("srn", 0)) &&
        pyopencv_to_safe(pyobj_stn, stn, ArgInfo("stn", 0)) &&
        pyopencv_to_safe(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to_safe(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) )
    {
        ERRWRAP2(cv::HoughLinesWithAccumulator(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_rho = NULL;
    double rho=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_srn = NULL;
    double srn=0;
    PyObject* pyobj_stn = NULL;
    double stn=0;
    PyObject* pyobj_min_theta = NULL;
    double min_theta=0;
    PyObject* pyobj_max_theta = NULL;
    double max_theta=CV_PI;

    const char* keywords[] = { "image", "rho", "theta", "threshold", "lines", "srn", "stn", "min_theta", "max_theta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:HoughLinesWithAccumulator", (char**)keywords, &pyobj_image, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_lines, &pyobj_srn, &pyobj_stn, &pyobj_min_theta, &pyobj_max_theta) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_srn, srn, ArgInfo("srn", 0)) &&
        pyopencv_to_safe(pyobj_stn, stn, ArgInfo("stn", 0)) &&
        pyopencv_to_safe(pyobj_min_theta, min_theta, ArgInfo("min_theta", 0)) &&
        pyopencv_to_safe(pyobj_max_theta, max_theta, ArgInfo("max_theta", 0)) )
    {
        ERRWRAP2(cv::HoughLinesWithAccumulator(image, lines, rho, theta, threshold, srn, stn, min_theta, max_theta));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HoughLinesWithAccumulator");

    return NULL;
}

static PyObject* pyopencv_cv_HuMoments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_m = NULL;
    Ptr<cv::Moments> m;
    PyObject* pyobj_hu = NULL;
    Mat hu;

    const char* keywords[] = { "m", "hu", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:HuMoments", (char**)keywords, &pyobj_m, &pyobj_hu) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_hu, hu, ArgInfo("hu", 1)) )
    {
        ERRWRAP2(cv::HuMoments(*m, hu));
        return pyopencv_from(hu);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    Ptr<cv::Moments> m;
    PyObject* pyobj_hu = NULL;
    UMat hu;

    const char* keywords[] = { "m", "hu", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:HuMoments", (char**)keywords, &pyobj_m, &pyobj_hu) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_hu, hu, ArgInfo("hu", 1)) )
    {
        ERRWRAP2(cv::HuMoments(*m, hu));
        return pyopencv_from(hu);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HuMoments");

    return NULL;
}

static PyObject* pyopencv_cv_KeyPoint_convert(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_keypoints = NULL;
    vector_KeyPoint keypoints;
    vector_Point2f points2f;
    PyObject* pyobj_keypointIndexes = NULL;
    vector_int keypointIndexes=std::vector<int>();

    const char* keywords[] = { "keypoints", "keypointIndexes", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:KeyPoint_convert", (char**)keywords, &pyobj_keypoints, &pyobj_keypointIndexes) &&
        pyopencv_to_safe(pyobj_keypoints, keypoints, ArgInfo("keypoints", 0)) &&
        pyopencv_to_safe(pyobj_keypointIndexes, keypointIndexes, ArgInfo("keypointIndexes", 0)) )
    {
        ERRWRAP2(cv::KeyPoint::convert(keypoints, points2f, keypointIndexes));
        return pyopencv_from(points2f);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points2f = NULL;
    vector_Point2f points2f;
    vector_KeyPoint keypoints;
    PyObject* pyobj_size = NULL;
    float size=1;
    PyObject* pyobj_response = NULL;
    float response=1;
    PyObject* pyobj_octave = NULL;
    int octave=0;
    PyObject* pyobj_class_id = NULL;
    int class_id=-1;

    const char* keywords[] = { "points2f", "size", "response", "octave", "class_id", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:KeyPoint_convert", (char**)keywords, &pyobj_points2f, &pyobj_size, &pyobj_response, &pyobj_octave, &pyobj_class_id) &&
        pyopencv_to_safe(pyobj_points2f, points2f, ArgInfo("points2f", 0)) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_response, response, ArgInfo("response", 0)) &&
        pyopencv_to_safe(pyobj_octave, octave, ArgInfo("octave", 0)) &&
        pyopencv_to_safe(pyobj_class_id, class_id, ArgInfo("class_id", 0)) )
    {
        ERRWRAP2(cv::KeyPoint::convert(points2f, keypoints, size, response, octave, class_id));
        return pyopencv_from(keypoints);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("KeyPoint_convert");

    return NULL;
}

static PyObject* pyopencv_cv_KeyPoint_overlap(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_kp1 = NULL;
    cv::KeyPoint kp1;
    PyObject* pyobj_kp2 = NULL;
    cv::KeyPoint kp2;
    float retval;

    const char* keywords[] = { "kp1", "kp2", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:KeyPoint_overlap", (char**)keywords, &pyobj_kp1, &pyobj_kp2) &&
        pyopencv_to_safe(pyobj_kp1, kp1, ArgInfo("kp1", 0)) &&
        pyopencv_to_safe(pyobj_kp2, kp2, ArgInfo("kp2", 0)) )
    {
        ERRWRAP2(retval = cv::KeyPoint::overlap(kp1, kp2));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_LUT(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lut = NULL;
    Mat lut;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "lut", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:LUT", (char**)keywords, &pyobj_src, &pyobj_lut, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lut, lut, ArgInfo("lut", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::LUT(src, lut, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lut = NULL;
    UMat lut;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "lut", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:LUT", (char**)keywords, &pyobj_src, &pyobj_lut, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lut, lut, ArgInfo("lut", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::LUT(src, lut, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("LUT");

    return NULL;
}

static PyObject* pyopencv_cv_Laplacian(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=1;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:Laplacian", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Laplacian(src, dst, ddepth, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=1;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:Laplacian", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Laplacian(src, dst, ddepth, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Laplacian");

    return NULL;
}

static PyObject* pyopencv_cv_Mahalanobis(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_v1 = NULL;
    Mat v1;
    PyObject* pyobj_v2 = NULL;
    Mat v2;
    PyObject* pyobj_icovar = NULL;
    Mat icovar;
    double retval;

    const char* keywords[] = { "v1", "v2", "icovar", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:Mahalanobis", (char**)keywords, &pyobj_v1, &pyobj_v2, &pyobj_icovar) &&
        pyopencv_to_safe(pyobj_v1, v1, ArgInfo("v1", 0)) &&
        pyopencv_to_safe(pyobj_v2, v2, ArgInfo("v2", 0)) &&
        pyopencv_to_safe(pyobj_icovar, icovar, ArgInfo("icovar", 0)) )
    {
        ERRWRAP2(retval = cv::Mahalanobis(v1, v2, icovar));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_v1 = NULL;
    UMat v1;
    PyObject* pyobj_v2 = NULL;
    UMat v2;
    PyObject* pyobj_icovar = NULL;
    UMat icovar;
    double retval;

    const char* keywords[] = { "v1", "v2", "icovar", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:Mahalanobis", (char**)keywords, &pyobj_v1, &pyobj_v2, &pyobj_icovar) &&
        pyopencv_to_safe(pyobj_v1, v1, ArgInfo("v1", 0)) &&
        pyopencv_to_safe(pyobj_v2, v2, ArgInfo("v2", 0)) &&
        pyopencv_to_safe(pyobj_icovar, icovar, ArgInfo("icovar", 0)) )
    {
        ERRWRAP2(retval = cv::Mahalanobis(v1, v2, icovar));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Mahalanobis");

    return NULL;
}

static PyObject* pyopencv_cv_PCABackProject(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_result = NULL;
    Mat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:PCABackProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCABackProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_result = NULL;
    UMat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:PCABackProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCABackProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("PCABackProject");

    return NULL;
}

static PyObject* pyopencv_cv_PCACompute(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_maxComponents) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, maxComponents));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_maxComponents) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, maxComponents));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, retainedVariance));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:PCACompute", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, retainedVariance));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("PCACompute");

    return NULL;
}

static PyObject* pyopencv_cv_PCACompute2(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "eigenvalues", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_eigenvalues, &pyobj_maxComponents) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, maxComponents));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_maxComponents = NULL;
    int maxComponents=0;

    const char* keywords[] = { "data", "mean", "eigenvectors", "eigenvalues", "maxComponents", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_eigenvalues, &pyobj_maxComponents) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_maxComponents, maxComponents, ArgInfo("maxComponents", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, maxComponents));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", "eigenvalues", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors, &pyobj_eigenvalues) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, retainedVariance));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_retainedVariance = NULL;
    double retainedVariance=0;

    const char* keywords[] = { "data", "mean", "retainedVariance", "eigenvectors", "eigenvalues", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:PCACompute2", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_retainedVariance, &pyobj_eigenvectors, &pyobj_eigenvalues) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_retainedVariance, retainedVariance, ArgInfo("retainedVariance", 0)) )
    {
        ERRWRAP2(cv::PCACompute(data, mean, eigenvectors, eigenvalues, retainedVariance));
        return Py_BuildValue("(NNN)", pyopencv_from(mean), pyopencv_from(eigenvectors), pyopencv_from(eigenvalues));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("PCACompute2");

    return NULL;
}

static PyObject* pyopencv_cv_PCAProject(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    PyObject* pyobj_result = NULL;
    Mat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:PCAProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCAProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    PyObject* pyobj_result = NULL;
    UMat result;

    const char* keywords[] = { "data", "mean", "eigenvectors", "result", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:PCAProject", (char**)keywords, &pyobj_data, &pyobj_mean, &pyobj_eigenvectors, &pyobj_result) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) )
    {
        ERRWRAP2(cv::PCAProject(data, mean, eigenvectors, result));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("PCAProject");

    return NULL;
}

static PyObject* pyopencv_cv_PSNR(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_R = NULL;
    double R=255.;
    double retval;

    const char* keywords[] = { "src1", "src2", "R", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:PSNR", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_R) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_R, R, ArgInfo("R", 0)) )
    {
        ERRWRAP2(retval = cv::PSNR(src1, src2, R));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_R = NULL;
    double R=255.;
    double retval;

    const char* keywords[] = { "src1", "src2", "R", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:PSNR", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_R) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_R, R, ArgInfo("R", 0)) )
    {
        ERRWRAP2(retval = cv::PSNR(src1, src2, R));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("PSNR");

    return NULL;
}

static PyObject* pyopencv_cv_SVBackSubst(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_w = NULL;
    Mat w;
    PyObject* pyobj_u = NULL;
    Mat u;
    PyObject* pyobj_vt = NULL;
    Mat vt;
    PyObject* pyobj_rhs = NULL;
    Mat rhs;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "w", "u", "vt", "rhs", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:SVBackSubst", (char**)keywords, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_rhs, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_w, w, ArgInfo("w", 0)) &&
        pyopencv_to_safe(pyobj_u, u, ArgInfo("u", 0)) &&
        pyopencv_to_safe(pyobj_vt, vt, ArgInfo("vt", 0)) &&
        pyopencv_to_safe(pyobj_rhs, rhs, ArgInfo("rhs", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::SVBackSubst(w, u, vt, rhs, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_w = NULL;
    UMat w;
    PyObject* pyobj_u = NULL;
    UMat u;
    PyObject* pyobj_vt = NULL;
    UMat vt;
    PyObject* pyobj_rhs = NULL;
    UMat rhs;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "w", "u", "vt", "rhs", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:SVBackSubst", (char**)keywords, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_rhs, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_w, w, ArgInfo("w", 0)) &&
        pyopencv_to_safe(pyobj_u, u, ArgInfo("u", 0)) &&
        pyopencv_to_safe(pyobj_vt, vt, ArgInfo("vt", 0)) &&
        pyopencv_to_safe(pyobj_rhs, rhs, ArgInfo("rhs", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::SVBackSubst(w, u, vt, rhs, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("SVBackSubst");

    return NULL;
}

static PyObject* pyopencv_cv_SVDecomp(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_w = NULL;
    Mat w;
    PyObject* pyobj_u = NULL;
    Mat u;
    PyObject* pyobj_vt = NULL;
    Mat vt;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "w", "u", "vt", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:SVDecomp", (char**)keywords, &pyobj_src, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_w, w, ArgInfo("w", 1)) &&
        pyopencv_to_safe(pyobj_u, u, ArgInfo("u", 1)) &&
        pyopencv_to_safe(pyobj_vt, vt, ArgInfo("vt", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::SVDecomp(src, w, u, vt, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(w), pyopencv_from(u), pyopencv_from(vt));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_w = NULL;
    UMat w;
    PyObject* pyobj_u = NULL;
    UMat u;
    PyObject* pyobj_vt = NULL;
    UMat vt;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "w", "u", "vt", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:SVDecomp", (char**)keywords, &pyobj_src, &pyobj_w, &pyobj_u, &pyobj_vt, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_w, w, ArgInfo("w", 1)) &&
        pyopencv_to_safe(pyobj_u, u, ArgInfo("u", 1)) &&
        pyopencv_to_safe(pyobj_vt, vt, ArgInfo("vt", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::SVDecomp(src, w, u, vt, flags));
        return Py_BuildValue("(NNN)", pyopencv_from(w), pyopencv_from(u), pyopencv_from(vt));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("SVDecomp");

    return NULL;
}

static PyObject* pyopencv_cv_Scharr(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:Scharr", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Scharr(src, dst, ddepth, dx, dy, scale, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:Scharr", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Scharr(src, dst, ddepth, dx, dy, scale, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Scharr");

    return NULL;
}

static PyObject* pyopencv_cv_Sobel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:Sobel", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Sobel(src, dst, ddepth, dx, dy, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "dx", "dy", "dst", "ksize", "scale", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:Sobel", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_dx, &pyobj_dy, &pyobj_dst, &pyobj_ksize, &pyobj_scale, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::Sobel(src, dst, ddepth, dx, dy, ksize, scale, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Sobel");

    return NULL;
}

static PyObject* pyopencv_cv_UMat_context(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    void* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_context());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_queue(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    void* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_queue());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_waitAny(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_streams = NULL;
    vector_VideoCapture streams;
    vector_int readyIndex;
    PyObject* pyobj_timeoutNs = NULL;
    int64 timeoutNs=0;
    bool retval;

    const char* keywords[] = { "streams", "timeoutNs", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:VideoCapture_waitAny", (char**)keywords, &pyobj_streams, &pyobj_timeoutNs) &&
        pyopencv_to_safe(pyobj_streams, streams, ArgInfo("streams", 0)) &&
        pyopencv_to_safe(pyobj_timeoutNs, timeoutNs, ArgInfo("timeoutNs", 0)) )
    {
        ERRWRAP2(retval = cv::VideoCapture::waitAny(streams, readyIndex, timeoutNs));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(readyIndex));
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_fourcc(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_c1 = NULL;
    char c1;
    PyObject* pyobj_c2 = NULL;
    char c2;
    PyObject* pyobj_c3 = NULL;
    char c3;
    PyObject* pyobj_c4 = NULL;
    char c4;
    int retval;

    const char* keywords[] = { "c1", "c2", "c3", "c4", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:VideoWriter_fourcc", (char**)keywords, &pyobj_c1, &pyobj_c2, &pyobj_c3, &pyobj_c4) &&
        convert_to_char(pyobj_c1, &c1, ArgInfo("c1", 0)) &&
        convert_to_char(pyobj_c2, &c2, ArgInfo("c2", 0)) &&
        convert_to_char(pyobj_c3, &c3, ArgInfo("c3", 0)) &&
        convert_to_char(pyobj_c4, &c4, ArgInfo("c4", 0)) )
    {
        ERRWRAP2(retval = cv::VideoWriter::fourcc(c1, c2, c3, c4));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_absdiff(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::absdiff(src1, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::absdiff(src1, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("absdiff");

    return NULL;
}

static PyObject* pyopencv_cv_accumulate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:accumulate", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulate(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:accumulate", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulate(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("accumulate");

    return NULL;
}

static PyObject* pyopencv_cv_accumulateProduct(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:accumulateProduct", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateProduct(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:accumulateProduct", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateProduct(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("accumulateProduct");

    return NULL;
}

static PyObject* pyopencv_cv_accumulateSquare(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:accumulateSquare", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateSquare(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:accumulateSquare", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateSquare(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("accumulateSquare");

    return NULL;
}

static PyObject* pyopencv_cv_accumulateWeighted(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "alpha", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:accumulateWeighted", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateWeighted(src, dst, alpha, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "alpha", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:accumulateWeighted", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::accumulateWeighted(src, dst, alpha, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("accumulateWeighted");

    return NULL;
}

static PyObject* pyopencv_cv_adaptiveThreshold(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_maxValue = NULL;
    double maxValue=0;
    PyObject* pyobj_adaptiveMethod = NULL;
    int adaptiveMethod=0;
    PyObject* pyobj_thresholdType = NULL;
    int thresholdType=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_C = NULL;
    double C=0;

    const char* keywords[] = { "src", "maxValue", "adaptiveMethod", "thresholdType", "blockSize", "C", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:adaptiveThreshold", (char**)keywords, &pyobj_src, &pyobj_maxValue, &pyobj_adaptiveMethod, &pyobj_thresholdType, &pyobj_blockSize, &pyobj_C, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_maxValue, maxValue, ArgInfo("maxValue", 0)) &&
        pyopencv_to_safe(pyobj_adaptiveMethod, adaptiveMethod, ArgInfo("adaptiveMethod", 0)) &&
        pyopencv_to_safe(pyobj_thresholdType, thresholdType, ArgInfo("thresholdType", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_C, C, ArgInfo("C", 0)) )
    {
        ERRWRAP2(cv::adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_maxValue = NULL;
    double maxValue=0;
    PyObject* pyobj_adaptiveMethod = NULL;
    int adaptiveMethod=0;
    PyObject* pyobj_thresholdType = NULL;
    int thresholdType=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_C = NULL;
    double C=0;

    const char* keywords[] = { "src", "maxValue", "adaptiveMethod", "thresholdType", "blockSize", "C", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:adaptiveThreshold", (char**)keywords, &pyobj_src, &pyobj_maxValue, &pyobj_adaptiveMethod, &pyobj_thresholdType, &pyobj_blockSize, &pyobj_C, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_maxValue, maxValue, ArgInfo("maxValue", 0)) &&
        pyopencv_to_safe(pyobj_adaptiveMethod, adaptiveMethod, ArgInfo("adaptiveMethod", 0)) &&
        pyopencv_to_safe(pyobj_thresholdType, thresholdType, ArgInfo("thresholdType", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_C, C, ArgInfo("C", 0)) )
    {
        ERRWRAP2(cv::adaptiveThreshold(src, dst, maxValue, adaptiveMethod, thresholdType, blockSize, C));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("adaptiveThreshold");

    return NULL;
}

static PyObject* pyopencv_cv_add(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 2)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::add(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 2)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::add(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("add");

    return NULL;
}

static PyObject* pyopencv_cv_addWeighted(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("addWeighted");

    return NULL;
}

static PyObject* pyopencv_cv_applyColorMap(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_colormap = NULL;
    int colormap=0;

    const char* keywords[] = { "src", "colormap", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_colormap, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_colormap, colormap, ArgInfo("colormap", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, colormap));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_colormap = NULL;
    int colormap=0;

    const char* keywords[] = { "src", "colormap", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_colormap, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_colormap, colormap, ArgInfo("colormap", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, colormap));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_userColor = NULL;
    Mat userColor;

    const char* keywords[] = { "src", "userColor", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_userColor, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_userColor, userColor, ArgInfo("userColor", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, userColor));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_userColor = NULL;
    UMat userColor;

    const char* keywords[] = { "src", "userColor", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:applyColorMap", (char**)keywords, &pyobj_src, &pyobj_userColor, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_userColor, userColor, ArgInfo("userColor", 0)) )
    {
        ERRWRAP2(cv::applyColorMap(src, dst, userColor));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("applyColorMap");

    return NULL;
}

static PyObject* pyopencv_cv_approxPolyDP(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_curve = NULL;
    Mat curve;
    PyObject* pyobj_approxCurve = NULL;
    Mat approxCurve;
    PyObject* pyobj_epsilon = NULL;
    double epsilon=0;
    PyObject* pyobj_closed = NULL;
    bool closed=0;

    const char* keywords[] = { "curve", "epsilon", "closed", "approxCurve", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:approxPolyDP", (char**)keywords, &pyobj_curve, &pyobj_epsilon, &pyobj_closed, &pyobj_approxCurve) &&
        pyopencv_to_safe(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to_safe(pyobj_approxCurve, approxCurve, ArgInfo("approxCurve", 1)) &&
        pyopencv_to_safe(pyobj_epsilon, epsilon, ArgInfo("epsilon", 0)) &&
        pyopencv_to_safe(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(cv::approxPolyDP(curve, approxCurve, epsilon, closed));
        return pyopencv_from(approxCurve);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_curve = NULL;
    UMat curve;
    PyObject* pyobj_approxCurve = NULL;
    UMat approxCurve;
    PyObject* pyobj_epsilon = NULL;
    double epsilon=0;
    PyObject* pyobj_closed = NULL;
    bool closed=0;

    const char* keywords[] = { "curve", "epsilon", "closed", "approxCurve", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:approxPolyDP", (char**)keywords, &pyobj_curve, &pyobj_epsilon, &pyobj_closed, &pyobj_approxCurve) &&
        pyopencv_to_safe(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to_safe(pyobj_approxCurve, approxCurve, ArgInfo("approxCurve", 1)) &&
        pyopencv_to_safe(pyobj_epsilon, epsilon, ArgInfo("epsilon", 0)) &&
        pyopencv_to_safe(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(cv::approxPolyDP(curve, approxCurve, epsilon, closed));
        return pyopencv_from(approxCurve);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("approxPolyDP");

    return NULL;
}

static PyObject* pyopencv_cv_arcLength(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_curve = NULL;
    Mat curve;
    PyObject* pyobj_closed = NULL;
    bool closed=0;
    double retval;

    const char* keywords[] = { "curve", "closed", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:arcLength", (char**)keywords, &pyobj_curve, &pyobj_closed) &&
        pyopencv_to_safe(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to_safe(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(retval = cv::arcLength(curve, closed));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_curve = NULL;
    UMat curve;
    PyObject* pyobj_closed = NULL;
    bool closed=0;
    double retval;

    const char* keywords[] = { "curve", "closed", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:arcLength", (char**)keywords, &pyobj_curve, &pyobj_closed) &&
        pyopencv_to_safe(pyobj_curve, curve, ArgInfo("curve", 0)) &&
        pyopencv_to_safe(pyobj_closed, closed, ArgInfo("closed", 0)) )
    {
        ERRWRAP2(retval = cv::arcLength(curve, closed));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("arcLength");

    return NULL;
}

static PyObject* pyopencv_cv_arrowedLine(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_tipLength = NULL;
    double tipLength=0.1;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "line_type", "shift", "tipLength", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:arrowedLine", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_line_type, &pyobj_shift, &pyobj_tipLength) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_line_type, line_type, ArgInfo("line_type", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to_safe(pyobj_tipLength, tipLength, ArgInfo("tipLength", 0)) )
    {
        ERRWRAP2(cv::arrowedLine(img, pt1, pt2, color, thickness, line_type, shift, tipLength));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_tipLength = NULL;
    double tipLength=0.1;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "line_type", "shift", "tipLength", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:arrowedLine", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_line_type, &pyobj_shift, &pyobj_tipLength) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_line_type, line_type, ArgInfo("line_type", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to_safe(pyobj_tipLength, tipLength, ArgInfo("tipLength", 0)) )
    {
        ERRWRAP2(cv::arrowedLine(img, pt1, pt2, color, thickness, line_type, shift, tipLength));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("arrowedLine");

    return NULL;
}

static PyObject* pyopencv_cv_batchDistance(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dist = NULL;
    Mat dist;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_nidx = NULL;
    Mat nidx;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_update = NULL;
    int update=0;
    PyObject* pyobj_crosscheck = NULL;
    bool crosscheck=false;

    const char* keywords[] = { "src1", "src2", "dtype", "dist", "nidx", "normType", "K", "mask", "update", "crosscheck", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOOOO:batchDistance", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dtype, &pyobj_dist, &pyobj_nidx, &pyobj_normType, &pyobj_K, &pyobj_mask, &pyobj_update, &pyobj_crosscheck) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dist, dist, ArgInfo("dist", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_nidx, nidx, ArgInfo("nidx", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_update, update, ArgInfo("update", 0)) &&
        pyopencv_to_safe(pyobj_crosscheck, crosscheck, ArgInfo("crosscheck", 0)) )
    {
        ERRWRAP2(cv::batchDistance(src1, src2, dist, dtype, nidx, normType, K, mask, update, crosscheck));
        return Py_BuildValue("(NN)", pyopencv_from(dist), pyopencv_from(nidx));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dist = NULL;
    UMat dist;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_nidx = NULL;
    UMat nidx;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_update = NULL;
    int update=0;
    PyObject* pyobj_crosscheck = NULL;
    bool crosscheck=false;

    const char* keywords[] = { "src1", "src2", "dtype", "dist", "nidx", "normType", "K", "mask", "update", "crosscheck", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOOOO:batchDistance", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dtype, &pyobj_dist, &pyobj_nidx, &pyobj_normType, &pyobj_K, &pyobj_mask, &pyobj_update, &pyobj_crosscheck) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dist, dist, ArgInfo("dist", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_nidx, nidx, ArgInfo("nidx", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_update, update, ArgInfo("update", 0)) &&
        pyopencv_to_safe(pyobj_crosscheck, crosscheck, ArgInfo("crosscheck", 0)) )
    {
        ERRWRAP2(cv::batchDistance(src1, src2, dist, dtype, nidx, normType, K, mask, update, crosscheck));
        return Py_BuildValue("(NN)", pyopencv_from(dist), pyopencv_from(nidx));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("batchDistance");

    return NULL;
}

static PyObject* pyopencv_cv_bilateralFilter(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_d = NULL;
    int d=0;
    PyObject* pyobj_sigmaColor = NULL;
    double sigmaColor=0;
    PyObject* pyobj_sigmaSpace = NULL;
    double sigmaSpace=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "d", "sigmaColor", "sigmaSpace", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_d, &pyobj_sigmaColor, &pyobj_sigmaSpace, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_d, d, ArgInfo("d", 0)) &&
        pyopencv_to_safe(pyobj_sigmaColor, sigmaColor, ArgInfo("sigmaColor", 0)) &&
        pyopencv_to_safe(pyobj_sigmaSpace, sigmaSpace, ArgInfo("sigmaSpace", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_d = NULL;
    int d=0;
    PyObject* pyobj_sigmaColor = NULL;
    double sigmaColor=0;
    PyObject* pyobj_sigmaSpace = NULL;
    double sigmaSpace=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "d", "sigmaColor", "sigmaSpace", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_d, &pyobj_sigmaColor, &pyobj_sigmaSpace, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_d, d, ArgInfo("d", 0)) &&
        pyopencv_to_safe(pyobj_sigmaColor, sigmaColor, ArgInfo("sigmaColor", 0)) &&
        pyopencv_to_safe(pyobj_sigmaSpace, sigmaSpace, ArgInfo("sigmaSpace", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::bilateralFilter(src, dst, d, sigmaColor, sigmaSpace, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bilateralFilter");

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_and(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_and(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_and(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_and");

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_not(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_not(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_not(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_not");

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_or(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_or(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_or(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_or");

    return NULL;
}

static PyObject* pyopencv_cv_bitwise_xor(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_xor(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src1", "src2", "dst", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::bitwise_xor(src1, src2, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_xor");

    return NULL;
}

static PyObject* pyopencv_cv_blendLinear(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_weights1 = NULL;
    Mat weights1;
    PyObject* pyobj_weights2 = NULL;
    Mat weights2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "weights1", "weights2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:blendLinear", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_weights1, &pyobj_weights2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_weights1, weights1, ArgInfo("weights1", 0)) &&
        pyopencv_to_safe(pyobj_weights2, weights2, ArgInfo("weights2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::blendLinear(src1, src2, weights1, weights2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_weights1 = NULL;
    UMat weights1;
    PyObject* pyobj_weights2 = NULL;
    UMat weights2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "weights1", "weights2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:blendLinear", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_weights1, &pyobj_weights2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_weights1, weights1, ArgInfo("weights1", 0)) &&
        pyopencv_to_safe(pyobj_weights2, weights2, ArgInfo("weights2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::blendLinear(src1, src2, weights1, weights2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("blendLinear");

    return NULL;
}

static PyObject* pyopencv_cv_blur(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "anchor", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:blur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::blur(src, dst, ksize, anchor, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "anchor", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:blur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::blur(src, dst, ksize, anchor, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("blur");

    return NULL;
}

static PyObject* pyopencv_cv_borderInterpolate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_p = NULL;
    int p=0;
    PyObject* pyobj_len = NULL;
    int len=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    int retval;

    const char* keywords[] = { "p", "len", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:borderInterpolate", (char**)keywords, &pyobj_p, &pyobj_len, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_p, p, ArgInfo("p", 0)) &&
        pyopencv_to_safe(pyobj_len, len, ArgInfo("len", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(retval = cv::borderInterpolate(p, len, borderType));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_boundingRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_array = NULL;
    Mat array;
    Rect retval;

    const char* keywords[] = { "array", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:boundingRect", (char**)keywords, &pyobj_array) &&
        pyopencv_to_safe(pyobj_array, array, ArgInfo("array", 0)) )
    {
        ERRWRAP2(retval = cv::boundingRect(array));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_array = NULL;
    UMat array;
    Rect retval;

    const char* keywords[] = { "array", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:boundingRect", (char**)keywords, &pyobj_array) &&
        pyopencv_to_safe(pyobj_array, array, ArgInfo("array", 0)) )
    {
        ERRWRAP2(retval = cv::boundingRect(array));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("boundingRect");

    return NULL;
}

static PyObject* pyopencv_cv_boxFilter(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:boxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::boxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:boxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::boxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("boxFilter");

    return NULL;
}

static PyObject* pyopencv_cv_boxPoints(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_box = NULL;
    cv::RotatedRect box;
    PyObject* pyobj_points = NULL;
    Mat points;

    const char* keywords[] = { "box", "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:boxPoints", (char**)keywords, &pyobj_box, &pyobj_points) &&
        pyopencv_to_safe(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 1)) )
    {
        ERRWRAP2(cv::boxPoints(box, points));
        return pyopencv_from(points);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_box = NULL;
    cv::RotatedRect box;
    PyObject* pyobj_points = NULL;
    UMat points;

    const char* keywords[] = { "box", "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:boxPoints", (char**)keywords, &pyobj_box, &pyobj_points) &&
        pyopencv_to_safe(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 1)) )
    {
        ERRWRAP2(cv::boxPoints(box, points));
        return pyopencv_from(points);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("boxPoints");

    return NULL;
}

static PyObject* pyopencv_cv_broadcast(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_shape = NULL;
    Mat shape;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "shape", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:broadcast", (char**)keywords, &pyobj_src, &pyobj_shape, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_shape, shape, ArgInfo("shape", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::broadcast(src, shape, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_shape = NULL;
    UMat shape;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "shape", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:broadcast", (char**)keywords, &pyobj_src, &pyobj_shape, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_shape, shape, ArgInfo("shape", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::broadcast(src, shape, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("broadcast");

    return NULL;
}

static PyObject* pyopencv_cv_calcBackProject(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_images = NULL;
    vector_Mat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_scale = NULL;
    double scale=0;

    const char* keywords[] = { "images", "channels", "hist", "ranges", "scale", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:calcBackProject", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_hist, &pyobj_ranges, &pyobj_scale, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to_safe(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) )
    {
        ERRWRAP2(cv::calcBackProject(images, channels, hist, dst, ranges, scale));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_scale = NULL;
    double scale=0;

    const char* keywords[] = { "images", "channels", "hist", "ranges", "scale", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:calcBackProject", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_hist, &pyobj_ranges, &pyobj_scale, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to_safe(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) )
    {
        ERRWRAP2(cv::calcBackProject(images, channels, hist, dst, ranges, scale));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcBackProject");

    return NULL;
}

static PyObject* pyopencv_cv_calcCovarMatrix(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_samples = NULL;
    Mat samples;
    PyObject* pyobj_covar = NULL;
    Mat covar;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_ctype = NULL;
    int ctype=CV_64F;

    const char* keywords[] = { "samples", "mean", "flags", "covar", "ctype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:calcCovarMatrix", (char**)keywords, &pyobj_samples, &pyobj_mean, &pyobj_flags, &pyobj_covar, &pyobj_ctype) &&
        pyopencv_to_safe(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to_safe(pyobj_covar, covar, ArgInfo("covar", 1)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_ctype, ctype, ArgInfo("ctype", 0)) )
    {
        ERRWRAP2(cv::calcCovarMatrix(samples, covar, mean, flags, ctype));
        return Py_BuildValue("(NN)", pyopencv_from(covar), pyopencv_from(mean));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_samples = NULL;
    UMat samples;
    PyObject* pyobj_covar = NULL;
    UMat covar;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_ctype = NULL;
    int ctype=CV_64F;

    const char* keywords[] = { "samples", "mean", "flags", "covar", "ctype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:calcCovarMatrix", (char**)keywords, &pyobj_samples, &pyobj_mean, &pyobj_flags, &pyobj_covar, &pyobj_ctype) &&
        pyopencv_to_safe(pyobj_samples, samples, ArgInfo("samples", 0)) &&
        pyopencv_to_safe(pyobj_covar, covar, ArgInfo("covar", 1)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_ctype, ctype, ArgInfo("ctype", 0)) )
    {
        ERRWRAP2(cv::calcCovarMatrix(samples, covar, mean, flags, ctype));
        return Py_BuildValue("(NN)", pyopencv_from(covar), pyopencv_from(mean));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcCovarMatrix");

    return NULL;
}

static PyObject* pyopencv_cv_calcHist(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_images = NULL;
    vector_Mat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_histSize = NULL;
    vector_int histSize;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_accumulate = NULL;
    bool accumulate=false;

    const char* keywords[] = { "images", "channels", "mask", "histSize", "ranges", "hist", "accumulate", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:calcHist", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_mask, &pyobj_histSize, &pyobj_ranges, &pyobj_hist, &pyobj_accumulate) &&
        pyopencv_to_safe(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to_safe(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to_safe(pyobj_accumulate, accumulate, ArgInfo("accumulate", 0)) )
    {
        ERRWRAP2(cv::calcHist(images, channels, mask, hist, histSize, ranges, accumulate));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_images = NULL;
    vector_UMat images;
    PyObject* pyobj_channels = NULL;
    vector_int channels;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_histSize = NULL;
    vector_int histSize;
    PyObject* pyobj_ranges = NULL;
    vector_float ranges;
    PyObject* pyobj_accumulate = NULL;
    bool accumulate=false;

    const char* keywords[] = { "images", "channels", "mask", "histSize", "ranges", "hist", "accumulate", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:calcHist", (char**)keywords, &pyobj_images, &pyobj_channels, &pyobj_mask, &pyobj_histSize, &pyobj_ranges, &pyobj_hist, &pyobj_accumulate) &&
        pyopencv_to_safe(pyobj_images, images, ArgInfo("images", 0)) &&
        pyopencv_to_safe(pyobj_channels, channels, ArgInfo("channels", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_ranges, ranges, ArgInfo("ranges", 0)) &&
        pyopencv_to_safe(pyobj_accumulate, accumulate, ArgInfo("accumulate", 0)) )
    {
        ERRWRAP2(cv::calcHist(images, channels, mask, hist, histSize, ranges, accumulate));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcHist");

    return NULL;
}

static PyObject* pyopencv_cv_cartToPolar(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::cartToPolar(x, y, magnitude, angle, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::cartToPolar(x, y, magnitude, angle, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cartToPolar");

    return NULL;
}

static PyObject* pyopencv_cv_checkHardwareSupport(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_feature = NULL;
    int feature=0;
    bool retval;

    const char* keywords[] = { "feature", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:checkHardwareSupport", (char**)keywords, &pyobj_feature) &&
        pyopencv_to_safe(pyobj_feature, feature, ArgInfo("feature", 0)) )
    {
        ERRWRAP2(retval = cv::checkHardwareSupport(feature));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_checkRange(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_quiet = NULL;
    bool quiet=true;
    Point pos;
    PyObject* pyobj_minVal = NULL;
    double minVal=-DBL_MAX;
    PyObject* pyobj_maxVal = NULL;
    double maxVal=DBL_MAX;
    bool retval;

    const char* keywords[] = { "a", "quiet", "minVal", "maxVal", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:checkRange", (char**)keywords, &pyobj_a, &pyobj_quiet, &pyobj_minVal, &pyobj_maxVal) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_quiet, quiet, ArgInfo("quiet", 0)) &&
        pyopencv_to_safe(pyobj_minVal, minVal, ArgInfo("minVal", 0)) &&
        pyopencv_to_safe(pyobj_maxVal, maxVal, ArgInfo("maxVal", 0)) )
    {
        ERRWRAP2(retval = cv::checkRange(a, quiet, &pos, minVal, maxVal));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(pos));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_quiet = NULL;
    bool quiet=true;
    Point pos;
    PyObject* pyobj_minVal = NULL;
    double minVal=-DBL_MAX;
    PyObject* pyobj_maxVal = NULL;
    double maxVal=DBL_MAX;
    bool retval;

    const char* keywords[] = { "a", "quiet", "minVal", "maxVal", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:checkRange", (char**)keywords, &pyobj_a, &pyobj_quiet, &pyobj_minVal, &pyobj_maxVal) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_quiet, quiet, ArgInfo("quiet", 0)) &&
        pyopencv_to_safe(pyobj_minVal, minVal, ArgInfo("minVal", 0)) &&
        pyopencv_to_safe(pyobj_maxVal, maxVal, ArgInfo("maxVal", 0)) )
    {
        ERRWRAP2(retval = cv::checkRange(a, quiet, &pos, minVal, maxVal));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(pos));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("checkRange");

    return NULL;
}

static PyObject* pyopencv_cv_circle(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_radius = NULL;
    int radius=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "radius", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:circle", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_radius, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_radius, radius, ArgInfo("radius", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::circle(img, center, radius, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_radius = NULL;
    int radius=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "radius", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:circle", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_radius, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_radius, radius, ArgInfo("radius", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::circle(img, center, radius, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("circle");

    return NULL;
}

static PyObject* pyopencv_cv_clipLine(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_imgRect = NULL;
    Rect imgRect;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    bool retval;

    const char* keywords[] = { "imgRect", "pt1", "pt2", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:clipLine", (char**)keywords, &pyobj_imgRect, &pyobj_pt1, &pyobj_pt2) &&
        pyopencv_to_safe(pyobj_imgRect, imgRect, ArgInfo("imgRect", 0)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 1)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 1)) )
    {
        ERRWRAP2(retval = cv::clipLine(imgRect, pt1, pt2));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(pt1), pyopencv_from(pt2));
    }

    return NULL;
}

static PyObject* pyopencv_cv_compare(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) )
    {
        ERRWRAP2(cv::compare(src1, src2, dst, cmpop));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) )
    {
        ERRWRAP2(cv::compare(src1, src2, dst, cmpop));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("compare");

    return NULL;
}

static PyObject* pyopencv_cv_compareHist(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_H1 = NULL;
    Mat H1;
    PyObject* pyobj_H2 = NULL;
    Mat H2;
    PyObject* pyobj_method = NULL;
    int method=0;
    double retval;

    const char* keywords[] = { "H1", "H2", "method", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:compareHist", (char**)keywords, &pyobj_H1, &pyobj_H2, &pyobj_method) &&
        pyopencv_to_safe(pyobj_H1, H1, ArgInfo("H1", 0)) &&
        pyopencv_to_safe(pyobj_H2, H2, ArgInfo("H2", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) )
    {
        ERRWRAP2(retval = cv::compareHist(H1, H2, method));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_H1 = NULL;
    UMat H1;
    PyObject* pyobj_H2 = NULL;
    UMat H2;
    PyObject* pyobj_method = NULL;
    int method=0;
    double retval;

    const char* keywords[] = { "H1", "H2", "method", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:compareHist", (char**)keywords, &pyobj_H1, &pyobj_H2, &pyobj_method) &&
        pyopencv_to_safe(pyobj_H1, H1, ArgInfo("H1", 0)) &&
        pyopencv_to_safe(pyobj_H2, H2, ArgInfo("H2", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) )
    {
        ERRWRAP2(retval = cv::compareHist(H1, H2, method));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("compareHist");

    return NULL;
}

static PyObject* pyopencv_cv_completeSymm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_m = NULL;
    Mat m;
    PyObject* pyobj_lowerToUpper = NULL;
    bool lowerToUpper=false;

    const char* keywords[] = { "m", "lowerToUpper", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:completeSymm", (char**)keywords, &pyobj_m, &pyobj_lowerToUpper) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 1)) &&
        pyopencv_to_safe(pyobj_lowerToUpper, lowerToUpper, ArgInfo("lowerToUpper", 0)) )
    {
        ERRWRAP2(cv::completeSymm(m, lowerToUpper));
        return pyopencv_from(m);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_lowerToUpper = NULL;
    bool lowerToUpper=false;

    const char* keywords[] = { "m", "lowerToUpper", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:completeSymm", (char**)keywords, &pyobj_m, &pyobj_lowerToUpper) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 1)) &&
        pyopencv_to_safe(pyobj_lowerToUpper, lowerToUpper, ArgInfo("lowerToUpper", 0)) )
    {
        ERRWRAP2(cv::completeSymm(m, lowerToUpper));
        return pyopencv_from(m);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("completeSymm");

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponents(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("connectedComponents");

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponentsWithAlgorithm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(labels));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("connectedComponentsWithAlgorithm");

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponentsWithStats(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_stats = NULL;
    Mat stats;
    PyObject* pyobj_centroids = NULL;
    Mat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "stats", "centroids", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:connectedComponentsWithStats", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_stats, &pyobj_centroids, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to_safe(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_stats = NULL;
    UMat stats;
    PyObject* pyobj_centroids = NULL;
    UMat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;
    int retval;

    const char* keywords[] = { "image", "labels", "stats", "centroids", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:connectedComponentsWithStats", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_stats, &pyobj_centroids, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to_safe(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("connectedComponentsWithStats");

    return NULL;
}

static PyObject* pyopencv_cv_connectedComponentsWithStatsWithAlgorithm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_stats = NULL;
    Mat stats;
    PyObject* pyobj_centroids = NULL;
    Mat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", "stats", "centroids", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:connectedComponentsWithStatsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels, &pyobj_stats, &pyobj_centroids) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to_safe(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype, ccltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_stats = NULL;
    UMat stats;
    PyObject* pyobj_centroids = NULL;
    UMat centroids;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    int ccltype=0;
    int retval;

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", "stats", "centroids", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:connectedComponentsWithStatsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels, &pyobj_stats, &pyobj_centroids) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_stats, stats, ArgInfo("stats", 1)) &&
        pyopencv_to_safe(pyobj_centroids, centroids, ArgInfo("centroids", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(retval = cv::connectedComponentsWithStats(image, labels, stats, centroids, connectivity, ltype, ccltype));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(labels), pyopencv_from(stats), pyopencv_from(centroids));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("connectedComponentsWithStatsWithAlgorithm");

    return NULL;
}

static PyObject* pyopencv_cv_contourArea(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_oriented = NULL;
    bool oriented=false;
    double retval;

    const char* keywords[] = { "contour", "oriented", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:contourArea", (char**)keywords, &pyobj_contour, &pyobj_oriented) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to_safe(pyobj_oriented, oriented, ArgInfo("oriented", 0)) )
    {
        ERRWRAP2(retval = cv::contourArea(contour, oriented));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_oriented = NULL;
    bool oriented=false;
    double retval;

    const char* keywords[] = { "contour", "oriented", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:contourArea", (char**)keywords, &pyobj_contour, &pyobj_oriented) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to_safe(pyobj_oriented, oriented, ArgInfo("oriented", 0)) )
    {
        ERRWRAP2(retval = cv::contourArea(contour, oriented));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("contourArea");

    return NULL;
}

static PyObject* pyopencv_cv_convertFp16(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:convertFp16", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertFp16(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:convertFp16", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::convertFp16(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convertFp16");

    return NULL;
}

static PyObject* pyopencv_cv_convertMaps(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_map1 = NULL;
    Mat map1;
    PyObject* pyobj_map2 = NULL;
    Mat map2;
    PyObject* pyobj_dstmap1 = NULL;
    Mat dstmap1;
    PyObject* pyobj_dstmap2 = NULL;
    Mat dstmap2;
    PyObject* pyobj_dstmap1type = NULL;
    int dstmap1type=0;
    PyObject* pyobj_nninterpolation = NULL;
    bool nninterpolation=false;

    const char* keywords[] = { "map1", "map2", "dstmap1type", "dstmap1", "dstmap2", "nninterpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:convertMaps", (char**)keywords, &pyobj_map1, &pyobj_map2, &pyobj_dstmap1type, &pyobj_dstmap1, &pyobj_dstmap2, &pyobj_nninterpolation) &&
        pyopencv_to_safe(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to_safe(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to_safe(pyobj_dstmap1, dstmap1, ArgInfo("dstmap1", 1)) &&
        pyopencv_to_safe(pyobj_dstmap2, dstmap2, ArgInfo("dstmap2", 1)) &&
        pyopencv_to_safe(pyobj_dstmap1type, dstmap1type, ArgInfo("dstmap1type", 0)) &&
        pyopencv_to_safe(pyobj_nninterpolation, nninterpolation, ArgInfo("nninterpolation", 0)) )
    {
        ERRWRAP2(cv::convertMaps(map1, map2, dstmap1, dstmap2, dstmap1type, nninterpolation));
        return Py_BuildValue("(NN)", pyopencv_from(dstmap1), pyopencv_from(dstmap2));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_map1 = NULL;
    UMat map1;
    PyObject* pyobj_map2 = NULL;
    UMat map2;
    PyObject* pyobj_dstmap1 = NULL;
    UMat dstmap1;
    PyObject* pyobj_dstmap2 = NULL;
    UMat dstmap2;
    PyObject* pyobj_dstmap1type = NULL;
    int dstmap1type=0;
    PyObject* pyobj_nninterpolation = NULL;
    bool nninterpolation=false;

    const char* keywords[] = { "map1", "map2", "dstmap1type", "dstmap1", "dstmap2", "nninterpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:convertMaps", (char**)keywords, &pyobj_map1, &pyobj_map2, &pyobj_dstmap1type, &pyobj_dstmap1, &pyobj_dstmap2, &pyobj_nninterpolation) &&
        pyopencv_to_safe(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to_safe(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to_safe(pyobj_dstmap1, dstmap1, ArgInfo("dstmap1", 1)) &&
        pyopencv_to_safe(pyobj_dstmap2, dstmap2, ArgInfo("dstmap2", 1)) &&
        pyopencv_to_safe(pyobj_dstmap1type, dstmap1type, ArgInfo("dstmap1type", 0)) &&
        pyopencv_to_safe(pyobj_nninterpolation, nninterpolation, ArgInfo("nninterpolation", 0)) )
    {
        ERRWRAP2(cv::convertMaps(map1, map2, dstmap1, dstmap2, dstmap1type, nninterpolation));
        return Py_BuildValue("(NN)", pyopencv_from(dstmap1), pyopencv_from(dstmap2));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convertMaps");

    return NULL;
}

static PyObject* pyopencv_cv_convertScaleAbs(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;

    const char* keywords[] = { "src", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:convertScaleAbs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(cv::convertScaleAbs(src, dst, alpha, beta));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;

    const char* keywords[] = { "src", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:convertScaleAbs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(cv::convertScaleAbs(src, dst, alpha, beta));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convertScaleAbs");

    return NULL;
}

static PyObject* pyopencv_cv_convexHull(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_hull = NULL;
    Mat hull;
    PyObject* pyobj_clockwise = NULL;
    bool clockwise=false;
    PyObject* pyobj_returnPoints = NULL;
    bool returnPoints=true;

    const char* keywords[] = { "points", "hull", "clockwise", "returnPoints", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:convexHull", (char**)keywords, &pyobj_points, &pyobj_hull, &pyobj_clockwise, &pyobj_returnPoints) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_hull, hull, ArgInfo("hull", 1)) &&
        pyopencv_to_safe(pyobj_clockwise, clockwise, ArgInfo("clockwise", 0)) &&
        pyopencv_to_safe(pyobj_returnPoints, returnPoints, ArgInfo("returnPoints", 0)) )
    {
        ERRWRAP2(cv::convexHull(points, hull, clockwise, returnPoints));
        return pyopencv_from(hull);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_hull = NULL;
    UMat hull;
    PyObject* pyobj_clockwise = NULL;
    bool clockwise=false;
    PyObject* pyobj_returnPoints = NULL;
    bool returnPoints=true;

    const char* keywords[] = { "points", "hull", "clockwise", "returnPoints", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:convexHull", (char**)keywords, &pyobj_points, &pyobj_hull, &pyobj_clockwise, &pyobj_returnPoints) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_hull, hull, ArgInfo("hull", 1)) &&
        pyopencv_to_safe(pyobj_clockwise, clockwise, ArgInfo("clockwise", 0)) &&
        pyopencv_to_safe(pyobj_returnPoints, returnPoints, ArgInfo("returnPoints", 0)) )
    {
        ERRWRAP2(cv::convexHull(points, hull, clockwise, returnPoints));
        return pyopencv_from(hull);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convexHull");

    return NULL;
}

static PyObject* pyopencv_cv_convexityDefects(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_convexhull = NULL;
    Mat convexhull;
    PyObject* pyobj_convexityDefects = NULL;
    Mat convexityDefects;

    const char* keywords[] = { "contour", "convexhull", "convexityDefects", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:convexityDefects", (char**)keywords, &pyobj_contour, &pyobj_convexhull, &pyobj_convexityDefects) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to_safe(pyobj_convexhull, convexhull, ArgInfo("convexhull", 0)) &&
        pyopencv_to_safe(pyobj_convexityDefects, convexityDefects, ArgInfo("convexityDefects", 1)) )
    {
        ERRWRAP2(cv::convexityDefects(contour, convexhull, convexityDefects));
        return pyopencv_from(convexityDefects);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_convexhull = NULL;
    UMat convexhull;
    PyObject* pyobj_convexityDefects = NULL;
    UMat convexityDefects;

    const char* keywords[] = { "contour", "convexhull", "convexityDefects", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:convexityDefects", (char**)keywords, &pyobj_contour, &pyobj_convexhull, &pyobj_convexityDefects) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to_safe(pyobj_convexhull, convexhull, ArgInfo("convexhull", 0)) &&
        pyopencv_to_safe(pyobj_convexityDefects, convexityDefects, ArgInfo("convexityDefects", 1)) )
    {
        ERRWRAP2(cv::convexityDefects(contour, convexhull, convexityDefects));
        return pyopencv_from(convexityDefects);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convexityDefects");

    return NULL;
}

static PyObject* pyopencv_cv_copyMakeBorder(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to_safe(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to_safe(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to_safe(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(cv::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to_safe(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to_safe(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to_safe(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(cv::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("copyMakeBorder");

    return NULL;
}

static PyObject* pyopencv_cv_copyTo(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:copyTo", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::copyTo(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:copyTo", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::copyTo(src, dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("copyTo");

    return NULL;
}

static PyObject* pyopencv_cv_cornerEigenValsAndVecs(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:cornerEigenValsAndVecs", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerEigenValsAndVecs(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:cornerEigenValsAndVecs", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerEigenValsAndVecs(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cornerEigenValsAndVecs");

    return NULL;
}

static PyObject* pyopencv_cv_cornerHarris(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_k = NULL;
    double k=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "k", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:cornerHarris", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_k, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerHarris(src, dst, blockSize, ksize, k, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_k = NULL;
    double k=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "ksize", "k", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:cornerHarris", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_ksize, &pyobj_k, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerHarris(src, dst, blockSize, ksize, k, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cornerHarris");

    return NULL;
}

static PyObject* pyopencv_cv_cornerMinEigenVal(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "dst", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cornerMinEigenVal", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_dst, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerMinEigenVal(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "blockSize", "dst", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cornerMinEigenVal", (char**)keywords, &pyobj_src, &pyobj_blockSize, &pyobj_dst, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::cornerMinEigenVal(src, dst, blockSize, ksize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cornerMinEigenVal");

    return NULL;
}

static PyObject* pyopencv_cv_cornerSubPix(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_zeroZone = NULL;
    Size zeroZone;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;

    const char* keywords[] = { "image", "corners", "winSize", "zeroZone", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO:cornerSubPix", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_winSize, &pyobj_zeroZone, &pyobj_criteria) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to_safe(pyobj_zeroZone, zeroZone, ArgInfo("zeroZone", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::cornerSubPix(image, corners, winSize, zeroZone, criteria));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_zeroZone = NULL;
    Size zeroZone;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;

    const char* keywords[] = { "image", "corners", "winSize", "zeroZone", "criteria", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO:cornerSubPix", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_winSize, &pyobj_zeroZone, &pyobj_criteria) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to_safe(pyobj_zeroZone, zeroZone, ArgInfo("zeroZone", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) )
    {
        ERRWRAP2(cv::cornerSubPix(image, corners, winSize, zeroZone, criteria));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cornerSubPix");

    return NULL;
}

static PyObject* pyopencv_cv_countNonZero(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::countNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::countNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("countNonZero");

    return NULL;
}

static PyObject* pyopencv_cv_createCLAHE(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_clipLimit = NULL;
    double clipLimit=40.0;
    PyObject* pyobj_tileGridSize = NULL;
    Size tileGridSize=Size(8, 8);
    Ptr<CLAHE> retval;

    const char* keywords[] = { "clipLimit", "tileGridSize", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:createCLAHE", (char**)keywords, &pyobj_clipLimit, &pyobj_tileGridSize) &&
        pyopencv_to_safe(pyobj_clipLimit, clipLimit, ArgInfo("clipLimit", 0)) &&
        pyopencv_to_safe(pyobj_tileGridSize, tileGridSize, ArgInfo("tileGridSize", 0)) )
    {
        ERRWRAP2(retval = cv::createCLAHE(clipLimit, tileGridSize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createGeneralizedHoughBallard(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    Ptr<GeneralizedHoughBallard> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::createGeneralizedHoughBallard());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createGeneralizedHoughGuil(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    Ptr<GeneralizedHoughGuil> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::createGeneralizedHoughGuil());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_createHanningWindow(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "winSize", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:createHanningWindow", (char**)keywords, &pyobj_winSize, &pyobj_type, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(cv::createHanningWindow(dst, winSize, type));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_winSize = NULL;
    Size winSize;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "winSize", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:createHanningWindow", (char**)keywords, &pyobj_winSize, &pyobj_type, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_winSize, winSize, ArgInfo("winSize", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(cv::createHanningWindow(dst, winSize, type));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("createHanningWindow");

    return NULL;
}

static PyObject* pyopencv_cv_createLineSegmentDetector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_refine = NULL;
    int refine=LSD_REFINE_STD;
    PyObject* pyobj_scale = NULL;
    double scale=0.8;
    PyObject* pyobj_sigma_scale = NULL;
    double sigma_scale=0.6;
    PyObject* pyobj_quant = NULL;
    double quant=2.0;
    PyObject* pyobj_ang_th = NULL;
    double ang_th=22.5;
    PyObject* pyobj_log_eps = NULL;
    double log_eps=0;
    PyObject* pyobj_density_th = NULL;
    double density_th=0.7;
    PyObject* pyobj_n_bins = NULL;
    int n_bins=1024;
    Ptr<LineSegmentDetector> retval;

    const char* keywords[] = { "refine", "scale", "sigma_scale", "quant", "ang_th", "log_eps", "density_th", "n_bins", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OOOOOOOO:createLineSegmentDetector", (char**)keywords, &pyobj_refine, &pyobj_scale, &pyobj_sigma_scale, &pyobj_quant, &pyobj_ang_th, &pyobj_log_eps, &pyobj_density_th, &pyobj_n_bins) &&
        pyopencv_to_safe(pyobj_refine, refine, ArgInfo("refine", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_sigma_scale, sigma_scale, ArgInfo("sigma_scale", 0)) &&
        pyopencv_to_safe(pyobj_quant, quant, ArgInfo("quant", 0)) &&
        pyopencv_to_safe(pyobj_ang_th, ang_th, ArgInfo("ang_th", 0)) &&
        pyopencv_to_safe(pyobj_log_eps, log_eps, ArgInfo("log_eps", 0)) &&
        pyopencv_to_safe(pyobj_density_th, density_th, ArgInfo("density_th", 0)) &&
        pyopencv_to_safe(pyobj_n_bins, n_bins, ArgInfo("n_bins", 0)) )
    {
        ERRWRAP2(retval = cv::createLineSegmentDetector(refine, scale, sigma_scale, quant, ang_th, log_eps, density_th, n_bins));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cubeRoot(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_val = NULL;
    float val=0.f;
    float retval;

    const char* keywords[] = { "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cubeRoot", (char**)keywords, &pyobj_val) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(retval = cv::cubeRoot(val));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cvtColor(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::cvtColor(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::cvtColor(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cvtColor");

    return NULL;
}

static PyObject* pyopencv_cv_cvtColorTwoPlane(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;

    const char* keywords[] = { "src1", "src2", "code", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:cvtColorTwoPlane", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_code, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) )
    {
        ERRWRAP2(cv::cvtColorTwoPlane(src1, src2, dst, code));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;

    const char* keywords[] = { "src1", "src2", "code", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:cvtColorTwoPlane", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_code, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) )
    {
        ERRWRAP2(cv::cvtColorTwoPlane(src1, src2, dst, code));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cvtColorTwoPlane");

    return NULL;
}

static PyObject* pyopencv_cv_dct(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:dct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::dct(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:dct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::dct(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dct");

    return NULL;
}

static PyObject* pyopencv_cv_demosaicing(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::demosaicing(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dstCn = NULL;
    int dstCn=0;

    const char* keywords[] = { "src", "code", "dst", "dstCn", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dstCn) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dstCn, dstCn, ArgInfo("dstCn", 0)) )
    {
        ERRWRAP2(cv::demosaicing(src, dst, code, dstCn));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("demosaicing");

    return NULL;
}

static PyObject* pyopencv_cv_determinant(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    double retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:determinant", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::determinant(mtx));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    double retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:determinant", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::determinant(mtx));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("determinant");

    return NULL;
}

static PyObject* pyopencv_cv_dft(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::dft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::dft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dft");

    return NULL;
}

static PyObject* pyopencv_cv_dilate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:dilate", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::dilate(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:dilate", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::dilate(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dilate");

    return NULL;
}

static PyObject* pyopencv_cv_distanceTransform(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_dstType = NULL;
    int dstType=CV_32F;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "dstType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:distanceTransform", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_dstType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to_safe(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to_safe(pyobj_dstType, dstType, ArgInfo("dstType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, distanceType, maskSize, dstType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_dstType = NULL;
    int dstType=CV_32F;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "dstType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:distanceTransform", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_dstType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to_safe(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to_safe(pyobj_dstType, dstType, ArgInfo("dstType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, distanceType, maskSize, dstType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("distanceTransform");

    return NULL;
}

static PyObject* pyopencv_cv_distanceTransformWithLabels(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_labelType = NULL;
    int labelType=DIST_LABEL_CCOMP;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "labels", "labelType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:distanceTransformWithLabels", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_labels, &pyobj_labelType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to_safe(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to_safe(pyobj_labelType, labelType, ArgInfo("labelType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, labels, distanceType, maskSize, labelType));
        return Py_BuildValue("(NN)", pyopencv_from(dst), pyopencv_from(labels));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_distanceType = NULL;
    int distanceType=0;
    PyObject* pyobj_maskSize = NULL;
    int maskSize=0;
    PyObject* pyobj_labelType = NULL;
    int labelType=DIST_LABEL_CCOMP;

    const char* keywords[] = { "src", "distanceType", "maskSize", "dst", "labels", "labelType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:distanceTransformWithLabels", (char**)keywords, &pyobj_src, &pyobj_distanceType, &pyobj_maskSize, &pyobj_dst, &pyobj_labels, &pyobj_labelType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_distanceType, distanceType, ArgInfo("distanceType", 0)) &&
        pyopencv_to_safe(pyobj_maskSize, maskSize, ArgInfo("maskSize", 0)) &&
        pyopencv_to_safe(pyobj_labelType, labelType, ArgInfo("labelType", 0)) )
    {
        ERRWRAP2(cv::distanceTransform(src, dst, labels, distanceType, maskSize, labelType));
        return Py_BuildValue("(NN)", pyopencv_from(dst), pyopencv_from(labels));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("distanceTransformWithLabels");

    return NULL;
}

static PyObject* pyopencv_cv_divSpectrums(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_b = NULL;
    Mat b;
    PyObject* pyobj_c = NULL;
    Mat c;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;

    const char* keywords[] = { "a", "b", "flags", "c", "conjB", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:divSpectrums", (char**)keywords, &pyobj_a, &pyobj_b, &pyobj_flags, &pyobj_c, &pyobj_conjB) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_b, b, ArgInfo("b", 0)) &&
        pyopencv_to_safe(pyobj_c, c, ArgInfo("c", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) )
    {
        ERRWRAP2(cv::divSpectrums(a, b, c, flags, conjB));
        return pyopencv_from(c);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_b = NULL;
    UMat b;
    PyObject* pyobj_c = NULL;
    UMat c;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;

    const char* keywords[] = { "a", "b", "flags", "c", "conjB", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:divSpectrums", (char**)keywords, &pyobj_a, &pyobj_b, &pyobj_flags, &pyobj_c, &pyobj_conjB) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_b, b, ArgInfo("b", 0)) &&
        pyopencv_to_safe(pyobj_c, c, ArgInfo("c", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) )
    {
        ERRWRAP2(cv::divSpectrums(a, b, c, flags, conjB));
        return pyopencv_from(c);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("divSpectrums");

    return NULL;
}

static PyObject* pyopencv_cv_divide(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_scale = NULL;
    double scale=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "scale", "src2", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:divide", (char**)keywords, &pyobj_scale, &pyobj_src2, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(scale, src2, dst, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_scale = NULL;
    double scale=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "scale", "src2", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:divide", (char**)keywords, &pyobj_scale, &pyobj_src2, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::divide(scale, src2, dst, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("divide");

    return NULL;
}

static PyObject* pyopencv_cv_drawContours(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_contours = NULL;
    vector_Mat contours;
    PyObject* pyobj_contourIdx = NULL;
    int contourIdx=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_hierarchy = NULL;
    Mat hierarchy;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=INT_MAX;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "contours", "contourIdx", "color", "thickness", "lineType", "hierarchy", "maxLevel", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:drawContours", (char**)keywords, &pyobj_image, &pyobj_contours, &pyobj_contourIdx, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_hierarchy, &pyobj_maxLevel, &pyobj_offset) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 0)) &&
        pyopencv_to_safe(pyobj_contourIdx, contourIdx, ArgInfo("contourIdx", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 0)) &&
        pyopencv_to_safe(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::drawContours(image, contours, contourIdx, color, thickness, lineType, hierarchy, maxLevel, offset));
        return pyopencv_from(image);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_contours = NULL;
    vector_UMat contours;
    PyObject* pyobj_contourIdx = NULL;
    int contourIdx=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_hierarchy = NULL;
    UMat hierarchy;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=INT_MAX;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "contours", "contourIdx", "color", "thickness", "lineType", "hierarchy", "maxLevel", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:drawContours", (char**)keywords, &pyobj_image, &pyobj_contours, &pyobj_contourIdx, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_hierarchy, &pyobj_maxLevel, &pyobj_offset) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 0)) &&
        pyopencv_to_safe(pyobj_contourIdx, contourIdx, ArgInfo("contourIdx", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 0)) &&
        pyopencv_to_safe(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::drawContours(image, contours, contourIdx, color, thickness, lineType, hierarchy, maxLevel, offset));
        return pyopencv_from(image);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("drawContours");

    return NULL;
}

static PyObject* pyopencv_cv_drawMarker(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_position = NULL;
    Point position;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_markerType = NULL;
    int markerType=MARKER_CROSS;
    PyObject* pyobj_markerSize = NULL;
    int markerSize=20;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;

    const char* keywords[] = { "img", "position", "color", "markerType", "markerSize", "thickness", "line_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:drawMarker", (char**)keywords, &pyobj_img, &pyobj_position, &pyobj_color, &pyobj_markerType, &pyobj_markerSize, &pyobj_thickness, &pyobj_line_type) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_position, position, ArgInfo("position", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_markerType, markerType, ArgInfo("markerType", 0)) &&
        pyopencv_to_safe(pyobj_markerSize, markerSize, ArgInfo("markerSize", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_line_type, line_type, ArgInfo("line_type", 0)) )
    {
        ERRWRAP2(cv::drawMarker(img, position, color, markerType, markerSize, thickness, line_type));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_position = NULL;
    Point position;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_markerType = NULL;
    int markerType=MARKER_CROSS;
    PyObject* pyobj_markerSize = NULL;
    int markerSize=20;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_line_type = NULL;
    int line_type=8;

    const char* keywords[] = { "img", "position", "color", "markerType", "markerSize", "thickness", "line_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:drawMarker", (char**)keywords, &pyobj_img, &pyobj_position, &pyobj_color, &pyobj_markerType, &pyobj_markerSize, &pyobj_thickness, &pyobj_line_type) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_position, position, ArgInfo("position", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_markerType, markerType, ArgInfo("markerType", 0)) &&
        pyopencv_to_safe(pyobj_markerSize, markerSize, ArgInfo("markerSize", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_line_type, line_type, ArgInfo("line_type", 0)) )
    {
        ERRWRAP2(cv::drawMarker(img, position, color, markerType, markerSize, thickness, line_type));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("drawMarker");

    return NULL;
}

static PyObject* pyopencv_cv_eigen(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;
    bool retval;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:eigen", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(retval = cv::eigen(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;
    bool retval;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:eigen", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(retval = cv::eigen(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("eigen");

    return NULL;
}

static PyObject* pyopencv_cv_eigenNonSymmetric(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_eigenvalues = NULL;
    Mat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    Mat eigenvectors;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:eigenNonSymmetric", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(cv::eigenNonSymmetric(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NN)", pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_eigenvalues = NULL;
    UMat eigenvalues;
    PyObject* pyobj_eigenvectors = NULL;
    UMat eigenvectors;

    const char* keywords[] = { "src", "eigenvalues", "eigenvectors", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:eigenNonSymmetric", (char**)keywords, &pyobj_src, &pyobj_eigenvalues, &pyobj_eigenvectors) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_eigenvalues, eigenvalues, ArgInfo("eigenvalues", 1)) &&
        pyopencv_to_safe(pyobj_eigenvectors, eigenvectors, ArgInfo("eigenvectors", 1)) )
    {
        ERRWRAP2(cv::eigenNonSymmetric(src, eigenvalues, eigenvectors));
        return Py_BuildValue("(NN)", pyopencv_from(eigenvalues), pyopencv_from(eigenvectors));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("eigenNonSymmetric");

    return NULL;
}

static PyObject* pyopencv_cv_ellipse(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_axes = NULL;
    Size axes;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_startAngle = NULL;
    double startAngle=0;
    PyObject* pyobj_endAngle = NULL;
    double endAngle=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "axes", "angle", "startAngle", "endAngle", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOOO|OOO:ellipse", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_axes, &pyobj_angle, &pyobj_startAngle, &pyobj_endAngle, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_axes, axes, ArgInfo("axes", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_startAngle, startAngle, ArgInfo("startAngle", 0)) &&
        pyopencv_to_safe(pyobj_endAngle, endAngle, ArgInfo("endAngle", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_axes = NULL;
    Size axes;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_startAngle = NULL;
    double startAngle=0;
    PyObject* pyobj_endAngle = NULL;
    double endAngle=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "center", "axes", "angle", "startAngle", "endAngle", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOOO|OOO:ellipse", (char**)keywords, &pyobj_img, &pyobj_center, &pyobj_axes, &pyobj_angle, &pyobj_startAngle, &pyobj_endAngle, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_axes, axes, ArgInfo("axes", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_startAngle, startAngle, ArgInfo("startAngle", 0)) &&
        pyopencv_to_safe(pyobj_endAngle, endAngle, ArgInfo("endAngle", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, center, axes, angle, startAngle, endAngle, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_box = NULL;
    cv::RotatedRect box;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;

    const char* keywords[] = { "img", "box", "color", "thickness", "lineType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:ellipse", (char**)keywords, &pyobj_img, &pyobj_box, &pyobj_color, &pyobj_thickness, &pyobj_lineType) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, box, color, thickness, lineType));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_box = NULL;
    cv::RotatedRect box;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;

    const char* keywords[] = { "img", "box", "color", "thickness", "lineType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:ellipse", (char**)keywords, &pyobj_img, &pyobj_box, &pyobj_color, &pyobj_thickness, &pyobj_lineType) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_box, box, ArgInfo("box", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) )
    {
        ERRWRAP2(cv::ellipse(img, box, color, thickness, lineType));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("ellipse");

    return NULL;
}

static PyObject* pyopencv_cv_ellipse2Poly(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_center = NULL;
    Point center;
    PyObject* pyobj_axes = NULL;
    Size axes;
    PyObject* pyobj_angle = NULL;
    int angle=0;
    PyObject* pyobj_arcStart = NULL;
    int arcStart=0;
    PyObject* pyobj_arcEnd = NULL;
    int arcEnd=0;
    PyObject* pyobj_delta = NULL;
    int delta=0;
    vector_Point pts;

    const char* keywords[] = { "center", "axes", "angle", "arcStart", "arcEnd", "delta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO:ellipse2Poly", (char**)keywords, &pyobj_center, &pyobj_axes, &pyobj_angle, &pyobj_arcStart, &pyobj_arcEnd, &pyobj_delta) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_axes, axes, ArgInfo("axes", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_arcStart, arcStart, ArgInfo("arcStart", 0)) &&
        pyopencv_to_safe(pyobj_arcEnd, arcEnd, ArgInfo("arcEnd", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) )
    {
        ERRWRAP2(cv::ellipse2Poly(center, axes, angle, arcStart, arcEnd, delta, pts));
        return pyopencv_from(pts);
    }

    return NULL;
}

static PyObject* pyopencv_cv_equalizeHist(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::equalizeHist(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::equalizeHist(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("equalizeHist");

    return NULL;
}

static PyObject* pyopencv_cv_erode(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:erode", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::erode(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:erode", (char**)keywords, &pyobj_src, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::erode(src, dst, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("erode");

    return NULL;
}

static PyObject* pyopencv_cv_exp(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:exp", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::exp(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:exp", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::exp(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("exp");

    return NULL;
}

static PyObject* pyopencv_cv_extractChannel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "coi", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:extractChannel", (char**)keywords, &pyobj_src, &pyobj_coi, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::extractChannel(src, dst, coi));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "coi", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:extractChannel", (char**)keywords, &pyobj_src, &pyobj_coi, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::extractChannel(src, dst, coi));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("extractChannel");

    return NULL;
}

static PyObject* pyopencv_cv_fastAtan2(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_y = NULL;
    float y=0.f;
    PyObject* pyobj_x = NULL;
    float x=0.f;
    float retval;

    const char* keywords[] = { "y", "x", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:fastAtan2", (char**)keywords, &pyobj_y, &pyobj_x) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) )
    {
        ERRWRAP2(retval = cv::fastAtan2(y, x));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_fillConvexPoly(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "points", "color", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:fillConvexPoly", (char**)keywords, &pyobj_img, &pyobj_points, &pyobj_color, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::fillConvexPoly(img, points, color, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "points", "color", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:fillConvexPoly", (char**)keywords, &pyobj_img, &pyobj_points, &pyobj_color, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::fillConvexPoly(img, points, color, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("fillConvexPoly");

    return NULL;
}

static PyObject* pyopencv_cv_fillPoly(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pts = NULL;
    vector_Mat pts;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "img", "pts", "color", "lineType", "shift", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:fillPoly", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_color, &pyobj_lineType, &pyobj_shift, &pyobj_offset) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::fillPoly(img, pts, color, lineType, shift, offset));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pts = NULL;
    vector_UMat pts;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "img", "pts", "color", "lineType", "shift", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:fillPoly", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_color, &pyobj_lineType, &pyobj_shift, &pyobj_offset) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::fillPoly(img, pts, color, lineType, shift, offset));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("fillPoly");

    return NULL;
}

static PyObject* pyopencv_cv_filter2D(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernel", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:filter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::filter2D(src, dst, ddepth, kernel, anchor, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernel", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:filter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::filter2D(src, dst, ddepth, kernel, anchor, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("filter2D");

    return NULL;
}

static PyObject* pyopencv_cv_findContours(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_contours = NULL;
    vector_Mat contours;
    PyObject* pyobj_hierarchy = NULL;
    Mat hierarchy;
    PyObject* pyobj_mode = NULL;
    int mode=0;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "mode", "method", "contours", "hierarchy", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:findContours", (char**)keywords, &pyobj_image, &pyobj_mode, &pyobj_method, &pyobj_contours, &pyobj_hierarchy, &pyobj_offset) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 1)) &&
        pyopencv_to_safe(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 1)) &&
        pyopencv_to_safe(pyobj_mode, mode, ArgInfo("mode", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::findContours(image, contours, hierarchy, mode, method, offset));
        return Py_BuildValue("(NN)", pyopencv_from(contours), pyopencv_from(hierarchy));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_contours = NULL;
    vector_UMat contours;
    PyObject* pyobj_hierarchy = NULL;
    UMat hierarchy;
    PyObject* pyobj_mode = NULL;
    int mode=0;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_offset = NULL;
    Point offset;

    const char* keywords[] = { "image", "mode", "method", "contours", "hierarchy", "offset", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:findContours", (char**)keywords, &pyobj_image, &pyobj_mode, &pyobj_method, &pyobj_contours, &pyobj_hierarchy, &pyobj_offset) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 1)) &&
        pyopencv_to_safe(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 1)) &&
        pyopencv_to_safe(pyobj_mode, mode, ArgInfo("mode", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) )
    {
        ERRWRAP2(cv::findContours(image, contours, hierarchy, mode, method, offset));
        return Py_BuildValue("(NN)", pyopencv_from(contours), pyopencv_from(hierarchy));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("findContours");

    return NULL;
}

static PyObject* pyopencv_cv_findContoursLinkRuns(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_contours = NULL;
    vector_Mat contours;
    PyObject* pyobj_hierarchy = NULL;
    Mat hierarchy;

    const char* keywords[] = { "image", "contours", "hierarchy", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:findContoursLinkRuns", (char**)keywords, &pyobj_image, &pyobj_contours, &pyobj_hierarchy) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 1)) &&
        pyopencv_to_safe(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 1)) )
    {
        ERRWRAP2(cv::findContoursLinkRuns(image, contours, hierarchy));
        return Py_BuildValue("(NN)", pyopencv_from(contours), pyopencv_from(hierarchy));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_contours = NULL;
    vector_UMat contours;
    PyObject* pyobj_hierarchy = NULL;
    UMat hierarchy;

    const char* keywords[] = { "image", "contours", "hierarchy", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:findContoursLinkRuns", (char**)keywords, &pyobj_image, &pyobj_contours, &pyobj_hierarchy) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 1)) &&
        pyopencv_to_safe(pyobj_hierarchy, hierarchy, ArgInfo("hierarchy", 1)) )
    {
        ERRWRAP2(cv::findContoursLinkRuns(image, contours, hierarchy));
        return Py_BuildValue("(NN)", pyopencv_from(contours), pyopencv_from(hierarchy));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_contours = NULL;
    vector_Mat contours;

    const char* keywords[] = { "image", "contours", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:findContoursLinkRuns", (char**)keywords, &pyobj_image, &pyobj_contours) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 1)) )
    {
        ERRWRAP2(cv::findContoursLinkRuns(image, contours));
        return pyopencv_from(contours);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_contours = NULL;
    vector_UMat contours;

    const char* keywords[] = { "image", "contours", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:findContoursLinkRuns", (char**)keywords, &pyobj_image, &pyobj_contours) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_contours, contours, ArgInfo("contours", 1)) )
    {
        ERRWRAP2(cv::findContoursLinkRuns(image, contours));
        return pyopencv_from(contours);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("findContoursLinkRuns");

    return NULL;
}

static PyObject* pyopencv_cv_findNonZero(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_idx = NULL;
    Mat idx;

    const char* keywords[] = { "src", "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:findNonZero", (char**)keywords, &pyobj_src, &pyobj_idx) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_idx, idx, ArgInfo("idx", 1)) )
    {
        ERRWRAP2(cv::findNonZero(src, idx));
        return pyopencv_from(idx);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_idx = NULL;
    UMat idx;

    const char* keywords[] = { "src", "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:findNonZero", (char**)keywords, &pyobj_src, &pyobj_idx) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_idx, idx, ArgInfo("idx", 1)) )
    {
        ERRWRAP2(cv::findNonZero(src, idx));
        return pyopencv_from(idx);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("findNonZero");

    return NULL;
}

static PyObject* pyopencv_cv_fitEllipse(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:fitEllipse", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipse(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:fitEllipse", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipse(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("fitEllipse");

    return NULL;
}

static PyObject* pyopencv_cv_fitEllipseAMS(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:fitEllipseAMS", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseAMS(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:fitEllipseAMS", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseAMS(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("fitEllipseAMS");

    return NULL;
}

static PyObject* pyopencv_cv_fitEllipseDirect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:fitEllipseDirect", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseDirect(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:fitEllipseDirect", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::fitEllipseDirect(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("fitEllipseDirect");

    return NULL;
}

static PyObject* pyopencv_cv_fitLine(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_line = NULL;
    Mat line;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_param = NULL;
    double param=0;
    PyObject* pyobj_reps = NULL;
    double reps=0;
    PyObject* pyobj_aeps = NULL;
    double aeps=0;

    const char* keywords[] = { "points", "distType", "param", "reps", "aeps", "line", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:fitLine", (char**)keywords, &pyobj_points, &pyobj_distType, &pyobj_param, &pyobj_reps, &pyobj_aeps, &pyobj_line) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_line, line, ArgInfo("line", 1)) &&
        pyopencv_to_safe(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to_safe(pyobj_param, param, ArgInfo("param", 0)) &&
        pyopencv_to_safe(pyobj_reps, reps, ArgInfo("reps", 0)) &&
        pyopencv_to_safe(pyobj_aeps, aeps, ArgInfo("aeps", 0)) )
    {
        ERRWRAP2(cv::fitLine(points, line, distType, param, reps, aeps));
        return pyopencv_from(line);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_line = NULL;
    UMat line;
    PyObject* pyobj_distType = NULL;
    int distType=0;
    PyObject* pyobj_param = NULL;
    double param=0;
    PyObject* pyobj_reps = NULL;
    double reps=0;
    PyObject* pyobj_aeps = NULL;
    double aeps=0;

    const char* keywords[] = { "points", "distType", "param", "reps", "aeps", "line", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:fitLine", (char**)keywords, &pyobj_points, &pyobj_distType, &pyobj_param, &pyobj_reps, &pyobj_aeps, &pyobj_line) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_line, line, ArgInfo("line", 1)) &&
        pyopencv_to_safe(pyobj_distType, distType, ArgInfo("distType", 0)) &&
        pyopencv_to_safe(pyobj_param, param, ArgInfo("param", 0)) &&
        pyopencv_to_safe(pyobj_reps, reps, ArgInfo("reps", 0)) &&
        pyopencv_to_safe(pyobj_aeps, aeps, ArgInfo("aeps", 0)) )
    {
        ERRWRAP2(cv::fitLine(points, line, distType, param, reps, aeps));
        return pyopencv_from(line);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("fitLine");

    return NULL;
}

static PyObject* pyopencv_cv_flip(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;

    const char* keywords[] = { "src", "flipCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) )
    {
        ERRWRAP2(cv::flip(src, dst, flipCode));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;

    const char* keywords[] = { "src", "flipCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) )
    {
        ERRWRAP2(cv::flip(src, dst, flipCode));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("flip");

    return NULL;
}

static PyObject* pyopencv_cv_flipND(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_axis = NULL;
    int axis=0;

    const char* keywords[] = { "src", "axis", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:flipND", (char**)keywords, &pyobj_src, &pyobj_axis, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_axis, axis, ArgInfo("axis", 0)) )
    {
        ERRWRAP2(cv::flipND(src, dst, axis));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_axis = NULL;
    int axis=0;

    const char* keywords[] = { "src", "axis", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:flipND", (char**)keywords, &pyobj_src, &pyobj_axis, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_axis, axis, ArgInfo("axis", 0)) )
    {
        ERRWRAP2(cv::flipND(src, dst, axis));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("flipND");

    return NULL;
}

static PyObject* pyopencv_cv_floodFill(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_seedPoint = NULL;
    Point seedPoint;
    PyObject* pyobj_newVal = NULL;
    Scalar newVal;
    Rect rect;
    PyObject* pyobj_loDiff = NULL;
    Scalar loDiff;
    PyObject* pyobj_upDiff = NULL;
    Scalar upDiff;
    PyObject* pyobj_flags = NULL;
    int flags=4;
    int retval;

    const char* keywords[] = { "image", "mask", "seedPoint", "newVal", "loDiff", "upDiff", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:floodFill", (char**)keywords, &pyobj_image, &pyobj_mask, &pyobj_seedPoint, &pyobj_newVal, &pyobj_loDiff, &pyobj_upDiff, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to_safe(pyobj_seedPoint, seedPoint, ArgInfo("seedPoint", 0)) &&
        pyopencv_to_safe(pyobj_newVal, newVal, ArgInfo("newVal", 0)) &&
        pyopencv_to_safe(pyobj_loDiff, loDiff, ArgInfo("loDiff", 0)) &&
        pyopencv_to_safe(pyobj_upDiff, upDiff, ArgInfo("upDiff", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::floodFill(image, mask, seedPoint, newVal, &rect, loDiff, upDiff, flags));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(image), pyopencv_from(mask), pyopencv_from(rect));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_seedPoint = NULL;
    Point seedPoint;
    PyObject* pyobj_newVal = NULL;
    Scalar newVal;
    Rect rect;
    PyObject* pyobj_loDiff = NULL;
    Scalar loDiff;
    PyObject* pyobj_upDiff = NULL;
    Scalar upDiff;
    PyObject* pyobj_flags = NULL;
    int flags=4;
    int retval;

    const char* keywords[] = { "image", "mask", "seedPoint", "newVal", "loDiff", "upDiff", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:floodFill", (char**)keywords, &pyobj_image, &pyobj_mask, &pyobj_seedPoint, &pyobj_newVal, &pyobj_loDiff, &pyobj_upDiff, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to_safe(pyobj_seedPoint, seedPoint, ArgInfo("seedPoint", 0)) &&
        pyopencv_to_safe(pyobj_newVal, newVal, ArgInfo("newVal", 0)) &&
        pyopencv_to_safe(pyobj_loDiff, loDiff, ArgInfo("loDiff", 0)) &&
        pyopencv_to_safe(pyobj_upDiff, upDiff, ArgInfo("upDiff", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::floodFill(image, mask, seedPoint, newVal, &rect, loDiff, upDiff, flags));
        return Py_BuildValue("(NNNN)", pyopencv_from(retval), pyopencv_from(image), pyopencv_from(mask), pyopencv_from(rect));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("floodFill");

    return NULL;
}

static PyObject* pyopencv_cv_gemm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    Mat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::gemm(src1, src2, alpha, src3, beta, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    UMat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::gemm(src1, src2, alpha, src3, beta, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("gemm");

    return NULL;
}

static PyObject* pyopencv_cv_getAffineTransform(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    Mat retval;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:getAffineTransform", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 0)) )
    {
        ERRWRAP2(retval = cv::getAffineTransform(src, dst));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    Mat retval;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:getAffineTransform", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 0)) )
    {
        ERRWRAP2(retval = cv::getAffineTransform(src, dst));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("getAffineTransform");

    return NULL;
}

static PyObject* pyopencv_cv_getBuildInformation(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getBuildInformation());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getCPUFeaturesLine(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    std::string retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getCPUFeaturesLine());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getCPUTickCount(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int64 retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getCPUTickCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getDerivKernels(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_kx = NULL;
    Mat kx;
    PyObject* pyobj_ky = NULL;
    Mat ky;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_normalize = NULL;
    bool normalize=false;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_32F;

    const char* keywords[] = { "dx", "dy", "ksize", "kx", "ky", "normalize", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:getDerivKernels", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_kx, &pyobj_ky, &pyobj_normalize, &pyobj_ktype) &&
        pyopencv_to_safe(pyobj_kx, kx, ArgInfo("kx", 1)) &&
        pyopencv_to_safe(pyobj_ky, ky, ArgInfo("ky", 1)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to_safe(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(cv::getDerivKernels(kx, ky, dx, dy, ksize, normalize, ktype));
        return Py_BuildValue("(NN)", pyopencv_from(kx), pyopencv_from(ky));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_kx = NULL;
    UMat kx;
    PyObject* pyobj_ky = NULL;
    UMat ky;
    PyObject* pyobj_dx = NULL;
    int dx=0;
    PyObject* pyobj_dy = NULL;
    int dy=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_normalize = NULL;
    bool normalize=false;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_32F;

    const char* keywords[] = { "dx", "dy", "ksize", "kx", "ky", "normalize", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:getDerivKernels", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_kx, &pyobj_ky, &pyobj_normalize, &pyobj_ktype) &&
        pyopencv_to_safe(pyobj_kx, kx, ArgInfo("kx", 1)) &&
        pyopencv_to_safe(pyobj_ky, ky, ArgInfo("ky", 1)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to_safe(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(cv::getDerivKernels(kx, ky, dx, dy, ksize, normalize, ktype));
        return Py_BuildValue("(NN)", pyopencv_from(kx), pyopencv_from(ky));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("getDerivKernels");

    return NULL;
}

static PyObject* pyopencv_cv_getFontScaleFromHeight(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_pixelHeight = NULL;
    int pixelHeight=0;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    double retval;

    const char* keywords[] = { "fontFace", "pixelHeight", "thickness", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:getFontScaleFromHeight", (char**)keywords, &pyobj_fontFace, &pyobj_pixelHeight, &pyobj_thickness) &&
        pyopencv_to_safe(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to_safe(pyobj_pixelHeight, pixelHeight, ArgInfo("pixelHeight", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) )
    {
        ERRWRAP2(retval = cv::getFontScaleFromHeight(fontFace, pixelHeight, thickness));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getGaborKernel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_sigma = NULL;
    double sigma=0;
    PyObject* pyobj_theta = NULL;
    double theta=0;
    PyObject* pyobj_lambd = NULL;
    double lambd=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_psi = NULL;
    double psi=CV_PI*0.5;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_64F;
    Mat retval;

    const char* keywords[] = { "ksize", "sigma", "theta", "lambd", "gamma", "psi", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OO:getGaborKernel", (char**)keywords, &pyobj_ksize, &pyobj_sigma, &pyobj_theta, &pyobj_lambd, &pyobj_gamma, &pyobj_psi, &pyobj_ktype) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_sigma, sigma, ArgInfo("sigma", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_lambd, lambd, ArgInfo("lambd", 0)) &&
        pyopencv_to_safe(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to_safe(pyobj_psi, psi, ArgInfo("psi", 0)) &&
        pyopencv_to_safe(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(retval = cv::getGaborKernel(ksize, sigma, theta, lambd, gamma, psi, ktype));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getGaussianKernel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_sigma = NULL;
    double sigma=0;
    PyObject* pyobj_ktype = NULL;
    int ktype=CV_64F;
    Mat retval;

    const char* keywords[] = { "ksize", "sigma", "ktype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:getGaussianKernel", (char**)keywords, &pyobj_ksize, &pyobj_sigma, &pyobj_ktype) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_sigma, sigma, ArgInfo("sigma", 0)) &&
        pyopencv_to_safe(pyobj_ktype, ktype, ArgInfo("ktype", 0)) )
    {
        ERRWRAP2(retval = cv::getGaussianKernel(ksize, sigma, ktype));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getHardwareFeatureName(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_feature = NULL;
    int feature=0;
    String retval;

    const char* keywords[] = { "feature", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:getHardwareFeatureName", (char**)keywords, &pyobj_feature) &&
        pyopencv_to_safe(pyobj_feature, feature, ArgInfo("feature", 0)) )
    {
        ERRWRAP2(retval = cv::getHardwareFeatureName(feature));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getLogLevel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getLogLevel());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getNumThreads(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getNumThreads());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getNumberOfCPUs(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getNumberOfCPUs());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getOptimalDFTSize(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_vecsize = NULL;
    int vecsize=0;
    int retval;

    const char* keywords[] = { "vecsize", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:getOptimalDFTSize", (char**)keywords, &pyobj_vecsize) &&
        pyopencv_to_safe(pyobj_vecsize, vecsize, ArgInfo("vecsize", 0)) )
    {
        ERRWRAP2(retval = cv::getOptimalDFTSize(vecsize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getPerspectiveTransform(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_solveMethod = NULL;
    int solveMethod=DECOMP_LU;
    Mat retval;

    const char* keywords[] = { "src", "dst", "solveMethod", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:getPerspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_solveMethod) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to_safe(pyobj_solveMethod, solveMethod, ArgInfo("solveMethod", 0)) )
    {
        ERRWRAP2(retval = cv::getPerspectiveTransform(src, dst, solveMethod));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_solveMethod = NULL;
    int solveMethod=DECOMP_LU;
    Mat retval;

    const char* keywords[] = { "src", "dst", "solveMethod", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:getPerspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_solveMethod) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 0)) &&
        pyopencv_to_safe(pyobj_solveMethod, solveMethod, ArgInfo("solveMethod", 0)) )
    {
        ERRWRAP2(retval = cv::getPerspectiveTransform(src, dst, solveMethod));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("getPerspectiveTransform");

    return NULL;
}

static PyObject* pyopencv_cv_getRectSubPix(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_patchSize = NULL;
    Size patchSize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_patch = NULL;
    Mat patch;
    PyObject* pyobj_patchType = NULL;
    int patchType=-1;

    const char* keywords[] = { "image", "patchSize", "center", "patch", "patchType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:getRectSubPix", (char**)keywords, &pyobj_image, &pyobj_patchSize, &pyobj_center, &pyobj_patch, &pyobj_patchType) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_patchSize, patchSize, ArgInfo("patchSize", 0)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_patch, patch, ArgInfo("patch", 1)) &&
        pyopencv_to_safe(pyobj_patchType, patchType, ArgInfo("patchType", 0)) )
    {
        ERRWRAP2(cv::getRectSubPix(image, patchSize, center, patch, patchType));
        return pyopencv_from(patch);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_patchSize = NULL;
    Size patchSize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_patch = NULL;
    UMat patch;
    PyObject* pyobj_patchType = NULL;
    int patchType=-1;

    const char* keywords[] = { "image", "patchSize", "center", "patch", "patchType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:getRectSubPix", (char**)keywords, &pyobj_image, &pyobj_patchSize, &pyobj_center, &pyobj_patch, &pyobj_patchType) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_patchSize, patchSize, ArgInfo("patchSize", 0)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_patch, patch, ArgInfo("patch", 1)) &&
        pyopencv_to_safe(pyobj_patchType, patchType, ArgInfo("patchType", 0)) )
    {
        ERRWRAP2(cv::getRectSubPix(image, patchSize, center, patch, patchType));
        return pyopencv_from(patch);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("getRectSubPix");

    return NULL;
}

static PyObject* pyopencv_cv_getRotationMatrix2D(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_scale = NULL;
    double scale=0;
    Mat retval;

    const char* keywords[] = { "center", "angle", "scale", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:getRotationMatrix2D", (char**)keywords, &pyobj_center, &pyobj_angle, &pyobj_scale) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) )
    {
        ERRWRAP2(retval = cv::getRotationMatrix2D(center, angle, scale));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getStructuringElement(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_shape = NULL;
    int shape=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    Mat retval;

    const char* keywords[] = { "shape", "ksize", "anchor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:getStructuringElement", (char**)keywords, &pyobj_shape, &pyobj_ksize, &pyobj_anchor) &&
        pyopencv_to_safe(pyobj_shape, shape, ArgInfo("shape", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) )
    {
        ERRWRAP2(retval = cv::getStructuringElement(shape, ksize, anchor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTextSize(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_fontScale = NULL;
    double fontScale=0;
    PyObject* pyobj_thickness = NULL;
    int thickness=0;
    int baseLine;
    Size retval;

    const char* keywords[] = { "text", "fontFace", "fontScale", "thickness", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:getTextSize", (char**)keywords, &pyobj_text, &pyobj_fontFace, &pyobj_fontScale, &pyobj_thickness) &&
        pyopencv_to_safe(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to_safe(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to_safe(pyobj_fontScale, fontScale, ArgInfo("fontScale", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) )
    {
        ERRWRAP2(retval = cv::getTextSize(text, fontFace, fontScale, thickness, &baseLine));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(baseLine));
    }

    return NULL;
}

static PyObject* pyopencv_cv_getThreadNum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getThreadNum());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTickCount(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int64 retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getTickCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getTickFrequency(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getTickFrequency());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionMajor(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionMajor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionMinor(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionMinor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionRevision(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionRevision());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_getVersionString(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::getVersionString());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_goodFeaturesToTrack(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "corners", "mask", "blockSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_corners, &pyobj_mask, &pyobj_blockSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "corners", "mask", "blockSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_corners, &pyobj_mask, &pyobj_blockSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_gradientSize = NULL;
    int gradientSize=0;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "mask", "blockSize", "gradientSize", "corners", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOOO|OOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_mask, &pyobj_blockSize, &pyobj_gradientSize, &pyobj_corners, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_gradientSize, gradientSize, ArgInfo("gradientSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, gradientSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_gradientSize = NULL;
    int gradientSize=0;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "mask", "blockSize", "gradientSize", "corners", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOOO|OOO:goodFeaturesToTrack", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_mask, &pyobj_blockSize, &pyobj_gradientSize, &pyobj_corners, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_gradientSize, gradientSize, ArgInfo("gradientSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, blockSize, gradientSize, useHarrisDetector, k));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("goodFeaturesToTrack");

    return NULL;
}

static PyObject* pyopencv_cv_goodFeaturesToTrackWithQuality(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_cornersQuality = NULL;
    Mat cornersQuality;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_gradientSize = NULL;
    int gradientSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "mask", "corners", "cornersQuality", "blockSize", "gradientSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOOOOO:goodFeaturesToTrackWithQuality", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_mask, &pyobj_corners, &pyobj_cornersQuality, &pyobj_blockSize, &pyobj_gradientSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_cornersQuality, cornersQuality, ArgInfo("cornersQuality", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_gradientSize, gradientSize, ArgInfo("gradientSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, cornersQuality, blockSize, gradientSize, useHarrisDetector, k));
        return Py_BuildValue("(NN)", pyopencv_from(corners), pyopencv_from(cornersQuality));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_cornersQuality = NULL;
    UMat cornersQuality;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_gradientSize = NULL;
    int gradientSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_k = NULL;
    double k=0.04;

    const char* keywords[] = { "image", "maxCorners", "qualityLevel", "minDistance", "mask", "corners", "cornersQuality", "blockSize", "gradientSize", "useHarrisDetector", "k", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOOOOO:goodFeaturesToTrackWithQuality", (char**)keywords, &pyobj_image, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_mask, &pyobj_corners, &pyobj_cornersQuality, &pyobj_blockSize, &pyobj_gradientSize, &pyobj_useHarrisDetector, &pyobj_k) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_cornersQuality, cornersQuality, ArgInfo("cornersQuality", 1)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_gradientSize, gradientSize, ArgInfo("gradientSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) )
    {
        ERRWRAP2(cv::goodFeaturesToTrack(image, corners, maxCorners, qualityLevel, minDistance, mask, cornersQuality, blockSize, gradientSize, useHarrisDetector, k));
        return Py_BuildValue("(NN)", pyopencv_from(corners), pyopencv_from(cornersQuality));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("goodFeaturesToTrackWithQuality");

    return NULL;
}

static PyObject* pyopencv_cv_grabCut(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_bgdModel = NULL;
    Mat bgdModel;
    PyObject* pyobj_fgdModel = NULL;
    Mat fgdModel;
    PyObject* pyobj_iterCount = NULL;
    int iterCount=0;
    PyObject* pyobj_mode = NULL;
    int mode=GC_EVAL;

    const char* keywords[] = { "img", "mask", "rect", "bgdModel", "fgdModel", "iterCount", "mode", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:grabCut", (char**)keywords, &pyobj_img, &pyobj_mask, &pyobj_rect, &pyobj_bgdModel, &pyobj_fgdModel, &pyobj_iterCount, &pyobj_mode) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to_safe(pyobj_bgdModel, bgdModel, ArgInfo("bgdModel", 1)) &&
        pyopencv_to_safe(pyobj_fgdModel, fgdModel, ArgInfo("fgdModel", 1)) &&
        pyopencv_to_safe(pyobj_iterCount, iterCount, ArgInfo("iterCount", 0)) &&
        pyopencv_to_safe(pyobj_mode, mode, ArgInfo("mode", 0)) )
    {
        ERRWRAP2(cv::grabCut(img, mask, rect, bgdModel, fgdModel, iterCount, mode));
        return Py_BuildValue("(NNN)", pyopencv_from(mask), pyopencv_from(bgdModel), pyopencv_from(fgdModel));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_bgdModel = NULL;
    UMat bgdModel;
    PyObject* pyobj_fgdModel = NULL;
    UMat fgdModel;
    PyObject* pyobj_iterCount = NULL;
    int iterCount=0;
    PyObject* pyobj_mode = NULL;
    int mode=GC_EVAL;

    const char* keywords[] = { "img", "mask", "rect", "bgdModel", "fgdModel", "iterCount", "mode", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:grabCut", (char**)keywords, &pyobj_img, &pyobj_mask, &pyobj_rect, &pyobj_bgdModel, &pyobj_fgdModel, &pyobj_iterCount, &pyobj_mode) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 1)) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to_safe(pyobj_bgdModel, bgdModel, ArgInfo("bgdModel", 1)) &&
        pyopencv_to_safe(pyobj_fgdModel, fgdModel, ArgInfo("fgdModel", 1)) &&
        pyopencv_to_safe(pyobj_iterCount, iterCount, ArgInfo("iterCount", 0)) &&
        pyopencv_to_safe(pyobj_mode, mode, ArgInfo("mode", 0)) )
    {
        ERRWRAP2(cv::grabCut(img, mask, rect, bgdModel, fgdModel, iterCount, mode));
        return Py_BuildValue("(NNN)", pyopencv_from(mask), pyopencv_from(bgdModel), pyopencv_from(fgdModel));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("grabCut");

    return NULL;
}

static PyObject* pyopencv_cv_hasNonZero(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    bool retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:hasNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::hasNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    bool retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:hasNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::hasNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("hasNonZero");

    return NULL;
}

static PyObject* pyopencv_cv_haveImageReader(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:haveImageReader", (char**)keywords, &pyobj_filename) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) )
    {
        ERRWRAP2(retval = cv::haveImageReader(filename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_haveImageWriter(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    bool retval;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:haveImageWriter", (char**)keywords, &pyobj_filename) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) )
    {
        ERRWRAP2(retval = cv::haveImageWriter(filename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_haveOpenVX(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::haveOpenVX());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_hconcat(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    vector_Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:hconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::hconcat(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    vector_UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:hconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::hconcat(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("hconcat");

    return NULL;
}

static PyObject* pyopencv_cv_idct(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:idct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::idct(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:idct", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::idct(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("idct");

    return NULL;
}

static PyObject* pyopencv_cv_idft(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:idft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::idft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_nonzeroRows = NULL;
    int nonzeroRows=0;

    const char* keywords[] = { "src", "dst", "flags", "nonzeroRows", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:idft", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags, &pyobj_nonzeroRows) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_nonzeroRows, nonzeroRows, ArgInfo("nonzeroRows", 0)) )
    {
        ERRWRAP2(cv::idft(src, dst, flags, nonzeroRows));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("idft");

    return NULL;
}

static PyObject* pyopencv_cv_imcount(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    size_t retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:imcount", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imcount(filename, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_imdecode(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_buf = NULL;
    Mat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_buf = NULL;
    UMat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Mat retval;

    const char* keywords[] = { "buf", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:imdecode", (char**)keywords, &pyobj_buf, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imdecode(buf, flags));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imdecode");

    return NULL;
}

static PyObject* pyopencv_cv_imdecodemulti(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_buf = NULL;
    Mat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_range = NULL;
    Range range=Range::all();
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", "range", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:imdecodemulti", (char**)keywords, &pyobj_buf, &pyobj_flags, &pyobj_mats, &pyobj_range) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to_safe(pyobj_range, range, ArgInfo("range", 0)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats, range));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_buf = NULL;
    UMat buf;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_range = NULL;
    Range range=Range::all();
    bool retval;

    const char* keywords[] = { "buf", "flags", "mats", "range", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:imdecodemulti", (char**)keywords, &pyobj_buf, &pyobj_flags, &pyobj_mats, &pyobj_range) &&
        pyopencv_to_safe(pyobj_buf, buf, ArgInfo("buf", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to_safe(pyobj_range, range, ArgInfo("range", 0)) )
    {
        ERRWRAP2(retval = cv::imdecodemulti(buf, flags, mats, range));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imdecodemulti");

    return NULL;
}

static PyObject* pyopencv_cv_imencode(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_ext = NULL;
    String ext;
    PyObject* pyobj_img = NULL;
    Mat img;
    vector_uchar buf;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_ext, ext, ArgInfo("ext", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(buf));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_ext = NULL;
    String ext;
    PyObject* pyobj_img = NULL;
    UMat img;
    vector_uchar buf;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "ext", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imencode", (char**)keywords, &pyobj_ext, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_ext, ext, ArgInfo("ext", 0)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imencode(ext, img, buf, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(buf));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imencode");

    return NULL;
}

static PyObject* pyopencv_cv_imread(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;
    Mat retval;

    const char* keywords[] = { "filename", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:imread", (char**)keywords, &pyobj_filename, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imread(filename, flags));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;

    const char* keywords[] = { "filename", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:imread", (char**)keywords, &pyobj_filename, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::imread(filename, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_COLOR;

    const char* keywords[] = { "filename", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:imread", (char**)keywords, &pyobj_filename, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::imread(filename, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imread");

    return NULL;
}

static PyObject* pyopencv_cv_imreadmulti(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "mats", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_mats, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_mats = NULL;
    vector_Mat mats;
    PyObject* pyobj_start = NULL;
    int start=0;
    PyObject* pyobj_count = NULL;
    int count=0;
    PyObject* pyobj_flags = NULL;
    int flags=IMREAD_ANYCOLOR;
    bool retval;

    const char* keywords[] = { "filename", "start", "count", "mats", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:imreadmulti", (char**)keywords, &pyobj_filename, &pyobj_start, &pyobj_count, &pyobj_mats, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_mats, mats, ArgInfo("mats", 1)) &&
        pyopencv_to_safe(pyobj_start, start, ArgInfo("start", 0)) &&
        pyopencv_to_safe(pyobj_count, count, ArgInfo("count", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::imreadmulti(filename, mats, start, count, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(mats));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imreadmulti");

    return NULL;
}

static PyObject* pyopencv_cv_imwrite(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwrite", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwrite(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imwrite");

    return NULL;
}

static PyObject* pyopencv_cv_imwritemulti(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    vector_Mat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwritemulti", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_img = NULL;
    vector_UMat img;
    PyObject* pyobj_params = NULL;
    vector_int params=std::vector<int>();
    bool retval;

    const char* keywords[] = { "filename", "img", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:imwritemulti", (char**)keywords, &pyobj_filename, &pyobj_img, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::imwritemulti(filename, img, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("imwritemulti");

    return NULL;
}

static PyObject* pyopencv_cv_inRange(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lowerb = NULL;
    Mat lowerb;
    PyObject* pyobj_upperb = NULL;
    Mat upperb;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to_safe(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::inRange(src, lowerb, upperb, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lowerb = NULL;
    UMat lowerb;
    PyObject* pyobj_upperb = NULL;
    UMat upperb;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to_safe(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::inRange(src, lowerb, upperb, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("inRange");

    return NULL;
}

static PyObject* pyopencv_cv_insertChannel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "dst", "coi", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:insertChannel", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_coi) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::insertChannel(src, dst, coi));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_coi = NULL;
    int coi=0;

    const char* keywords[] = { "src", "dst", "coi", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:insertChannel", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_coi) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_coi, coi, ArgInfo("coi", 0)) )
    {
        ERRWRAP2(cv::insertChannel(src, dst, coi));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("insertChannel");

    return NULL;
}

static PyObject* pyopencv_cv_integral(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;

    const char* keywords[] = { "src", "sum", "sdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sdepth) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sdepth));
        return pyopencv_from(sum);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;

    const char* keywords[] = { "src", "sum", "sdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sdepth) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sdepth));
        return pyopencv_from(sum);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("integral");

    return NULL;
}

static PyObject* pyopencv_cv_integral2(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_sqsum = NULL;
    Mat sqsum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:integral2", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to_safe(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, sdepth, sqdepth));
        return Py_BuildValue("(NN)", pyopencv_from(sum), pyopencv_from(sqsum));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_sqsum = NULL;
    UMat sqsum;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:integral2", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to_safe(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, sdepth, sqdepth));
        return Py_BuildValue("(NN)", pyopencv_from(sum), pyopencv_from(sqsum));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("integral2");

    return NULL;
}

static PyObject* pyopencv_cv_integral3(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_sqsum = NULL;
    Mat sqsum;
    PyObject* pyobj_tilted = NULL;
    Mat tilted;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "tilted", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:integral3", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_tilted, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_tilted, tilted, ArgInfo("tilted", 1)) &&
        pyopencv_to_safe(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to_safe(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, tilted, sdepth, sqdepth));
        return Py_BuildValue("(NNN)", pyopencv_from(sum), pyopencv_from(sqsum), pyopencv_from(tilted));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_sqsum = NULL;
    UMat sqsum;
    PyObject* pyobj_tilted = NULL;
    UMat tilted;
    PyObject* pyobj_sdepth = NULL;
    int sdepth=-1;
    PyObject* pyobj_sqdepth = NULL;
    int sqdepth=-1;

    const char* keywords[] = { "src", "sum", "sqsum", "tilted", "sdepth", "sqdepth", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:integral3", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_sqsum, &pyobj_tilted, &pyobj_sdepth, &pyobj_sqdepth) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_tilted, tilted, ArgInfo("tilted", 1)) &&
        pyopencv_to_safe(pyobj_sdepth, sdepth, ArgInfo("sdepth", 0)) &&
        pyopencv_to_safe(pyobj_sqdepth, sqdepth, ArgInfo("sqdepth", 0)) )
    {
        ERRWRAP2(cv::integral(src, sum, sqsum, tilted, sdepth, sqdepth));
        return Py_BuildValue("(NNN)", pyopencv_from(sum), pyopencv_from(sqsum), pyopencv_from(tilted));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("integral3");

    return NULL;
}

static PyObject* pyopencv_cv_intersectConvexConvex(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_p1 = NULL;
    Mat p1;
    PyObject* pyobj_p2 = NULL;
    Mat p2;
    PyObject* pyobj_p12 = NULL;
    Mat p12;
    PyObject* pyobj_handleNested = NULL;
    bool handleNested=true;
    float retval;

    const char* keywords[] = { "p1", "p2", "p12", "handleNested", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:intersectConvexConvex", (char**)keywords, &pyobj_p1, &pyobj_p2, &pyobj_p12, &pyobj_handleNested) &&
        pyopencv_to_safe(pyobj_p1, p1, ArgInfo("p1", 0)) &&
        pyopencv_to_safe(pyobj_p2, p2, ArgInfo("p2", 0)) &&
        pyopencv_to_safe(pyobj_p12, p12, ArgInfo("p12", 1)) &&
        pyopencv_to_safe(pyobj_handleNested, handleNested, ArgInfo("handleNested", 0)) )
    {
        ERRWRAP2(retval = cv::intersectConvexConvex(p1, p2, p12, handleNested));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(p12));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_p1 = NULL;
    UMat p1;
    PyObject* pyobj_p2 = NULL;
    UMat p2;
    PyObject* pyobj_p12 = NULL;
    UMat p12;
    PyObject* pyobj_handleNested = NULL;
    bool handleNested=true;
    float retval;

    const char* keywords[] = { "p1", "p2", "p12", "handleNested", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:intersectConvexConvex", (char**)keywords, &pyobj_p1, &pyobj_p2, &pyobj_p12, &pyobj_handleNested) &&
        pyopencv_to_safe(pyobj_p1, p1, ArgInfo("p1", 0)) &&
        pyopencv_to_safe(pyobj_p2, p2, ArgInfo("p2", 0)) &&
        pyopencv_to_safe(pyobj_p12, p12, ArgInfo("p12", 1)) &&
        pyopencv_to_safe(pyobj_handleNested, handleNested, ArgInfo("handleNested", 0)) )
    {
        ERRWRAP2(retval = cv::intersectConvexConvex(p1, p2, p12, handleNested));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(p12));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("intersectConvexConvex");

    return NULL;
}

static PyObject* pyopencv_cv_invert(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    double retval;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:invert", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::invert(src, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    double retval;

    const char* keywords[] = { "src", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:invert", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::invert(src, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("invert");

    return NULL;
}

static PyObject* pyopencv_cv_invertAffineTransform(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_iM = NULL;
    Mat iM;

    const char* keywords[] = { "M", "iM", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:invertAffineTransform", (char**)keywords, &pyobj_M, &pyobj_iM) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_iM, iM, ArgInfo("iM", 1)) )
    {
        ERRWRAP2(cv::invertAffineTransform(M, iM));
        return pyopencv_from(iM);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_iM = NULL;
    UMat iM;

    const char* keywords[] = { "M", "iM", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:invertAffineTransform", (char**)keywords, &pyobj_M, &pyobj_iM) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_iM, iM, ArgInfo("iM", 1)) )
    {
        ERRWRAP2(cv::invertAffineTransform(M, iM));
        return pyopencv_from(iM);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("invertAffineTransform");

    return NULL;
}

static PyObject* pyopencv_cv_isContourConvex(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    bool retval;

    const char* keywords[] = { "contour", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:isContourConvex", (char**)keywords, &pyobj_contour) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) )
    {
        ERRWRAP2(retval = cv::isContourConvex(contour));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    bool retval;

    const char* keywords[] = { "contour", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:isContourConvex", (char**)keywords, &pyobj_contour) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) )
    {
        ERRWRAP2(retval = cv::isContourConvex(contour));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("isContourConvex");

    return NULL;
}

static PyObject* pyopencv_cv_kmeans(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_data = NULL;
    Mat data;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_bestLabels = NULL;
    Mat bestLabels;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    PyObject* pyobj_attempts = NULL;
    int attempts=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_centers = NULL;
    Mat centers;
    double retval;

    const char* keywords[] = { "data", "K", "bestLabels", "criteria", "attempts", "flags", "centers", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:kmeans", (char**)keywords, &pyobj_data, &pyobj_K, &pyobj_bestLabels, &pyobj_criteria, &pyobj_attempts, &pyobj_flags, &pyobj_centers) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to_safe(pyobj_bestLabels, bestLabels, ArgInfo("bestLabels", 1)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_attempts, attempts, ArgInfo("attempts", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_centers, centers, ArgInfo("centers", 1)) )
    {
        ERRWRAP2(retval = cv::kmeans(data, K, bestLabels, criteria, attempts, flags, centers));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(bestLabels), pyopencv_from(centers));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_data = NULL;
    UMat data;
    PyObject* pyobj_K = NULL;
    int K=0;
    PyObject* pyobj_bestLabels = NULL;
    UMat bestLabels;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria;
    PyObject* pyobj_attempts = NULL;
    int attempts=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_centers = NULL;
    UMat centers;
    double retval;

    const char* keywords[] = { "data", "K", "bestLabels", "criteria", "attempts", "flags", "centers", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:kmeans", (char**)keywords, &pyobj_data, &pyobj_K, &pyobj_bestLabels, &pyobj_criteria, &pyobj_attempts, &pyobj_flags, &pyobj_centers) &&
        pyopencv_to_safe(pyobj_data, data, ArgInfo("data", 0)) &&
        pyopencv_to_safe(pyobj_K, K, ArgInfo("K", 0)) &&
        pyopencv_to_safe(pyobj_bestLabels, bestLabels, ArgInfo("bestLabels", 1)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_attempts, attempts, ArgInfo("attempts", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_centers, centers, ArgInfo("centers", 1)) )
    {
        ERRWRAP2(retval = cv::kmeans(data, K, bestLabels, criteria, attempts, flags, centers));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(bestLabels), pyopencv_from(centers));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("kmeans");

    return NULL;
}

static PyObject* pyopencv_cv_line(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:line", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::line(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:line", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::line(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("line");

    return NULL;
}

static PyObject* pyopencv_cv_linearPolar(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:linearPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::linearPolar(src, dst, center, maxRadius, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:linearPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::linearPolar(src, dst, center, maxRadius, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("linearPolar");

    return NULL;
}

static PyObject* pyopencv_cv_log(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:log", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::log(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:log", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::log(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("log");

    return NULL;
}

static PyObject* pyopencv_cv_logPolar(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_M = NULL;
    double M=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "M", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:logPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_M, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::logPolar(src, dst, center, M, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_M = NULL;
    double M=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "center", "M", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:logPolar", (char**)keywords, &pyobj_src, &pyobj_center, &pyobj_M, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::logPolar(src, dst, center, M, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("logPolar");

    return NULL;
}

static PyObject* pyopencv_cv_magnitude(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;

    const char* keywords[] = { "x", "y", "magnitude", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) )
    {
        ERRWRAP2(cv::magnitude(x, y, magnitude));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;

    const char* keywords[] = { "x", "y", "magnitude", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) )
    {
        ERRWRAP2(cv::magnitude(x, y, magnitude));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("magnitude");

    return NULL;
}

static PyObject* pyopencv_cv_matchShapes(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_contour1 = NULL;
    Mat contour1;
    PyObject* pyobj_contour2 = NULL;
    Mat contour2;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_parameter = NULL;
    double parameter=0;
    double retval;

    const char* keywords[] = { "contour1", "contour2", "method", "parameter", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:matchShapes", (char**)keywords, &pyobj_contour1, &pyobj_contour2, &pyobj_method, &pyobj_parameter) &&
        pyopencv_to_safe(pyobj_contour1, contour1, ArgInfo("contour1", 0)) &&
        pyopencv_to_safe(pyobj_contour2, contour2, ArgInfo("contour2", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_parameter, parameter, ArgInfo("parameter", 0)) )
    {
        ERRWRAP2(retval = cv::matchShapes(contour1, contour2, method, parameter));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_contour1 = NULL;
    UMat contour1;
    PyObject* pyobj_contour2 = NULL;
    UMat contour2;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_parameter = NULL;
    double parameter=0;
    double retval;

    const char* keywords[] = { "contour1", "contour2", "method", "parameter", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:matchShapes", (char**)keywords, &pyobj_contour1, &pyobj_contour2, &pyobj_method, &pyobj_parameter) &&
        pyopencv_to_safe(pyobj_contour1, contour1, ArgInfo("contour1", 0)) &&
        pyopencv_to_safe(pyobj_contour2, contour2, ArgInfo("contour2", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_parameter, parameter, ArgInfo("parameter", 0)) )
    {
        ERRWRAP2(retval = cv::matchShapes(contour1, contour2, method, parameter));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("matchShapes");

    return NULL;
}

static PyObject* pyopencv_cv_matchTemplate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_templ = NULL;
    Mat templ;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "image", "templ", "method", "result", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:matchTemplate", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_method, &pyobj_result, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::matchTemplate(image, templ, result, method, mask));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_templ = NULL;
    UMat templ;
    PyObject* pyobj_result = NULL;
    UMat result;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "image", "templ", "method", "result", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:matchTemplate", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_method, &pyobj_result, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::matchTemplate(image, templ, result, method, mask));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("matchTemplate");

    return NULL;
}

static PyObject* pyopencv_cv_max(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::max(src1, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::max(src1, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("max");

    return NULL;
}

static PyObject* pyopencv_cv_mean(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:mean", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::mean(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:mean", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::mean(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("mean");

    return NULL;
}

static PyObject* pyopencv_cv_meanStdDev(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_stddev = NULL;
    Mat stddev;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mean", "stddev", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mean, &pyobj_stddev, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_stddev, stddev, ArgInfo("stddev", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_stddev = NULL;
    UMat stddev;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mean", "stddev", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mean, &pyobj_stddev, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 1)) &&
        pyopencv_to_safe(pyobj_stddev, stddev, ArgInfo("stddev", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("meanStdDev");

    return NULL;
}

static PyObject* pyopencv_cv_medianBlur(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;

    const char* keywords[] = { "src", "ksize", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:medianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) )
    {
        ERRWRAP2(cv::medianBlur(src, dst, ksize));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;

    const char* keywords[] = { "src", "ksize", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:medianBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) )
    {
        ERRWRAP2(cv::medianBlur(src, dst, ksize));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("medianBlur");

    return NULL;
}

static PyObject* pyopencv_cv_merge(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_mv = NULL;
    vector_Mat mv;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "mv", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:merge", (char**)keywords, &pyobj_mv, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_mv, mv, ArgInfo("mv", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::merge(mv, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mv = NULL;
    vector_UMat mv;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "mv", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:merge", (char**)keywords, &pyobj_mv, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_mv, mv, ArgInfo("mv", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::merge(mv, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("merge");

    return NULL;
}

static PyObject* pyopencv_cv_min(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::min(src1, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::min(src1, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("min");

    return NULL;
}

static PyObject* pyopencv_cv_minAreaRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:minAreaRect", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::minAreaRect(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    RotatedRect retval;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:minAreaRect", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(retval = cv::minAreaRect(points));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("minAreaRect");

    return NULL;
}

static PyObject* pyopencv_cv_minEnclosingCircle(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    Point2f center;
    float radius;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:minEnclosingCircle", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(cv::minEnclosingCircle(points, center, radius));
        return Py_BuildValue("(NN)", pyopencv_from(center), pyopencv_from(radius));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    Point2f center;
    float radius;

    const char* keywords[] = { "points", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:minEnclosingCircle", (char**)keywords, &pyobj_points) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) )
    {
        ERRWRAP2(cv::minEnclosingCircle(points, center, radius));
        return Py_BuildValue("(NN)", pyopencv_from(center), pyopencv_from(radius));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("minEnclosingCircle");

    return NULL;
}

static PyObject* pyopencv_cv_minEnclosingTriangle(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_points = NULL;
    Mat points;
    PyObject* pyobj_triangle = NULL;
    Mat triangle;
    double retval;

    const char* keywords[] = { "points", "triangle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minEnclosingTriangle", (char**)keywords, &pyobj_points, &pyobj_triangle) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_triangle, triangle, ArgInfo("triangle", 1)) )
    {
        ERRWRAP2(retval = cv::minEnclosingTriangle(points, triangle));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(triangle));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_points = NULL;
    UMat points;
    PyObject* pyobj_triangle = NULL;
    UMat triangle;
    double retval;

    const char* keywords[] = { "points", "triangle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minEnclosingTriangle", (char**)keywords, &pyobj_points, &pyobj_triangle) &&
        pyopencv_to_safe(pyobj_points, points, ArgInfo("points", 0)) &&
        pyopencv_to_safe(pyobj_triangle, triangle, ArgInfo("triangle", 1)) )
    {
        ERRWRAP2(retval = cv::minEnclosingTriangle(points, triangle));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(triangle));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("minEnclosingTriangle");

    return NULL;
}

static PyObject* pyopencv_cv_minMaxLoc(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("minMaxLoc");

    return NULL;
}

static PyObject* pyopencv_cv_mixChannels(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    vector_Mat src;
    PyObject* pyobj_dst = NULL;
    vector_Mat dst;
    PyObject* pyobj_fromTo = NULL;
    vector_int fromTo;

    const char* keywords[] = { "src", "dst", "fromTo", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:mixChannels", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_fromTo) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_fromTo, fromTo, ArgInfo("fromTo", 0)) )
    {
        ERRWRAP2(cv::mixChannels(src, dst, fromTo));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    vector_UMat src;
    PyObject* pyobj_dst = NULL;
    vector_UMat dst;
    PyObject* pyobj_fromTo = NULL;
    vector_int fromTo;

    const char* keywords[] = { "src", "dst", "fromTo", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:mixChannels", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_fromTo) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_fromTo, fromTo, ArgInfo("fromTo", 0)) )
    {
        ERRWRAP2(cv::mixChannels(src, dst, fromTo));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("mixChannels");

    return NULL;
}

static PyObject* pyopencv_cv_moments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_array = NULL;
    Mat array;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    Moments retval;

    const char* keywords[] = { "array", "binaryImage", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:moments", (char**)keywords, &pyobj_array, &pyobj_binaryImage) &&
        pyopencv_to_safe(pyobj_array, array, ArgInfo("array", 0)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) )
    {
        ERRWRAP2(retval = cv::moments(array, binaryImage));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_array = NULL;
    UMat array;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    Moments retval;

    const char* keywords[] = { "array", "binaryImage", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:moments", (char**)keywords, &pyobj_array, &pyobj_binaryImage) &&
        pyopencv_to_safe(pyobj_array, array, ArgInfo("array", 0)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) )
    {
        ERRWRAP2(retval = cv::moments(array, binaryImage));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("moments");

    return NULL;
}

static PyObject* pyopencv_cv_morphologyEx(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_op = NULL;
    int op=0;
    PyObject* pyobj_kernel = NULL;
    Mat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "op", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:morphologyEx", (char**)keywords, &pyobj_src, &pyobj_op, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_op, op, ArgInfo("op", 0)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::morphologyEx(src, dst, op, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_op = NULL;
    int op=0;
    PyObject* pyobj_kernel = NULL;
    UMat kernel;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_iterations = NULL;
    int iterations=1;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue=morphologyDefaultBorderValue();

    const char* keywords[] = { "src", "op", "kernel", "dst", "anchor", "iterations", "borderType", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:morphologyEx", (char**)keywords, &pyobj_src, &pyobj_op, &pyobj_kernel, &pyobj_dst, &pyobj_anchor, &pyobj_iterations, &pyobj_borderType, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_op, op, ArgInfo("op", 0)) &&
        pyopencv_to_safe(pyobj_kernel, kernel, ArgInfo("kernel", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_iterations, iterations, ArgInfo("iterations", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::morphologyEx(src, dst, op, kernel, anchor, iterations, borderType, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("morphologyEx");

    return NULL;
}

static PyObject* pyopencv_cv_mulSpectrums(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_b = NULL;
    Mat b;
    PyObject* pyobj_c = NULL;
    Mat c;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;

    const char* keywords[] = { "a", "b", "flags", "c", "conjB", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:mulSpectrums", (char**)keywords, &pyobj_a, &pyobj_b, &pyobj_flags, &pyobj_c, &pyobj_conjB) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_b, b, ArgInfo("b", 0)) &&
        pyopencv_to_safe(pyobj_c, c, ArgInfo("c", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) )
    {
        ERRWRAP2(cv::mulSpectrums(a, b, c, flags, conjB));
        return pyopencv_from(c);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_b = NULL;
    UMat b;
    PyObject* pyobj_c = NULL;
    UMat c;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;

    const char* keywords[] = { "a", "b", "flags", "c", "conjB", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:mulSpectrums", (char**)keywords, &pyobj_a, &pyobj_b, &pyobj_flags, &pyobj_c, &pyobj_conjB) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_b, b, ArgInfo("b", 0)) &&
        pyopencv_to_safe(pyobj_c, c, ArgInfo("c", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) )
    {
        ERRWRAP2(cv::mulSpectrums(a, b, c, flags, conjB));
        return pyopencv_from(c);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("mulSpectrums");

    return NULL;
}

static PyObject* pyopencv_cv_mulTransposed(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_aTa = NULL;
    bool aTa=0;
    PyObject* pyobj_delta = NULL;
    Mat delta;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "aTa", "dst", "delta", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:mulTransposed", (char**)keywords, &pyobj_src, &pyobj_aTa, &pyobj_dst, &pyobj_delta, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_aTa, aTa, ArgInfo("aTa", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::mulTransposed(src, dst, aTa, delta, scale, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_aTa = NULL;
    bool aTa=0;
    PyObject* pyobj_delta = NULL;
    UMat delta;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "aTa", "dst", "delta", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:mulTransposed", (char**)keywords, &pyobj_src, &pyobj_aTa, &pyobj_dst, &pyobj_delta, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_aTa, aTa, ArgInfo("aTa", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::mulTransposed(src, dst, aTa, delta, scale, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("mulTransposed");

    return NULL;
}

static PyObject* pyopencv_cv_multiply(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::multiply(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::multiply(src1, src2, dst, scale, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("multiply");

    return NULL;
}

static PyObject* pyopencv_cv_norm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, src2, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::norm(src1, src2, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("norm");

    return NULL;
}

static PyObject* pyopencv_cv_normalize(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=NORM_L2;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "dst", "alpha", "beta", "norm_type", "dtype", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:normalize", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::normalize(src, dst, alpha, beta, norm_type, dtype, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=1;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=NORM_L2;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "dst", "alpha", "beta", "norm_type", "dtype", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:normalize", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::normalize(src, dst, alpha, beta, norm_type, dtype, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("normalize");

    return NULL;
}

static PyObject* pyopencv_cv_patchNaNs(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_a = NULL;
    Mat a;
    PyObject* pyobj_val = NULL;
    double val=0;

    const char* keywords[] = { "a", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:patchNaNs", (char**)keywords, &pyobj_a, &pyobj_val) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 1)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(cv::patchNaNs(a, val));
        return pyopencv_from(a);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_a = NULL;
    UMat a;
    PyObject* pyobj_val = NULL;
    double val=0;

    const char* keywords[] = { "a", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:patchNaNs", (char**)keywords, &pyobj_a, &pyobj_val) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 1)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(cv::patchNaNs(a, val));
        return pyopencv_from(a);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("patchNaNs");

    return NULL;
}

static PyObject* pyopencv_cv_perspectiveTransform(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:perspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::perspectiveTransform(src, dst, m));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_m = NULL;
    UMat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:perspectiveTransform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::perspectiveTransform(src, dst, m));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("perspectiveTransform");

    return NULL;
}

static PyObject* pyopencv_cv_phase(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::phase(x, y, angle, angleInDegrees));
        return pyopencv_from(angle);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::phase(x, y, angle, angleInDegrees));
        return pyopencv_from(angle);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("phase");

    return NULL;
}

static PyObject* pyopencv_cv_phaseCorrelate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_window = NULL;
    Mat window;
    double response;
    Point2d retval;

    const char* keywords[] = { "src1", "src2", "window", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:phaseCorrelate", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_window) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_window, window, ArgInfo("window", 0)) )
    {
        ERRWRAP2(retval = cv::phaseCorrelate(src1, src2, window, &response));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(response));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_window = NULL;
    UMat window;
    double response;
    Point2d retval;

    const char* keywords[] = { "src1", "src2", "window", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:phaseCorrelate", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_window) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_window, window, ArgInfo("window", 0)) )
    {
        ERRWRAP2(retval = cv::phaseCorrelate(src1, src2, window, &response));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(response));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("phaseCorrelate");

    return NULL;
}

static PyObject* pyopencv_cv_pointPolygonTest(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    PyObject* pyobj_measureDist = NULL;
    bool measureDist=0;
    double retval;

    const char* keywords[] = { "contour", "pt", "measureDist", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:pointPolygonTest", (char**)keywords, &pyobj_contour, &pyobj_pt, &pyobj_measureDist) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to_safe(pyobj_pt, pt, ArgInfo("pt", 0)) &&
        pyopencv_to_safe(pyobj_measureDist, measureDist, ArgInfo("measureDist", 0)) )
    {
        ERRWRAP2(retval = cv::pointPolygonTest(contour, pt, measureDist));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    PyObject* pyobj_measureDist = NULL;
    bool measureDist=0;
    double retval;

    const char* keywords[] = { "contour", "pt", "measureDist", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:pointPolygonTest", (char**)keywords, &pyobj_contour, &pyobj_pt, &pyobj_measureDist) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 0)) &&
        pyopencv_to_safe(pyobj_pt, pt, ArgInfo("pt", 0)) &&
        pyopencv_to_safe(pyobj_measureDist, measureDist, ArgInfo("measureDist", 0)) )
    {
        ERRWRAP2(retval = cv::pointPolygonTest(contour, pt, measureDist));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pointPolygonTest");

    return NULL;
}

static PyObject* pyopencv_cv_polarToCart(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::polarToCart(magnitude, angle, x, y, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) )
    {
        ERRWRAP2(cv::polarToCart(magnitude, angle, x, y, angleInDegrees));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("polarToCart");

    return NULL;
}

static PyObject* pyopencv_cv_polylines(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pts = NULL;
    vector_Mat pts;
    PyObject* pyobj_isClosed = NULL;
    bool isClosed=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pts", "isClosed", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:polylines", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_isClosed, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to_safe(pyobj_isClosed, isClosed, ArgInfo("isClosed", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::polylines(img, pts, isClosed, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pts = NULL;
    vector_UMat pts;
    PyObject* pyobj_isClosed = NULL;
    bool isClosed=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pts", "isClosed", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:polylines", (char**)keywords, &pyobj_img, &pyobj_pts, &pyobj_isClosed, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pts, pts, ArgInfo("pts", 0)) &&
        pyopencv_to_safe(pyobj_isClosed, isClosed, ArgInfo("isClosed", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::polylines(img, pts, isClosed, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("polylines");

    return NULL;
}

static PyObject* pyopencv_cv_pow(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "power", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::pow(src, power, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "power", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::pow(src, power, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pow");

    return NULL;
}

static PyObject* pyopencv_cv_preCornerDetect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:preCornerDetect", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::preCornerDetect(src, dst, ksize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ksize", "dst", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:preCornerDetect", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::preCornerDetect(src, dst, ksize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("preCornerDetect");

    return NULL;
}

static PyObject* pyopencv_cv_putText(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_org = NULL;
    Point org;
    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_fontScale = NULL;
    double fontScale=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_bottomLeftOrigin = NULL;
    bool bottomLeftOrigin=false;

    const char* keywords[] = { "img", "text", "org", "fontFace", "fontScale", "color", "thickness", "lineType", "bottomLeftOrigin", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OOO:putText", (char**)keywords, &pyobj_img, &pyobj_text, &pyobj_org, &pyobj_fontFace, &pyobj_fontScale, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_bottomLeftOrigin) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to_safe(pyobj_org, org, ArgInfo("org", 0)) &&
        pyopencv_to_safe(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to_safe(pyobj_fontScale, fontScale, ArgInfo("fontScale", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_bottomLeftOrigin, bottomLeftOrigin, ArgInfo("bottomLeftOrigin", 0)) )
    {
        ERRWRAP2(cv::putText(img, text, org, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_text = NULL;
    String text;
    PyObject* pyobj_org = NULL;
    Point org;
    PyObject* pyobj_fontFace = NULL;
    int fontFace=0;
    PyObject* pyobj_fontScale = NULL;
    double fontScale=0;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_bottomLeftOrigin = NULL;
    bool bottomLeftOrigin=false;

    const char* keywords[] = { "img", "text", "org", "fontFace", "fontScale", "color", "thickness", "lineType", "bottomLeftOrigin", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OOO:putText", (char**)keywords, &pyobj_img, &pyobj_text, &pyobj_org, &pyobj_fontFace, &pyobj_fontScale, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_bottomLeftOrigin) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_text, text, ArgInfo("text", 0)) &&
        pyopencv_to_safe(pyobj_org, org, ArgInfo("org", 0)) &&
        pyopencv_to_safe(pyobj_fontFace, fontFace, ArgInfo("fontFace", 0)) &&
        pyopencv_to_safe(pyobj_fontScale, fontScale, ArgInfo("fontScale", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_bottomLeftOrigin, bottomLeftOrigin, ArgInfo("bottomLeftOrigin", 0)) )
    {
        ERRWRAP2(cv::putText(img, text, org, fontFace, fontScale, color, thickness, lineType, bottomLeftOrigin));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("putText");

    return NULL;
}

static PyObject* pyopencv_cv_pyrDown(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrDown(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrDown(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pyrDown");

    return NULL;
}

static PyObject* pyopencv_cv_pyrMeanShiftFiltering(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_sp = NULL;
    double sp=0;
    PyObject* pyobj_sr = NULL;
    double sr=0;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=1;
    PyObject* pyobj_termcrit = NULL;
    TermCriteria termcrit=TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1);

    const char* keywords[] = { "src", "sp", "sr", "dst", "maxLevel", "termcrit", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:pyrMeanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_maxLevel, &pyobj_termcrit) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to_safe(pyobj_termcrit, termcrit, ArgInfo("termcrit", 0)) )
    {
        ERRWRAP2(cv::pyrMeanShiftFiltering(src, dst, sp, sr, maxLevel, termcrit));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_sp = NULL;
    double sp=0;
    PyObject* pyobj_sr = NULL;
    double sr=0;
    PyObject* pyobj_maxLevel = NULL;
    int maxLevel=1;
    PyObject* pyobj_termcrit = NULL;
    TermCriteria termcrit=TermCriteria(TermCriteria::MAX_ITER+TermCriteria::EPS,5,1);

    const char* keywords[] = { "src", "sp", "sr", "dst", "maxLevel", "termcrit", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:pyrMeanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_maxLevel, &pyobj_termcrit) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_maxLevel, maxLevel, ArgInfo("maxLevel", 0)) &&
        pyopencv_to_safe(pyobj_termcrit, termcrit, ArgInfo("termcrit", 0)) )
    {
        ERRWRAP2(cv::pyrMeanShiftFiltering(src, dst, sp, sr, maxLevel, termcrit));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pyrMeanShiftFiltering");

    return NULL;
}

static PyObject* pyopencv_cv_pyrUp(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrUp(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dstsize = NULL;
    Size dstsize;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dst", "dstsize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_dstsize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dstsize, dstsize, ArgInfo("dstsize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::pyrUp(src, dst, dstsize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pyrUp");

    return NULL;
}

static PyObject* pyopencv_cv_randShuffle(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_iterFactor = NULL;
    double iterFactor=1.;

    const char* keywords[] = { "dst", "iterFactor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:randShuffle", (char**)keywords, &pyobj_dst, &pyobj_iterFactor) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_iterFactor, iterFactor, ArgInfo("iterFactor", 0)) )
    {
        ERRWRAP2(cv::randShuffle(dst, iterFactor, 0));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_iterFactor = NULL;
    double iterFactor=1.;

    const char* keywords[] = { "dst", "iterFactor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:randShuffle", (char**)keywords, &pyobj_dst, &pyobj_iterFactor) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_iterFactor, iterFactor, ArgInfo("iterFactor", 0)) )
    {
        ERRWRAP2(cv::randShuffle(dst, iterFactor, 0));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("randShuffle");

    return NULL;
}

static PyObject* pyopencv_cv_randn(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mean = NULL;
    Mat mean;
    PyObject* pyobj_stddev = NULL;
    Mat stddev;

    const char* keywords[] = { "dst", "mean", "stddev", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:randn", (char**)keywords, &pyobj_dst, &pyobj_mean, &pyobj_stddev) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to_safe(pyobj_stddev, stddev, ArgInfo("stddev", 0)) )
    {
        ERRWRAP2(cv::randn(dst, mean, stddev));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mean = NULL;
    UMat mean;
    PyObject* pyobj_stddev = NULL;
    UMat stddev;

    const char* keywords[] = { "dst", "mean", "stddev", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:randn", (char**)keywords, &pyobj_dst, &pyobj_mean, &pyobj_stddev) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mean, mean, ArgInfo("mean", 0)) &&
        pyopencv_to_safe(pyobj_stddev, stddev, ArgInfo("stddev", 0)) )
    {
        ERRWRAP2(cv::randn(dst, mean, stddev));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("randn");

    return NULL;
}

static PyObject* pyopencv_cv_randu(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_low = NULL;
    Mat low;
    PyObject* pyobj_high = NULL;
    Mat high;

    const char* keywords[] = { "dst", "low", "high", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:randu", (char**)keywords, &pyobj_dst, &pyobj_low, &pyobj_high) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_low, low, ArgInfo("low", 0)) &&
        pyopencv_to_safe(pyobj_high, high, ArgInfo("high", 0)) )
    {
        ERRWRAP2(cv::randu(dst, low, high));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_low = NULL;
    UMat low;
    PyObject* pyobj_high = NULL;
    UMat high;

    const char* keywords[] = { "dst", "low", "high", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:randu", (char**)keywords, &pyobj_dst, &pyobj_low, &pyobj_high) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_low, low, ArgInfo("low", 0)) &&
        pyopencv_to_safe(pyobj_high, high, ArgInfo("high", 0)) )
    {
        ERRWRAP2(cv::randu(dst, low, high));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("randu");

    return NULL;
}

static PyObject* pyopencv_cv_rectangle(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_pt1 = NULL;
    Point pt1;
    PyObject* pyobj_pt2 = NULL;
    Point pt2;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "pt1", "pt2", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_pt1, &pyobj_pt2, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_pt1, pt1, ArgInfo("pt1", 0)) &&
        pyopencv_to_safe(pyobj_pt2, pt2, ArgInfo("pt2", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, pt1, pt2, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    Mat img;
    PyObject* pyobj_rec = NULL;
    Rect rec;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "rec", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_rec, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_rec, rec, ArgInfo("rec", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, rec, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img = NULL;
    UMat img;
    PyObject* pyobj_rec = NULL;
    Rect rec;
    PyObject* pyobj_color = NULL;
    Scalar color;
    PyObject* pyobj_thickness = NULL;
    int thickness=1;
    PyObject* pyobj_lineType = NULL;
    int lineType=LINE_8;
    PyObject* pyobj_shift = NULL;
    int shift=0;

    const char* keywords[] = { "img", "rec", "color", "thickness", "lineType", "shift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:rectangle", (char**)keywords, &pyobj_img, &pyobj_rec, &pyobj_color, &pyobj_thickness, &pyobj_lineType, &pyobj_shift) &&
        pyopencv_to_safe(pyobj_img, img, ArgInfo("img", 1)) &&
        pyopencv_to_safe(pyobj_rec, rec, ArgInfo("rec", 0)) &&
        pyopencv_to_safe(pyobj_color, color, ArgInfo("color", 0)) &&
        pyopencv_to_safe(pyobj_thickness, thickness, ArgInfo("thickness", 0)) &&
        pyopencv_to_safe(pyobj_lineType, lineType, ArgInfo("lineType", 0)) &&
        pyopencv_to_safe(pyobj_shift, shift, ArgInfo("shift", 0)) )
    {
        ERRWRAP2(cv::rectangle(img, rec, color, thickness, lineType, shift));
        return pyopencv_from(img);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rectangle");

    return NULL;
}

static PyObject* pyopencv_cv_rectangleIntersectionArea(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_a = NULL;
    Rect2d a;
    PyObject* pyobj_b = NULL;
    Rect2d b;
    double retval;

    const char* keywords[] = { "a", "b", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:rectangleIntersectionArea", (char**)keywords, &pyobj_a, &pyobj_b) &&
        pyopencv_to_safe(pyobj_a, a, ArgInfo("a", 0)) &&
        pyopencv_to_safe(pyobj_b, b, ArgInfo("b", 0)) )
    {
        ERRWRAP2(retval = cv::rectangleIntersectionArea(a, b));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_reduce(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "dim", "rtype", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:reduce", (char**)keywords, &pyobj_src, &pyobj_dim, &pyobj_rtype, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to_safe(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::reduce(src, dst, dim, rtype, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src", "dim", "rtype", "dst", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:reduce", (char**)keywords, &pyobj_src, &pyobj_dim, &pyobj_rtype, &pyobj_dst, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to_safe(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::reduce(src, dst, dim, rtype, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("reduce");

    return NULL;
}

static PyObject* pyopencv_cv_reduceArgMax(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_axis = NULL;
    int axis=0;
    PyObject* pyobj_lastIndex = NULL;
    bool lastIndex=false;

    const char* keywords[] = { "src", "axis", "dst", "lastIndex", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:reduceArgMax", (char**)keywords, &pyobj_src, &pyobj_axis, &pyobj_dst, &pyobj_lastIndex) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_axis, axis, ArgInfo("axis", 0)) &&
        pyopencv_to_safe(pyobj_lastIndex, lastIndex, ArgInfo("lastIndex", 0)) )
    {
        ERRWRAP2(cv::reduceArgMax(src, dst, axis, lastIndex));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_axis = NULL;
    int axis=0;
    PyObject* pyobj_lastIndex = NULL;
    bool lastIndex=false;

    const char* keywords[] = { "src", "axis", "dst", "lastIndex", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:reduceArgMax", (char**)keywords, &pyobj_src, &pyobj_axis, &pyobj_dst, &pyobj_lastIndex) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_axis, axis, ArgInfo("axis", 0)) &&
        pyopencv_to_safe(pyobj_lastIndex, lastIndex, ArgInfo("lastIndex", 0)) )
    {
        ERRWRAP2(cv::reduceArgMax(src, dst, axis, lastIndex));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("reduceArgMax");

    return NULL;
}

static PyObject* pyopencv_cv_reduceArgMin(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_axis = NULL;
    int axis=0;
    PyObject* pyobj_lastIndex = NULL;
    bool lastIndex=false;

    const char* keywords[] = { "src", "axis", "dst", "lastIndex", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:reduceArgMin", (char**)keywords, &pyobj_src, &pyobj_axis, &pyobj_dst, &pyobj_lastIndex) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_axis, axis, ArgInfo("axis", 0)) &&
        pyopencv_to_safe(pyobj_lastIndex, lastIndex, ArgInfo("lastIndex", 0)) )
    {
        ERRWRAP2(cv::reduceArgMin(src, dst, axis, lastIndex));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_axis = NULL;
    int axis=0;
    PyObject* pyobj_lastIndex = NULL;
    bool lastIndex=false;

    const char* keywords[] = { "src", "axis", "dst", "lastIndex", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:reduceArgMin", (char**)keywords, &pyobj_src, &pyobj_axis, &pyobj_dst, &pyobj_lastIndex) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_axis, axis, ArgInfo("axis", 0)) &&
        pyopencv_to_safe(pyobj_lastIndex, lastIndex, ArgInfo("lastIndex", 0)) )
    {
        ERRWRAP2(cv::reduceArgMin(src, dst, axis, lastIndex));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("reduceArgMin");

    return NULL;
}

static PyObject* pyopencv_cv_remap(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_map1 = NULL;
    Mat map1;
    PyObject* pyobj_map2 = NULL;
    Mat map2;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "map1", "map2", "interpolation", "dst", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:remap", (char**)keywords, &pyobj_src, &pyobj_map1, &pyobj_map2, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to_safe(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::remap(src, dst, map1, map2, interpolation, borderMode, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_map1 = NULL;
    UMat map1;
    PyObject* pyobj_map2 = NULL;
    UMat map2;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "map1", "map2", "interpolation", "dst", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:remap", (char**)keywords, &pyobj_src, &pyobj_map1, &pyobj_map2, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_map1, map1, ArgInfo("map1", 0)) &&
        pyopencv_to_safe(pyobj_map2, map2, ArgInfo("map2", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::remap(src, dst, map1, map2, interpolation, borderMode, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("remap");

    return NULL;
}

static PyObject* pyopencv_cv_repeat(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_ny = NULL;
    int ny=0;
    PyObject* pyobj_nx = NULL;
    int nx=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "ny", "nx", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:repeat", (char**)keywords, &pyobj_src, &pyobj_ny, &pyobj_nx, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_ny, ny, ArgInfo("ny", 0)) &&
        pyopencv_to_safe(pyobj_nx, nx, ArgInfo("nx", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::repeat(src, ny, nx, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_ny = NULL;
    int ny=0;
    PyObject* pyobj_nx = NULL;
    int nx=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "ny", "nx", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:repeat", (char**)keywords, &pyobj_src, &pyobj_ny, &pyobj_nx, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_ny, ny, ArgInfo("ny", 0)) &&
        pyopencv_to_safe(pyobj_nx, nx, ArgInfo("nx", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::repeat(src, ny, nx, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("repeat");

    return NULL;
}

static PyObject* pyopencv_cv_resize(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to_safe(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) )
    {
        ERRWRAP2(cv::resize(src, dst, dsize, fx, fy, interpolation));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to_safe(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) )
    {
        ERRWRAP2(cv::resize(src, dst, dsize, fx, fy, interpolation));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("resize");

    return NULL;
}

static PyObject* pyopencv_cv_rotate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_rotateCode = NULL;
    int rotateCode=0;

    const char* keywords[] = { "src", "rotateCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:rotate", (char**)keywords, &pyobj_src, &pyobj_rotateCode, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rotateCode, rotateCode, ArgInfo("rotateCode", 0)) )
    {
        ERRWRAP2(cv::rotate(src, dst, rotateCode));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_rotateCode = NULL;
    int rotateCode=0;

    const char* keywords[] = { "src", "rotateCode", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:rotate", (char**)keywords, &pyobj_src, &pyobj_rotateCode, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rotateCode, rotateCode, ArgInfo("rotateCode", 0)) )
    {
        ERRWRAP2(cv::rotate(src, dst, rotateCode));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rotate");

    return NULL;
}

static PyObject* pyopencv_cv_rotatedRectangleIntersection(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_rect1 = NULL;
    cv::RotatedRect rect1;
    PyObject* pyobj_rect2 = NULL;
    cv::RotatedRect rect2;
    PyObject* pyobj_intersectingRegion = NULL;
    Mat intersectingRegion;
    int retval;

    const char* keywords[] = { "rect1", "rect2", "intersectingRegion", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:rotatedRectangleIntersection", (char**)keywords, &pyobj_rect1, &pyobj_rect2, &pyobj_intersectingRegion) &&
        pyopencv_to_safe(pyobj_rect1, rect1, ArgInfo("rect1", 0)) &&
        pyopencv_to_safe(pyobj_rect2, rect2, ArgInfo("rect2", 0)) &&
        pyopencv_to_safe(pyobj_intersectingRegion, intersectingRegion, ArgInfo("intersectingRegion", 1)) )
    {
        ERRWRAP2(retval = cv::rotatedRectangleIntersection(rect1, rect2, intersectingRegion));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(intersectingRegion));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rect1 = NULL;
    cv::RotatedRect rect1;
    PyObject* pyobj_rect2 = NULL;
    cv::RotatedRect rect2;
    PyObject* pyobj_intersectingRegion = NULL;
    UMat intersectingRegion;
    int retval;

    const char* keywords[] = { "rect1", "rect2", "intersectingRegion", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:rotatedRectangleIntersection", (char**)keywords, &pyobj_rect1, &pyobj_rect2, &pyobj_intersectingRegion) &&
        pyopencv_to_safe(pyobj_rect1, rect1, ArgInfo("rect1", 0)) &&
        pyopencv_to_safe(pyobj_rect2, rect2, ArgInfo("rect2", 0)) &&
        pyopencv_to_safe(pyobj_intersectingRegion, intersectingRegion, ArgInfo("intersectingRegion", 1)) )
    {
        ERRWRAP2(retval = cv::rotatedRectangleIntersection(rect1, rect2, intersectingRegion));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(intersectingRegion));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rotatedRectangleIntersection");

    return NULL;
}

static PyObject* pyopencv_cv_scaleAdd(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src1", "alpha", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:scaleAdd", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::scaleAdd(src1, alpha, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src1", "alpha", "src2", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:scaleAdd", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::scaleAdd(src1, alpha, src2, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("scaleAdd");

    return NULL;
}

static PyObject* pyopencv_cv_sepFilter2D(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernelX = NULL;
    Mat kernelX;
    PyObject* pyobj_kernelY = NULL;
    Mat kernelY;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernelX", "kernelY", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:sepFilter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernelX, &pyobj_kernelY, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_kernelX, kernelX, ArgInfo("kernelX", 0)) &&
        pyopencv_to_safe(pyobj_kernelY, kernelY, ArgInfo("kernelY", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sepFilter2D(src, dst, ddepth, kernelX, kernelY, anchor, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_kernelX = NULL;
    UMat kernelX;
    PyObject* pyobj_kernelY = NULL;
    UMat kernelY;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1,-1);
    PyObject* pyobj_delta = NULL;
    double delta=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "kernelX", "kernelY", "dst", "anchor", "delta", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:sepFilter2D", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_kernelX, &pyobj_kernelY, &pyobj_dst, &pyobj_anchor, &pyobj_delta, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_kernelX, kernelX, ArgInfo("kernelX", 0)) &&
        pyopencv_to_safe(pyobj_kernelY, kernelY, ArgInfo("kernelY", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_delta, delta, ArgInfo("delta", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sepFilter2D(src, dst, ddepth, kernelX, kernelY, anchor, delta, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sepFilter2D");

    return NULL;
}

static PyObject* pyopencv_cv_setIdentity(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    PyObject* pyobj_s = NULL;
    Scalar s=Scalar(1);

    const char* keywords[] = { "mtx", "s", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:setIdentity", (char**)keywords, &pyobj_mtx, &pyobj_s) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 1)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) )
    {
        ERRWRAP2(cv::setIdentity(mtx, s));
        return pyopencv_from(mtx);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    PyObject* pyobj_s = NULL;
    Scalar s=Scalar(1);

    const char* keywords[] = { "mtx", "s", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:setIdentity", (char**)keywords, &pyobj_mtx, &pyobj_s) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 1)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) )
    {
        ERRWRAP2(cv::setIdentity(mtx, s));
        return pyopencv_from(mtx);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("setIdentity");

    return NULL;
}

static PyObject* pyopencv_cv_setLogLevel(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_level = NULL;
    int level=0;
    int retval;

    const char* keywords[] = { "level", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setLogLevel", (char**)keywords, &pyobj_level) &&
        pyopencv_to_safe(pyobj_level, level, ArgInfo("level", 0)) )
    {
        ERRWRAP2(retval = cv::setLogLevel(level));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_setNumThreads(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_nthreads = NULL;
    int nthreads=0;

    const char* keywords[] = { "nthreads", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setNumThreads", (char**)keywords, &pyobj_nthreads) &&
        pyopencv_to_safe(pyobj_nthreads, nthreads, ArgInfo("nthreads", 0)) )
    {
        ERRWRAP2(cv::setNumThreads(nthreads));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setRNGSeed(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_seed = NULL;
    int seed=0;

    const char* keywords[] = { "seed", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setRNGSeed", (char**)keywords, &pyobj_seed) &&
        pyopencv_to_safe(pyobj_seed, seed, ArgInfo("seed", 0)) )
    {
        ERRWRAP2(cv::setRNGSeed(seed));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setUseOpenVX(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setUseOpenVX", (char**)keywords, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::setUseOpenVX(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_setUseOptimized(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_onoff = NULL;
    bool onoff=0;

    const char* keywords[] = { "onoff", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setUseOptimized", (char**)keywords, &pyobj_onoff) &&
        pyopencv_to_safe(pyobj_onoff, onoff, ArgInfo("onoff", 0)) )
    {
        ERRWRAP2(cv::setUseOptimized(onoff));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_solve(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    bool retval;

    const char* keywords[] = { "src1", "src2", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:solve", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solve(src1, src2, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=DECOMP_LU;
    bool retval;

    const char* keywords[] = { "src1", "src2", "dst", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:solve", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::solve(src1, src2, dst, flags));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("solve");

    return NULL;
}

static PyObject* pyopencv_cv_solveCubic(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_coeffs = NULL;
    Mat coeffs;
    PyObject* pyobj_roots = NULL;
    Mat roots;
    int retval;

    const char* keywords[] = { "coeffs", "roots", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:solveCubic", (char**)keywords, &pyobj_coeffs, &pyobj_roots) &&
        pyopencv_to_safe(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to_safe(pyobj_roots, roots, ArgInfo("roots", 1)) )
    {
        ERRWRAP2(retval = cv::solveCubic(coeffs, roots));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_coeffs = NULL;
    UMat coeffs;
    PyObject* pyobj_roots = NULL;
    UMat roots;
    int retval;

    const char* keywords[] = { "coeffs", "roots", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:solveCubic", (char**)keywords, &pyobj_coeffs, &pyobj_roots) &&
        pyopencv_to_safe(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to_safe(pyobj_roots, roots, ArgInfo("roots", 1)) )
    {
        ERRWRAP2(retval = cv::solveCubic(coeffs, roots));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("solveCubic");

    return NULL;
}

static PyObject* pyopencv_cv_solveLP(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_Func = NULL;
    Mat Func;
    PyObject* pyobj_Constr = NULL;
    Mat Constr;
    PyObject* pyobj_z = NULL;
    Mat z;
    PyObject* pyobj_constr_eps = NULL;
    double constr_eps=0;
    int retval;

    const char* keywords[] = { "Func", "Constr", "constr_eps", "z", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:solveLP", (char**)keywords, &pyobj_Func, &pyobj_Constr, &pyobj_constr_eps, &pyobj_z) &&
        pyopencv_to_safe(pyobj_Func, Func, ArgInfo("Func", 0)) &&
        pyopencv_to_safe(pyobj_Constr, Constr, ArgInfo("Constr", 0)) &&
        pyopencv_to_safe(pyobj_z, z, ArgInfo("z", 1)) &&
        pyopencv_to_safe(pyobj_constr_eps, constr_eps, ArgInfo("constr_eps", 0)) )
    {
        ERRWRAP2(retval = cv::solveLP(Func, Constr, z, constr_eps));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(z));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_Func = NULL;
    UMat Func;
    PyObject* pyobj_Constr = NULL;
    UMat Constr;
    PyObject* pyobj_z = NULL;
    UMat z;
    PyObject* pyobj_constr_eps = NULL;
    double constr_eps=0;
    int retval;

    const char* keywords[] = { "Func", "Constr", "constr_eps", "z", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:solveLP", (char**)keywords, &pyobj_Func, &pyobj_Constr, &pyobj_constr_eps, &pyobj_z) &&
        pyopencv_to_safe(pyobj_Func, Func, ArgInfo("Func", 0)) &&
        pyopencv_to_safe(pyobj_Constr, Constr, ArgInfo("Constr", 0)) &&
        pyopencv_to_safe(pyobj_z, z, ArgInfo("z", 1)) &&
        pyopencv_to_safe(pyobj_constr_eps, constr_eps, ArgInfo("constr_eps", 0)) )
    {
        ERRWRAP2(retval = cv::solveLP(Func, Constr, z, constr_eps));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(z));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_Func = NULL;
    Mat Func;
    PyObject* pyobj_Constr = NULL;
    Mat Constr;
    PyObject* pyobj_z = NULL;
    Mat z;
    int retval;

    const char* keywords[] = { "Func", "Constr", "z", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:solveLP", (char**)keywords, &pyobj_Func, &pyobj_Constr, &pyobj_z) &&
        pyopencv_to_safe(pyobj_Func, Func, ArgInfo("Func", 0)) &&
        pyopencv_to_safe(pyobj_Constr, Constr, ArgInfo("Constr", 0)) &&
        pyopencv_to_safe(pyobj_z, z, ArgInfo("z", 1)) )
    {
        ERRWRAP2(retval = cv::solveLP(Func, Constr, z));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(z));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_Func = NULL;
    UMat Func;
    PyObject* pyobj_Constr = NULL;
    UMat Constr;
    PyObject* pyobj_z = NULL;
    UMat z;
    int retval;

    const char* keywords[] = { "Func", "Constr", "z", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:solveLP", (char**)keywords, &pyobj_Func, &pyobj_Constr, &pyobj_z) &&
        pyopencv_to_safe(pyobj_Func, Func, ArgInfo("Func", 0)) &&
        pyopencv_to_safe(pyobj_Constr, Constr, ArgInfo("Constr", 0)) &&
        pyopencv_to_safe(pyobj_z, z, ArgInfo("z", 1)) )
    {
        ERRWRAP2(retval = cv::solveLP(Func, Constr, z));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(z));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("solveLP");

    return NULL;
}

static PyObject* pyopencv_cv_solvePoly(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_coeffs = NULL;
    Mat coeffs;
    PyObject* pyobj_roots = NULL;
    Mat roots;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=300;
    double retval;

    const char* keywords[] = { "coeffs", "roots", "maxIters", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:solvePoly", (char**)keywords, &pyobj_coeffs, &pyobj_roots, &pyobj_maxIters) &&
        pyopencv_to_safe(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to_safe(pyobj_roots, roots, ArgInfo("roots", 1)) &&
        pyopencv_to_safe(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) )
    {
        ERRWRAP2(retval = cv::solvePoly(coeffs, roots, maxIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_coeffs = NULL;
    UMat coeffs;
    PyObject* pyobj_roots = NULL;
    UMat roots;
    PyObject* pyobj_maxIters = NULL;
    int maxIters=300;
    double retval;

    const char* keywords[] = { "coeffs", "roots", "maxIters", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:solvePoly", (char**)keywords, &pyobj_coeffs, &pyobj_roots, &pyobj_maxIters) &&
        pyopencv_to_safe(pyobj_coeffs, coeffs, ArgInfo("coeffs", 0)) &&
        pyopencv_to_safe(pyobj_roots, roots, ArgInfo("roots", 1)) &&
        pyopencv_to_safe(pyobj_maxIters, maxIters, ArgInfo("maxIters", 0)) )
    {
        ERRWRAP2(retval = cv::solvePoly(coeffs, roots, maxIters));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(roots));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("solvePoly");

    return NULL;
}

static PyObject* pyopencv_cv_sort(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:sort", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sort(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:sort", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sort(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sort");

    return NULL;
}

static PyObject* pyopencv_cv_sortIdx(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:sortIdx", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sortIdx(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:sortIdx", (char**)keywords, &pyobj_src, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::sortIdx(src, dst, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sortIdx");

    return NULL;
}

static PyObject* pyopencv_cv_spatialGradient(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dx = NULL;
    Mat dx;
    PyObject* pyobj_dy = NULL;
    Mat dy;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dx", "dy", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:spatialGradient", (char**)keywords, &pyobj_src, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 1)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::spatialGradient(src, dx, dy, ksize, borderType));
        return Py_BuildValue("(NN)", pyopencv_from(dx), pyopencv_from(dy));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dx = NULL;
    UMat dx;
    PyObject* pyobj_dy = NULL;
    UMat dy;
    PyObject* pyobj_ksize = NULL;
    int ksize=3;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "dx", "dy", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:spatialGradient", (char**)keywords, &pyobj_src, &pyobj_dx, &pyobj_dy, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 1)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::spatialGradient(src, dx, dy, ksize, borderType));
        return Py_BuildValue("(NN)", pyopencv_from(dx), pyopencv_from(dy));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("spatialGradient");

    return NULL;
}

static PyObject* pyopencv_cv_split(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_m = NULL;
    Mat m;
    PyObject* pyobj_mv = NULL;
    vector_Mat mv;

    const char* keywords[] = { "m", "mv", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:split", (char**)keywords, &pyobj_m, &pyobj_mv) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_mv, mv, ArgInfo("mv", 1)) )
    {
        ERRWRAP2(cv::split(m, mv));
        return pyopencv_from(mv);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_mv = NULL;
    vector_UMat mv;

    const char* keywords[] = { "m", "mv", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:split", (char**)keywords, &pyobj_m, &pyobj_mv) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_mv, mv, ArgInfo("mv", 1)) )
    {
        ERRWRAP2(cv::split(m, mv));
        return pyopencv_from(mv);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("split");

    return NULL;
}

static PyObject* pyopencv_cv_sqrBoxFilter(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1, -1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:sqrBoxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sqrBoxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ddepth = NULL;
    int ddepth=0;
    PyObject* pyobj_ksize = NULL;
    Size ksize;
    PyObject* pyobj_anchor = NULL;
    Point anchor=Point(-1, -1);
    PyObject* pyobj_normalize = NULL;
    bool normalize=true;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_DEFAULT;

    const char* keywords[] = { "src", "ddepth", "ksize", "dst", "anchor", "normalize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:sqrBoxFilter", (char**)keywords, &pyobj_src, &pyobj_ddepth, &pyobj_ksize, &pyobj_dst, &pyobj_anchor, &pyobj_normalize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ddepth, ddepth, ArgInfo("ddepth", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_anchor, anchor, ArgInfo("anchor", 0)) &&
        pyopencv_to_safe(pyobj_normalize, normalize, ArgInfo("normalize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(cv::sqrBoxFilter(src, dst, ddepth, ksize, anchor, normalize, borderType));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sqrBoxFilter");

    return NULL;
}

static PyObject* pyopencv_cv_sqrt(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::sqrt(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::sqrt(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sqrt");

    return NULL;
}

static PyObject* pyopencv_cv_stackBlur(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;

    const char* keywords[] = { "src", "ksize", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:stackBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) )
    {
        ERRWRAP2(cv::stackBlur(src, dst, ksize));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_ksize = NULL;
    Size ksize;

    const char* keywords[] = { "src", "ksize", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:stackBlur", (char**)keywords, &pyobj_src, &pyobj_ksize, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) )
    {
        ERRWRAP2(cv::stackBlur(src, dst, ksize));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("stackBlur");

    return NULL;
}

static PyObject* pyopencv_cv_subtract(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 2)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::subtract(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 2)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 2)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 2)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) )
    {
        ERRWRAP2(cv::subtract(src1, src2, dst, mask, dtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("subtract");

    return NULL;
}

static PyObject* pyopencv_cv_sumElems(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    Scalar retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:sumElems", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::sum(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    Scalar retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:sumElems", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::sum(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sumElems");

    return NULL;
}

static PyObject* pyopencv_cv_threshold(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to_safe(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::threshold(src, dst, thresh, maxval, type));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to_safe(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = cv::threshold(src, dst, thresh, maxval, type));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("threshold");

    return NULL;
}

static PyObject* pyopencv_cv_trace(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    Scalar retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:trace", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::trace(mtx));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    Scalar retval;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:trace", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(retval = cv::trace(mtx));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("trace");

    return NULL;
}

static PyObject* pyopencv_cv_transform(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:transform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::transform(src, dst, m));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_m = NULL;
    UMat m;

    const char* keywords[] = { "src", "m", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:transform", (char**)keywords, &pyobj_src, &pyobj_m, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::transform(src, dst, m));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("transform");

    return NULL;
}

static PyObject* pyopencv_cv_transpose(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:transpose", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::transpose(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:transpose", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::transpose(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("transpose");

    return NULL;
}

static PyObject* pyopencv_cv_transposeND(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_order = NULL;
    vector_int order;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "order", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:transposeND", (char**)keywords, &pyobj_src, &pyobj_order, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::transposeND(src, order, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_order = NULL;
    vector_int order;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "order", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:transposeND", (char**)keywords, &pyobj_src, &pyobj_order, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::transposeND(src, order, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("transposeND");

    return NULL;
}

static PyObject* pyopencv_cv_useOpenVX(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::useOpenVX());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_useOptimized(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::useOptimized());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_vconcat(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    vector_Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:vconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::vconcat(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    vector_UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:vconcat", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(cv::vconcat(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("vconcat");

    return NULL;
}

static PyObject* pyopencv_cv_warpAffine(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("warpAffine");

    return NULL;
}

static PyObject* pyopencv_cv_warpPerspective(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) )
    {
        ERRWRAP2(cv::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("warpPerspective");

    return NULL;
}

static PyObject* pyopencv_cv_warpPolar(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dsize", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:warpPolar", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::warpPolar(src, dst, dsize, center, maxRadius, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_maxRadius = NULL;
    double maxRadius=0;
    PyObject* pyobj_flags = NULL;
    int flags=0;

    const char* keywords[] = { "src", "dsize", "center", "maxRadius", "flags", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:warpPolar", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_center, &pyobj_maxRadius, &pyobj_flags, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(cv::warpPolar(src, dst, dsize, center, maxRadius, flags));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("warpPolar");

    return NULL;
}

static PyObject* pyopencv_cv_watershed(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_markers = NULL;
    Mat markers;

    const char* keywords[] = { "image", "markers", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:watershed", (char**)keywords, &pyobj_image, &pyobj_markers) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_markers, markers, ArgInfo("markers", 1)) )
    {
        ERRWRAP2(cv::watershed(image, markers));
        return pyopencv_from(markers);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_markers = NULL;
    UMat markers;

    const char* keywords[] = { "image", "markers", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:watershed", (char**)keywords, &pyobj_image, &pyobj_markers) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_markers, markers, ArgInfo("markers", 1)) )
    {
        ERRWRAP2(cv::watershed(image, markers));
        return pyopencv_from(markers);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("watershed");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_Event_elapsedTime(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_start = NULL;
    Event start;
    PyObject* pyobj_end = NULL;
    Event end;
    float retval;

    const char* keywords[] = { "start", "end", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:Event_elapsedTime", (char**)keywords, &pyobj_start, &pyobj_end) &&
        pyopencv_to_safe(pyobj_start, start, ArgInfo("start", 0)) &&
        pyopencv_to_safe(pyobj_end, end, ArgInfo("end", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::Event::elapsedTime(start, end));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_GpuMat_defaultAllocator(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    GpuMat::Allocator* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::GpuMat::defaultAllocator());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_GpuMat_setDefaultAllocator(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator;

    const char* keywords[] = { "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GpuMat_setDefaultAllocator", (char**)keywords, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        ERRWRAP2(cv::cuda::GpuMat::setDefaultAllocator(allocator));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_Stream_Null(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    Stream retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::Stream::Null());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_has(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_has", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::has(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasBin(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_hasBin", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasBin(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrGreater(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_hasEqualOrGreater", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreater(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrGreaterBin(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_hasEqualOrGreaterBin", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreaterBin(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrGreaterPtx(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_hasEqualOrGreaterPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreaterPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasEqualOrLessPtx(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_hasEqualOrLessPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrLessPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_TargetArchs_hasPtx(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:TargetArchs_hasPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_abs(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:abs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::abs(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:abs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::abs(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:abs", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::abs(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("abs");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_absSum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:absSum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::absSum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:absSum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::absSum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:absSum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::absSum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("absSum");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_absdiff(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::absdiff(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::absdiff(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:absdiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::absdiff(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("absdiff");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_add(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::add(src1, src2, dst, mask, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::add(src1, src2, dst, mask, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:add", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::add(src1, src2, dst, mask, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("add");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_addWeighted(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_gamma = NULL;
    double gamma=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "alpha", "src2", "beta", "gamma", "dst", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:addWeighted", (char**)keywords, &pyobj_src1, &pyobj_alpha, &pyobj_src2, &pyobj_beta, &pyobj_gamma, &pyobj_dst, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_gamma, gamma, ArgInfo("gamma", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::addWeighted(src1, alpha, src2, beta, gamma, dst, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("addWeighted");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_alphaComp(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_img1 = NULL;
    Mat img1;
    PyObject* pyobj_img2 = NULL;
    Mat img2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha_op = NULL;
    int alpha_op=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "img1", "img2", "alpha_op", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:alphaComp", (char**)keywords, &pyobj_img1, &pyobj_img2, &pyobj_alpha_op, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to_safe(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha_op, alpha_op, ArgInfo("alpha_op", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::alphaComp(img1, img2, dst, alpha_op, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img1 = NULL;
    cuda::GpuMat img1;
    PyObject* pyobj_img2 = NULL;
    cuda::GpuMat img2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_alpha_op = NULL;
    int alpha_op=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "img1", "img2", "alpha_op", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:alphaComp", (char**)keywords, &pyobj_img1, &pyobj_img2, &pyobj_alpha_op, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to_safe(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha_op, alpha_op, ArgInfo("alpha_op", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::alphaComp(img1, img2, dst, alpha_op, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img1 = NULL;
    UMat img1;
    PyObject* pyobj_img2 = NULL;
    UMat img2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha_op = NULL;
    int alpha_op=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "img1", "img2", "alpha_op", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:alphaComp", (char**)keywords, &pyobj_img1, &pyobj_img2, &pyobj_alpha_op, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to_safe(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha_op, alpha_op, ArgInfo("alpha_op", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::alphaComp(img1, img2, dst, alpha_op, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("alphaComp");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_bilateralFilter(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_kernel_size = NULL;
    int kernel_size=0;
    PyObject* pyobj_sigma_color = NULL;
    float sigma_color=0.f;
    PyObject* pyobj_sigma_spatial = NULL;
    float sigma_spatial=0.f;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_DEFAULT;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "kernel_size", "sigma_color", "sigma_spatial", "dst", "borderMode", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_kernel_size, &pyobj_sigma_color, &pyobj_sigma_spatial, &pyobj_dst, &pyobj_borderMode, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel_size, kernel_size, ArgInfo("kernel_size", 0)) &&
        pyopencv_to_safe(pyobj_sigma_color, sigma_color, ArgInfo("sigma_color", 0)) &&
        pyopencv_to_safe(pyobj_sigma_spatial, sigma_spatial, ArgInfo("sigma_spatial", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bilateralFilter(src, dst, kernel_size, sigma_color, sigma_spatial, borderMode, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_kernel_size = NULL;
    int kernel_size=0;
    PyObject* pyobj_sigma_color = NULL;
    float sigma_color=0.f;
    PyObject* pyobj_sigma_spatial = NULL;
    float sigma_spatial=0.f;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_DEFAULT;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "kernel_size", "sigma_color", "sigma_spatial", "dst", "borderMode", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_kernel_size, &pyobj_sigma_color, &pyobj_sigma_spatial, &pyobj_dst, &pyobj_borderMode, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel_size, kernel_size, ArgInfo("kernel_size", 0)) &&
        pyopencv_to_safe(pyobj_sigma_color, sigma_color, ArgInfo("sigma_color", 0)) &&
        pyopencv_to_safe(pyobj_sigma_spatial, sigma_spatial, ArgInfo("sigma_spatial", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bilateralFilter(src, dst, kernel_size, sigma_color, sigma_spatial, borderMode, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_kernel_size = NULL;
    int kernel_size=0;
    PyObject* pyobj_sigma_color = NULL;
    float sigma_color=0.f;
    PyObject* pyobj_sigma_spatial = NULL;
    float sigma_spatial=0.f;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_DEFAULT;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "kernel_size", "sigma_color", "sigma_spatial", "dst", "borderMode", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:bilateralFilter", (char**)keywords, &pyobj_src, &pyobj_kernel_size, &pyobj_sigma_color, &pyobj_sigma_spatial, &pyobj_dst, &pyobj_borderMode, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_kernel_size, kernel_size, ArgInfo("kernel_size", 0)) &&
        pyopencv_to_safe(pyobj_sigma_color, sigma_color, ArgInfo("sigma_color", 0)) &&
        pyopencv_to_safe(pyobj_sigma_spatial, sigma_spatial, ArgInfo("sigma_spatial", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bilateralFilter(src, dst, kernel_size, sigma_color, sigma_spatial, borderMode, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bilateralFilter");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_bitwise_and(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_and(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_and(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_and", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_and(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_and");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_bitwise_not(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_not(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_not(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:bitwise_not", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_not(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_not");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_bitwise_or(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_or(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_or(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_or", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_or(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_or");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_bitwise_xor(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_xor(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_xor(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:bitwise_xor", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::bitwise_xor(src1, src2, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("bitwise_xor");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_blendLinear(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_img1 = NULL;
    Mat img1;
    PyObject* pyobj_img2 = NULL;
    Mat img2;
    PyObject* pyobj_weights1 = NULL;
    Mat weights1;
    PyObject* pyobj_weights2 = NULL;
    Mat weights2;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "img1", "img2", "weights1", "weights2", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:blendLinear", (char**)keywords, &pyobj_img1, &pyobj_img2, &pyobj_weights1, &pyobj_weights2, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to_safe(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to_safe(pyobj_weights1, weights1, ArgInfo("weights1", 0)) &&
        pyopencv_to_safe(pyobj_weights2, weights2, ArgInfo("weights2", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::blendLinear(img1, img2, weights1, weights2, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img1 = NULL;
    cuda::GpuMat img1;
    PyObject* pyobj_img2 = NULL;
    cuda::GpuMat img2;
    PyObject* pyobj_weights1 = NULL;
    cuda::GpuMat weights1;
    PyObject* pyobj_weights2 = NULL;
    cuda::GpuMat weights2;
    PyObject* pyobj_result = NULL;
    cuda::GpuMat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "img1", "img2", "weights1", "weights2", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:blendLinear", (char**)keywords, &pyobj_img1, &pyobj_img2, &pyobj_weights1, &pyobj_weights2, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to_safe(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to_safe(pyobj_weights1, weights1, ArgInfo("weights1", 0)) &&
        pyopencv_to_safe(pyobj_weights2, weights2, ArgInfo("weights2", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::blendLinear(img1, img2, weights1, weights2, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_img1 = NULL;
    UMat img1;
    PyObject* pyobj_img2 = NULL;
    UMat img2;
    PyObject* pyobj_weights1 = NULL;
    UMat weights1;
    PyObject* pyobj_weights2 = NULL;
    UMat weights2;
    PyObject* pyobj_result = NULL;
    UMat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "img1", "img2", "weights1", "weights2", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:blendLinear", (char**)keywords, &pyobj_img1, &pyobj_img2, &pyobj_weights1, &pyobj_weights2, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_img1, img1, ArgInfo("img1", 0)) &&
        pyopencv_to_safe(pyobj_img2, img2, ArgInfo("img2", 0)) &&
        pyopencv_to_safe(pyobj_weights1, weights1, ArgInfo("weights1", 0)) &&
        pyopencv_to_safe(pyobj_weights2, weights2, ArgInfo("weights2", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::blendLinear(img1, img2, weights1, weights2, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("blendLinear");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_buildWarpAffineMaps(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_inverse = NULL;
    bool inverse=0;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_xmap = NULL;
    GpuMat xmap;
    PyObject* pyobj_ymap = NULL;
    GpuMat ymap;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "M", "inverse", "dsize", "xmap", "ymap", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:buildWarpAffineMaps", (char**)keywords, &pyobj_M, &pyobj_inverse, &pyobj_dsize, &pyobj_xmap, &pyobj_ymap, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_inverse, inverse, ArgInfo("inverse", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 1)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::buildWarpAffineMaps(M, inverse, dsize, xmap, ymap, stream));
        return Py_BuildValue("(NN)", pyopencv_from(xmap), pyopencv_from(ymap));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_inverse = NULL;
    bool inverse=0;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_xmap = NULL;
    GpuMat xmap;
    PyObject* pyobj_ymap = NULL;
    GpuMat ymap;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "M", "inverse", "dsize", "xmap", "ymap", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:buildWarpAffineMaps", (char**)keywords, &pyobj_M, &pyobj_inverse, &pyobj_dsize, &pyobj_xmap, &pyobj_ymap, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_inverse, inverse, ArgInfo("inverse", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 1)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::buildWarpAffineMaps(M, inverse, dsize, xmap, ymap, stream));
        return Py_BuildValue("(NN)", pyopencv_from(xmap), pyopencv_from(ymap));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("buildWarpAffineMaps");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_buildWarpPerspectiveMaps(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_inverse = NULL;
    bool inverse=0;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_xmap = NULL;
    GpuMat xmap;
    PyObject* pyobj_ymap = NULL;
    GpuMat ymap;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "M", "inverse", "dsize", "xmap", "ymap", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:buildWarpPerspectiveMaps", (char**)keywords, &pyobj_M, &pyobj_inverse, &pyobj_dsize, &pyobj_xmap, &pyobj_ymap, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_inverse, inverse, ArgInfo("inverse", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 1)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::buildWarpPerspectiveMaps(M, inverse, dsize, xmap, ymap, stream));
        return Py_BuildValue("(NN)", pyopencv_from(xmap), pyopencv_from(ymap));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_inverse = NULL;
    bool inverse=0;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_xmap = NULL;
    GpuMat xmap;
    PyObject* pyobj_ymap = NULL;
    GpuMat ymap;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "M", "inverse", "dsize", "xmap", "ymap", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:buildWarpPerspectiveMaps", (char**)keywords, &pyobj_M, &pyobj_inverse, &pyobj_dsize, &pyobj_xmap, &pyobj_ymap, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_inverse, inverse, ArgInfo("inverse", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 1)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::buildWarpPerspectiveMaps(M, inverse, dsize, xmap, ymap, stream));
        return Py_BuildValue("(NN)", pyopencv_from(xmap), pyopencv_from(ymap));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("buildWarpPerspectiveMaps");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_calcAbsSum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcAbsSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcAbsSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcAbsSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcAbsSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcAbsSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcAbsSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcAbsSum");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_calcHist(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:calcHist", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcHist(src, hist, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_hist = NULL;
    cuda::GpuMat hist;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:calcHist", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcHist(src, hist, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:calcHist", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcHist(src, hist, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "mask", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:calcHist", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcHist(src, mask, hist, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_hist = NULL;
    cuda::GpuMat hist;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "mask", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:calcHist", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcHist(src, mask, hist, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "mask", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:calcHist", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcHist(src, mask, hist, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcHist");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_calcNorm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_normType = NULL;
    int normType=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "normType", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:calcNorm", (char**)keywords, &pyobj_src, &pyobj_normType, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcNorm(src, dst, normType, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_normType = NULL;
    int normType=0;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "normType", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:calcNorm", (char**)keywords, &pyobj_src, &pyobj_normType, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcNorm(src, dst, normType, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_normType = NULL;
    int normType=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "normType", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:calcNorm", (char**)keywords, &pyobj_src, &pyobj_normType, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcNorm(src, dst, normType, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcNorm");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_calcNormDiff(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "normType", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:calcNormDiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_normType, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcNormDiff(src1, src2, dst, normType, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "normType", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:calcNormDiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_normType, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcNormDiff(src1, src2, dst, normType, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "normType", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:calcNormDiff", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_normType, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcNormDiff(src1, src2, dst, normType, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcNormDiff");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_calcSqrSum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcSqrSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcSqrSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcSqrSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcSqrSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcSqrSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcSqrSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcSqrSum");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_calcSum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:calcSum", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::calcSum(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("calcSum");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cartToPolar(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::cartToPolar(x, y, magnitude, angle, angleInDegrees, stream));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    cuda::GpuMat x;
    PyObject* pyobj_y = NULL;
    cuda::GpuMat y;
    PyObject* pyobj_magnitude = NULL;
    cuda::GpuMat magnitude;
    PyObject* pyobj_angle = NULL;
    cuda::GpuMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::cartToPolar(x, y, magnitude, angle, angleInDegrees, stream));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "angle", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:cartToPolar", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_angle, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::cartToPolar(x, y, magnitude, angle, angleInDegrees, stream));
        return Py_BuildValue("(NN)", pyopencv_from(magnitude), pyopencv_from(angle));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cartToPolar");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_compare(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::compare(src1, src2, dst, cmpop, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::compare(src1, src2, dst, cmpop, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_cmpop = NULL;
    int cmpop=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "cmpop", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:compare", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_cmpop, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_cmpop, cmpop, ArgInfo("cmpop", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::compare(src1, src2, dst, cmpop, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("compare");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_connectedComponents(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(cv::cuda::connectedComponents(image, labels, connectivity, ltype));
        return pyopencv_from(labels);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_labels = NULL;
    cuda::GpuMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(cv::cuda::connectedComponents(image, labels, connectivity, ltype));
        return pyopencv_from(labels);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=8;
    PyObject* pyobj_ltype = NULL;
    int ltype=CV_32S;

    const char* keywords[] = { "image", "labels", "connectivity", "ltype", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:connectedComponents", (char**)keywords, &pyobj_image, &pyobj_labels, &pyobj_connectivity, &pyobj_ltype) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) )
    {
        ERRWRAP2(cv::cuda::connectedComponents(image, labels, connectivity, ltype));
        return pyopencv_from(labels);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("connectedComponents");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_connectedComponentsWithAlgorithm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_labels = NULL;
    Mat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    cuda_ConnectedComponentsAlgorithmsTypes ccltype=static_cast<cuda_ConnectedComponentsAlgorithmsTypes>(0);

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(cv::cuda::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return pyopencv_from(labels);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_labels = NULL;
    cuda::GpuMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    cuda_ConnectedComponentsAlgorithmsTypes ccltype=static_cast<cuda_ConnectedComponentsAlgorithmsTypes>(0);

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(cv::cuda::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return pyopencv_from(labels);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_labels = NULL;
    UMat labels;
    PyObject* pyobj_connectivity = NULL;
    int connectivity=0;
    PyObject* pyobj_ltype = NULL;
    int ltype=0;
    PyObject* pyobj_ccltype = NULL;
    cuda_ConnectedComponentsAlgorithmsTypes ccltype=static_cast<cuda_ConnectedComponentsAlgorithmsTypes>(0);

    const char* keywords[] = { "image", "connectivity", "ltype", "ccltype", "labels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:connectedComponentsWithAlgorithm", (char**)keywords, &pyobj_image, &pyobj_connectivity, &pyobj_ltype, &pyobj_ccltype, &pyobj_labels) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_labels, labels, ArgInfo("labels", 1)) &&
        pyopencv_to_safe(pyobj_connectivity, connectivity, ArgInfo("connectivity", 0)) &&
        pyopencv_to_safe(pyobj_ltype, ltype, ArgInfo("ltype", 0)) &&
        pyopencv_to_safe(pyobj_ccltype, ccltype, ArgInfo("ccltype", 0)) )
    {
        ERRWRAP2(cv::cuda::connectedComponents(image, labels, connectivity, ltype, ccltype));
        return pyopencv_from(labels);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("connectedComponentsWithAlgorithm");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_convertSpatialMoments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_spatialMoments = NULL;
    Mat spatialMoments;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=static_cast<MomentsOrder>(0);
    PyObject* pyobj_momentsType = NULL;
    int momentsType=0;
    Moments retval;

    const char* keywords[] = { "spatialMoments", "order", "momentsType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:convertSpatialMoments", (char**)keywords, &pyobj_spatialMoments, &pyobj_order, &pyobj_momentsType) &&
        pyopencv_to_safe(pyobj_spatialMoments, spatialMoments, ArgInfo("spatialMoments", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::convertSpatialMoments(spatialMoments, order, momentsType));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_copyMakeBorder(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OOO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to_safe(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to_safe(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to_safe(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OOO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to_safe(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to_safe(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to_safe(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_top = NULL;
    int top=0;
    PyObject* pyobj_bottom = NULL;
    int bottom=0;
    PyObject* pyobj_left = NULL;
    int left=0;
    PyObject* pyobj_right = NULL;
    int right=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=0;
    PyObject* pyobj_value = NULL;
    Scalar value;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "top", "bottom", "left", "right", "borderType", "dst", "value", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|OOO:copyMakeBorder", (char**)keywords, &pyobj_src, &pyobj_top, &pyobj_bottom, &pyobj_left, &pyobj_right, &pyobj_borderType, &pyobj_dst, &pyobj_value, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_top, top, ArgInfo("top", 0)) &&
        pyopencv_to_safe(pyobj_bottom, bottom, ArgInfo("bottom", 0)) &&
        pyopencv_to_safe(pyobj_left, left, ArgInfo("left", 0)) &&
        pyopencv_to_safe(pyobj_right, right, ArgInfo("right", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("copyMakeBorder");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_countNonZero(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::countNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::countNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    int retval;

    const char* keywords[] = { "src", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:countNonZero", (char**)keywords, &pyobj_src) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::countNonZero(src));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:countNonZero", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::countNonZero(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:countNonZero", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::countNonZero(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:countNonZero", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::countNonZero(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("countNonZero");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createCLAHE(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_clipLimit = NULL;
    double clipLimit=40.0;
    PyObject* pyobj_tileGridSize = NULL;
    Size tileGridSize=Size(8, 8);
    Ptr<cuda::CLAHE> retval;

    const char* keywords[] = { "clipLimit", "tileGridSize", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:createCLAHE", (char**)keywords, &pyobj_clipLimit, &pyobj_tileGridSize) &&
        pyopencv_to_safe(pyobj_clipLimit, clipLimit, ArgInfo("clipLimit", 0)) &&
        pyopencv_to_safe(pyobj_tileGridSize, tileGridSize, ArgInfo("tileGridSize", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createCLAHE(clipLimit, tileGridSize));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createCannyEdgeDetector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_low_thresh = NULL;
    double low_thresh=0;
    PyObject* pyobj_high_thresh = NULL;
    double high_thresh=0;
    PyObject* pyobj_apperture_size = NULL;
    int apperture_size=3;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;
    Ptr<CannyEdgeDetector> retval;

    const char* keywords[] = { "low_thresh", "high_thresh", "apperture_size", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:createCannyEdgeDetector", (char**)keywords, &pyobj_low_thresh, &pyobj_high_thresh, &pyobj_apperture_size, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_low_thresh, low_thresh, ArgInfo("low_thresh", 0)) &&
        pyopencv_to_safe(pyobj_high_thresh, high_thresh, ArgInfo("high_thresh", 0)) &&
        pyopencv_to_safe(pyobj_apperture_size, apperture_size, ArgInfo("apperture_size", 0)) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createCannyEdgeDetector(low_thresh, high_thresh, apperture_size, L2gradient));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createContinuous(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    Mat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:createContinuous", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::createContinuous(rows, cols, type, arr));
        return pyopencv_from(arr);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:createContinuous", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::createContinuous(rows, cols, type, arr));
        return pyopencv_from(arr);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    UMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:createContinuous", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::createContinuous(rows, cols, type, arr));
        return pyopencv_from(arr);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("createContinuous");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createConvolution(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_user_block_size = NULL;
    Size user_block_size;
    Ptr<Convolution> retval;

    const char* keywords[] = { "user_block_size", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:createConvolution", (char**)keywords, &pyobj_user_block_size) &&
        pyopencv_to_safe(pyobj_user_block_size, user_block_size, ArgInfo("user_block_size", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createConvolution(user_block_size));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createDFT(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_dft_size = NULL;
    Size dft_size;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    Ptr<DFT> retval;

    const char* keywords[] = { "dft_size", "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:createDFT", (char**)keywords, &pyobj_dft_size, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_dft_size, dft_size, ArgInfo("dft_size", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createDFT(dft_size, flags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createGeneralizedHoughBallard(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    Ptr<GeneralizedHoughBallard> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::createGeneralizedHoughBallard());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createGeneralizedHoughGuil(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    Ptr<GeneralizedHoughGuil> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::createGeneralizedHoughGuil());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createGoodFeaturesToTrackDetector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_srcType = NULL;
    int srcType=0;
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=1000;
    PyObject* pyobj_qualityLevel = NULL;
    double qualityLevel=0.01;
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0.0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=3;
    PyObject* pyobj_useHarrisDetector = NULL;
    bool useHarrisDetector=false;
    PyObject* pyobj_harrisK = NULL;
    double harrisK=0.04;
    Ptr<CornersDetector> retval;

    const char* keywords[] = { "srcType", "maxCorners", "qualityLevel", "minDistance", "blockSize", "useHarrisDetector", "harrisK", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOOO:createGoodFeaturesToTrackDetector", (char**)keywords, &pyobj_srcType, &pyobj_maxCorners, &pyobj_qualityLevel, &pyobj_minDistance, &pyobj_blockSize, &pyobj_useHarrisDetector, &pyobj_harrisK) &&
        pyopencv_to_safe(pyobj_srcType, srcType, ArgInfo("srcType", 0)) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) &&
        pyopencv_to_safe(pyobj_qualityLevel, qualityLevel, ArgInfo("qualityLevel", 0)) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_useHarrisDetector, useHarrisDetector, ArgInfo("useHarrisDetector", 0)) &&
        pyopencv_to_safe(pyobj_harrisK, harrisK, ArgInfo("harrisK", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createGoodFeaturesToTrackDetector(srcType, maxCorners, qualityLevel, minDistance, blockSize, useHarrisDetector, harrisK));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createGpuMatFromCudaMemory(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_cudaMemoryAddress = NULL;
    size_t cudaMemoryAddress=0;
    PyObject* pyobj_step = NULL;
    size_t step=Mat::AUTO_STEP;
    GpuMat retval;

    const char* keywords[] = { "rows", "cols", "type", "cudaMemoryAddress", "step", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:createGpuMatFromCudaMemory", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_cudaMemoryAddress, &pyobj_step) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_cudaMemoryAddress, cudaMemoryAddress, ArgInfo("cudaMemoryAddress", 0)) &&
        pyopencv_to_safe(pyobj_step, step, ArgInfo("step", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createGpuMatFromCudaMemory(rows, cols, type, cudaMemoryAddress, step));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_cudaMemoryAddress = NULL;
    size_t cudaMemoryAddress=0;
    PyObject* pyobj_step = NULL;
    size_t step=Mat::AUTO_STEP;
    GpuMat retval;

    const char* keywords[] = { "size", "type", "cudaMemoryAddress", "step", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:createGpuMatFromCudaMemory", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_cudaMemoryAddress, &pyobj_step) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_cudaMemoryAddress, cudaMemoryAddress, ArgInfo("cudaMemoryAddress", 0)) &&
        pyopencv_to_safe(pyobj_step, step, ArgInfo("step", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createGpuMatFromCudaMemory(size, type, cudaMemoryAddress, step));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("createGpuMatFromCudaMemory");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createHarrisCorner(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_srcType = NULL;
    int srcType=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_k = NULL;
    double k=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_REFLECT101;
    Ptr<CornernessCriteria> retval;

    const char* keywords[] = { "srcType", "blockSize", "ksize", "k", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:createHarrisCorner", (char**)keywords, &pyobj_srcType, &pyobj_blockSize, &pyobj_ksize, &pyobj_k, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_srcType, srcType, ArgInfo("srcType", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_k, k, ArgInfo("k", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createHarrisCorner(srcType, blockSize, ksize, k, borderType));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createHoughCirclesDetector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_dp = NULL;
    float dp=0.f;
    PyObject* pyobj_minDist = NULL;
    float minDist=0.f;
    PyObject* pyobj_cannyThreshold = NULL;
    int cannyThreshold=0;
    PyObject* pyobj_votesThreshold = NULL;
    int votesThreshold=0;
    PyObject* pyobj_minRadius = NULL;
    int minRadius=0;
    PyObject* pyobj_maxRadius = NULL;
    int maxRadius=0;
    PyObject* pyobj_maxCircles = NULL;
    int maxCircles=4096;
    Ptr<HoughCirclesDetector> retval;

    const char* keywords[] = { "dp", "minDist", "cannyThreshold", "votesThreshold", "minRadius", "maxRadius", "maxCircles", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO|O:createHoughCirclesDetector", (char**)keywords, &pyobj_dp, &pyobj_minDist, &pyobj_cannyThreshold, &pyobj_votesThreshold, &pyobj_minRadius, &pyobj_maxRadius, &pyobj_maxCircles) &&
        pyopencv_to_safe(pyobj_dp, dp, ArgInfo("dp", 0)) &&
        pyopencv_to_safe(pyobj_minDist, minDist, ArgInfo("minDist", 0)) &&
        pyopencv_to_safe(pyobj_cannyThreshold, cannyThreshold, ArgInfo("cannyThreshold", 0)) &&
        pyopencv_to_safe(pyobj_votesThreshold, votesThreshold, ArgInfo("votesThreshold", 0)) &&
        pyopencv_to_safe(pyobj_minRadius, minRadius, ArgInfo("minRadius", 0)) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) &&
        pyopencv_to_safe(pyobj_maxCircles, maxCircles, ArgInfo("maxCircles", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createHoughCirclesDetector(dp, minDist, cannyThreshold, votesThreshold, minRadius, maxRadius, maxCircles));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createHoughLinesDetector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_rho = NULL;
    float rho=0.f;
    PyObject* pyobj_theta = NULL;
    float theta=0.f;
    PyObject* pyobj_threshold = NULL;
    int threshold=0;
    PyObject* pyobj_doSort = NULL;
    bool doSort=false;
    PyObject* pyobj_maxLines = NULL;
    int maxLines=4096;
    Ptr<HoughLinesDetector> retval;

    const char* keywords[] = { "rho", "theta", "threshold", "doSort", "maxLines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:createHoughLinesDetector", (char**)keywords, &pyobj_rho, &pyobj_theta, &pyobj_threshold, &pyobj_doSort, &pyobj_maxLines) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) &&
        pyopencv_to_safe(pyobj_doSort, doSort, ArgInfo("doSort", 0)) &&
        pyopencv_to_safe(pyobj_maxLines, maxLines, ArgInfo("maxLines", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createHoughLinesDetector(rho, theta, threshold, doSort, maxLines));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createHoughSegmentDetector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_rho = NULL;
    float rho=0.f;
    PyObject* pyobj_theta = NULL;
    float theta=0.f;
    PyObject* pyobj_minLineLength = NULL;
    int minLineLength=0;
    PyObject* pyobj_maxLineGap = NULL;
    int maxLineGap=0;
    PyObject* pyobj_maxLines = NULL;
    int maxLines=4096;
    PyObject* pyobj_threshold = NULL;
    int threshold=-1;
    Ptr<HoughSegmentDetector> retval;

    const char* keywords[] = { "rho", "theta", "minLineLength", "maxLineGap", "maxLines", "threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:createHoughSegmentDetector", (char**)keywords, &pyobj_rho, &pyobj_theta, &pyobj_minLineLength, &pyobj_maxLineGap, &pyobj_maxLines, &pyobj_threshold) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) &&
        pyopencv_to_safe(pyobj_minLineLength, minLineLength, ArgInfo("minLineLength", 0)) &&
        pyopencv_to_safe(pyobj_maxLineGap, maxLineGap, ArgInfo("maxLineGap", 0)) &&
        pyopencv_to_safe(pyobj_maxLines, maxLines, ArgInfo("maxLines", 0)) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createHoughSegmentDetector(rho, theta, minLineLength, maxLineGap, maxLines, threshold));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createLookUpTable(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_lut = NULL;
    Mat lut;
    Ptr<LookUpTable> retval;

    const char* keywords[] = { "lut", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:createLookUpTable", (char**)keywords, &pyobj_lut) &&
        pyopencv_to_safe(pyobj_lut, lut, ArgInfo("lut", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createLookUpTable(lut));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_lut = NULL;
    cuda::GpuMat lut;
    Ptr<LookUpTable> retval;

    const char* keywords[] = { "lut", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:createLookUpTable", (char**)keywords, &pyobj_lut) &&
        pyopencv_to_safe(pyobj_lut, lut, ArgInfo("lut", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createLookUpTable(lut));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_lut = NULL;
    UMat lut;
    Ptr<LookUpTable> retval;

    const char* keywords[] = { "lut", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:createLookUpTable", (char**)keywords, &pyobj_lut) &&
        pyopencv_to_safe(pyobj_lut, lut, ArgInfo("lut", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createLookUpTable(lut));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("createLookUpTable");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createMinEigenValCorner(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_srcType = NULL;
    int srcType=0;
    PyObject* pyobj_blockSize = NULL;
    int blockSize=0;
    PyObject* pyobj_ksize = NULL;
    int ksize=0;
    PyObject* pyobj_borderType = NULL;
    int borderType=BORDER_REFLECT101;
    Ptr<CornernessCriteria> retval;

    const char* keywords[] = { "srcType", "blockSize", "ksize", "borderType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:createMinEigenValCorner", (char**)keywords, &pyobj_srcType, &pyobj_blockSize, &pyobj_ksize, &pyobj_borderType) &&
        pyopencv_to_safe(pyobj_srcType, srcType, ArgInfo("srcType", 0)) &&
        pyopencv_to_safe(pyobj_blockSize, blockSize, ArgInfo("blockSize", 0)) &&
        pyopencv_to_safe(pyobj_ksize, ksize, ArgInfo("ksize", 0)) &&
        pyopencv_to_safe(pyobj_borderType, borderType, ArgInfo("borderType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createMinEigenValCorner(srcType, blockSize, ksize, borderType));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_createTemplateMatching(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_srcType = NULL;
    int srcType=0;
    PyObject* pyobj_method = NULL;
    int method=0;
    PyObject* pyobj_user_block_size = NULL;
    Size user_block_size;
    Ptr<TemplateMatching> retval;

    const char* keywords[] = { "srcType", "method", "user_block_size", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:createTemplateMatching", (char**)keywords, &pyobj_srcType, &pyobj_method, &pyobj_user_block_size) &&
        pyopencv_to_safe(pyobj_srcType, srcType, ArgInfo("srcType", 0)) &&
        pyopencv_to_safe(pyobj_method, method, ArgInfo("method", 0)) &&
        pyopencv_to_safe(pyobj_user_block_size, user_block_size, ArgInfo("user_block_size", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::createTemplateMatching(srcType, method, user_block_size));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cvtColor(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dcn = NULL;
    int dcn=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "code", "dst", "dcn", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dcn, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dcn, dcn, ArgInfo("dcn", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::cvtColor(src, dst, code, dcn, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dcn = NULL;
    int dcn=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "code", "dst", "dcn", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dcn, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dcn, dcn, ArgInfo("dcn", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::cvtColor(src, dst, code, dcn, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dcn = NULL;
    int dcn=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "code", "dst", "dcn", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cvtColor", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dcn, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dcn, dcn, ArgInfo("dcn", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::cvtColor(src, dst, code, dcn, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("cvtColor");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_demosaicing(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dcn = NULL;
    int dcn=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "code", "dst", "dcn", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dcn, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dcn, dcn, ArgInfo("dcn", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::demosaicing(src, dst, code, dcn, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dcn = NULL;
    int dcn=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "code", "dst", "dcn", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dcn, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dcn, dcn, ArgInfo("dcn", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::demosaicing(src, dst, code, dcn, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_code = NULL;
    int code=0;
    PyObject* pyobj_dcn = NULL;
    int dcn=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "code", "dst", "dcn", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:demosaicing", (char**)keywords, &pyobj_src, &pyobj_code, &pyobj_dst, &pyobj_dcn, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_code, code, ArgInfo("code", 0)) &&
        pyopencv_to_safe(pyobj_dcn, dcn, ArgInfo("dcn", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::demosaicing(src, dst, code, dcn, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("demosaicing");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_dft(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dft_size = NULL;
    Size dft_size;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dft_size", "dst", "flags", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dft_size, &pyobj_dst, &pyobj_flags, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dft_size, dft_size, ArgInfo("dft_size", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::dft(src, dst, dft_size, flags, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_dft_size = NULL;
    Size dft_size;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dft_size", "dst", "flags", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dft_size, &pyobj_dst, &pyobj_flags, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dft_size, dft_size, ArgInfo("dft_size", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::dft(src, dst, dft_size, flags, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dft_size = NULL;
    Size dft_size;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dft_size", "dst", "flags", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:dft", (char**)keywords, &pyobj_src, &pyobj_dft_size, &pyobj_dst, &pyobj_flags, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dft_size, dft_size, ArgInfo("dft_size", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::dft(src, dst, dft_size, flags, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dft");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_divide(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::divide(src1, src2, dst, scale, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::divide(src1, src2, dst, scale, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:divide", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::divide(src1, src2, dst, scale, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("divide");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_ensureSizeIsEnough(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    Mat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:ensureSizeIsEnough", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::ensureSizeIsEnough(rows, cols, type, arr));
        return pyopencv_from(arr);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:ensureSizeIsEnough", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::ensureSizeIsEnough(rows, cols, type, arr));
        return pyopencv_from(arr);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_arr = NULL;
    UMat arr;

    const char* keywords[] = { "rows", "cols", "type", "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:ensureSizeIsEnough", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 1)) )
    {
        ERRWRAP2(cv::cuda::ensureSizeIsEnough(rows, cols, type, arr));
        return pyopencv_from(arr);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("ensureSizeIsEnough");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_equalizeHist(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::equalizeHist(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::equalizeHist(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:equalizeHist", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::equalizeHist(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("equalizeHist");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_evenLevels(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_levels = NULL;
    Mat levels;
    PyObject* pyobj_nLevels = NULL;
    int nLevels=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "nLevels", "lowerLevel", "upperLevel", "levels", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:evenLevels", (char**)keywords, &pyobj_nLevels, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_levels, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 1)) &&
        pyopencv_to_safe(pyobj_nLevels, nLevels, ArgInfo("nLevels", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::evenLevels(levels, nLevels, lowerLevel, upperLevel, stream));
        return pyopencv_from(levels);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_levels = NULL;
    cuda::GpuMat levels;
    PyObject* pyobj_nLevels = NULL;
    int nLevels=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "nLevels", "lowerLevel", "upperLevel", "levels", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:evenLevels", (char**)keywords, &pyobj_nLevels, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_levels, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 1)) &&
        pyopencv_to_safe(pyobj_nLevels, nLevels, ArgInfo("nLevels", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::evenLevels(levels, nLevels, lowerLevel, upperLevel, stream));
        return pyopencv_from(levels);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_levels = NULL;
    UMat levels;
    PyObject* pyobj_nLevels = NULL;
    int nLevels=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "nLevels", "lowerLevel", "upperLevel", "levels", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:evenLevels", (char**)keywords, &pyobj_nLevels, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_levels, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 1)) &&
        pyopencv_to_safe(pyobj_nLevels, nLevels, ArgInfo("nLevels", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::evenLevels(levels, nLevels, lowerLevel, upperLevel, stream));
        return pyopencv_from(levels);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("evenLevels");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_exp(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:exp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::exp(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:exp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::exp(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:exp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::exp(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("exp");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_findMinMax(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:findMinMax", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::findMinMax(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:findMinMax", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::findMinMax(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:findMinMax", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::findMinMax(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("findMinMax");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_findMinMaxLoc(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_minMaxVals = NULL;
    Mat minMaxVals;
    PyObject* pyobj_loc = NULL;
    Mat loc;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "minMaxVals", "loc", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:findMinMaxLoc", (char**)keywords, &pyobj_src, &pyobj_minMaxVals, &pyobj_loc, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_minMaxVals, minMaxVals, ArgInfo("minMaxVals", 1)) &&
        pyopencv_to_safe(pyobj_loc, loc, ArgInfo("loc", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::findMinMaxLoc(src, minMaxVals, loc, mask, stream));
        return Py_BuildValue("(NN)", pyopencv_from(minMaxVals), pyopencv_from(loc));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_minMaxVals = NULL;
    cuda::GpuMat minMaxVals;
    PyObject* pyobj_loc = NULL;
    cuda::GpuMat loc;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "minMaxVals", "loc", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:findMinMaxLoc", (char**)keywords, &pyobj_src, &pyobj_minMaxVals, &pyobj_loc, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_minMaxVals, minMaxVals, ArgInfo("minMaxVals", 1)) &&
        pyopencv_to_safe(pyobj_loc, loc, ArgInfo("loc", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::findMinMaxLoc(src, minMaxVals, loc, mask, stream));
        return Py_BuildValue("(NN)", pyopencv_from(minMaxVals), pyopencv_from(loc));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_minMaxVals = NULL;
    UMat minMaxVals;
    PyObject* pyobj_loc = NULL;
    UMat loc;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "minMaxVals", "loc", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:findMinMaxLoc", (char**)keywords, &pyobj_src, &pyobj_minMaxVals, &pyobj_loc, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_minMaxVals, minMaxVals, ArgInfo("minMaxVals", 1)) &&
        pyopencv_to_safe(pyobj_loc, loc, ArgInfo("loc", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::findMinMaxLoc(src, minMaxVals, loc, mask, stream));
        return Py_BuildValue("(NN)", pyopencv_from(minMaxVals), pyopencv_from(loc));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("findMinMaxLoc");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_flip(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "flipCode", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::flip(src, dst, flipCode, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "flipCode", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::flip(src, dst, flipCode, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flipCode = NULL;
    int flipCode=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "flipCode", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:flip", (char**)keywords, &pyobj_src, &pyobj_flipCode, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flipCode, flipCode, ArgInfo("flipCode", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::flip(src, dst, flipCode, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("flip");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_gammaCorrection(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_forward = NULL;
    bool forward=true;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "forward", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:gammaCorrection", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_forward, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_forward, forward, ArgInfo("forward", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::gammaCorrection(src, dst, forward, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_forward = NULL;
    bool forward=true;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "forward", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:gammaCorrection", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_forward, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_forward, forward, ArgInfo("forward", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::gammaCorrection(src, dst, forward, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_forward = NULL;
    bool forward=true;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "forward", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:gammaCorrection", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_forward, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_forward, forward, ArgInfo("forward", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::gammaCorrection(src, dst, forward, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("gammaCorrection");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_gemm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    Mat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::gemm(src1, src2, alpha, src3, beta, dst, flags, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    cuda::GpuMat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::gemm(src1, src2, alpha, src3, beta, dst, flags, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_src3 = NULL;
    UMat src3;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "alpha", "src3", "beta", "dst", "flags", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:gemm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_alpha, &pyobj_src3, &pyobj_beta, &pyobj_dst, &pyobj_flags, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_src3, src3, ArgInfo("src3", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::gemm(src1, src2, alpha, src3, beta, dst, flags, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("gemm");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_getCudaEnabledDeviceCount(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::getCudaEnabledDeviceCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_getDevice(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::getDevice());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_histEven(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_histSize = NULL;
    int histSize=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "histSize", "lowerLevel", "upperLevel", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:histEven", (char**)keywords, &pyobj_src, &pyobj_histSize, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histEven(src, hist, histSize, lowerLevel, upperLevel, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_hist = NULL;
    cuda::GpuMat hist;
    PyObject* pyobj_histSize = NULL;
    int histSize=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "histSize", "lowerLevel", "upperLevel", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:histEven", (char**)keywords, &pyobj_src, &pyobj_histSize, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histEven(src, hist, histSize, lowerLevel, upperLevel, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_histSize = NULL;
    int histSize=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "histSize", "lowerLevel", "upperLevel", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:histEven", (char**)keywords, &pyobj_src, &pyobj_histSize, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histEven(src, hist, histSize, lowerLevel, upperLevel, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_hist = NULL;
    GpuMat* hist;
    PyObject* pyobj_histSize = NULL;
    int histSize=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "histSize", "lowerLevel", "upperLevel", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:histEven", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_histSize, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histEven(src, hist, &histSize, &lowerLevel, &upperLevel, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_hist = NULL;
    GpuMat* hist;
    PyObject* pyobj_histSize = NULL;
    int histSize=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "histSize", "lowerLevel", "upperLevel", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:histEven", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_histSize, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histEven(src, hist, &histSize, &lowerLevel, &upperLevel, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_hist = NULL;
    GpuMat* hist;
    PyObject* pyobj_histSize = NULL;
    int histSize=0;
    PyObject* pyobj_lowerLevel = NULL;
    int lowerLevel=0;
    PyObject* pyobj_upperLevel = NULL;
    int upperLevel=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "histSize", "lowerLevel", "upperLevel", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:histEven", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_histSize, &pyobj_lowerLevel, &pyobj_upperLevel, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_histSize, histSize, ArgInfo("histSize", 0)) &&
        pyopencv_to_safe(pyobj_lowerLevel, lowerLevel, ArgInfo("lowerLevel", 0)) &&
        pyopencv_to_safe(pyobj_upperLevel, upperLevel, ArgInfo("upperLevel", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histEven(src, hist, &histSize, &lowerLevel, &upperLevel, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("histEven");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_histRange(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_hist = NULL;
    Mat hist;
    PyObject* pyobj_levels = NULL;
    Mat levels;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "levels", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:histRange", (char**)keywords, &pyobj_src, &pyobj_levels, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histRange(src, hist, levels, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_hist = NULL;
    cuda::GpuMat hist;
    PyObject* pyobj_levels = NULL;
    cuda::GpuMat levels;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "levels", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:histRange", (char**)keywords, &pyobj_src, &pyobj_levels, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histRange(src, hist, levels, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_hist = NULL;
    UMat hist;
    PyObject* pyobj_levels = NULL;
    UMat levels;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "levels", "hist", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:histRange", (char**)keywords, &pyobj_src, &pyobj_levels, &pyobj_hist, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 1)) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histRange(src, hist, levels, stream));
        return pyopencv_from(hist);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_hist = NULL;
    GpuMat* hist;
    PyObject* pyobj_levels = NULL;
    GpuMat* levels;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "levels", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:histRange", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_levels, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histRange(src, hist, levels, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_hist = NULL;
    GpuMat* hist;
    PyObject* pyobj_levels = NULL;
    GpuMat* levels;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "levels", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:histRange", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_levels, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histRange(src, hist, levels, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_hist = NULL;
    GpuMat* hist;
    PyObject* pyobj_levels = NULL;
    GpuMat* levels;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "hist", "levels", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:histRange", (char**)keywords, &pyobj_src, &pyobj_hist, &pyobj_levels, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_hist, hist, ArgInfo("hist", 0)) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::histRange(src, hist, levels, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("histRange");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_inRange(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lowerb = NULL;
    Scalar lowerb;
    PyObject* pyobj_upperb = NULL;
    Scalar upperb;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to_safe(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::inRange(src, lowerb, upperb, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_lowerb = NULL;
    Scalar lowerb;
    PyObject* pyobj_upperb = NULL;
    Scalar upperb;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to_safe(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::inRange(src, lowerb, upperb, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lowerb = NULL;
    Scalar lowerb;
    PyObject* pyobj_upperb = NULL;
    Scalar upperb;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lowerb", "upperb", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:inRange", (char**)keywords, &pyobj_src, &pyobj_lowerb, &pyobj_upperb, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lowerb, lowerb, ArgInfo("lowerb", 0)) &&
        pyopencv_to_safe(pyobj_upperb, upperb, ArgInfo("upperb", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::inRange(src, lowerb, upperb, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("inRange");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_integral(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sum = NULL;
    Mat sum;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sum", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::integral(src, sum, stream));
        return pyopencv_from(sum);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_sum = NULL;
    cuda::GpuMat sum;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sum", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::integral(src, sum, stream));
        return pyopencv_from(sum);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sum = NULL;
    UMat sum;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sum", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:integral", (char**)keywords, &pyobj_src, &pyobj_sum, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sum, sum, ArgInfo("sum", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::integral(src, sum, stream));
        return pyopencv_from(sum);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("integral");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_log(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:log", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::log(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:log", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::log(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:log", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::log(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("log");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_lshift(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_val = NULL;
    Scalar val;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "val", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:lshift", (char**)keywords, &pyobj_src, &pyobj_val, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::lshift(src, val, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_val = NULL;
    Scalar val;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "val", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:lshift", (char**)keywords, &pyobj_src, &pyobj_val, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::lshift(src, val, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_val = NULL;
    Scalar val;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "val", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:lshift", (char**)keywords, &pyobj_src, &pyobj_val, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::lshift(src, val, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("lshift");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_magnitude(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_xy = NULL;
    Mat xy;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "xy", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:magnitude", (char**)keywords, &pyobj_xy, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_xy, xy, ArgInfo("xy", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitude(xy, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_xy = NULL;
    cuda::GpuMat xy;
    PyObject* pyobj_magnitude = NULL;
    cuda::GpuMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "xy", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:magnitude", (char**)keywords, &pyobj_xy, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_xy, xy, ArgInfo("xy", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitude(xy, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_xy = NULL;
    UMat xy;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "xy", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:magnitude", (char**)keywords, &pyobj_xy, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_xy, xy, ArgInfo("xy", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitude(xy, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitude(x, y, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    cuda::GpuMat x;
    PyObject* pyobj_y = NULL;
    cuda::GpuMat y;
    PyObject* pyobj_magnitude = NULL;
    cuda::GpuMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitude(x, y, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:magnitude", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitude(x, y, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("magnitude");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_magnitudeSqr(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_xy = NULL;
    Mat xy;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "xy", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:magnitudeSqr", (char**)keywords, &pyobj_xy, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_xy, xy, ArgInfo("xy", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitudeSqr(xy, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_xy = NULL;
    cuda::GpuMat xy;
    PyObject* pyobj_magnitude = NULL;
    cuda::GpuMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "xy", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:magnitudeSqr", (char**)keywords, &pyobj_xy, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_xy, xy, ArgInfo("xy", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitudeSqr(xy, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_xy = NULL;
    UMat xy;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "xy", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:magnitudeSqr", (char**)keywords, &pyobj_xy, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_xy, xy, ArgInfo("xy", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitudeSqr(xy, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:magnitudeSqr", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitudeSqr(x, y, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    cuda::GpuMat x;
    PyObject* pyobj_y = NULL;
    cuda::GpuMat y;
    PyObject* pyobj_magnitude = NULL;
    cuda::GpuMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:magnitudeSqr", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitudeSqr(x, y, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "magnitude", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:magnitudeSqr", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_magnitude, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::magnitudeSqr(x, y, magnitude, stream));
        return pyopencv_from(magnitude);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("magnitudeSqr");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_max(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::max(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::max(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:max", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::max(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("max");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_meanShiftFiltering(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "dst", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:meanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftFiltering(src, dst, sp, sr, criteria, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "dst", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:meanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftFiltering(src, dst, sp, sr, criteria, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "dst", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:meanShiftFiltering", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dst, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftFiltering(src, dst, sp, sr, criteria, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("meanShiftFiltering");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_meanShiftProc(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dstr = NULL;
    Mat dstr;
    PyObject* pyobj_dstsp = NULL;
    Mat dstsp;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "dstr", "dstsp", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:meanShiftProc", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dstr, &pyobj_dstsp, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dstr, dstr, ArgInfo("dstr", 1)) &&
        pyopencv_to_safe(pyobj_dstsp, dstsp, ArgInfo("dstsp", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftProc(src, dstr, dstsp, sp, sr, criteria, stream));
        return Py_BuildValue("(NN)", pyopencv_from(dstr), pyopencv_from(dstsp));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dstr = NULL;
    cuda::GpuMat dstr;
    PyObject* pyobj_dstsp = NULL;
    cuda::GpuMat dstsp;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "dstr", "dstsp", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:meanShiftProc", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dstr, &pyobj_dstsp, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dstr, dstr, ArgInfo("dstr", 1)) &&
        pyopencv_to_safe(pyobj_dstsp, dstsp, ArgInfo("dstsp", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftProc(src, dstr, dstsp, sp, sr, criteria, stream));
        return Py_BuildValue("(NN)", pyopencv_from(dstr), pyopencv_from(dstsp));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dstr = NULL;
    UMat dstr;
    PyObject* pyobj_dstsp = NULL;
    UMat dstsp;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "dstr", "dstsp", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:meanShiftProc", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_dstr, &pyobj_dstsp, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dstr, dstr, ArgInfo("dstr", 1)) &&
        pyopencv_to_safe(pyobj_dstsp, dstsp, ArgInfo("dstsp", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftProc(src, dstr, dstsp, sp, sr, criteria, stream));
        return Py_BuildValue("(NN)", pyopencv_from(dstr), pyopencv_from(dstsp));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("meanShiftProc");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_meanShiftSegmentation(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_minsize = NULL;
    int minsize=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "minsize", "dst", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:meanShiftSegmentation", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_minsize, &pyobj_dst, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_minsize, minsize, ArgInfo("minsize", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftSegmentation(src, dst, sp, sr, minsize, criteria, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_minsize = NULL;
    int minsize=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "minsize", "dst", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:meanShiftSegmentation", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_minsize, &pyobj_dst, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_minsize, minsize, ArgInfo("minsize", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftSegmentation(src, dst, sp, sr, minsize, criteria, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_sp = NULL;
    int sp=0;
    PyObject* pyobj_sr = NULL;
    int sr=0;
    PyObject* pyobj_minsize = NULL;
    int minsize=0;
    PyObject* pyobj_criteria = NULL;
    TermCriteria criteria=TermCriteria(TermCriteria::MAX_ITER + TermCriteria::EPS, 5, 1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sp", "sr", "minsize", "dst", "criteria", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:meanShiftSegmentation", (char**)keywords, &pyobj_src, &pyobj_sp, &pyobj_sr, &pyobj_minsize, &pyobj_dst, &pyobj_criteria, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_sp, sp, ArgInfo("sp", 0)) &&
        pyopencv_to_safe(pyobj_sr, sr, ArgInfo("sr", 0)) &&
        pyopencv_to_safe(pyobj_minsize, minsize, ArgInfo("minsize", 0)) &&
        pyopencv_to_safe(pyobj_criteria, criteria, ArgInfo("criteria", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanShiftSegmentation(src, dst, sp, sr, minsize, criteria, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("meanShiftSegmentation");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_meanStdDev(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(12);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "mask", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "mask", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "mask", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mask, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(src, dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mtx", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:meanStdDev", (char**)keywords, &pyobj_mtx, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(mtx, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    cuda::GpuMat mtx;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mtx", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:meanStdDev", (char**)keywords, &pyobj_mtx, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(mtx, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mtx", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:meanStdDev", (char**)keywords, &pyobj_mtx, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(mtx, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    Scalar mean;
    Scalar stddev;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    Scalar mean;
    Scalar stddev;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    Scalar mean;
    Scalar stddev;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:meanStdDev", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(src, mean, stddev, mask));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    Scalar mean;
    Scalar stddev;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:meanStdDev", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(mtx, mean, stddev));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    cuda::GpuMat mtx;
    Scalar mean;
    Scalar stddev;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:meanStdDev", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(mtx, mean, stddev));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    Scalar mean;
    Scalar stddev;

    const char* keywords[] = { "mtx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:meanStdDev", (char**)keywords, &pyobj_mtx) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) )
    {
        ERRWRAP2(cv::cuda::meanStdDev(mtx, mean, stddev));
        return Py_BuildValue("(NN)", pyopencv_from(mean), pyopencv_from(stddev));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("meanStdDev");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_merge(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    vector_GpuMat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:merge", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::merge(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    vector_GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:merge", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::merge(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    vector_GpuMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:merge", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::merge(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("merge");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_min(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::min(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::min(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:min", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::min(src1, src2, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("min");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_minMax(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    double minVal;
    double maxVal;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMax", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::minMax(src, &minVal, &maxVal, mask));
        return Py_BuildValue("(NN)", pyopencv_from(minVal), pyopencv_from(maxVal));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    double minVal;
    double maxVal;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMax", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::minMax(src, &minVal, &maxVal, mask));
        return Py_BuildValue("(NN)", pyopencv_from(minVal), pyopencv_from(maxVal));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    double minVal;
    double maxVal;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMax", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::minMax(src, &minVal, &maxVal, mask));
        return Py_BuildValue("(NN)", pyopencv_from(minVal), pyopencv_from(maxVal));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("minMax");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_minMaxLoc(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    Mat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    double minVal;
    double maxVal;
    Point minLoc;
    Point maxLoc;
    PyObject* pyobj_mask = NULL;
    UMat mask;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:minMaxLoc", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(cv::cuda::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask));
        return Py_BuildValue("(NNNN)", pyopencv_from(minVal), pyopencv_from(maxVal), pyopencv_from(minLoc), pyopencv_from(maxLoc));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("minMaxLoc");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_moments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=MomentsOrder::THIRD_ORDER_MOMENTS;
    PyObject* pyobj_momentsType = NULL;
    int momentsType=CV_64F;
    Moments retval;

    const char* keywords[] = { "src", "binaryImage", "order", "momentsType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:moments", (char**)keywords, &pyobj_src, &pyobj_binaryImage, &pyobj_order, &pyobj_momentsType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::moments(src, binaryImage, order, momentsType));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=MomentsOrder::THIRD_ORDER_MOMENTS;
    PyObject* pyobj_momentsType = NULL;
    int momentsType=CV_64F;
    Moments retval;

    const char* keywords[] = { "src", "binaryImage", "order", "momentsType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:moments", (char**)keywords, &pyobj_src, &pyobj_binaryImage, &pyobj_order, &pyobj_momentsType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::moments(src, binaryImage, order, momentsType));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=MomentsOrder::THIRD_ORDER_MOMENTS;
    PyObject* pyobj_momentsType = NULL;
    int momentsType=CV_64F;
    Moments retval;

    const char* keywords[] = { "src", "binaryImage", "order", "momentsType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:moments", (char**)keywords, &pyobj_src, &pyobj_binaryImage, &pyobj_order, &pyobj_momentsType) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::moments(src, binaryImage, order, momentsType));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("moments");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_mulAndScaleSpectrums(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_scale = NULL;
    float scale=0.f;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "flags", "scale", "dst", "conjB", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:mulAndScaleSpectrums", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_flags, &pyobj_scale, &pyobj_dst, &pyobj_conjB, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::mulAndScaleSpectrums(src1, src2, dst, flags, scale, conjB, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_scale = NULL;
    float scale=0.f;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "flags", "scale", "dst", "conjB", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:mulAndScaleSpectrums", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_flags, &pyobj_scale, &pyobj_dst, &pyobj_conjB, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::mulAndScaleSpectrums(src1, src2, dst, flags, scale, conjB, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_scale = NULL;
    float scale=0.f;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "flags", "scale", "dst", "conjB", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOO:mulAndScaleSpectrums", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_flags, &pyobj_scale, &pyobj_dst, &pyobj_conjB, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::mulAndScaleSpectrums(src1, src2, dst, flags, scale, conjB, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("mulAndScaleSpectrums");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_mulSpectrums(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "flags", "dst", "conjB", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:mulSpectrums", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_flags, &pyobj_dst, &pyobj_conjB, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::mulSpectrums(src1, src2, dst, flags, conjB, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "flags", "dst", "conjB", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:mulSpectrums", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_flags, &pyobj_dst, &pyobj_conjB, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::mulSpectrums(src1, src2, dst, flags, conjB, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_conjB = NULL;
    bool conjB=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "flags", "dst", "conjB", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:mulSpectrums", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_flags, &pyobj_dst, &pyobj_conjB, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_conjB, conjB, ArgInfo("conjB", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::mulSpectrums(src1, src2, dst, flags, conjB, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("mulSpectrums");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_multiply(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::multiply(src1, src2, dst, scale, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::multiply(src1, src2, dst, scale, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_scale = NULL;
    double scale=1;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "scale", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:multiply", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_scale, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_scale, scale, ArgInfo("scale", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::multiply(src1, src2, dst, scale, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("multiply");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_norm(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_normType = NULL;
    int normType=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_normType = NULL;
    int normType=0;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_normType = NULL;
    int normType=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    double retval;

    const char* keywords[] = { "src1", "normType", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:norm", (char**)keywords, &pyobj_src1, &pyobj_normType, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::norm(src1, normType, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::norm(src1, src2, normType));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::norm(src1, src2, normType));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_normType = NULL;
    int normType=NORM_L2;
    double retval;

    const char* keywords[] = { "src1", "src2", "normType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:norm", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_normType) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_normType, normType, ArgInfo("normType", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::norm(src1, src2, normType));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("norm");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_normalize(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "alpha", "beta", "norm_type", "dtype", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:normalize", (char**)keywords, &pyobj_src, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::normalize(src, dst, alpha, beta, norm_type, dtype, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "alpha", "beta", "norm_type", "dtype", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:normalize", (char**)keywords, &pyobj_src, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::normalize(src, dst, alpha, beta, norm_type, dtype, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_norm_type = NULL;
    int norm_type=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "alpha", "beta", "norm_type", "dtype", "dst", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|OOO:normalize", (char**)keywords, &pyobj_src, &pyobj_alpha, &pyobj_beta, &pyobj_norm_type, &pyobj_dtype, &pyobj_dst, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_norm_type, norm_type, ArgInfo("norm_type", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::normalize(src, dst, alpha, beta, norm_type, dtype, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("normalize");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_numMoments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_order = NULL;
    MomentsOrder order=static_cast<MomentsOrder>(0);
    int retval;

    const char* keywords[] = { "order", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:numMoments", (char**)keywords, &pyobj_order) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::numMoments(order));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_phase(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::phase(x, y, angle, angleInDegrees, stream));
        return pyopencv_from(angle);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    cuda::GpuMat x;
    PyObject* pyobj_y = NULL;
    cuda::GpuMat y;
    PyObject* pyobj_angle = NULL;
    cuda::GpuMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::phase(x, y, angle, angleInDegrees, stream));
        return pyopencv_from(angle);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "x", "y", "angle", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:phase", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_angle, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::phase(x, y, angle, angleInDegrees, stream));
        return pyopencv_from(angle);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("phase");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_polarToCart(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_magnitude = NULL;
    Mat magnitude;
    PyObject* pyobj_angle = NULL;
    Mat angle;
    PyObject* pyobj_x = NULL;
    Mat x;
    PyObject* pyobj_y = NULL;
    Mat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::polarToCart(magnitude, angle, x, y, angleInDegrees, stream));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_magnitude = NULL;
    cuda::GpuMat magnitude;
    PyObject* pyobj_angle = NULL;
    cuda::GpuMat angle;
    PyObject* pyobj_x = NULL;
    cuda::GpuMat x;
    PyObject* pyobj_y = NULL;
    cuda::GpuMat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::polarToCart(magnitude, angle, x, y, angleInDegrees, stream));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_magnitude = NULL;
    UMat magnitude;
    PyObject* pyobj_angle = NULL;
    UMat angle;
    PyObject* pyobj_x = NULL;
    UMat x;
    PyObject* pyobj_y = NULL;
    UMat y;
    PyObject* pyobj_angleInDegrees = NULL;
    bool angleInDegrees=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "magnitude", "angle", "x", "y", "angleInDegrees", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:polarToCart", (char**)keywords, &pyobj_magnitude, &pyobj_angle, &pyobj_x, &pyobj_y, &pyobj_angleInDegrees, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_magnitude, magnitude, ArgInfo("magnitude", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 1)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 1)) &&
        pyopencv_to_safe(pyobj_angleInDegrees, angleInDegrees, ArgInfo("angleInDegrees", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::polarToCart(magnitude, angle, x, y, angleInDegrees, stream));
        return Py_BuildValue("(NN)", pyopencv_from(x), pyopencv_from(y));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("polarToCart");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_pow(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "power", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pow(src, power, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "power", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pow(src, power, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_power = NULL;
    double power=0;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "power", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:pow", (char**)keywords, &pyobj_src, &pyobj_power, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_power, power, ArgInfo("power", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pow(src, power, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pow");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_printCudaDeviceInfo(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_device = NULL;
    int device=0;

    const char* keywords[] = { "device", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:printCudaDeviceInfo", (char**)keywords, &pyobj_device) &&
        pyopencv_to_safe(pyobj_device, device, ArgInfo("device", 0)) )
    {
        ERRWRAP2(cv::cuda::printCudaDeviceInfo(device));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_printShortCudaDeviceInfo(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_device = NULL;
    int device=0;

    const char* keywords[] = { "device", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:printShortCudaDeviceInfo", (char**)keywords, &pyobj_device) &&
        pyopencv_to_safe(pyobj_device, device, ArgInfo("device", 0)) )
    {
        ERRWRAP2(cv::cuda::printShortCudaDeviceInfo(device));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_pyrDown(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pyrDown(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pyrDown(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:pyrDown", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pyrDown(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pyrDown");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_pyrUp(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pyrUp(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pyrUp(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:pyrUp", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::pyrUp(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("pyrUp");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_rectStdDev(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sqr = NULL;
    Mat sqr;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sqr", "rect", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:rectStdDev", (char**)keywords, &pyobj_src, &pyobj_sqr, &pyobj_rect, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sqr, sqr, ArgInfo("sqr", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rectStdDev(src, sqr, dst, rect, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_sqr = NULL;
    cuda::GpuMat sqr;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sqr", "rect", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:rectStdDev", (char**)keywords, &pyobj_src, &pyobj_sqr, &pyobj_rect, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sqr, sqr, ArgInfo("sqr", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rectStdDev(src, sqr, dst, rect, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sqr = NULL;
    UMat sqr;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_rect = NULL;
    Rect rect;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sqr", "rect", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:rectStdDev", (char**)keywords, &pyobj_src, &pyobj_sqr, &pyobj_rect, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sqr, sqr, ArgInfo("sqr", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rectStdDev(src, sqr, dst, rect, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rectStdDev");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_reduce(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_mtx = NULL;
    Mat mtx;
    PyObject* pyobj_vec = NULL;
    Mat vec;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_reduceOp = NULL;
    int reduceOp=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mtx", "dim", "reduceOp", "vec", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:reduce", (char**)keywords, &pyobj_mtx, &pyobj_dim, &pyobj_reduceOp, &pyobj_vec, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 1)) &&
        pyopencv_to_safe(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to_safe(pyobj_reduceOp, reduceOp, ArgInfo("reduceOp", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::reduce(mtx, vec, dim, reduceOp, dtype, stream));
        return pyopencv_from(vec);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    cuda::GpuMat mtx;
    PyObject* pyobj_vec = NULL;
    cuda::GpuMat vec;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_reduceOp = NULL;
    int reduceOp=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mtx", "dim", "reduceOp", "vec", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:reduce", (char**)keywords, &pyobj_mtx, &pyobj_dim, &pyobj_reduceOp, &pyobj_vec, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 1)) &&
        pyopencv_to_safe(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to_safe(pyobj_reduceOp, reduceOp, ArgInfo("reduceOp", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::reduce(mtx, vec, dim, reduceOp, dtype, stream));
        return pyopencv_from(vec);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_mtx = NULL;
    UMat mtx;
    PyObject* pyobj_vec = NULL;
    UMat vec;
    PyObject* pyobj_dim = NULL;
    int dim=0;
    PyObject* pyobj_reduceOp = NULL;
    int reduceOp=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mtx", "dim", "reduceOp", "vec", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOO:reduce", (char**)keywords, &pyobj_mtx, &pyobj_dim, &pyobj_reduceOp, &pyobj_vec, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_mtx, mtx, ArgInfo("mtx", 0)) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 1)) &&
        pyopencv_to_safe(pyobj_dim, dim, ArgInfo("dim", 0)) &&
        pyopencv_to_safe(pyobj_reduceOp, reduceOp, ArgInfo("reduceOp", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::reduce(mtx, vec, dim, reduceOp, dtype, stream));
        return pyopencv_from(vec);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("reduce");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_registerPageLocked(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:registerPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::registerPageLocked(m));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_remap(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_xmap = NULL;
    Mat xmap;
    PyObject* pyobj_ymap = NULL;
    Mat ymap;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "xmap", "ymap", "interpolation", "dst", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:remap", (char**)keywords, &pyobj_src, &pyobj_xmap, &pyobj_ymap, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 0)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::remap(src, dst, xmap, ymap, interpolation, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_xmap = NULL;
    cuda::GpuMat xmap;
    PyObject* pyobj_ymap = NULL;
    cuda::GpuMat ymap;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "xmap", "ymap", "interpolation", "dst", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:remap", (char**)keywords, &pyobj_src, &pyobj_xmap, &pyobj_ymap, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 0)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::remap(src, dst, xmap, ymap, interpolation, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_xmap = NULL;
    UMat xmap;
    PyObject* pyobj_ymap = NULL;
    UMat ymap;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=0;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "xmap", "ymap", "interpolation", "dst", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OOOO:remap", (char**)keywords, &pyobj_src, &pyobj_xmap, &pyobj_ymap, &pyobj_interpolation, &pyobj_dst, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_xmap, xmap, ArgInfo("xmap", 0)) &&
        pyopencv_to_safe(pyobj_ymap, ymap, ArgInfo("ymap", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::remap(src, dst, xmap, ymap, interpolation, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("remap");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_resetDevice(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(cv::cuda::resetDevice());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_resize(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to_safe(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::resize(src, dst, dsize, fx, fy, interpolation, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to_safe(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::resize(src, dst, dsize, fx, fy, interpolation, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_fx = NULL;
    double fx=0;
    PyObject* pyobj_fy = NULL;
    double fy=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dsize", "dst", "fx", "fy", "interpolation", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOOO:resize", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_dst, &pyobj_fx, &pyobj_fy, &pyobj_interpolation, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_fx, fx, ArgInfo("fx", 0)) &&
        pyopencv_to_safe(pyobj_fy, fy, ArgInfo("fy", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::resize(src, dst, dsize, fx, fy, interpolation, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("resize");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_rotate(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_xShift = NULL;
    double xShift=0;
    PyObject* pyobj_yShift = NULL;
    double yShift=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dsize", "angle", "dst", "xShift", "yShift", "interpolation", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:rotate", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_angle, &pyobj_dst, &pyobj_xShift, &pyobj_yShift, &pyobj_interpolation, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_xShift, xShift, ArgInfo("xShift", 0)) &&
        pyopencv_to_safe(pyobj_yShift, yShift, ArgInfo("yShift", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rotate(src, dst, dsize, angle, xShift, yShift, interpolation, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_xShift = NULL;
    double xShift=0;
    PyObject* pyobj_yShift = NULL;
    double yShift=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dsize", "angle", "dst", "xShift", "yShift", "interpolation", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:rotate", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_angle, &pyobj_dst, &pyobj_xShift, &pyobj_yShift, &pyobj_interpolation, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_xShift, xShift, ArgInfo("xShift", 0)) &&
        pyopencv_to_safe(pyobj_yShift, yShift, ArgInfo("yShift", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rotate(src, dst, dsize, angle, xShift, yShift, interpolation, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_angle = NULL;
    double angle=0;
    PyObject* pyobj_xShift = NULL;
    double xShift=0;
    PyObject* pyobj_yShift = NULL;
    double yShift=0;
    PyObject* pyobj_interpolation = NULL;
    int interpolation=INTER_LINEAR;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dsize", "angle", "dst", "xShift", "yShift", "interpolation", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:rotate", (char**)keywords, &pyobj_src, &pyobj_dsize, &pyobj_angle, &pyobj_dst, &pyobj_xShift, &pyobj_yShift, &pyobj_interpolation, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_xShift, xShift, ArgInfo("xShift", 0)) &&
        pyopencv_to_safe(pyobj_yShift, yShift, ArgInfo("yShift", 0)) &&
        pyopencv_to_safe(pyobj_interpolation, interpolation, ArgInfo("interpolation", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rotate(src, dst, dsize, angle, xShift, yShift, interpolation, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rotate");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_rshift(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_val = NULL;
    Scalar val;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "val", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:rshift", (char**)keywords, &pyobj_src, &pyobj_val, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rshift(src, val, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_val = NULL;
    Scalar val;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "val", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:rshift", (char**)keywords, &pyobj_src, &pyobj_val, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rshift(src, val, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_val = NULL;
    Scalar val;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "val", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:rshift", (char**)keywords, &pyobj_src, &pyobj_val, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::rshift(src, val, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rshift");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_setBufferPoolConfig(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_deviceId = NULL;
    int deviceId=0;
    PyObject* pyobj_stackSize = NULL;
    size_t stackSize=0;
    PyObject* pyobj_stackCount = NULL;
    int stackCount=0;

    const char* keywords[] = { "deviceId", "stackSize", "stackCount", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:setBufferPoolConfig", (char**)keywords, &pyobj_deviceId, &pyobj_stackSize, &pyobj_stackCount) &&
        pyopencv_to_safe(pyobj_deviceId, deviceId, ArgInfo("deviceId", 0)) &&
        pyopencv_to_safe(pyobj_stackSize, stackSize, ArgInfo("stackSize", 0)) &&
        pyopencv_to_safe(pyobj_stackCount, stackCount, ArgInfo("stackCount", 0)) )
    {
        ERRWRAP2(cv::cuda::setBufferPoolConfig(deviceId, stackSize, stackCount));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_setBufferPoolUsage(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_on = NULL;
    bool on=0;

    const char* keywords[] = { "on", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setBufferPoolUsage", (char**)keywords, &pyobj_on) &&
        pyopencv_to_safe(pyobj_on, on, ArgInfo("on", 0)) )
    {
        ERRWRAP2(cv::cuda::setBufferPoolUsage(on));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_setDevice(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_device = NULL;
    int device=0;

    const char* keywords[] = { "device", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setDevice", (char**)keywords, &pyobj_device) &&
        pyopencv_to_safe(pyobj_device, device, ArgInfo("device", 0)) )
    {
        ERRWRAP2(cv::cuda::setDevice(device));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_spatialMoments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_moments = NULL;
    Mat moments;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=MomentsOrder::THIRD_ORDER_MOMENTS;
    PyObject* pyobj_momentsType = NULL;
    int momentsType=CV_64F;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "moments", "binaryImage", "order", "momentsType", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:spatialMoments", (char**)keywords, &pyobj_src, &pyobj_moments, &pyobj_binaryImage, &pyobj_order, &pyobj_momentsType, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_moments, moments, ArgInfo("moments", 1)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::spatialMoments(src, moments, binaryImage, order, momentsType, stream));
        return pyopencv_from(moments);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_moments = NULL;
    cuda::GpuMat moments;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=MomentsOrder::THIRD_ORDER_MOMENTS;
    PyObject* pyobj_momentsType = NULL;
    int momentsType=CV_64F;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "moments", "binaryImage", "order", "momentsType", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:spatialMoments", (char**)keywords, &pyobj_src, &pyobj_moments, &pyobj_binaryImage, &pyobj_order, &pyobj_momentsType, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_moments, moments, ArgInfo("moments", 1)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::spatialMoments(src, moments, binaryImage, order, momentsType, stream));
        return pyopencv_from(moments);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_moments = NULL;
    UMat moments;
    PyObject* pyobj_binaryImage = NULL;
    bool binaryImage=false;
    PyObject* pyobj_order = NULL;
    MomentsOrder order=MomentsOrder::THIRD_ORDER_MOMENTS;
    PyObject* pyobj_momentsType = NULL;
    int momentsType=CV_64F;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "moments", "binaryImage", "order", "momentsType", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOOO:spatialMoments", (char**)keywords, &pyobj_src, &pyobj_moments, &pyobj_binaryImage, &pyobj_order, &pyobj_momentsType, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_moments, moments, ArgInfo("moments", 1)) &&
        pyopencv_to_safe(pyobj_binaryImage, binaryImage, ArgInfo("binaryImage", 0)) &&
        pyopencv_to_safe(pyobj_order, order, ArgInfo("order", 0)) &&
        pyopencv_to_safe(pyobj_momentsType, momentsType, ArgInfo("momentsType", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::spatialMoments(src, moments, binaryImage, order, momentsType, stream));
        return pyopencv_from(moments);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("spatialMoments");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_split(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    vector_GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:split", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::split(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    vector_GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:split", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::split(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    vector_GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:split", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::split(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("split");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_sqr(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqr", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqr(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqr", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqr(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqr", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqr(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sqr");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_sqrIntegral(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_sqsum = NULL;
    Mat sqsum;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sqsum", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqrIntegral", (char**)keywords, &pyobj_src, &pyobj_sqsum, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqrIntegral(src, sqsum, stream));
        return pyopencv_from(sqsum);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_sqsum = NULL;
    cuda::GpuMat sqsum;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sqsum", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqrIntegral", (char**)keywords, &pyobj_src, &pyobj_sqsum, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqrIntegral(src, sqsum, stream));
        return pyopencv_from(sqsum);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_sqsum = NULL;
    UMat sqsum;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "sqsum", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqrIntegral", (char**)keywords, &pyobj_src, &pyobj_sqsum, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_sqsum, sqsum, ArgInfo("sqsum", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqrIntegral(src, sqsum, stream));
        return pyopencv_from(sqsum);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sqrIntegral");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_sqrSum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sqrSum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::sqrSum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sqrSum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::sqrSum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sqrSum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::sqrSum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sqrSum");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_sqrt(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqrt(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqrt(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:sqrt", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::sqrt(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sqrt");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_subtract(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_src2 = NULL;
    Mat src2;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::subtract(src1, src2, dst, mask, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_src2 = NULL;
    cuda::GpuMat src2;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::subtract(src1, src2, dst, mask, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_src2 = NULL;
    UMat src2;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_dtype = NULL;
    int dtype=-1;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "src2", "dst", "mask", "dtype", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOOO:subtract", (char**)keywords, &pyobj_src1, &pyobj_src2, &pyobj_dst, &pyobj_mask, &pyobj_dtype, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_src2, src2, ArgInfo("src2", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::subtract(src1, src2, dst, mask, dtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("subtract");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_sum(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::sum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::sum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    Scalar retval;

    const char* keywords[] = { "src", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:sum", (char**)keywords, &pyobj_src, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::sum(src, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("sum");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_threshold(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to_safe(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::threshold(src, dst, thresh, maxval, type, stream));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to_safe(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::threshold(src, dst, thresh, maxval, type, stream));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_thresh = NULL;
    double thresh=0;
    PyObject* pyobj_maxval = NULL;
    double maxval=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    double retval;

    const char* keywords[] = { "src", "thresh", "maxval", "type", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|OO:threshold", (char**)keywords, &pyobj_src, &pyobj_thresh, &pyobj_maxval, &pyobj_type, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_thresh, thresh, ArgInfo("thresh", 0)) &&
        pyopencv_to_safe(pyobj_maxval, maxval, ArgInfo("maxval", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::threshold(src, dst, thresh, maxval, type, stream));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("threshold");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_transpose(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src1 = NULL;
    Mat src1;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:transpose", (char**)keywords, &pyobj_src1, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::transpose(src1, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    cuda::GpuMat src1;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:transpose", (char**)keywords, &pyobj_src1, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::transpose(src1, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src1 = NULL;
    UMat src1;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src1", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:transpose", (char**)keywords, &pyobj_src1, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src1, src1, ArgInfo("src1", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::transpose(src1, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("transpose");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_unregisterPageLocked(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_m = NULL;
    Mat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:unregisterPageLocked", (char**)keywords, &pyobj_m) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        ERRWRAP2(cv::cuda::unregisterPageLocked(m));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_warpAffine(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpAffine", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpAffine(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("warpAffine");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_warpPerspective(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    UMat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_M = NULL;
    Mat M;
    PyObject* pyobj_dsize = NULL;
    Size dsize;
    PyObject* pyobj_flags = NULL;
    int flags=INTER_LINEAR;
    PyObject* pyobj_borderMode = NULL;
    int borderMode=BORDER_CONSTANT;
    PyObject* pyobj_borderValue = NULL;
    Scalar borderValue;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "M", "dsize", "dst", "flags", "borderMode", "borderValue", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOOO:warpPerspective", (char**)keywords, &pyobj_src, &pyobj_M, &pyobj_dsize, &pyobj_dst, &pyobj_flags, &pyobj_borderMode, &pyobj_borderValue, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_M, M, ArgInfo("M", 0)) &&
        pyopencv_to_safe(pyobj_dsize, dsize, ArgInfo("dsize", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_borderMode, borderMode, ArgInfo("borderMode", 0)) &&
        pyopencv_to_safe(pyobj_borderValue, borderValue, ArgInfo("borderValue", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(cv::cuda::warpPerspective(src, dst, M, dsize, flags, borderMode, borderValue, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("warpPerspective");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_wrapStream(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_cudaStreamMemoryAddress = NULL;
    size_t cudaStreamMemoryAddress=0;
    Stream retval;

    const char* keywords[] = { "cudaStreamMemoryAddress", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:wrapStream", (char**)keywords, &pyobj_cudaStreamMemoryAddress) &&
        pyopencv_to_safe(pyobj_cudaStreamMemoryAddress, cudaStreamMemoryAddress, ArgInfo("cudaStreamMemoryAddress", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::wrapStream(cudaStreamMemoryAddress));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_getIppVersion(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ipp;

    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ipp::getIppVersion());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_setUseIPP(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ipp;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setUseIPP", (char**)keywords, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::ipp::setUseIPP(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_setUseIPP_NotExact(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ipp;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setUseIPP_NotExact", (char**)keywords, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::ipp::setUseIPP_NotExact(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_useIPP(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ipp;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ipp::useIPP());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ipp_useIPP_NotExact(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ipp;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ipp::useIPP_NotExact());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_Device_getDefault(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;

    Device retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::Device::getDefault());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_finish(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(cv::ocl::finish());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_haveAmdBlas(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::haveAmdBlas());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_haveAmdFft(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::haveAmdFft());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_haveOpenCL(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::haveOpenCL());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_setUseOpenCL(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;

    PyObject* pyobj_flag = NULL;
    bool flag=0;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:setUseOpenCL", (char**)keywords, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(cv::ocl::setUseOpenCL(flag));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_useOpenCL(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;

    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::ocl::useOpenCL());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_parallel_setParallelForBackend(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::parallel;

    PyObject* pyobj_backendName = NULL;
    std::string backendName;
    PyObject* pyobj_propagateNumThreads = NULL;
    bool propagateNumThreads=true;
    bool retval;

    const char* keywords[] = { "backendName", "propagateNumThreads", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:setParallelForBackend", (char**)keywords, &pyobj_backendName, &pyobj_propagateNumThreads) &&
        pyopencv_to_safe(pyobj_backendName, backendName, ArgInfo("backendName", 0)) &&
        pyopencv_to_safe(pyobj_propagateNumThreads, propagateNumThreads, ArgInfo("propagateNumThreads", 0)) )
    {
        ERRWRAP2(retval = cv::parallel::setParallelForBackend(backendName, propagateNumThreads));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_addSamplesDataSearchPath(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_path = NULL;
    String path;

    const char* keywords[] = { "path", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:addSamplesDataSearchPath", (char**)keywords, &pyobj_path) &&
        pyopencv_to_safe(pyobj_path, path, ArgInfo("path", 0)) )
    {
        ERRWRAP2(cv::samples::addSamplesDataSearchPath(path));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_addSamplesDataSearchSubDirectory(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_subdir = NULL;
    String subdir;

    const char* keywords[] = { "subdir", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:addSamplesDataSearchSubDirectory", (char**)keywords, &pyobj_subdir) &&
        pyopencv_to_safe(pyobj_subdir, subdir, ArgInfo("subdir", 0)) )
    {
        ERRWRAP2(cv::samples::addSamplesDataSearchSubDirectory(subdir));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_findFile(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_relative_path = NULL;
    String relative_path;
    PyObject* pyobj_required = NULL;
    bool required=true;
    PyObject* pyobj_silentMode = NULL;
    bool silentMode=false;
    cv::String retval;

    const char* keywords[] = { "relative_path", "required", "silentMode", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:findFile", (char**)keywords, &pyobj_relative_path, &pyobj_required, &pyobj_silentMode) &&
        pyopencv_to_safe(pyobj_relative_path, relative_path, ArgInfo("relative_path", 0)) &&
        pyopencv_to_safe(pyobj_required, required, ArgInfo("required", 0)) &&
        pyopencv_to_safe(pyobj_silentMode, silentMode, ArgInfo("silentMode", 0)) )
    {
        ERRWRAP2(retval = cv::samples::findFile(relative_path, required, silentMode));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_samples_findFileOrKeep(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::samples;

    PyObject* pyobj_relative_path = NULL;
    String relative_path;
    PyObject* pyobj_silentMode = NULL;
    bool silentMode=false;
    cv::String retval;

    const char* keywords[] = { "relative_path", "silentMode", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:findFileOrKeep", (char**)keywords, &pyobj_relative_path, &pyobj_silentMode) &&
        pyopencv_to_safe(pyobj_relative_path, relative_path, ArgInfo("relative_path", 0)) &&
        pyopencv_to_safe(pyobj_silentMode, silentMode, ArgInfo("silentMode", 0)) )
    {
        ERRWRAP2(retval = cv::samples::findFileOrKeep(relative_path, silentMode));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_copyMatAndDumpNamedArguments(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_params_lambda = NULL;
    FunctionParams params=FunctionParams();
    PyObject* pyobj_params_sigma = NULL;
    String retval;

    const char* keywords[] = { "src", "dst", "lambda_", "sigma", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:copyMatAndDumpNamedArguments", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_params_lambda, &pyobj_params_sigma) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_params_lambda, params.lambda, ArgInfo("lambda", 0)) &&
        pyopencv_to_safe(pyobj_params_sigma, params.sigma, ArgInfo("sigma", 0)) )
    {
        ERRWRAP2(retval = cv::utils::copyMatAndDumpNamedArguments(src, dst, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_params_lambda = NULL;
    FunctionParams params=FunctionParams();
    PyObject* pyobj_params_sigma = NULL;
    String retval;

    const char* keywords[] = { "src", "dst", "lambda_", "sigma", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:copyMatAndDumpNamedArguments", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_params_lambda, &pyobj_params_sigma) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_params_lambda, params.lambda, ArgInfo("lambda", 0)) &&
        pyopencv_to_safe(pyobj_params_sigma, params.sigma, ArgInfo("sigma", 0)) )
    {
        ERRWRAP2(retval = cv::utils::copyMatAndDumpNamedArguments(src, dst, params));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("copyMatAndDumpNamedArguments");

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpBool(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    bool argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpBool", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpBool(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpCString(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    char* argument=(char*)"";
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "s:dumpCString", (char**)keywords, &argument) )
    {
        ERRWRAP2(retval = cv::utils::dumpCString(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpDouble(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    double argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpDouble", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpDouble(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpFloat(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    float argument=0.f;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpFloat", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpFloat(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputArray(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_argument = NULL;
    Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArray(argument));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_argument = NULL;
    UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArray(argument));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dumpInputArray");

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputArrayOfArrays(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_argument = NULL;
    vector_Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArrayOfArrays(argument));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_argument = NULL;
    vector_UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputArrayOfArrays(argument));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dumpInputArrayOfArrays");

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputOutputArray(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_argument = NULL;
    Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputOutputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArray(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_argument = NULL;
    UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputOutputArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArray(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dumpInputOutputArray");

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInputOutputArrayOfArrays(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_argument = NULL;
    vector_Mat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputOutputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArrayOfArrays(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_argument = NULL;
    vector_UMat argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInputOutputArrayOfArrays", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 1)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInputOutputArrayOfArrays(argument));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(argument));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("dumpInputOutputArrayOfArrays");

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInt(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    int argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInt", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInt(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpInt64(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    int64 argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpInt64", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpInt64(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpRange(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    Range argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpRange", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpRange(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    Rect argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpRect", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpRect(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpRotatedRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    cv::RotatedRect argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpRotatedRect", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpRotatedRect(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpSizeT(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    size_t argument=0;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpSizeT", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpSizeT(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpString(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    String argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpString", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpString(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpTermCriteria(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    TermCriteria argument;
    String retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpTermCriteria", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpTermCriteria(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpVec2i(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_value = NULL;
    Vec2i value=cv::Vec2i(42, 24);
    String retval;

    const char* keywords[] = { "value", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:dumpVec2i", (char**)keywords, &pyobj_value) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpVec2i(value));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpVectorOfDouble(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_vec = NULL;
    vector_double vec;
    String retval;

    const char* keywords[] = { "vec", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpVectorOfDouble", (char**)keywords, &pyobj_vec) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpVectorOfDouble(vec));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpVectorOfInt(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_vec = NULL;
    vector_int vec;
    String retval;

    const char* keywords[] = { "vec", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpVectorOfInt", (char**)keywords, &pyobj_vec) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpVectorOfInt(vec));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_dumpVectorOfRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_vec = NULL;
    vector_Rect vec;
    String retval;

    const char* keywords[] = { "vec", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:dumpVectorOfRect", (char**)keywords, &pyobj_vec) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 0)) )
    {
        ERRWRAP2(retval = cv::utils::dumpVectorOfRect(vec));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_generateVectorOfInt(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_len = NULL;
    size_t len=0;
    vector_int vec;

    const char* keywords[] = { "len", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:generateVectorOfInt", (char**)keywords, &pyobj_len) &&
        pyopencv_to_safe(pyobj_len, len, ArgInfo("len", 0)) )
    {
        ERRWRAP2(cv::utils::generateVectorOfInt(len, vec));
        return pyopencv_from(vec);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_generateVectorOfMat(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_len = NULL;
    size_t len=0;
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_dtype = NULL;
    int dtype=0;
    PyObject* pyobj_vec = NULL;
    vector_Mat vec;

    const char* keywords[] = { "len", "rows", "cols", "dtype", "vec", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:generateVectorOfMat", (char**)keywords, &pyobj_len, &pyobj_rows, &pyobj_cols, &pyobj_dtype, &pyobj_vec) &&
        pyopencv_to_safe(pyobj_len, len, ArgInfo("len", 0)) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_dtype, dtype, ArgInfo("dtype", 0)) &&
        pyopencv_to_safe(pyobj_vec, vec, ArgInfo("vec", 1)) )
    {
        ERRWRAP2(cv::utils::generateVectorOfMat(len, rows, cols, dtype, vec));
        return pyopencv_from(vec);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_generateVectorOfRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_len = NULL;
    size_t len=0;
    vector_Rect vec;

    const char* keywords[] = { "len", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:generateVectorOfRect", (char**)keywords, &pyobj_len) &&
        pyopencv_to_safe(pyobj_len, len, ArgInfo("len", 0)) )
    {
        ERRWRAP2(cv::utils::generateVectorOfRect(len, vec));
        return pyopencv_from(vec);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testAsyncArray(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_argument = NULL;
    Mat argument;
    AsyncArray retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:testAsyncArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testAsyncArray(argument));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_argument = NULL;
    UMat argument;
    AsyncArray retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:testAsyncArray", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testAsyncArray(argument));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("testAsyncArray");

    return NULL;
}

static PyObject* pyopencv_cv_utils_testAsyncException(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    AsyncArray retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::utils::testAsyncException());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testOverloadResolution(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_value = NULL;
    int value=0;
    PyObject* pyobj_point = NULL;
    Point point=Point(42, 24);
    String retval;

    const char* keywords[] = { "value", "point", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:testOverloadResolution", (char**)keywords, &pyobj_value, &pyobj_point) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) &&
        pyopencv_to_safe(pyobj_point, point, ArgInfo("point", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testOverloadResolution(value, point));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rect = NULL;
    Rect rect;
    String retval;

    const char* keywords[] = { "rect", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:testOverloadResolution", (char**)keywords, &pyobj_rect) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testOverloadResolution(rect));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("testOverloadResolution");

    return NULL;
}

static PyObject* pyopencv_cv_utils_testOverwriteNativeMethod(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_argument = NULL;
    int argument=0;
    int retval;

    const char* keywords[] = { "argument", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:testOverwriteNativeMethod", (char**)keywords, &pyobj_argument) &&
        pyopencv_to_safe(pyobj_argument, argument, ArgInfo("argument", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testOverwriteNativeMethod(argument));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testRaiseGeneralException(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(cv::utils::testRaiseGeneralException());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testReservedKeywordConversion(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_positional_argument = NULL;
    int positional_argument=0;
    PyObject* pyobj_lambda = NULL;
    int lambda=2;
    PyObject* pyobj_from = NULL;
    int from=3;
    String retval;

    const char* keywords[] = { "positional_argument", "lambda_", "from_", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:testReservedKeywordConversion", (char**)keywords, &pyobj_positional_argument, &pyobj_lambda, &pyobj_from) &&
        pyopencv_to_safe(pyobj_positional_argument, positional_argument, ArgInfo("positional_argument", 0)) &&
        pyopencv_to_safe(pyobj_lambda, lambda, ArgInfo("lambda", 0)) &&
        pyopencv_to_safe(pyobj_from, from, ArgInfo("from", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testReservedKeywordConversion(positional_argument, lambda, from));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testRotatedRect(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_x = NULL;
    float x=0.f;
    PyObject* pyobj_y = NULL;
    float y=0.f;
    PyObject* pyobj_w = NULL;
    float w=0.f;
    PyObject* pyobj_h = NULL;
    float h=0.f;
    PyObject* pyobj_angle = NULL;
    float angle=0.f;
    RotatedRect retval;

    const char* keywords[] = { "x", "y", "w", "h", "angle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO:testRotatedRect", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_w, &pyobj_h, &pyobj_angle) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_w, w, ArgInfo("w", 0)) &&
        pyopencv_to_safe(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testRotatedRect(x, y, w, h, angle));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_testRotatedRectVector(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_x = NULL;
    float x=0.f;
    PyObject* pyobj_y = NULL;
    float y=0.f;
    PyObject* pyobj_w = NULL;
    float w=0.f;
    PyObject* pyobj_h = NULL;
    float h=0.f;
    PyObject* pyobj_angle = NULL;
    float angle=0.f;
    std::vector<RotatedRect> retval;

    const char* keywords[] = { "x", "y", "w", "h", "angle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO:testRotatedRectVector", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_w, &pyobj_h, &pyobj_angle) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_w, w, ArgInfo("w", 0)) &&
        pyopencv_to_safe(pyobj_h, h, ArgInfo("h", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) )
    {
        ERRWRAP2(retval = cv::utils::testRotatedRectVector(x, y, w, h, angle));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_fs_getCacheDirectoryForDownloads(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::fs;

    cv::String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::utils::fs::getCacheDirectoryForDownloads());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_ExportClassName_create(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    PyObject* pyobj_params = NULL;
    OriginalClassName_Params params=OriginalClassName::Params();
    Ptr<OriginalClassName> retval;

    const char* keywords[] = { "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:ExportClassName_create", (char**)keywords, &pyobj_params) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::utils::nested::OriginalClassName::create(params));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_ExportClassName_originalName(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    std::string retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::utils::nested::OriginalClassName::originalName());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_OriginalClassName_create(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    PyObject* pyobj_params = NULL;
    OriginalClassName_Params params=OriginalClassName::Params();
    Ptr<OriginalClassName> retval;

    const char* keywords[] = { "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:OriginalClassName_create", (char**)keywords, &pyobj_params) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::utils::nested::OriginalClassName::create(params));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_OriginalClassName_originalName(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    std::string retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::utils::nested::OriginalClassName::originalName());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_testEchoBooleanFunction(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    PyObject* pyobj_flag = NULL;
    bool flag=0;
    bool retval;

    const char* keywords[] = { "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:testEchoBooleanFunction", (char**)keywords, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(retval = cv::utils::nested::testEchoBooleanFunction(flag));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getBackendName(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    cv::String retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:getBackendName", (char**)keywords, &pyobj_api) &&
        pyopencv_to_safe(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::getBackendName(api));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getBackends(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getCameraBackendPluginVersion(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    int version_ABI;
    int version_API;
    std::string retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:getCameraBackendPluginVersion", (char**)keywords, &pyobj_api) &&
        pyopencv_to_safe(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::getCameraBackendPluginVersion(api, version_ABI, version_API));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(version_ABI), pyopencv_from(version_API));
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getCameraBackends(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getCameraBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getStreamBackendPluginVersion(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    int version_ABI;
    int version_API;
    std::string retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:getStreamBackendPluginVersion", (char**)keywords, &pyobj_api) &&
        pyopencv_to_safe(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::getStreamBackendPluginVersion(api, version_ABI, version_API));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(version_ABI), pyopencv_from(version_API));
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getStreamBackends(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getStreamBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getWriterBackendPluginVersion(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    int version_ABI;
    int version_API;
    std::string retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:getWriterBackendPluginVersion", (char**)keywords, &pyobj_api) &&
        pyopencv_to_safe(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::getWriterBackendPluginVersion(api, version_ABI, version_API));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(version_ABI), pyopencv_from(version_API));
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_getWriterBackends(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    std::vector<VideoCaptureAPIs> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::videoio_registry::getWriterBackends());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_hasBackend(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    bool retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:hasBackend", (char**)keywords, &pyobj_api) &&
        pyopencv_to_safe(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::hasBackend(api));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_videoio_registry_isBackendBuiltIn(PyObject* , PyObject* py_args, PyObject* kw)
{
    using namespace cv::videoio_registry;

    PyObject* pyobj_api = NULL;
    VideoCaptureAPIs api=static_cast<VideoCaptureAPIs>(0);
    bool retval;

    const char* keywords[] = { "api", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:isBackendBuiltIn", (char**)keywords, &pyobj_api) &&
        pyopencv_to_safe(pyobj_api, api, ArgInfo("api", 0)) )
    {
        ERRWRAP2(retval = cv::videoio_registry::isBackendBuiltIn(api));
        return pyopencv_from(retval);
    }

    return NULL;
}

