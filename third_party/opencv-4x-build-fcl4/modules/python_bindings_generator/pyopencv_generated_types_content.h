//================================================================================
// Algorithm (Generic)
//================================================================================

// GetSet (Algorithm)



// Methods (Algorithm)

static PyObject* pyopencv_cv_Algorithm_clear(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Algorithm> * self1 = 0;
    if (!pyopencv_Algorithm_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Algorithm' or its derivative)");
    Ptr<cv::Algorithm> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->clear());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_Algorithm_empty(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Algorithm> * self1 = 0;
    if (!pyopencv_Algorithm_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Algorithm' or its derivative)");
    Ptr<cv::Algorithm> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->empty());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Algorithm_getDefaultName(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Algorithm> * self1 = 0;
    if (!pyopencv_Algorithm_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Algorithm' or its derivative)");
    Ptr<cv::Algorithm> _self_ = *(self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getDefaultName());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Algorithm_read(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Algorithm> * self1 = 0;
    if (!pyopencv_Algorithm_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Algorithm' or its derivative)");
    Ptr<cv::Algorithm> _self_ = *(self1);
    PyObject* pyobj_fn = NULL;
    cv::FileNode fn;

    const char* keywords[] = { "fn", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Algorithm.read", (char**)keywords, &pyobj_fn) &&
        pyopencv_to_safe(pyobj_fn, fn, ArgInfo("fn", 0)) )
    {
        ERRWRAP2(_self_->read(fn));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_Algorithm_save(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Algorithm> * self1 = 0;
    if (!pyopencv_Algorithm_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Algorithm' or its derivative)");
    Ptr<cv::Algorithm> _self_ = *(self1);
    PyObject* pyobj_filename = NULL;
    String filename;

    const char* keywords[] = { "filename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Algorithm.save", (char**)keywords, &pyobj_filename) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) )
    {
        ERRWRAP2(_self_->save(filename));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_Algorithm_write(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Algorithm> * self1 = 0;
    if (!pyopencv_Algorithm_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Algorithm' or its derivative)");
    Ptr<cv::Algorithm> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_fs = NULL;
    Ptr<cv::FileStorage> fs;

    const char* keywords[] = { "fs", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Algorithm.write", (char**)keywords, &pyobj_fs) &&
        pyopencv_to_safe(pyobj_fs, fs, ArgInfo("fs", 0)) )
    {
        ERRWRAP2(_self_->write(*fs));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_fs = NULL;
    Ptr<cv::FileStorage> fs;
    PyObject* pyobj_name = NULL;
    String name;

    const char* keywords[] = { "fs", "name", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:Algorithm.write", (char**)keywords, &pyobj_fs, &pyobj_name) &&
        pyopencv_to_safe(pyobj_fs, fs, ArgInfo("fs", 0)) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) )
    {
        ERRWRAP2(_self_->write(*fs, name));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("write");

    return NULL;
}



// Tables (Algorithm)

static PyGetSetDef pyopencv_Algorithm_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_Algorithm_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_Algorithm
    PYOPENCV_EXTRA_METHODS_Algorithm
#endif
    {"clear", CV_PY_FN_WITH_KW_(pyopencv_cv_Algorithm_clear, 0), "clear() -> None\n.   @brief Clears the algorithm state"},
    {"empty", CV_PY_FN_WITH_KW_(pyopencv_cv_Algorithm_empty, 0), "empty() -> retval\n.   @brief Returns true if the Algorithm is empty (e.g. in the very beginning or after unsuccessful read"},
    {"getDefaultName", CV_PY_FN_WITH_KW_(pyopencv_cv_Algorithm_getDefaultName, 0), "getDefaultName() -> retval\n.   Returns the algorithm string identifier.\n.   This string is used as top level xml/yml node tag when the object is saved to a file or string."},
    {"read", CV_PY_FN_WITH_KW_(pyopencv_cv_Algorithm_read, 0), "read(fn) -> None\n.   @brief Reads algorithm parameters from a file storage"},
    {"save", CV_PY_FN_WITH_KW_(pyopencv_cv_Algorithm_save, 0), "save(filename) -> None\n.   Saves the algorithm to a file.\n.   In order to make this method work, the derived class must implement Algorithm::write(FileStorage& fs)."},
    {"write", CV_PY_FN_WITH_KW_(pyopencv_cv_Algorithm_write, 0), "write(fs) -> None\n.   @brief Stores algorithm parameters in a file storage\n\n\n\nwrite(fs, name) -> None\n.   * @overload"},

    {NULL,          NULL}
};

// Converter (Algorithm)

template<>
struct PyOpenCV_Converter< Ptr<cv::Algorithm> >
{
    static PyObject* from(const Ptr<cv::Algorithm>& r)
    {
        return pyopencv_Algorithm_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::Algorithm>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::Algorithm> * dst_;
        if (pyopencv_Algorithm_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::Algorithm> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// Animation (Generic)
//================================================================================

// GetSet (Animation)


static PyObject* pyopencv_Animation_get_bgcolor(pyopencv_Animation_t* p, void *closure)
{
    return pyopencv_from(p->v.bgcolor);
}

static int pyopencv_Animation_set_bgcolor(pyopencv_Animation_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the bgcolor attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.bgcolor, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_Animation_get_durations(pyopencv_Animation_t* p, void *closure)
{
    return pyopencv_from(p->v.durations);
}

static int pyopencv_Animation_set_durations(pyopencv_Animation_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the durations attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.durations, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_Animation_get_frames(pyopencv_Animation_t* p, void *closure)
{
    return pyopencv_from(p->v.frames);
}

static int pyopencv_Animation_set_frames(pyopencv_Animation_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the frames attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.frames, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_Animation_get_loop_count(pyopencv_Animation_t* p, void *closure)
{
    return pyopencv_from(p->v.loop_count);
}

static int pyopencv_Animation_set_loop_count(pyopencv_Animation_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the loop_count attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.loop_count, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_Animation_get_still_image(pyopencv_Animation_t* p, void *closure)
{
    return pyopencv_from(p->v.still_image);
}

static int pyopencv_Animation_set_still_image(pyopencv_Animation_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the still_image attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.still_image, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (Animation)

static int pyopencv_cv_Animation_Animation(pyopencv_Animation_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_loopCount = NULL;
    int loopCount=0;
    PyObject* pyobj_bgColor = NULL;
    Scalar bgColor;

    const char* keywords[] = { "loopCount", "bgColor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:Animation", (char**)keywords, &pyobj_loopCount, &pyobj_bgColor) &&
        pyopencv_to_safe(pyobj_loopCount, loopCount, ArgInfo("loopCount", 0)) &&
        pyopencv_to_safe(pyobj_bgColor, bgColor, ArgInfo("bgColor", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::Animation(loopCount, bgColor));
        return 0;
    }

    return -1;
}



// Tables (Animation)

static PyGetSetDef pyopencv_Animation_getseters[] =
{
    {(char*)"bgcolor", (getter)pyopencv_Animation_get_bgcolor, (setter)pyopencv_Animation_set_bgcolor, (char*)"bgcolor", NULL},
    {(char*)"durations", (getter)pyopencv_Animation_get_durations, (setter)pyopencv_Animation_set_durations, (char*)"durations", NULL},
    {(char*)"frames", (getter)pyopencv_Animation_get_frames, (setter)pyopencv_Animation_set_frames, (char*)"frames", NULL},
    {(char*)"loop_count", (getter)pyopencv_Animation_get_loop_count, (setter)pyopencv_Animation_set_loop_count, (char*)"loop_count", NULL},
    {(char*)"still_image", (getter)pyopencv_Animation_get_still_image, (setter)pyopencv_Animation_set_still_image, (char*)"still_image", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_Animation_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_Animation
    PYOPENCV_EXTRA_METHODS_Animation
#endif

    {NULL,          NULL}
};

// Converter (Animation)

template<>
struct PyOpenCV_Converter< cv::Animation >
{
    static PyObject* from(const cv::Animation& r)
    {
        return pyopencv_Animation_Instance(r);
    }
    static bool to(PyObject* src, cv::Animation& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::Animation * dst_;
        if (pyopencv_Animation_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::Animation for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// AsyncArray (Generic)
//================================================================================

// GetSet (AsyncArray)



// Methods (AsyncArray)

static int pyopencv_cv_AsyncArray_AsyncArray(pyopencv_AsyncArray_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::AsyncArray>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::AsyncArray()));
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_AsyncArray_get(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::AsyncArray> * self1 = 0;
    if (!pyopencv_AsyncArray_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'AsyncArray' or its derivative)");
    Ptr<cv::AsyncArray> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:AsyncArray.get", (char**)keywords, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->get(dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_timeoutNs = NULL;
    double timeoutNs=0;
    bool retval;

    const char* keywords[] = { "timeoutNs", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:AsyncArray.get", (char**)keywords, &pyobj_timeoutNs, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_timeoutNs, timeoutNs, ArgInfo("timeoutNs", 0)) )
    {
        ERRWRAP2(retval = _self_->get(dst, timeoutNs));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:AsyncArray.get", (char**)keywords, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->get(dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_timeoutNs = NULL;
    double timeoutNs=0;
    bool retval;

    const char* keywords[] = { "timeoutNs", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:AsyncArray.get", (char**)keywords, &pyobj_timeoutNs, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_timeoutNs, timeoutNs, ArgInfo("timeoutNs", 0)) )
    {
        ERRWRAP2(retval = _self_->get(dst, timeoutNs));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dst));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("get");

    return NULL;
}

static PyObject* pyopencv_cv_AsyncArray_release(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::AsyncArray> * self1 = 0;
    if (!pyopencv_AsyncArray_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'AsyncArray' or its derivative)");
    Ptr<cv::AsyncArray> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->release());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_AsyncArray_valid(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::AsyncArray> * self1 = 0;
    if (!pyopencv_AsyncArray_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'AsyncArray' or its derivative)");
    Ptr<cv::AsyncArray> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->valid());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_AsyncArray_wait_for(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::AsyncArray> * self1 = 0;
    if (!pyopencv_AsyncArray_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'AsyncArray' or its derivative)");
    Ptr<cv::AsyncArray> _self_ = *(self1);
    PyObject* pyobj_timeoutNs = NULL;
    double timeoutNs=0;
    bool retval;

    const char* keywords[] = { "timeoutNs", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:AsyncArray.wait_for", (char**)keywords, &pyobj_timeoutNs) &&
        pyopencv_to_safe(pyobj_timeoutNs, timeoutNs, ArgInfo("timeoutNs", 0)) )
    {
        ERRWRAP2(retval = _self_->wait_for(timeoutNs));
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (AsyncArray)

static PyGetSetDef pyopencv_AsyncArray_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_AsyncArray_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_AsyncArray
    PYOPENCV_EXTRA_METHODS_AsyncArray
#endif
    {"get", CV_PY_FN_WITH_KW_(pyopencv_cv_AsyncArray_get, 0), "get([, dst]) -> dst\n.   Fetch the result.\n.       @param[out] dst destination array\n.   \n.       Waits for result until container has valid result.\n.       Throws exception if exception was stored as a result.\n.   \n.       Throws exception on invalid container state.\n.   \n.       @note Result or stored exception can be fetched only once.\n\n\n\nget(timeoutNs[, dst]) -> retval, dst\n.   Retrieving the result with timeout\n.       @param[out] dst destination array\n.       @param[in] timeoutNs timeout in nanoseconds, -1 for infinite wait\n.   \n.       @returns true if result is ready, false if the timeout has expired\n.   \n.       @note Result or stored exception can be fetched only once."},
    {"release", CV_PY_FN_WITH_KW_(pyopencv_cv_AsyncArray_release, 0), "release() -> None\n."},
    {"valid", CV_PY_FN_WITH_KW_(pyopencv_cv_AsyncArray_valid, 0), "valid() -> retval\n."},
    {"wait_for", CV_PY_FN_WITH_KW_(pyopencv_cv_AsyncArray_wait_for, 0), "wait_for(timeoutNs) -> retval\n."},

    {NULL,          NULL}
};

// Converter (AsyncArray)

template<>
struct PyOpenCV_Converter< Ptr<cv::AsyncArray> >
{
    static PyObject* from(const Ptr<cv::AsyncArray>& r)
    {
        return pyopencv_AsyncArray_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::AsyncArray>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::AsyncArray> * dst_;
        if (pyopencv_AsyncArray_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::AsyncArray> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// CLAHE (Generic)
//================================================================================

// GetSet (CLAHE)



// Methods (CLAHE)

static PyObject* pyopencv_cv_CLAHE_apply(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "src", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:CLAHE.apply", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->apply(src, dst));
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:CLAHE.apply", (char**)keywords, &pyobj_src, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->apply(src, dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("apply");

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_collectGarbage(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->collectGarbage());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_getBitShift(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getBitShift());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_getClipLimit(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getClipLimit());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_getTilesGridSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    Size retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTilesGridSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_setBitShift(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    PyObject* pyobj_bitShift = NULL;
    int bitShift=0;

    const char* keywords[] = { "bitShift", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:CLAHE.setBitShift", (char**)keywords, &pyobj_bitShift) &&
        pyopencv_to_safe(pyobj_bitShift, bitShift, ArgInfo("bitShift", 0)) )
    {
        ERRWRAP2(_self_->setBitShift(bitShift));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_setClipLimit(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    PyObject* pyobj_clipLimit = NULL;
    double clipLimit=0;

    const char* keywords[] = { "clipLimit", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:CLAHE.setClipLimit", (char**)keywords, &pyobj_clipLimit) &&
        pyopencv_to_safe(pyobj_clipLimit, clipLimit, ArgInfo("clipLimit", 0)) )
    {
        ERRWRAP2(_self_->setClipLimit(clipLimit));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_CLAHE_setTilesGridSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::CLAHE> * self1 = 0;
    if (!pyopencv_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'CLAHE' or its derivative)");
    Ptr<cv::CLAHE> _self_ = *(self1);
    PyObject* pyobj_tileGridSize = NULL;
    Size tileGridSize;

    const char* keywords[] = { "tileGridSize", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:CLAHE.setTilesGridSize", (char**)keywords, &pyobj_tileGridSize) &&
        pyopencv_to_safe(pyobj_tileGridSize, tileGridSize, ArgInfo("tileGridSize", 0)) )
    {
        ERRWRAP2(_self_->setTilesGridSize(tileGridSize));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (CLAHE)

static PyGetSetDef pyopencv_CLAHE_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_CLAHE_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_CLAHE
    PYOPENCV_EXTRA_METHODS_CLAHE
#endif
    {"apply", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_apply, 0), "apply(src[, dst]) -> dst\n.   @brief Equalizes the histogram of a grayscale image using Contrast Limited Adaptive Histogram Equalization.\n.   \n.       @param src Source image of type CV_8UC1 or CV_16UC1.\n.       @param dst Destination image."},
    {"collectGarbage", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_collectGarbage, 0), "collectGarbage() -> None\n."},
    {"getBitShift", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_getBitShift, 0), "getBitShift() -> retval\n.   @brief Returns the bit shift parameter for histogram bins.\n.   \n.       @return current bit shift value."},
    {"getClipLimit", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_getClipLimit, 0), "getClipLimit() -> retval\n."},
    {"getTilesGridSize", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_getTilesGridSize, 0), "getTilesGridSize() -> retval\n."},
    {"setBitShift", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_setBitShift, 0), "setBitShift(bitShift) -> None\n.   @brief Sets bit shift parameter for histogram bins.\n.   \n.       @param bitShift bit shift value (default is 0)."},
    {"setClipLimit", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_setClipLimit, 0), "setClipLimit(clipLimit) -> None\n.   @brief Sets threshold for contrast limiting.\n.   \n.       @param clipLimit threshold value."},
    {"setTilesGridSize", CV_PY_FN_WITH_KW_(pyopencv_cv_CLAHE_setTilesGridSize, 0), "setTilesGridSize(tileGridSize) -> None\n.   @brief Sets size of grid for histogram equalization. Input image will be divided into\n.       equally sized rectangular tiles.\n.   \n.       @param tileGridSize defines the number of tiles in row and column."},

    {NULL,          NULL}
};

// Converter (CLAHE)

template<>
struct PyOpenCV_Converter< Ptr<cv::CLAHE> >
{
    static PyObject* from(const Ptr<cv::CLAHE>& r)
    {
        return pyopencv_CLAHE_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::CLAHE>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::CLAHE> * dst_;
        if (pyopencv_CLAHE_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::CLAHE> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// DMatch (Generic)
//================================================================================

// GetSet (DMatch)


static PyObject* pyopencv_DMatch_get_distance(pyopencv_DMatch_t* p, void *closure)
{
    return pyopencv_from(p->v.distance);
}

static int pyopencv_DMatch_set_distance(pyopencv_DMatch_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the distance attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.distance, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_DMatch_get_imgIdx(pyopencv_DMatch_t* p, void *closure)
{
    return pyopencv_from(p->v.imgIdx);
}

static int pyopencv_DMatch_set_imgIdx(pyopencv_DMatch_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the imgIdx attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.imgIdx, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_DMatch_get_queryIdx(pyopencv_DMatch_t* p, void *closure)
{
    return pyopencv_from(p->v.queryIdx);
}

static int pyopencv_DMatch_set_queryIdx(pyopencv_DMatch_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the queryIdx attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.queryIdx, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_DMatch_get_trainIdx(pyopencv_DMatch_t* p, void *closure)
{
    return pyopencv_from(p->v.trainIdx);
}

static int pyopencv_DMatch_set_trainIdx(pyopencv_DMatch_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the trainIdx attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.trainIdx, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (DMatch)

static int pyopencv_cv_DMatch_DMatch(pyopencv_DMatch_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(3);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::DMatch());
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj__queryIdx = NULL;
    int _queryIdx=0;
    PyObject* pyobj__trainIdx = NULL;
    int _trainIdx=0;
    PyObject* pyobj__distance = NULL;
    float _distance=0.f;

    const char* keywords[] = { "_queryIdx", "_trainIdx", "_distance", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:DMatch", (char**)keywords, &pyobj__queryIdx, &pyobj__trainIdx, &pyobj__distance) &&
        pyopencv_to_safe(pyobj__queryIdx, _queryIdx, ArgInfo("_queryIdx", 0)) &&
        pyopencv_to_safe(pyobj__trainIdx, _trainIdx, ArgInfo("_trainIdx", 0)) &&
        pyopencv_to_safe(pyobj__distance, _distance, ArgInfo("_distance", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::DMatch(_queryIdx, _trainIdx, _distance));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj__queryIdx = NULL;
    int _queryIdx=0;
    PyObject* pyobj__trainIdx = NULL;
    int _trainIdx=0;
    PyObject* pyobj__imgIdx = NULL;
    int _imgIdx=0;
    PyObject* pyobj__distance = NULL;
    float _distance=0.f;

    const char* keywords[] = { "_queryIdx", "_trainIdx", "_imgIdx", "_distance", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:DMatch", (char**)keywords, &pyobj__queryIdx, &pyobj__trainIdx, &pyobj__imgIdx, &pyobj__distance) &&
        pyopencv_to_safe(pyobj__queryIdx, _queryIdx, ArgInfo("_queryIdx", 0)) &&
        pyopencv_to_safe(pyobj__trainIdx, _trainIdx, ArgInfo("_trainIdx", 0)) &&
        pyopencv_to_safe(pyobj__imgIdx, _imgIdx, ArgInfo("_imgIdx", 0)) &&
        pyopencv_to_safe(pyobj__distance, _distance, ArgInfo("_distance", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::DMatch(_queryIdx, _trainIdx, _imgIdx, _distance));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("DMatch");

    return -1;
}



// Tables (DMatch)

static PyGetSetDef pyopencv_DMatch_getseters[] =
{
    {(char*)"distance", (getter)pyopencv_DMatch_get_distance, (setter)pyopencv_DMatch_set_distance, (char*)"distance", NULL},
    {(char*)"imgIdx", (getter)pyopencv_DMatch_get_imgIdx, (setter)pyopencv_DMatch_set_imgIdx, (char*)"imgIdx", NULL},
    {(char*)"queryIdx", (getter)pyopencv_DMatch_get_queryIdx, (setter)pyopencv_DMatch_set_queryIdx, (char*)"queryIdx", NULL},
    {(char*)"trainIdx", (getter)pyopencv_DMatch_get_trainIdx, (setter)pyopencv_DMatch_set_trainIdx, (char*)"trainIdx", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_DMatch_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_DMatch
    PYOPENCV_EXTRA_METHODS_DMatch
#endif

    {NULL,          NULL}
};

// Converter (DMatch)

template<>
struct PyOpenCV_Converter< cv::DMatch >
{
    static PyObject* from(const cv::DMatch& r)
    {
        return pyopencv_DMatch_Instance(r);
    }
    static bool to(PyObject* src, cv::DMatch& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::DMatch * dst_;
        if (pyopencv_DMatch_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::DMatch for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// FileNode (Generic)
//================================================================================

// GetSet (FileNode)



// Methods (FileNode)

static int pyopencv_cv_FileNode_FileNode(pyopencv_FileNode_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::FileNode());
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_FileNode_at(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    PyObject* pyobj_i = NULL;
    int i=0;
    FileNode retval;

    const char* keywords[] = { "i", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:FileNode.at", (char**)keywords, &pyobj_i) &&
        pyopencv_to_safe(pyobj_i, i, ArgInfo("i", 0)) )
    {
        ERRWRAP2(retval = _self_->operator[](i));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_empty(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->empty());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_getNode(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    char* nodename=(char*)"";
    FileNode retval;

    const char* keywords[] = { "nodename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "s:FileNode.getNode", (char**)keywords, &nodename) )
    {
        ERRWRAP2(retval = _self_->operator[](nodename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isInt(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isInt());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isMap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isMap());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isNamed(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isNamed());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isNone(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isNone());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isReal(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isReal());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isSeq(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isSeq());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_isString(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isString());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_keys(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    std::vector<String> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->keys());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_mat(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    Mat retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->mat());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_name(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    std::string retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->name());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_rawSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->rawSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_real(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->real());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_size(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->size());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_string(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    std::string retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->string());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileNode_type(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::FileNode * self1 = 0;
    if (!pyopencv_FileNode_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileNode' or its derivative)");
    cv::FileNode* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->type());
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (FileNode)

static PyGetSetDef pyopencv_FileNode_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_FileNode_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_FileNode
    PYOPENCV_EXTRA_METHODS_FileNode
#endif
    {"at", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_at, 0), "at(i) -> retval\n.   @overload\n.        @param i Index of an element in the sequence node."},
    {"empty", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_empty, 0), "empty() -> retval\n."},
    {"getNode", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_getNode, 0), "getNode(nodename) -> retval\n.   @overload\n.        @param nodename Name of an element in the mapping node."},
    {"isInt", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isInt, 0), "isInt() -> retval\n."},
    {"isMap", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isMap, 0), "isMap() -> retval\n."},
    {"isNamed", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isNamed, 0), "isNamed() -> retval\n."},
    {"isNone", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isNone, 0), "isNone() -> retval\n."},
    {"isReal", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isReal, 0), "isReal() -> retval\n."},
    {"isSeq", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isSeq, 0), "isSeq() -> retval\n."},
    {"isString", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_isString, 0), "isString() -> retval\n."},
    {"keys", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_keys, 0), "keys() -> retval\n.   @brief Returns keys of a mapping node.\n.        @returns Keys of a mapping node."},
    {"mat", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_mat, 0), "mat() -> retval\n."},
    {"name", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_name, 0), "name() -> retval\n."},
    {"rawSize", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_rawSize, 0), "rawSize() -> retval\n."},
    {"real", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_real, 0), "real() -> retval\n.   Internal method used when reading FileStorage.\n.        Sets the type (int, real or string) and value of the previously created node."},
    {"size", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_size, 0), "size() -> retval\n."},
    {"string", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_string, 0), "string() -> retval\n."},
    {"type", CV_PY_FN_WITH_KW_(pyopencv_cv_FileNode_type, 0), "type() -> retval\n.   @brief Returns type of the node.\n.        @returns Type of the node. See FileNode::Type"},

    {NULL,          NULL}
};

// Converter (FileNode)

template<>
struct PyOpenCV_Converter< cv::FileNode >
{
    static PyObject* from(const cv::FileNode& r)
    {
        return pyopencv_FileNode_Instance(r);
    }
    static bool to(PyObject* src, cv::FileNode& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::FileNode * dst_;
        if (pyopencv_FileNode_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::FileNode for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// FileStorage (Generic)
//================================================================================

// GetSet (FileStorage)



// Methods (FileStorage)

static int pyopencv_cv_FileStorage_FileStorage(pyopencv_FileStorage_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::FileStorage>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::FileStorage()));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_encoding = NULL;
    String encoding;

    const char* keywords[] = { "filename", "flags", "encoding", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:FileStorage", (char**)keywords, &pyobj_filename, &pyobj_flags, &pyobj_encoding) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_encoding, encoding, ArgInfo("encoding", 0)) )
    {
        new (&(self->v)) Ptr<cv::FileStorage>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::FileStorage(filename, flags, encoding)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("FileStorage");

    return -1;
}

static PyObject* pyopencv_cv_FileStorage_endWriteStruct(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->endWriteStruct());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_getFirstTopLevelNode(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    FileNode retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getFirstTopLevelNode());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_getFormat(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getFormat());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_getNode(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    char* nodename=(char*)"";
    FileNode retval;

    const char* keywords[] = { "nodename", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "s:FileStorage.getNode", (char**)keywords, &nodename) )
    {
        ERRWRAP2(retval = _self_->operator[](nodename));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_isOpened(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isOpened());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_open(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_encoding = NULL;
    String encoding;
    bool retval;

    const char* keywords[] = { "filename", "flags", "encoding", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:FileStorage.open", (char**)keywords, &pyobj_filename, &pyobj_flags, &pyobj_encoding) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_encoding, encoding, ArgInfo("encoding", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, flags, encoding));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_release(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->release());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_releaseAndGetString(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->releaseAndGetString());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_root(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    PyObject* pyobj_streamidx = NULL;
    int streamidx=0;
    FileNode retval;

    const char* keywords[] = { "streamidx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:FileStorage.root", (char**)keywords, &pyobj_streamidx) &&
        pyopencv_to_safe(pyobj_streamidx, streamidx, ArgInfo("streamidx", 0)) )
    {
        ERRWRAP2(retval = _self_->root(streamidx));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_startWriteStruct(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_flags = NULL;
    int flags=0;
    PyObject* pyobj_typeName = NULL;
    String typeName;

    const char* keywords[] = { "name", "flags", "typeName", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:FileStorage.startWriteStruct", (char**)keywords, &pyobj_name, &pyobj_flags, &pyobj_typeName) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) &&
        pyopencv_to_safe(pyobj_typeName, typeName, ArgInfo("typeName", 0)) )
    {
        ERRWRAP2(_self_->startWriteStruct(name, flags, typeName));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_write(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_val = NULL;
    int val=0;

    const char* keywords[] = { "name", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:FileStorage.write", (char**)keywords, &pyobj_name, &pyobj_val) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(_self_->write(name, val));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_val = NULL;
    int64_t val;

    const char* keywords[] = { "name", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:FileStorage.write", (char**)keywords, &pyobj_name, &pyobj_val) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(_self_->write(name, val));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_val = NULL;
    double val=0;

    const char* keywords[] = { "name", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:FileStorage.write", (char**)keywords, &pyobj_name, &pyobj_val) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(_self_->write(name, val));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_val = NULL;
    String val;

    const char* keywords[] = { "name", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:FileStorage.write", (char**)keywords, &pyobj_name, &pyobj_val) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(_self_->write(name, val));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_val = NULL;
    Mat val;

    const char* keywords[] = { "name", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:FileStorage.write", (char**)keywords, &pyobj_name, &pyobj_val) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(_self_->write(name, val));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_name = NULL;
    String name;
    PyObject* pyobj_val = NULL;
    vector_String val;

    const char* keywords[] = { "name", "val", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:FileStorage.write", (char**)keywords, &pyobj_name, &pyobj_val) &&
        pyopencv_to_safe(pyobj_name, name, ArgInfo("name", 0)) &&
        pyopencv_to_safe(pyobj_val, val, ArgInfo("val", 0)) )
    {
        ERRWRAP2(_self_->write(name, val));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("write");

    return NULL;
}

static PyObject* pyopencv_cv_FileStorage_writeComment(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::FileStorage> * self1 = 0;
    if (!pyopencv_FileStorage_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'FileStorage' or its derivative)");
    Ptr<cv::FileStorage> _self_ = *(self1);
    PyObject* pyobj_comment = NULL;
    String comment;
    PyObject* pyobj_append = NULL;
    bool append=false;

    const char* keywords[] = { "comment", "append", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:FileStorage.writeComment", (char**)keywords, &pyobj_comment, &pyobj_append) &&
        pyopencv_to_safe(pyobj_comment, comment, ArgInfo("comment", 0)) &&
        pyopencv_to_safe(pyobj_append, append, ArgInfo("append", 0)) )
    {
        ERRWRAP2(_self_->writeComment(comment, append));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (FileStorage)

static PyGetSetDef pyopencv_FileStorage_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_FileStorage_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_FileStorage
    PYOPENCV_EXTRA_METHODS_FileStorage
#endif
    {"endWriteStruct", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_endWriteStruct, 0), "endWriteStruct() -> None\n.   @brief Finishes writing nested structure (should pair startWriteStruct())"},
    {"getFirstTopLevelNode", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_getFirstTopLevelNode, 0), "getFirstTopLevelNode() -> retval\n.   @brief Returns the first element of the top-level mapping.\n.        @returns The first element of the top-level mapping."},
    {"getFormat", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_getFormat, 0), "getFormat() -> retval\n.   @brief Returns the current format.\n.        * @returns The current format, see FileStorage::Mode"},
    {"getNode", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_getNode, 0), "getNode(nodename) -> retval\n.   @overload"},
    {"isOpened", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_isOpened, 0), "isOpened() -> retval\n.   @brief Checks whether the file is opened.\n.   \n.        @returns true if the object is associated with the current file and false otherwise. It is a\n.        good practice to call this method after you tried to open a file."},
    {"open", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_open, 0), "open(filename, flags[, encoding]) -> retval\n.   @brief Opens a file.\n.   \n.        See description of parameters in FileStorage::FileStorage. The method calls FileStorage::release\n.        before opening the file.\n.        @param filename Name of the file to open or the text string to read the data from.\n.        Extension of the file (.xml, .yml/.yaml or .json) determines its format (XML, YAML or JSON\n.        respectively). Also you can append .gz to work with compressed files, for example myHugeMatrix.xml.gz. If both\n.        FileStorage::WRITE and FileStorage::MEMORY flags are specified, source is used just to specify\n.        the output file format (e.g. mydata.xml, .yml etc.). A file name can also contain parameters.\n.        You can use this format, \"*?base64\" (e.g. \"file.json?base64\" (case sensitive)), as an alternative to\n.        FileStorage::BASE64 flag.\n.        @param flags Mode of operation. One of FileStorage::Mode\n.        @param encoding Encoding of the file. Note that UTF-16 XML encoding is not supported currently and\n.        you should use 8-bit encoding instead of it."},
    {"release", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_release, 0), "release() -> None\n.   @brief Closes the file and releases all the memory buffers.\n.   \n.        Call this method after all I/O operations with the storage are finished."},
    {"releaseAndGetString", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_releaseAndGetString, 0), "releaseAndGetString() -> retval\n.   @brief Closes the file and releases all the memory buffers.\n.   \n.        Call this method after all I/O operations with the storage are finished. If the storage was\n.        opened for writing data and FileStorage::WRITE was specified"},
    {"root", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_root, 0), "root([, streamidx]) -> retval\n.   @brief Returns the top-level mapping\n.        @param streamidx Zero-based index of the stream. In most cases there is only one stream in the file.\n.        However, YAML supports multiple streams and so there can be several.\n.        @returns The top-level mapping."},
    {"startWriteStruct", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_startWriteStruct, 0), "startWriteStruct(name, flags[, typeName]) -> None\n.   @brief Starts to write a nested structure (sequence or a mapping).\n.       @param name name of the structure. When writing to sequences (a.k.a. \"arrays\"), pass an empty string.\n.       @param flags type of the structure (FileNode::MAP or FileNode::SEQ (both with optional FileNode::FLOW)).\n.       @param typeName optional name of the type you store. The effect of setting this depends on the storage format.\n.       I.e. if the format has a specification for storing type information, this parameter is used."},
    {"write", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_write, 0), "write(name, val) -> None\n.   * @brief Simplified writing API to use with bindings.\n.        * @param name Name of the written object. When writing to sequences (a.k.a. \"arrays\"), pass an empty string.\n.        * @param val Value of the written object."},
    {"writeComment", CV_PY_FN_WITH_KW_(pyopencv_cv_FileStorage_writeComment, 0), "writeComment(comment[, append]) -> None\n.   @brief Writes a comment.\n.   \n.        The function writes a comment into file storage. The comments are skipped when the storage is read.\n.        @param comment The written comment, single-line or multi-line\n.        @param append If true, the function tries to put the comment at the end of current line.\n.        Else if the comment is multi-line, or if it does not fit at the end of the current\n.        line, the comment starts a new line."},

    {NULL,          NULL}
};

// Converter (FileStorage)

template<>
struct PyOpenCV_Converter< Ptr<cv::FileStorage> >
{
    static PyObject* from(const Ptr<cv::FileStorage>& r)
    {
        return pyopencv_FileStorage_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::FileStorage>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::FileStorage> * dst_;
        if (pyopencv_FileStorage_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::FileStorage> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// GeneralizedHough (Generic)
//================================================================================

// GetSet (GeneralizedHough)



// Methods (GeneralizedHough)

static PyObject* pyopencv_cv_GeneralizedHough_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_positions = NULL;
    Mat positions;
    PyObject* pyobj_votes = NULL;
    Mat votes;

    const char* keywords[] = { "image", "positions", "votes", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:GeneralizedHough.detect", (char**)keywords, &pyobj_image, &pyobj_positions, &pyobj_votes) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_positions, positions, ArgInfo("positions", 1)) &&
        pyopencv_to_safe(pyobj_votes, votes, ArgInfo("votes", 1)) )
    {
        ERRWRAP2(_self_->detect(image, positions, votes));
        return Py_BuildValue("(NN)", pyopencv_from(positions), pyopencv_from(votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_dx = NULL;
    Mat dx;
    PyObject* pyobj_dy = NULL;
    Mat dy;
    PyObject* pyobj_positions = NULL;
    Mat positions;
    PyObject* pyobj_votes = NULL;
    Mat votes;

    const char* keywords[] = { "edges", "dx", "dy", "positions", "votes", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:GeneralizedHough.detect", (char**)keywords, &pyobj_edges, &pyobj_dx, &pyobj_dy, &pyobj_positions, &pyobj_votes) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_positions, positions, ArgInfo("positions", 1)) &&
        pyopencv_to_safe(pyobj_votes, votes, ArgInfo("votes", 1)) )
    {
        ERRWRAP2(_self_->detect(edges, dx, dy, positions, votes));
        return Py_BuildValue("(NN)", pyopencv_from(positions), pyopencv_from(votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_positions = NULL;
    UMat positions;
    PyObject* pyobj_votes = NULL;
    UMat votes;

    const char* keywords[] = { "image", "positions", "votes", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:GeneralizedHough.detect", (char**)keywords, &pyobj_image, &pyobj_positions, &pyobj_votes) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_positions, positions, ArgInfo("positions", 1)) &&
        pyopencv_to_safe(pyobj_votes, votes, ArgInfo("votes", 1)) )
    {
        ERRWRAP2(_self_->detect(image, positions, votes));
        return Py_BuildValue("(NN)", pyopencv_from(positions), pyopencv_from(votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_dx = NULL;
    UMat dx;
    PyObject* pyobj_dy = NULL;
    UMat dy;
    PyObject* pyobj_positions = NULL;
    UMat positions;
    PyObject* pyobj_votes = NULL;
    UMat votes;

    const char* keywords[] = { "edges", "dx", "dy", "positions", "votes", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OO:GeneralizedHough.detect", (char**)keywords, &pyobj_edges, &pyobj_dx, &pyobj_dy, &pyobj_positions, &pyobj_votes) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_positions, positions, ArgInfo("positions", 1)) &&
        pyopencv_to_safe(pyobj_votes, votes, ArgInfo("votes", 1)) )
    {
        ERRWRAP2(_self_->detect(edges, dx, dy, positions, votes));
        return Py_BuildValue("(NN)", pyopencv_from(positions), pyopencv_from(votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_getCannyHighThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getCannyHighThresh());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_getCannyLowThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getCannyLowThresh());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_getDp(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getDp());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_getMaxBufferSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxBufferSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_getMinDist(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMinDist());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_setCannyHighThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    PyObject* pyobj_cannyHighThresh = NULL;
    int cannyHighThresh=0;

    const char* keywords[] = { "cannyHighThresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHough.setCannyHighThresh", (char**)keywords, &pyobj_cannyHighThresh) &&
        pyopencv_to_safe(pyobj_cannyHighThresh, cannyHighThresh, ArgInfo("cannyHighThresh", 0)) )
    {
        ERRWRAP2(_self_->setCannyHighThresh(cannyHighThresh));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_setCannyLowThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    PyObject* pyobj_cannyLowThresh = NULL;
    int cannyLowThresh=0;

    const char* keywords[] = { "cannyLowThresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHough.setCannyLowThresh", (char**)keywords, &pyobj_cannyLowThresh) &&
        pyopencv_to_safe(pyobj_cannyLowThresh, cannyLowThresh, ArgInfo("cannyLowThresh", 0)) )
    {
        ERRWRAP2(_self_->setCannyLowThresh(cannyLowThresh));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_setDp(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    PyObject* pyobj_dp = NULL;
    double dp=0;

    const char* keywords[] = { "dp", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHough.setDp", (char**)keywords, &pyobj_dp) &&
        pyopencv_to_safe(pyobj_dp, dp, ArgInfo("dp", 0)) )
    {
        ERRWRAP2(_self_->setDp(dp));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_setMaxBufferSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    PyObject* pyobj_maxBufferSize = NULL;
    int maxBufferSize=0;

    const char* keywords[] = { "maxBufferSize", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHough.setMaxBufferSize", (char**)keywords, &pyobj_maxBufferSize) &&
        pyopencv_to_safe(pyobj_maxBufferSize, maxBufferSize, ArgInfo("maxBufferSize", 0)) )
    {
        ERRWRAP2(_self_->setMaxBufferSize(maxBufferSize));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_setMinDist(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    PyObject* pyobj_minDist = NULL;
    double minDist=0;

    const char* keywords[] = { "minDist", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHough.setMinDist", (char**)keywords, &pyobj_minDist) &&
        pyopencv_to_safe(pyobj_minDist, minDist, ArgInfo("minDist", 0)) )
    {
        ERRWRAP2(_self_->setMinDist(minDist));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHough_setTemplate(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHough> * self1 = 0;
    if (!pyopencv_GeneralizedHough_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHough' or its derivative)");
    Ptr<cv::GeneralizedHough> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_templ = NULL;
    Mat templ;
    PyObject* pyobj_templCenter = NULL;
    Point templCenter=Point(-1, -1);

    const char* keywords[] = { "templ", "templCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:GeneralizedHough.setTemplate", (char**)keywords, &pyobj_templ, &pyobj_templCenter) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_templCenter, templCenter, ArgInfo("templCenter", 0)) )
    {
        ERRWRAP2(_self_->setTemplate(templ, templCenter));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_dx = NULL;
    Mat dx;
    PyObject* pyobj_dy = NULL;
    Mat dy;
    PyObject* pyobj_templCenter = NULL;
    Point templCenter=Point(-1, -1);

    const char* keywords[] = { "edges", "dx", "dy", "templCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:GeneralizedHough.setTemplate", (char**)keywords, &pyobj_edges, &pyobj_dx, &pyobj_dy, &pyobj_templCenter) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_templCenter, templCenter, ArgInfo("templCenter", 0)) )
    {
        ERRWRAP2(_self_->setTemplate(edges, dx, dy, templCenter));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_templ = NULL;
    UMat templ;
    PyObject* pyobj_templCenter = NULL;
    Point templCenter=Point(-1, -1);

    const char* keywords[] = { "templ", "templCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:GeneralizedHough.setTemplate", (char**)keywords, &pyobj_templ, &pyobj_templCenter) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_templCenter, templCenter, ArgInfo("templCenter", 0)) )
    {
        ERRWRAP2(_self_->setTemplate(templ, templCenter));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_dx = NULL;
    UMat dx;
    PyObject* pyobj_dy = NULL;
    UMat dy;
    PyObject* pyobj_templCenter = NULL;
    Point templCenter=Point(-1, -1);

    const char* keywords[] = { "edges", "dx", "dy", "templCenter", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:GeneralizedHough.setTemplate", (char**)keywords, &pyobj_edges, &pyobj_dx, &pyobj_dy, &pyobj_templCenter) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 0)) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_templCenter, templCenter, ArgInfo("templCenter", 0)) )
    {
        ERRWRAP2(_self_->setTemplate(edges, dx, dy, templCenter));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("setTemplate");

    return NULL;
}



// Tables (GeneralizedHough)

static PyGetSetDef pyopencv_GeneralizedHough_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_GeneralizedHough_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_GeneralizedHough
    PYOPENCV_EXTRA_METHODS_GeneralizedHough
#endif
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_detect, 0), "detect(image[, positions[, votes]]) -> positions, votes\n.   \n\n\n\ndetect(edges, dx, dy[, positions[, votes]]) -> positions, votes\n."},
    {"getCannyHighThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_getCannyHighThresh, 0), "getCannyHighThresh() -> retval\n."},
    {"getCannyLowThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_getCannyLowThresh, 0), "getCannyLowThresh() -> retval\n."},
    {"getDp", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_getDp, 0), "getDp() -> retval\n."},
    {"getMaxBufferSize", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_getMaxBufferSize, 0), "getMaxBufferSize() -> retval\n."},
    {"getMinDist", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_getMinDist, 0), "getMinDist() -> retval\n."},
    {"setCannyHighThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_setCannyHighThresh, 0), "setCannyHighThresh(cannyHighThresh) -> None\n."},
    {"setCannyLowThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_setCannyLowThresh, 0), "setCannyLowThresh(cannyLowThresh) -> None\n."},
    {"setDp", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_setDp, 0), "setDp(dp) -> None\n."},
    {"setMaxBufferSize", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_setMaxBufferSize, 0), "setMaxBufferSize(maxBufferSize) -> None\n."},
    {"setMinDist", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_setMinDist, 0), "setMinDist(minDist) -> None\n."},
    {"setTemplate", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHough_setTemplate, 0), "setTemplate(templ[, templCenter]) -> None\n.   \n\n\n\nsetTemplate(edges, dx, dy[, templCenter]) -> None\n."},

    {NULL,          NULL}
};

// Converter (GeneralizedHough)

template<>
struct PyOpenCV_Converter< Ptr<cv::GeneralizedHough> >
{
    static PyObject* from(const Ptr<cv::GeneralizedHough>& r)
    {
        return pyopencv_GeneralizedHough_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::GeneralizedHough>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::GeneralizedHough> * dst_;
        if (pyopencv_GeneralizedHough_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::GeneralizedHough> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// GeneralizedHoughBallard (Generic)
//================================================================================

// GetSet (GeneralizedHoughBallard)



// Methods (GeneralizedHoughBallard)

static PyObject* pyopencv_cv_GeneralizedHoughBallard_getLevels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughBallard> * self1 = 0;
    if (!pyopencv_GeneralizedHoughBallard_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughBallard' or its derivative)");
    Ptr<cv::GeneralizedHoughBallard> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLevels());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughBallard_getVotesThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughBallard> * self1 = 0;
    if (!pyopencv_GeneralizedHoughBallard_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughBallard' or its derivative)");
    Ptr<cv::GeneralizedHoughBallard> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getVotesThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughBallard_setLevels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughBallard> * self1 = 0;
    if (!pyopencv_GeneralizedHoughBallard_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughBallard' or its derivative)");
    Ptr<cv::GeneralizedHoughBallard> _self_ = *(self1);
    PyObject* pyobj_levels = NULL;
    int levels=0;

    const char* keywords[] = { "levels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughBallard.setLevels", (char**)keywords, &pyobj_levels) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) )
    {
        ERRWRAP2(_self_->setLevels(levels));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughBallard_setVotesThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughBallard> * self1 = 0;
    if (!pyopencv_GeneralizedHoughBallard_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughBallard' or its derivative)");
    Ptr<cv::GeneralizedHoughBallard> _self_ = *(self1);
    PyObject* pyobj_votesThreshold = NULL;
    int votesThreshold=0;

    const char* keywords[] = { "votesThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughBallard.setVotesThreshold", (char**)keywords, &pyobj_votesThreshold) &&
        pyopencv_to_safe(pyobj_votesThreshold, votesThreshold, ArgInfo("votesThreshold", 0)) )
    {
        ERRWRAP2(_self_->setVotesThreshold(votesThreshold));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (GeneralizedHoughBallard)

static PyGetSetDef pyopencv_GeneralizedHoughBallard_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_GeneralizedHoughBallard_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_GeneralizedHoughBallard
    PYOPENCV_EXTRA_METHODS_GeneralizedHoughBallard
#endif
    {"getLevels", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughBallard_getLevels, 0), "getLevels() -> retval\n."},
    {"getVotesThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughBallard_getVotesThreshold, 0), "getVotesThreshold() -> retval\n."},
    {"setLevels", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughBallard_setLevels, 0), "setLevels(levels) -> None\n."},
    {"setVotesThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughBallard_setVotesThreshold, 0), "setVotesThreshold(votesThreshold) -> None\n."},

    {NULL,          NULL}
};

// Converter (GeneralizedHoughBallard)

template<>
struct PyOpenCV_Converter< Ptr<cv::GeneralizedHoughBallard> >
{
    static PyObject* from(const Ptr<cv::GeneralizedHoughBallard>& r)
    {
        return pyopencv_GeneralizedHoughBallard_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::GeneralizedHoughBallard>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::GeneralizedHoughBallard> * dst_;
        if (pyopencv_GeneralizedHoughBallard_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::GeneralizedHoughBallard> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// GeneralizedHoughGuil (Generic)
//================================================================================

// GetSet (GeneralizedHoughGuil)



// Methods (GeneralizedHoughGuil)

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getAngleEpsilon(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAngleEpsilon());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getAngleStep(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAngleStep());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getAngleThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAngleThresh());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getLevels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLevels());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getMaxAngle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxAngle());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getMaxScale(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxScale());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getMinAngle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMinAngle());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getMinScale(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMinScale());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getPosThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getPosThresh());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getScaleStep(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getScaleStep());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getScaleThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getScaleThresh());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_getXi(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getXi());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setAngleEpsilon(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_angleEpsilon = NULL;
    double angleEpsilon=0;

    const char* keywords[] = { "angleEpsilon", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setAngleEpsilon", (char**)keywords, &pyobj_angleEpsilon) &&
        pyopencv_to_safe(pyobj_angleEpsilon, angleEpsilon, ArgInfo("angleEpsilon", 0)) )
    {
        ERRWRAP2(_self_->setAngleEpsilon(angleEpsilon));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setAngleStep(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_angleStep = NULL;
    double angleStep=0;

    const char* keywords[] = { "angleStep", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setAngleStep", (char**)keywords, &pyobj_angleStep) &&
        pyopencv_to_safe(pyobj_angleStep, angleStep, ArgInfo("angleStep", 0)) )
    {
        ERRWRAP2(_self_->setAngleStep(angleStep));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setAngleThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_angleThresh = NULL;
    int angleThresh=0;

    const char* keywords[] = { "angleThresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setAngleThresh", (char**)keywords, &pyobj_angleThresh) &&
        pyopencv_to_safe(pyobj_angleThresh, angleThresh, ArgInfo("angleThresh", 0)) )
    {
        ERRWRAP2(_self_->setAngleThresh(angleThresh));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setLevels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_levels = NULL;
    int levels=0;

    const char* keywords[] = { "levels", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setLevels", (char**)keywords, &pyobj_levels) &&
        pyopencv_to_safe(pyobj_levels, levels, ArgInfo("levels", 0)) )
    {
        ERRWRAP2(_self_->setLevels(levels));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setMaxAngle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_maxAngle = NULL;
    double maxAngle=0;

    const char* keywords[] = { "maxAngle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setMaxAngle", (char**)keywords, &pyobj_maxAngle) &&
        pyopencv_to_safe(pyobj_maxAngle, maxAngle, ArgInfo("maxAngle", 0)) )
    {
        ERRWRAP2(_self_->setMaxAngle(maxAngle));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setMaxScale(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_maxScale = NULL;
    double maxScale=0;

    const char* keywords[] = { "maxScale", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setMaxScale", (char**)keywords, &pyobj_maxScale) &&
        pyopencv_to_safe(pyobj_maxScale, maxScale, ArgInfo("maxScale", 0)) )
    {
        ERRWRAP2(_self_->setMaxScale(maxScale));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setMinAngle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_minAngle = NULL;
    double minAngle=0;

    const char* keywords[] = { "minAngle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setMinAngle", (char**)keywords, &pyobj_minAngle) &&
        pyopencv_to_safe(pyobj_minAngle, minAngle, ArgInfo("minAngle", 0)) )
    {
        ERRWRAP2(_self_->setMinAngle(minAngle));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setMinScale(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_minScale = NULL;
    double minScale=0;

    const char* keywords[] = { "minScale", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setMinScale", (char**)keywords, &pyobj_minScale) &&
        pyopencv_to_safe(pyobj_minScale, minScale, ArgInfo("minScale", 0)) )
    {
        ERRWRAP2(_self_->setMinScale(minScale));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setPosThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_posThresh = NULL;
    int posThresh=0;

    const char* keywords[] = { "posThresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setPosThresh", (char**)keywords, &pyobj_posThresh) &&
        pyopencv_to_safe(pyobj_posThresh, posThresh, ArgInfo("posThresh", 0)) )
    {
        ERRWRAP2(_self_->setPosThresh(posThresh));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setScaleStep(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_scaleStep = NULL;
    double scaleStep=0;

    const char* keywords[] = { "scaleStep", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setScaleStep", (char**)keywords, &pyobj_scaleStep) &&
        pyopencv_to_safe(pyobj_scaleStep, scaleStep, ArgInfo("scaleStep", 0)) )
    {
        ERRWRAP2(_self_->setScaleStep(scaleStep));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setScaleThresh(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_scaleThresh = NULL;
    int scaleThresh=0;

    const char* keywords[] = { "scaleThresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setScaleThresh", (char**)keywords, &pyobj_scaleThresh) &&
        pyopencv_to_safe(pyobj_scaleThresh, scaleThresh, ArgInfo("scaleThresh", 0)) )
    {
        ERRWRAP2(_self_->setScaleThresh(scaleThresh));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_GeneralizedHoughGuil_setXi(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::GeneralizedHoughGuil> * self1 = 0;
    if (!pyopencv_GeneralizedHoughGuil_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'GeneralizedHoughGuil' or its derivative)");
    Ptr<cv::GeneralizedHoughGuil> _self_ = *(self1);
    PyObject* pyobj_xi = NULL;
    double xi=0;

    const char* keywords[] = { "xi", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GeneralizedHoughGuil.setXi", (char**)keywords, &pyobj_xi) &&
        pyopencv_to_safe(pyobj_xi, xi, ArgInfo("xi", 0)) )
    {
        ERRWRAP2(_self_->setXi(xi));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (GeneralizedHoughGuil)

static PyGetSetDef pyopencv_GeneralizedHoughGuil_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_GeneralizedHoughGuil_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_GeneralizedHoughGuil
    PYOPENCV_EXTRA_METHODS_GeneralizedHoughGuil
#endif
    {"getAngleEpsilon", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getAngleEpsilon, 0), "getAngleEpsilon() -> retval\n."},
    {"getAngleStep", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getAngleStep, 0), "getAngleStep() -> retval\n."},
    {"getAngleThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getAngleThresh, 0), "getAngleThresh() -> retval\n."},
    {"getLevels", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getLevels, 0), "getLevels() -> retval\n."},
    {"getMaxAngle", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getMaxAngle, 0), "getMaxAngle() -> retval\n."},
    {"getMaxScale", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getMaxScale, 0), "getMaxScale() -> retval\n."},
    {"getMinAngle", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getMinAngle, 0), "getMinAngle() -> retval\n."},
    {"getMinScale", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getMinScale, 0), "getMinScale() -> retval\n."},
    {"getPosThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getPosThresh, 0), "getPosThresh() -> retval\n."},
    {"getScaleStep", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getScaleStep, 0), "getScaleStep() -> retval\n."},
    {"getScaleThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getScaleThresh, 0), "getScaleThresh() -> retval\n."},
    {"getXi", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_getXi, 0), "getXi() -> retval\n."},
    {"setAngleEpsilon", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setAngleEpsilon, 0), "setAngleEpsilon(angleEpsilon) -> None\n."},
    {"setAngleStep", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setAngleStep, 0), "setAngleStep(angleStep) -> None\n."},
    {"setAngleThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setAngleThresh, 0), "setAngleThresh(angleThresh) -> None\n."},
    {"setLevels", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setLevels, 0), "setLevels(levels) -> None\n."},
    {"setMaxAngle", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setMaxAngle, 0), "setMaxAngle(maxAngle) -> None\n."},
    {"setMaxScale", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setMaxScale, 0), "setMaxScale(maxScale) -> None\n."},
    {"setMinAngle", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setMinAngle, 0), "setMinAngle(minAngle) -> None\n."},
    {"setMinScale", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setMinScale, 0), "setMinScale(minScale) -> None\n."},
    {"setPosThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setPosThresh, 0), "setPosThresh(posThresh) -> None\n."},
    {"setScaleStep", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setScaleStep, 0), "setScaleStep(scaleStep) -> None\n."},
    {"setScaleThresh", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setScaleThresh, 0), "setScaleThresh(scaleThresh) -> None\n."},
    {"setXi", CV_PY_FN_WITH_KW_(pyopencv_cv_GeneralizedHoughGuil_setXi, 0), "setXi(xi) -> None\n."},

    {NULL,          NULL}
};

// Converter (GeneralizedHoughGuil)

template<>
struct PyOpenCV_Converter< Ptr<cv::GeneralizedHoughGuil> >
{
    static PyObject* from(const Ptr<cv::GeneralizedHoughGuil>& r)
    {
        return pyopencv_GeneralizedHoughGuil_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::GeneralizedHoughGuil>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::GeneralizedHoughGuil> * dst_;
        if (pyopencv_GeneralizedHoughGuil_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::GeneralizedHoughGuil> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// IStreamReader (Generic)
//================================================================================

// GetSet (IStreamReader)



// Methods (IStreamReader)

static PyObject* pyopencv_cv_IStreamReader_read(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::IStreamReader> * self1 = 0;
    if (!pyopencv_IStreamReader_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'IStreamReader' or its derivative)");
    Ptr<cv::IStreamReader> _self_ = *(self1);
    char* buffer=(char*)"";
    PyObject* pyobj_size = NULL;
    long long size;
    long long retval;

    const char* keywords[] = { "buffer", "size", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "sO:IStreamReader.read", (char**)keywords, &buffer, &pyobj_size) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) )
    {
        ERRWRAP2(retval = _self_->read(buffer, size));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_IStreamReader_seek(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::IStreamReader> * self1 = 0;
    if (!pyopencv_IStreamReader_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'IStreamReader' or its derivative)");
    Ptr<cv::IStreamReader> _self_ = *(self1);
    PyObject* pyobj_offset = NULL;
    long long offset;
    PyObject* pyobj_origin = NULL;
    int origin=0;
    long long retval;

    const char* keywords[] = { "offset", "origin", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:IStreamReader.seek", (char**)keywords, &pyobj_offset, &pyobj_origin) &&
        pyopencv_to_safe(pyobj_offset, offset, ArgInfo("offset", 0)) &&
        pyopencv_to_safe(pyobj_origin, origin, ArgInfo("origin", 0)) )
    {
        ERRWRAP2(retval = _self_->seek(offset, origin));
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (IStreamReader)

static PyGetSetDef pyopencv_IStreamReader_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_IStreamReader_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_IStreamReader
    PYOPENCV_EXTRA_METHODS_IStreamReader
#endif
    {"read", CV_PY_FN_WITH_KW_(pyopencv_cv_IStreamReader_read, 0), "read(buffer, size) -> retval\n.   @brief Read bytes from stream\n.        *\n.        * @param buffer already allocated buffer of at least @p size bytes\n.        * @param size maximum number of bytes to read\n.        *\n.        * @return actual number of read bytes"},
    {"seek", CV_PY_FN_WITH_KW_(pyopencv_cv_IStreamReader_seek, 0), "seek(offset, origin) -> retval\n.   @brief Sets the stream position\n.        *\n.        * @param offset Seek offset\n.        * @param origin SEEK_SET / SEEK_END / SEEK_CUR\n.        *\n.        * @see fseek"},

    {NULL,          NULL}
};

// Converter (IStreamReader)

template<>
struct PyOpenCV_Converter< Ptr<cv::IStreamReader> >
{
    static PyObject* from(const Ptr<cv::IStreamReader>& r)
    {
        return pyopencv_IStreamReader_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::IStreamReader>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::IStreamReader> * dst_;
        if (pyopencv_IStreamReader_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::IStreamReader> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// KeyPoint (Generic)
//================================================================================

// GetSet (KeyPoint)


static PyObject* pyopencv_KeyPoint_get_angle(pyopencv_KeyPoint_t* p, void *closure)
{
    return pyopencv_from(p->v.angle);
}

static int pyopencv_KeyPoint_set_angle(pyopencv_KeyPoint_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the angle attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.angle, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_KeyPoint_get_class_id(pyopencv_KeyPoint_t* p, void *closure)
{
    return pyopencv_from(p->v.class_id);
}

static int pyopencv_KeyPoint_set_class_id(pyopencv_KeyPoint_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the class_id attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.class_id, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_KeyPoint_get_octave(pyopencv_KeyPoint_t* p, void *closure)
{
    return pyopencv_from(p->v.octave);
}

static int pyopencv_KeyPoint_set_octave(pyopencv_KeyPoint_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the octave attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.octave, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_KeyPoint_get_pt(pyopencv_KeyPoint_t* p, void *closure)
{
    return pyopencv_from(p->v.pt);
}

static int pyopencv_KeyPoint_set_pt(pyopencv_KeyPoint_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the pt attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.pt, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_KeyPoint_get_response(pyopencv_KeyPoint_t* p, void *closure)
{
    return pyopencv_from(p->v.response);
}

static int pyopencv_KeyPoint_set_response(pyopencv_KeyPoint_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the response attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.response, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_KeyPoint_get_size(pyopencv_KeyPoint_t* p, void *closure)
{
    return pyopencv_from(p->v.size);
}

static int pyopencv_KeyPoint_set_size(pyopencv_KeyPoint_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the size attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.size, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (KeyPoint)

static int pyopencv_cv_KeyPoint_KeyPoint(pyopencv_KeyPoint_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(2);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::KeyPoint());
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_x = NULL;
    float x=0.f;
    PyObject* pyobj_y = NULL;
    float y=0.f;
    PyObject* pyobj_size = NULL;
    float size=0.f;
    PyObject* pyobj_angle = NULL;
    float angle=-1;
    PyObject* pyobj_response = NULL;
    float response=0;
    PyObject* pyobj_octave = NULL;
    int octave=0;
    PyObject* pyobj_class_id = NULL;
    int class_id=-1;

    const char* keywords[] = { "x", "y", "size", "angle", "response", "octave", "class_id", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|OOOO:KeyPoint", (char**)keywords, &pyobj_x, &pyobj_y, &pyobj_size, &pyobj_angle, &pyobj_response, &pyobj_octave, &pyobj_class_id) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) &&
        pyopencv_to_safe(pyobj_response, response, ArgInfo("response", 0)) &&
        pyopencv_to_safe(pyobj_octave, octave, ArgInfo("octave", 0)) &&
        pyopencv_to_safe(pyobj_class_id, class_id, ArgInfo("class_id", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::KeyPoint(x, y, size, angle, response, octave, class_id));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("KeyPoint");

    return -1;
}

static PyObject* pyopencv_cv_KeyPoint_convert_static(PyObject* self, PyObject* py_args, PyObject* kw)
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:KeyPoint.convert", (char**)keywords, &pyobj_keypoints, &pyobj_keypointIndexes) &&
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:KeyPoint.convert", (char**)keywords, &pyobj_points2f, &pyobj_size, &pyobj_response, &pyobj_octave, &pyobj_class_id) &&
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
    pyRaiseCVOverloadException("convert");

    return NULL;
}

static PyObject* pyopencv_cv_KeyPoint_overlap_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_kp1 = NULL;
    cv::KeyPoint kp1;
    PyObject* pyobj_kp2 = NULL;
    cv::KeyPoint kp2;
    float retval;

    const char* keywords[] = { "kp1", "kp2", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:KeyPoint.overlap", (char**)keywords, &pyobj_kp1, &pyobj_kp2) &&
        pyopencv_to_safe(pyobj_kp1, kp1, ArgInfo("kp1", 0)) &&
        pyopencv_to_safe(pyobj_kp2, kp2, ArgInfo("kp2", 0)) )
    {
        ERRWRAP2(retval = cv::KeyPoint::overlap(kp1, kp2));
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (KeyPoint)

static PyGetSetDef pyopencv_KeyPoint_getseters[] =
{
    {(char*)"angle", (getter)pyopencv_KeyPoint_get_angle, (setter)pyopencv_KeyPoint_set_angle, (char*)"angle", NULL},
    {(char*)"class_id", (getter)pyopencv_KeyPoint_get_class_id, (setter)pyopencv_KeyPoint_set_class_id, (char*)"class_id", NULL},
    {(char*)"octave", (getter)pyopencv_KeyPoint_get_octave, (setter)pyopencv_KeyPoint_set_octave, (char*)"octave", NULL},
    {(char*)"pt", (getter)pyopencv_KeyPoint_get_pt, (setter)pyopencv_KeyPoint_set_pt, (char*)"pt", NULL},
    {(char*)"response", (getter)pyopencv_KeyPoint_get_response, (setter)pyopencv_KeyPoint_set_response, (char*)"response", NULL},
    {(char*)"size", (getter)pyopencv_KeyPoint_get_size, (setter)pyopencv_KeyPoint_set_size, (char*)"size", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_KeyPoint_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_KeyPoint
    PYOPENCV_EXTRA_METHODS_KeyPoint
#endif
    {"convert", CV_PY_FN_WITH_KW_(pyopencv_cv_KeyPoint_convert_static, METH_STATIC), "convert(keypoints[, keypointIndexes]) -> points2f\n.   This method converts vector of keypoints to vector of points or the reverse, where each keypoint is\n.       assigned the same size and the same orientation.\n.   \n.       @param keypoints Keypoints obtained from any feature detection algorithm like SIFT/SURF/ORB\n.       @param points2f Array of (x,y) coordinates of each keypoint\n.       @param keypointIndexes Array of indexes of keypoints to be converted to points. (Acts like a mask to\n.       convert only specified keypoints)\n\n\n\nconvert(points2f[, size[, response[, octave[, class_id]]]]) -> keypoints\n.   @overload\n.       @param points2f Array of (x,y) coordinates of each keypoint\n.       @param keypoints Keypoints obtained from any feature detection algorithm like SIFT/SURF/ORB\n.       @param size keypoint diameter\n.       @param response keypoint detector response on the keypoint (that is, strength of the keypoint)\n.       @param octave pyramid octave in which the keypoint has been detected\n.       @param class_id object id"},
    {"overlap", CV_PY_FN_WITH_KW_(pyopencv_cv_KeyPoint_overlap_static, METH_STATIC), "overlap(kp1, kp2) -> retval\n.   This method computes overlap for pair of keypoints. Overlap is the ratio between area of keypoint\n.       regions' intersection and area of keypoint regions' union (considering keypoint region as circle).\n.       If they don't overlap, we get zero. If they coincide at same location with same size, we get 1.\n.       @param kp1 First keypoint\n.       @param kp2 Second keypoint"},

    {NULL,          NULL}
};

// Converter (KeyPoint)

template<>
struct PyOpenCV_Converter< cv::KeyPoint >
{
    static PyObject* from(const cv::KeyPoint& r)
    {
        return pyopencv_KeyPoint_Instance(r);
    }
    static bool to(PyObject* src, cv::KeyPoint& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::KeyPoint * dst_;
        if (pyopencv_KeyPoint_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::KeyPoint for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// LineSegmentDetector (Generic)
//================================================================================

// GetSet (LineSegmentDetector)



// Methods (LineSegmentDetector)

static PyObject* pyopencv_cv_LineSegmentDetector_compareSegments(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::LineSegmentDetector> * self1 = 0;
    if (!pyopencv_LineSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'LineSegmentDetector' or its derivative)");
    Ptr<cv::LineSegmentDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_lines1 = NULL;
    Mat lines1;
    PyObject* pyobj_lines2 = NULL;
    Mat lines2;
    PyObject* pyobj_image = NULL;
    Mat image;
    int retval;

    const char* keywords[] = { "size", "lines1", "lines2", "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:LineSegmentDetector.compareSegments", (char**)keywords, &pyobj_size, &pyobj_lines1, &pyobj_lines2, &pyobj_image) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_lines1, lines1, ArgInfo("lines1", 0)) &&
        pyopencv_to_safe(pyobj_lines2, lines2, ArgInfo("lines2", 0)) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) )
    {
        ERRWRAP2(retval = _self_->compareSegments(size, lines1, lines2, image));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(image));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_lines1 = NULL;
    UMat lines1;
    PyObject* pyobj_lines2 = NULL;
    UMat lines2;
    PyObject* pyobj_image = NULL;
    UMat image;
    int retval;

    const char* keywords[] = { "size", "lines1", "lines2", "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:LineSegmentDetector.compareSegments", (char**)keywords, &pyobj_size, &pyobj_lines1, &pyobj_lines2, &pyobj_image) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_lines1, lines1, ArgInfo("lines1", 0)) &&
        pyopencv_to_safe(pyobj_lines2, lines2, ArgInfo("lines2", 0)) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) )
    {
        ERRWRAP2(retval = _self_->compareSegments(size, lines1, lines2, image));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(image));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("compareSegments");

    return NULL;
}

static PyObject* pyopencv_cv_LineSegmentDetector_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::LineSegmentDetector> * self1 = 0;
    if (!pyopencv_LineSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'LineSegmentDetector' or its derivative)");
    Ptr<cv::LineSegmentDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_width = NULL;
    Mat width;
    PyObject* pyobj_prec = NULL;
    Mat prec;
    PyObject* pyobj_nfa = NULL;
    Mat nfa;

    const char* keywords[] = { "image", "lines", "width", "prec", "nfa", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:LineSegmentDetector.detect", (char**)keywords, &pyobj_image, &pyobj_lines, &pyobj_width, &pyobj_prec, &pyobj_nfa) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_width, width, ArgInfo("width", 1)) &&
        pyopencv_to_safe(pyobj_prec, prec, ArgInfo("prec", 1)) &&
        pyopencv_to_safe(pyobj_nfa, nfa, ArgInfo("nfa", 1)) )
    {
        ERRWRAP2(_self_->detect(image, lines, width, prec, nfa));
        return Py_BuildValue("(NNNN)", pyopencv_from(lines), pyopencv_from(width), pyopencv_from(prec), pyopencv_from(nfa));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_width = NULL;
    UMat width;
    PyObject* pyobj_prec = NULL;
    UMat prec;
    PyObject* pyobj_nfa = NULL;
    UMat nfa;

    const char* keywords[] = { "image", "lines", "width", "prec", "nfa", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOOO:LineSegmentDetector.detect", (char**)keywords, &pyobj_image, &pyobj_lines, &pyobj_width, &pyobj_prec, &pyobj_nfa) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_width, width, ArgInfo("width", 1)) &&
        pyopencv_to_safe(pyobj_prec, prec, ArgInfo("prec", 1)) &&
        pyopencv_to_safe(pyobj_nfa, nfa, ArgInfo("nfa", 1)) )
    {
        ERRWRAP2(_self_->detect(image, lines, width, prec, nfa));
        return Py_BuildValue("(NNNN)", pyopencv_from(lines), pyopencv_from(width), pyopencv_from(prec), pyopencv_from(nfa));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_LineSegmentDetector_drawSegments(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::LineSegmentDetector> * self1 = 0;
    if (!pyopencv_LineSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'LineSegmentDetector' or its derivative)");
    Ptr<cv::LineSegmentDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_lines = NULL;
    Mat lines;

    const char* keywords[] = { "image", "lines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:LineSegmentDetector.drawSegments", (char**)keywords, &pyobj_image, &pyobj_lines) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 0)) )
    {
        ERRWRAP2(_self_->drawSegments(image, lines));
        return pyopencv_from(image);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_lines = NULL;
    UMat lines;

    const char* keywords[] = { "image", "lines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:LineSegmentDetector.drawSegments", (char**)keywords, &pyobj_image, &pyobj_lines) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 0)) )
    {
        ERRWRAP2(_self_->drawSegments(image, lines));
        return pyopencv_from(image);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("drawSegments");

    return NULL;
}



// Tables (LineSegmentDetector)

static PyGetSetDef pyopencv_LineSegmentDetector_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_LineSegmentDetector_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_LineSegmentDetector
    PYOPENCV_EXTRA_METHODS_LineSegmentDetector
#endif
    {"compareSegments", CV_PY_FN_WITH_KW_(pyopencv_cv_LineSegmentDetector_compareSegments, 0), "compareSegments(size, lines1, lines2[, image]) -> retval, image\n.   @brief Draws two groups of lines in blue and red, counting the non overlapping (mismatching) pixels.\n.   \n.       @param size The size of the image, where lines1 and lines2 were found.\n.       @param lines1 The first group of lines that needs to be drawn. It is visualized in blue color.\n.       @param lines2 The second group of lines. They visualized in red color.\n.       @param image Optional image, where the lines will be drawn. The image should be color(3-channel)\n.       in order for lines1 and lines2 to be drawn in the above mentioned colors."},
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_LineSegmentDetector_detect, 0), "detect(image[, lines[, width[, prec[, nfa]]]]) -> lines, width, prec, nfa\n.   @brief Finds lines in the input image.\n.   \n.       This is the output of the default parameters of the algorithm on the above shown image.\n.   \n.       ![image](pics/building_lsd.png)\n.   \n.       @param image A grayscale (CV_8UC1) input image. If only a roi needs to be selected, use:\n.       `lsd_ptr-\\>detect(image(roi), lines, ...); lines += Scalar(roi.x, roi.y, roi.x, roi.y);`\n.       @param lines A vector of Vec4f elements specifying the beginning and ending point of a line. Where\n.       Vec4f is (x1, y1, x2, y2), point 1 is the start, point 2 - end. Returned lines are strictly\n.       oriented depending on the gradient.\n.       @param width Vector of widths of the regions, where the lines are found. E.g. Width of line.\n.       @param prec Vector of precisions with which the lines are found.\n.       @param nfa Vector containing number of false alarms in the line region, with precision of 10%. The\n.       bigger the value, logarithmically better the detection.\n.       - -1 corresponds to 10 mean false alarms\n.       - 0 corresponds to 1 mean false alarm\n.       - 1 corresponds to 0.1 mean false alarms\n.       This vector will be calculated only when the objects type is #LSD_REFINE_ADV."},
    {"drawSegments", CV_PY_FN_WITH_KW_(pyopencv_cv_LineSegmentDetector_drawSegments, 0), "drawSegments(image, lines) -> image\n.   @brief Draws the line segments on a given image.\n.       @param image The image, where the lines will be drawn. Should be bigger or equal to the image,\n.       where the lines were found.\n.       @param lines A vector of the lines that needed to be drawn."},

    {NULL,          NULL}
};

// Converter (LineSegmentDetector)

template<>
struct PyOpenCV_Converter< Ptr<cv::LineSegmentDetector> >
{
    static PyObject* from(const Ptr<cv::LineSegmentDetector>& r)
    {
        return pyopencv_LineSegmentDetector_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::LineSegmentDetector>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::LineSegmentDetector> * dst_;
        if (pyopencv_LineSegmentDetector_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::LineSegmentDetector> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// Moments (Map)
//================================================================================
static bool pyopencv_to(PyObject* src, cv::Moments& dst, const ArgInfo& info)
{
    PyObject* tmp;
    bool ok;

    if( PyMapping_HasKeyString(src, (char*)"m00") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m00");
        ok = tmp && pyopencv_to_safe(tmp, dst.m00, ArgInfo("m00", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m10") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m10");
        ok = tmp && pyopencv_to_safe(tmp, dst.m10, ArgInfo("m10", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m01") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m01");
        ok = tmp && pyopencv_to_safe(tmp, dst.m01, ArgInfo("m01", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m20") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m20");
        ok = tmp && pyopencv_to_safe(tmp, dst.m20, ArgInfo("m20", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m11") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m11");
        ok = tmp && pyopencv_to_safe(tmp, dst.m11, ArgInfo("m11", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m02") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m02");
        ok = tmp && pyopencv_to_safe(tmp, dst.m02, ArgInfo("m02", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m30") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m30");
        ok = tmp && pyopencv_to_safe(tmp, dst.m30, ArgInfo("m30", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m21") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m21");
        ok = tmp && pyopencv_to_safe(tmp, dst.m21, ArgInfo("m21", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m12") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m12");
        ok = tmp && pyopencv_to_safe(tmp, dst.m12, ArgInfo("m12", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"m03") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"m03");
        ok = tmp && pyopencv_to_safe(tmp, dst.m03, ArgInfo("m03", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu20") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu20");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu20, ArgInfo("mu20", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu11") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu11");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu11, ArgInfo("mu11", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu02") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu02");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu02, ArgInfo("mu02", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu30") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu30");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu30, ArgInfo("mu30", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu21") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu21");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu21, ArgInfo("mu21", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu12") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu12");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu12, ArgInfo("mu12", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"mu03") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"mu03");
        ok = tmp && pyopencv_to_safe(tmp, dst.mu03, ArgInfo("mu03", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu20") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu20");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu20, ArgInfo("nu20", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu11") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu11");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu11, ArgInfo("nu11", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu02") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu02");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu02, ArgInfo("nu02", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu30") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu30");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu30, ArgInfo("nu30", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu21") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu21");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu21, ArgInfo("nu21", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu12") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu12");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu12, ArgInfo("nu12", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"nu03") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"nu03");
        ok = tmp && pyopencv_to_safe(tmp, dst.nu03, ArgInfo("nu03", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    return true;
}

template<> bool pyopencv_to(PyObject* src, cv::Moments& dst, const ArgInfo& info);

//================================================================================
// RotatedRect (Generic)
//================================================================================

// GetSet (RotatedRect)


static PyObject* pyopencv_RotatedRect_get_angle(pyopencv_RotatedRect_t* p, void *closure)
{
    return pyopencv_from(p->v.angle);
}

static int pyopencv_RotatedRect_set_angle(pyopencv_RotatedRect_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the angle attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.angle, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_RotatedRect_get_center(pyopencv_RotatedRect_t* p, void *closure)
{
    return pyopencv_from(p->v.center);
}

static int pyopencv_RotatedRect_set_center(pyopencv_RotatedRect_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the center attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.center, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_RotatedRect_get_size(pyopencv_RotatedRect_t* p, void *closure)
{
    return pyopencv_from(p->v.size);
}

static int pyopencv_RotatedRect_set_size(pyopencv_RotatedRect_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the size attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.size, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (RotatedRect)

static int pyopencv_cv_RotatedRect_RotatedRect(pyopencv_RotatedRect_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(3);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::RotatedRect());
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_center = NULL;
    Point2f center;
    PyObject* pyobj_size = NULL;
    Size2f size;
    PyObject* pyobj_angle = NULL;
    float angle=0.f;

    const char* keywords[] = { "center", "size", "angle", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:RotatedRect", (char**)keywords, &pyobj_center, &pyobj_size, &pyobj_angle) &&
        pyopencv_to_safe(pyobj_center, center, ArgInfo("center", 0)) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_angle, angle, ArgInfo("angle", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::RotatedRect(center, size, angle));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_point1 = NULL;
    Point2f point1;
    PyObject* pyobj_point2 = NULL;
    Point2f point2;
    PyObject* pyobj_point3 = NULL;
    Point2f point3;

    const char* keywords[] = { "point1", "point2", "point3", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:RotatedRect", (char**)keywords, &pyobj_point1, &pyobj_point2, &pyobj_point3) &&
        pyopencv_to_safe(pyobj_point1, point1, ArgInfo("point1", 0)) &&
        pyopencv_to_safe(pyobj_point2, point2, ArgInfo("point2", 0)) &&
        pyopencv_to_safe(pyobj_point3, point3, ArgInfo("point3", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::RotatedRect(point1, point2, point3));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("RotatedRect");

    return -1;
}

static PyObject* pyopencv_cv_RotatedRect_boundingRect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::RotatedRect * self1 = 0;
    if (!pyopencv_RotatedRect_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'RotatedRect' or its derivative)");
    cv::RotatedRect* _self_ = (self1);
    Rect retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->boundingRect());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_RotatedRect_boundingRect2f(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::RotatedRect * self1 = 0;
    if (!pyopencv_RotatedRect_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'RotatedRect' or its derivative)");
    cv::RotatedRect* _self_ = (self1);
    Rect2f retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->boundingRect2f());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_RotatedRect_points(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    cv::RotatedRect * self1 = 0;
    if (!pyopencv_RotatedRect_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'RotatedRect' or its derivative)");
    cv::RotatedRect* _self_ = (self1);
    vector_Point2f pts;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->points(pts));
        return pyopencv_from(pts);
    }

    return NULL;
}



// Tables (RotatedRect)

static PyGetSetDef pyopencv_RotatedRect_getseters[] =
{
    {(char*)"angle", (getter)pyopencv_RotatedRect_get_angle, (setter)pyopencv_RotatedRect_set_angle, (char*)"angle", NULL},
    {(char*)"center", (getter)pyopencv_RotatedRect_get_center, (setter)pyopencv_RotatedRect_set_center, (char*)"center", NULL},
    {(char*)"size", (getter)pyopencv_RotatedRect_get_size, (setter)pyopencv_RotatedRect_set_size, (char*)"size", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_RotatedRect_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_RotatedRect
    PYOPENCV_EXTRA_METHODS_RotatedRect
#endif
    {"boundingRect", CV_PY_FN_WITH_KW_(pyopencv_cv_RotatedRect_boundingRect, 0), "boundingRect() -> retval\n."},
    {"boundingRect2f", CV_PY_FN_WITH_KW_(pyopencv_cv_RotatedRect_boundingRect2f, 0), "boundingRect2f() -> retval\n."},
    {"points", CV_PY_FN_WITH_KW_(pyopencv_cv_RotatedRect_points, 0), "points() -> pts\n.   returns 4 vertices of the rotated rectangle\n.       @param pts The points array for storing rectangle vertices. The order is _bottomLeft_, _topLeft_, topRight, bottomRight.\n.       @note _Bottom_, _Top_, _Left_ and _Right_ sides refer to the original rectangle (angle is 0),\n.       so after 180 degree rotation _bottomLeft_ point will be located at the top right corner of the\n.       rectangle."},

    {NULL,          NULL}
};

// Converter (RotatedRect)

template<>
struct PyOpenCV_Converter< cv::RotatedRect >
{
    static PyObject* from(const cv::RotatedRect& r)
    {
        return pyopencv_RotatedRect_Instance(r);
    }
    static bool to(PyObject* src, cv::RotatedRect& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::RotatedRect * dst_;
        if (pyopencv_RotatedRect_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::RotatedRect for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// Subdiv2D (Generic)
//================================================================================

// GetSet (Subdiv2D)



// Methods (Subdiv2D)

static int pyopencv_cv_Subdiv2D_Subdiv2D(pyopencv_Subdiv2D_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(3);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::Subdiv2D>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::Subdiv2D()));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rect = NULL;
    Rect rect;

    const char* keywords[] = { "rect", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D", (char**)keywords, &pyobj_rect) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) )
    {
        new (&(self->v)) Ptr<cv::Subdiv2D>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::Subdiv2D(rect)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_rect2f = NULL;
    Rect2f rect2f;

    const char* keywords[] = { "rect2f", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D", (char**)keywords, &pyobj_rect2f) &&
        pyopencv_to_safe(pyobj_rect2f, rect2f, ArgInfo("rect2f", 0)) )
    {
        new (&(self->v)) Ptr<cv::Subdiv2D>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::Subdiv2D(rect2f)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Subdiv2D");

    return -1;
}

static PyObject* pyopencv_cv_Subdiv2D_edgeDst(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_edge = NULL;
    int edge=0;
    Point2f dstpt;
    int retval;

    const char* keywords[] = { "edge", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.edgeDst", (char**)keywords, &pyobj_edge) &&
        pyopencv_to_safe(pyobj_edge, edge, ArgInfo("edge", 0)) )
    {
        ERRWRAP2(retval = _self_->edgeDst(edge, &dstpt));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(dstpt));
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_edgeOrg(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_edge = NULL;
    int edge=0;
    Point2f orgpt;
    int retval;

    const char* keywords[] = { "edge", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.edgeOrg", (char**)keywords, &pyobj_edge) &&
        pyopencv_to_safe(pyobj_edge, edge, ArgInfo("edge", 0)) )
    {
        ERRWRAP2(retval = _self_->edgeOrg(edge, &orgpt));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(orgpt));
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_findNearest(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    Point2f nearestPt;
    int retval;

    const char* keywords[] = { "pt", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.findNearest", (char**)keywords, &pyobj_pt) &&
        pyopencv_to_safe(pyobj_pt, pt, ArgInfo("pt", 0)) )
    {
        ERRWRAP2(retval = _self_->findNearest(pt, &nearestPt));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(nearestPt));
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_getEdge(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_edge = NULL;
    int edge=0;
    PyObject* pyobj_nextEdgeType = NULL;
    int nextEdgeType=0;
    int retval;

    const char* keywords[] = { "edge", "nextEdgeType", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:Subdiv2D.getEdge", (char**)keywords, &pyobj_edge, &pyobj_nextEdgeType) &&
        pyopencv_to_safe(pyobj_edge, edge, ArgInfo("edge", 0)) &&
        pyopencv_to_safe(pyobj_nextEdgeType, nextEdgeType, ArgInfo("nextEdgeType", 0)) )
    {
        ERRWRAP2(retval = _self_->getEdge(edge, nextEdgeType));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_getEdgeList(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    vector_Vec4f edgeList;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->getEdgeList(edgeList));
        return pyopencv_from(edgeList);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_getLeadingEdgeList(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    vector_int leadingEdgeList;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->getLeadingEdgeList(leadingEdgeList));
        return pyopencv_from(leadingEdgeList);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_getTriangleList(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    vector_Vec6f triangleList;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->getTriangleList(triangleList));
        return pyopencv_from(triangleList);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_getVertex(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_vertex = NULL;
    int vertex=0;
    int firstEdge;
    Point2f retval;

    const char* keywords[] = { "vertex", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.getVertex", (char**)keywords, &pyobj_vertex) &&
        pyopencv_to_safe(pyobj_vertex, vertex, ArgInfo("vertex", 0)) )
    {
        ERRWRAP2(retval = _self_->getVertex(vertex, &firstEdge));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(firstEdge));
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_getVoronoiFacetList(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_idx = NULL;
    vector_int idx;
    vector_vector_Point2f facetList;
    vector_Point2f facetCenters;

    const char* keywords[] = { "idx", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.getVoronoiFacetList", (char**)keywords, &pyobj_idx) &&
        pyopencv_to_safe(pyobj_idx, idx, ArgInfo("idx", 0)) )
    {
        ERRWRAP2(_self_->getVoronoiFacetList(idx, facetList, facetCenters));
        return Py_BuildValue("(NN)", pyopencv_from(facetList), pyopencv_from(facetCenters));
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_initDelaunay(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_rect = NULL;
    Rect rect;

    const char* keywords[] = { "rect", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.initDelaunay", (char**)keywords, &pyobj_rect) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) )
    {
        ERRWRAP2(_self_->initDelaunay(rect));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_initDelaunay2f(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_rect = NULL;
    Rect2f rect;

    const char* keywords[] = { "rect", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.initDelaunay2f", (char**)keywords, &pyobj_rect) &&
        pyopencv_to_safe(pyobj_rect, rect, ArgInfo("rect", 0)) )
    {
        ERRWRAP2(_self_->initDelaunay(rect));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_insert(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    int retval;

    const char* keywords[] = { "pt", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.insert", (char**)keywords, &pyobj_pt) &&
        pyopencv_to_safe(pyobj_pt, pt, ArgInfo("pt", 0)) )
    {
        ERRWRAP2(retval = _self_->insert(pt));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_ptvec = NULL;
    vector_Point2f ptvec;

    const char* keywords[] = { "ptvec", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.insert", (char**)keywords, &pyobj_ptvec) &&
        pyopencv_to_safe(pyobj_ptvec, ptvec, ArgInfo("ptvec", 0)) )
    {
        ERRWRAP2(_self_->insert(ptvec));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("insert");

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_locate(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_pt = NULL;
    Point2f pt;
    int edge;
    int vertex;
    int retval;

    const char* keywords[] = { "pt", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.locate", (char**)keywords, &pyobj_pt) &&
        pyopencv_to_safe(pyobj_pt, pt, ArgInfo("pt", 0)) )
    {
        ERRWRAP2(retval = _self_->locate(pt, edge, vertex));
        return Py_BuildValue("(NNN)", pyopencv_from(retval), pyopencv_from(edge), pyopencv_from(vertex));
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_nextEdge(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_edge = NULL;
    int edge=0;
    int retval;

    const char* keywords[] = { "edge", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.nextEdge", (char**)keywords, &pyobj_edge) &&
        pyopencv_to_safe(pyobj_edge, edge, ArgInfo("edge", 0)) )
    {
        ERRWRAP2(retval = _self_->nextEdge(edge));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_rotateEdge(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_edge = NULL;
    int edge=0;
    PyObject* pyobj_rotate = NULL;
    int rotate=0;
    int retval;

    const char* keywords[] = { "edge", "rotate", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:Subdiv2D.rotateEdge", (char**)keywords, &pyobj_edge, &pyobj_rotate) &&
        pyopencv_to_safe(pyobj_edge, edge, ArgInfo("edge", 0)) &&
        pyopencv_to_safe(pyobj_rotate, rotate, ArgInfo("rotate", 0)) )
    {
        ERRWRAP2(retval = _self_->rotateEdge(edge, rotate));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_Subdiv2D_symEdge(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::Subdiv2D> * self1 = 0;
    if (!pyopencv_Subdiv2D_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'Subdiv2D' or its derivative)");
    Ptr<cv::Subdiv2D> _self_ = *(self1);
    PyObject* pyobj_edge = NULL;
    int edge=0;
    int retval;

    const char* keywords[] = { "edge", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Subdiv2D.symEdge", (char**)keywords, &pyobj_edge) &&
        pyopencv_to_safe(pyobj_edge, edge, ArgInfo("edge", 0)) )
    {
        ERRWRAP2(retval = _self_->symEdge(edge));
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (Subdiv2D)

static PyGetSetDef pyopencv_Subdiv2D_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_Subdiv2D_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_Subdiv2D
    PYOPENCV_EXTRA_METHODS_Subdiv2D
#endif
    {"edgeDst", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_edgeDst, 0), "edgeDst(edge) -> retval, dstpt\n.   @brief Returns the edge destination.\n.   \n.       @param edge Subdivision edge ID.\n.       @param dstpt Output vertex location.\n.   \n.       @returns vertex ID."},
    {"edgeOrg", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_edgeOrg, 0), "edgeOrg(edge) -> retval, orgpt\n.   @brief Returns the edge origin.\n.   \n.       @param edge Subdivision edge ID.\n.       @param orgpt Output vertex location.\n.   \n.       @returns vertex ID."},
    {"findNearest", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_findNearest, 0), "findNearest(pt) -> retval, nearestPt\n.   @brief Finds the subdivision vertex closest to the given point.\n.   \n.       @param pt Input point.\n.       @param nearestPt Output subdivision vertex point.\n.   \n.       The function is another function that locates the input point within the subdivision. It finds the\n.       subdivision vertex that is the closest to the input point. It is not necessarily one of vertices\n.       of the facet containing the input point, though the facet (located using locate() ) is used as a\n.       starting point.\n.   \n.       @returns vertex ID."},
    {"getEdge", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_getEdge, 0), "getEdge(edge, nextEdgeType) -> retval\n.   @brief Returns one of the edges related to the given edge.\n.   \n.       @param edge Subdivision edge ID.\n.       @param nextEdgeType Parameter specifying which of the related edges to return.\n.       The following values are possible:\n.       -   NEXT_AROUND_ORG next around the edge origin ( eOnext on the picture below if e is the input edge)\n.       -   NEXT_AROUND_DST next around the edge vertex ( eDnext )\n.       -   PREV_AROUND_ORG previous around the edge origin (reversed eRnext )\n.       -   PREV_AROUND_DST previous around the edge destination (reversed eLnext )\n.       -   NEXT_AROUND_LEFT next around the left facet ( eLnext )\n.       -   NEXT_AROUND_RIGHT next around the right facet ( eRnext )\n.       -   PREV_AROUND_LEFT previous around the left facet (reversed eOnext )\n.       -   PREV_AROUND_RIGHT previous around the right facet (reversed eDnext )\n.   \n.       ![sample output](pics/quadedge.png)\n.   \n.       @returns edge ID related to the input edge."},
    {"getEdgeList", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_getEdgeList, 0), "getEdgeList() -> edgeList\n.   @brief Returns a list of all edges.\n.   \n.       @param edgeList Output vector.\n.   \n.       The function gives each edge as a 4 numbers vector, where each two are one of the edge\n.       vertices. i.e. org_x = v[0], org_y = v[1], dst_x = v[2], dst_y = v[3]."},
    {"getLeadingEdgeList", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_getLeadingEdgeList, 0), "getLeadingEdgeList() -> leadingEdgeList\n.   @brief Returns a list of the leading edge ID connected to each triangle.\n.   \n.       @param leadingEdgeList Output vector.\n.   \n.       The function gives one edge ID for each triangle."},
    {"getTriangleList", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_getTriangleList, 0), "getTriangleList() -> triangleList\n.   @brief Returns a list of all triangles.\n.   \n.       @param triangleList Output vector.\n.   \n.       The function gives each triangle as a 6 numbers vector, where each two are one of the triangle\n.       vertices. i.e. p1_x = v[0], p1_y = v[1], p2_x = v[2], p2_y = v[3], p3_x = v[4], p3_y = v[5]."},
    {"getVertex", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_getVertex, 0), "getVertex(vertex) -> retval, firstEdge\n.   @brief Returns vertex location from vertex ID.\n.   \n.       @param vertex vertex ID.\n.       @param firstEdge Optional. The first edge ID which is connected to the vertex.\n.       @returns vertex (x,y)"},
    {"getVoronoiFacetList", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_getVoronoiFacetList, 0), "getVoronoiFacetList(idx) -> facetList, facetCenters\n.   @brief Returns a list of all Voronoi facets.\n.   \n.       @param idx Vector of vertices IDs to consider. For all vertices you can pass empty vector.\n.       @param facetList Output vector of the Voronoi facets.\n.       @param facetCenters Output vector of the Voronoi facets center points."},
    {"initDelaunay", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_initDelaunay, 0), "initDelaunay(rect) -> None\n.   @overload\n.   \n.       @brief Creates a new empty Delaunay subdivision\n.   \n.       @param rect Rectangle that includes all of the 2D points that are to be added to the subdivision."},
    {"initDelaunay2f", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_initDelaunay2f, 0), "initDelaunay2f(rect) -> None\n.   @overload\n.   \n.       @brief Creates a new empty Delaunay subdivision\n.   \n.       @param rect Rectangle that includes all of the 2d points that are to be added to the subdivision."},
    {"insert", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_insert, 0), "insert(pt) -> retval\n.   @brief Insert a single point into a Delaunay triangulation.\n.   \n.       @param pt Point to insert.\n.   \n.       The function inserts a single point into a subdivision and modifies the subdivision topology\n.       appropriately. If a point with the same coordinates exists already, no new point is added.\n.       @returns the ID of the point.\n.   \n.       @note If the point is outside of the triangulation specified rect a runtime error is raised.\n\n\n\ninsert(ptvec) -> None\n.   @brief Insert multiple points into a Delaunay triangulation.\n.   \n.       @param ptvec Points to insert.\n.   \n.       The function inserts a vector of points into a subdivision and modifies the subdivision topology\n.       appropriately."},
    {"locate", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_locate, 0), "locate(pt) -> retval, edge, vertex\n.   @brief Returns the location of a point within a Delaunay triangulation.\n.   \n.       @param pt Point to locate.\n.       @param edge Output edge that the point belongs to or is located to the right of it.\n.       @param vertex Optional output vertex the input point coincides with.\n.   \n.       The function locates the input point within the subdivision and gives one of the triangle edges\n.       or vertices.\n.   \n.       @returns an integer which specify one of the following five cases for point location:\n.       -  The point falls into some facet. The function returns #PTLOC_INSIDE and edge will contain one of\n.          edges of the facet.\n.       -  The point falls onto the edge. The function returns #PTLOC_ON_EDGE and edge will contain this edge.\n.       -  The point coincides with one of the subdivision vertices. The function returns #PTLOC_VERTEX and\n.          vertex will contain a pointer to the vertex.\n.       -  The point is outside the subdivision reference rectangle. The function returns #PTLOC_OUTSIDE_RECT\n.          and no pointers are filled.\n.       -  One of input arguments is invalid. A runtime error is raised or, if silent or \"parent\" error\n.          processing mode is selected, #PTLOC_ERROR is returned."},
    {"nextEdge", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_nextEdge, 0), "nextEdge(edge) -> retval\n.   @brief Returns next edge around the edge origin.\n.   \n.       @param edge Subdivision edge ID.\n.   \n.       @returns an integer which is next edge ID around the edge origin: eOnext on the\n.       picture above if e is the input edge)."},
    {"rotateEdge", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_rotateEdge, 0), "rotateEdge(edge, rotate) -> retval\n.   @brief Returns another edge of the same quad-edge.\n.   \n.       @param edge Subdivision edge ID.\n.       @param rotate Parameter specifying which of the edges of the same quad-edge as the input\n.       one to return. The following values are possible:\n.       -   0 - the input edge ( e on the picture below if e is the input edge)\n.       -   1 - the rotated edge ( eRot )\n.       -   2 - the reversed edge (reversed e (in green))\n.       -   3 - the reversed rotated edge (reversed eRot (in green))\n.   \n.       @returns one of the edges ID of the same quad-edge as the input edge."},
    {"symEdge", CV_PY_FN_WITH_KW_(pyopencv_cv_Subdiv2D_symEdge, 0), "symEdge(edge) -> retval\n."},

    {NULL,          NULL}
};

// Converter (Subdiv2D)

template<>
struct PyOpenCV_Converter< Ptr<cv::Subdiv2D> >
{
    static PyObject* from(const Ptr<cv::Subdiv2D>& r)
    {
        return pyopencv_Subdiv2D_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::Subdiv2D>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::Subdiv2D> * dst_;
        if (pyopencv_Subdiv2D_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::Subdiv2D> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// TickMeter (Generic)
//================================================================================

// GetSet (TickMeter)



// Methods (TickMeter)

static int pyopencv_cv_TickMeter_TickMeter(pyopencv_TickMeter_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::TickMeter>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::TickMeter()));
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_TickMeter_getAvgTimeMilli(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAvgTimeMilli());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getAvgTimeSec(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAvgTimeSec());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getCounter(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    int64 retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getCounter());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getFPS(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getFPS());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getLastTimeMicro(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLastTimeMicro());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getLastTimeMilli(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLastTimeMilli());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getLastTimeSec(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLastTimeSec());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getLastTimeTicks(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    int64 retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLastTimeTicks());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getTimeMicro(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTimeMicro());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getTimeMilli(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTimeMilli());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getTimeSec(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTimeSec());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_getTimeTicks(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);
    int64 retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTimeTicks());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_reset(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->reset());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_start(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->start());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_TickMeter_stop(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::TickMeter> * self1 = 0;
    if (!pyopencv_TickMeter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'TickMeter' or its derivative)");
    Ptr<cv::TickMeter> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->stop());
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (TickMeter)

static PyGetSetDef pyopencv_TickMeter_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_TickMeter_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_TickMeter
    PYOPENCV_EXTRA_METHODS_TickMeter
#endif
    {"getAvgTimeMilli", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getAvgTimeMilli, 0), "getAvgTimeMilli() -> retval\n."},
    {"getAvgTimeSec", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getAvgTimeSec, 0), "getAvgTimeSec() -> retval\n."},
    {"getCounter", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getCounter, 0), "getCounter() -> retval\n."},
    {"getFPS", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getFPS, 0), "getFPS() -> retval\n."},
    {"getLastTimeMicro", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getLastTimeMicro, 0), "getLastTimeMicro() -> retval\n."},
    {"getLastTimeMilli", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getLastTimeMilli, 0), "getLastTimeMilli() -> retval\n."},
    {"getLastTimeSec", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getLastTimeSec, 0), "getLastTimeSec() -> retval\n."},
    {"getLastTimeTicks", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getLastTimeTicks, 0), "getLastTimeTicks() -> retval\n."},
    {"getTimeMicro", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getTimeMicro, 0), "getTimeMicro() -> retval\n."},
    {"getTimeMilli", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getTimeMilli, 0), "getTimeMilli() -> retval\n."},
    {"getTimeSec", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getTimeSec, 0), "getTimeSec() -> retval\n."},
    {"getTimeTicks", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_getTimeTicks, 0), "getTimeTicks() -> retval\n."},
    {"reset", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_reset, 0), "reset() -> None\n."},
    {"start", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_start, 0), "start() -> None\n."},
    {"stop", CV_PY_FN_WITH_KW_(pyopencv_cv_TickMeter_stop, 0), "stop() -> None\n."},

    {NULL,          NULL}
};

// Converter (TickMeter)

template<>
struct PyOpenCV_Converter< Ptr<cv::TickMeter> >
{
    static PyObject* from(const Ptr<cv::TickMeter>& r)
    {
        return pyopencv_TickMeter_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::TickMeter>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::TickMeter> * dst_;
        if (pyopencv_TickMeter_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::TickMeter> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// UMat (Generic)
//================================================================================

// GetSet (UMat)


static PyObject* pyopencv_UMat_get_offset(pyopencv_UMat_t* p, void *closure)
{
    return pyopencv_from(p->v->offset);
}

static int pyopencv_UMat_set_offset(pyopencv_UMat_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the offset attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v->offset, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (UMat)

static int pyopencv_cv_UMat_UMat(pyopencv_UMat_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(9);

    {
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:UMat", (char**)keywords, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(usageFlags)));
        return 0;
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
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "rows", "cols", "type", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:UMat", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(rows, cols, type, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "size", "type", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:UMat", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(size, type, usageFlags)));
        return 0;
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
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "rows", "cols", "type", "s", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:UMat", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_s, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(rows, cols, type, s, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_usageFlags = NULL;
    UMatUsageFlags usageFlags=USAGE_DEFAULT;

    const char* keywords[] = { "size", "type", "s", "usageFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:UMat", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_s, &pyobj_usageFlags) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_usageFlags, usageFlags, ArgInfo("usageFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(size, type, s, usageFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:UMat", (char**)keywords, &pyobj_m) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_rowRange = NULL;
    Range rowRange;
    PyObject* pyobj_colRange = NULL;
    Range colRange=Range::all();

    const char* keywords[] = { "m", "rowRange", "colRange", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:UMat", (char**)keywords, &pyobj_m, &pyobj_rowRange, &pyobj_colRange) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_rowRange, rowRange, ArgInfo("rowRange", 0)) &&
        pyopencv_to_safe(pyobj_colRange, colRange, ArgInfo("colRange", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, rowRange, colRange)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_roi = NULL;
    Rect roi;

    const char* keywords[] = { "m", "roi", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:UMat", (char**)keywords, &pyobj_m, &pyobj_roi) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_roi, roi, ArgInfo("roi", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, roi)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    UMat m;
    PyObject* pyobj_ranges = NULL;
    vector_Range ranges;

    const char* keywords[] = { "m", "ranges", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:UMat", (char**)keywords, &pyobj_m, &pyobj_ranges) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_ranges, ranges, ArgInfo("ranges", 0)) )
    {
        new (&(self->v)) Ptr<cv::UMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::UMat(m, ranges)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("UMat");

    return -1;
}

static PyObject* pyopencv_cv_UMat_context_static(PyObject* self, PyObject* py_args, PyObject* kw)
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

static PyObject* pyopencv_cv_UMat_get(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    Mat retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv_UMat_get(_self_));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_handle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    PyObject* pyobj_accessFlags = NULL;
    AccessFlag accessFlags=static_cast<AccessFlag>(0);
    void* retval;

    const char* keywords[] = { "accessFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:UMat.handle", (char**)keywords, &pyobj_accessFlags) &&
        pyopencv_to_safe(pyobj_accessFlags, accessFlags, ArgInfo("accessFlags", 0)) )
    {
        ERRWRAP2(retval = _self_->handle(accessFlags));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_isContinuous(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isContinuous());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_isSubmatrix(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::UMat> * self1 = 0;
    if (!pyopencv_UMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'UMat' or its derivative)");
    Ptr<cv::UMat> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isSubmatrix());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_UMat_queue_static(PyObject* self, PyObject* py_args, PyObject* kw)
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



// Tables (UMat)

static PyGetSetDef pyopencv_UMat_getseters[] =
{
    {(char*)"offset", (getter)pyopencv_UMat_get_offset, (setter)pyopencv_UMat_set_offset, (char*)"offset", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_UMat_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_UMat
    PYOPENCV_EXTRA_METHODS_UMat
#endif
    {"context", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_context_static, METH_STATIC), "context() -> retval\n."},
    {"get", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_get, 0), "get() -> retval\n."},
    {"handle", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_handle, 0), "handle(accessFlags) -> retval\n."},
    {"isContinuous", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_isContinuous, 0), "isContinuous() -> retval\n."},
    {"isSubmatrix", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_isSubmatrix, 0), "isSubmatrix() -> retval\n."},
    {"queue", CV_PY_FN_WITH_KW_(pyopencv_cv_UMat_queue_static, METH_STATIC), "queue() -> retval\n."},

    {NULL,          NULL}
};

// Converter (UMat)

template<>
struct PyOpenCV_Converter< Ptr<cv::UMat> >
{
    static PyObject* from(const Ptr<cv::UMat>& r)
    {
        return pyopencv_UMat_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::UMat>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::UMat> * dst_;
        if (pyopencv_UMat_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
    {
        Ptr<Mat> _src;
        if (pyopencv_to_safe(src, _src, info))
        {
            return cv_mappable_to(_src, dst);
        }
    }

        failmsg("Expected Ptr<cv::UMat> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// VideoCapture (Generic)
//================================================================================

// GetSet (VideoCapture)



// Methods (VideoCapture)

static int pyopencv_cv_VideoCapture_VideoCapture(pyopencv_VideoCapture_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(6);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::VideoCapture>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoCapture()));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=CAP_ANY;

    const char* keywords[] = { "filename", "apiPreference", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:VideoCapture", (char**)keywords, &pyobj_filename, &pyobj_apiPreference) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoCapture>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoCapture(filename, apiPreference)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_params = NULL;
    vector_int params;

    const char* keywords[] = { "filename", "apiPreference", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:VideoCapture", (char**)keywords, &pyobj_filename, &pyobj_apiPreference, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoCapture>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoCapture(filename, apiPreference, params)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_index = NULL;
    int index=0;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=CAP_ANY;

    const char* keywords[] = { "index", "apiPreference", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:VideoCapture", (char**)keywords, &pyobj_index, &pyobj_apiPreference) &&
        pyopencv_to_safe(pyobj_index, index, ArgInfo("index", 0)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoCapture>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoCapture(index, apiPreference)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_index = NULL;
    int index=0;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_params = NULL;
    vector_int params;

    const char* keywords[] = { "index", "apiPreference", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:VideoCapture", (char**)keywords, &pyobj_index, &pyobj_apiPreference, &pyobj_params) &&
        pyopencv_to_safe(pyobj_index, index, ArgInfo("index", 0)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoCapture>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoCapture(index, apiPreference, params)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_source = NULL;
    Ptr<IStreamReader> source;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_params = NULL;
    vector_int params;

    const char* keywords[] = { "source", "apiPreference", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:VideoCapture", (char**)keywords, &pyobj_source, &pyobj_apiPreference, &pyobj_params) &&
        pyopencv_to_safe(pyobj_source, source, ArgInfo("source", 0)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoCapture>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoCapture(source, apiPreference, params)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("VideoCapture");

    return -1;
}

static PyObject* pyopencv_cv_VideoCapture_get(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    PyObject* pyobj_propId = NULL;
    int propId=0;
    double retval;

    const char* keywords[] = { "propId", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:VideoCapture.get", (char**)keywords, &pyobj_propId) &&
        pyopencv_to_safe(pyobj_propId, propId, ArgInfo("propId", 0)) )
    {
        ERRWRAP2(retval = _self_->get(propId));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_getBackendName(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getBackendName());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_getExceptionMode(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getExceptionMode());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_grab(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->grab());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_isOpened(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isOpened());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_open(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(5);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=CAP_ANY;
    bool retval;

    const char* keywords[] = { "filename", "apiPreference", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:VideoCapture.open", (char**)keywords, &pyobj_filename, &pyobj_apiPreference) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, apiPreference));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_params = NULL;
    vector_int params;
    bool retval;

    const char* keywords[] = { "filename", "apiPreference", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:VideoCapture.open", (char**)keywords, &pyobj_filename, &pyobj_apiPreference, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, apiPreference, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_index = NULL;
    int index=0;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=CAP_ANY;
    bool retval;

    const char* keywords[] = { "index", "apiPreference", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:VideoCapture.open", (char**)keywords, &pyobj_index, &pyobj_apiPreference) &&
        pyopencv_to_safe(pyobj_index, index, ArgInfo("index", 0)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) )
    {
        ERRWRAP2(retval = _self_->open(index, apiPreference));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_index = NULL;
    int index=0;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_params = NULL;
    vector_int params;
    bool retval;

    const char* keywords[] = { "index", "apiPreference", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:VideoCapture.open", (char**)keywords, &pyobj_index, &pyobj_apiPreference, &pyobj_params) &&
        pyopencv_to_safe(pyobj_index, index, ArgInfo("index", 0)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = _self_->open(index, apiPreference, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_source = NULL;
    Ptr<IStreamReader> source;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_params = NULL;
    vector_int params;
    bool retval;

    const char* keywords[] = { "source", "apiPreference", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:VideoCapture.open", (char**)keywords, &pyobj_source, &pyobj_apiPreference, &pyobj_params) &&
        pyopencv_to_safe(pyobj_source, source, ArgInfo("source", 0)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = _self_->open(source, apiPreference, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("open");

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_read(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    bool retval;

    const char* keywords[] = { "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:VideoCapture.read", (char**)keywords, &pyobj_image) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) )
    {
        ERRWRAP2(retval = _self_->read(image));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(image));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    bool retval;

    const char* keywords[] = { "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:VideoCapture.read", (char**)keywords, &pyobj_image) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) )
    {
        ERRWRAP2(retval = _self_->read(image));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(image));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("read");

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_release(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->release());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_retrieve(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_flag = NULL;
    int flag=0;
    bool retval;

    const char* keywords[] = { "image", "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:VideoCapture.retrieve", (char**)keywords, &pyobj_image, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(retval = _self_->retrieve(image, flag));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(image));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_flag = NULL;
    int flag=0;
    bool retval;

    const char* keywords[] = { "image", "flag", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:VideoCapture.retrieve", (char**)keywords, &pyobj_image, &pyobj_flag) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 1)) &&
        pyopencv_to_safe(pyobj_flag, flag, ArgInfo("flag", 0)) )
    {
        ERRWRAP2(retval = _self_->retrieve(image, flag));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(image));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("retrieve");

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_set(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    PyObject* pyobj_propId = NULL;
    int propId=0;
    PyObject* pyobj_value = NULL;
    double value=0;
    bool retval;

    const char* keywords[] = { "propId", "value", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:VideoCapture.set", (char**)keywords, &pyobj_propId, &pyobj_value) &&
        pyopencv_to_safe(pyobj_propId, propId, ArgInfo("propId", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(retval = _self_->set(propId, value));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_setExceptionMode(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoCapture> * self1 = 0;
    if (!pyopencv_VideoCapture_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoCapture' or its derivative)");
    Ptr<cv::VideoCapture> _self_ = *(self1);
    PyObject* pyobj_enable = NULL;
    bool enable=0;

    const char* keywords[] = { "enable", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:VideoCapture.setExceptionMode", (char**)keywords, &pyobj_enable) &&
        pyopencv_to_safe(pyobj_enable, enable, ArgInfo("enable", 0)) )
    {
        ERRWRAP2(_self_->setExceptionMode(enable));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoCapture_waitAny_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    PyObject* pyobj_streams = NULL;
    vector_VideoCapture streams;
    vector_int readyIndex;
    PyObject* pyobj_timeoutNs = NULL;
    int64 timeoutNs=0;
    bool retval;

    const char* keywords[] = { "streams", "timeoutNs", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:VideoCapture.waitAny", (char**)keywords, &pyobj_streams, &pyobj_timeoutNs) &&
        pyopencv_to_safe(pyobj_streams, streams, ArgInfo("streams", 0)) &&
        pyopencv_to_safe(pyobj_timeoutNs, timeoutNs, ArgInfo("timeoutNs", 0)) )
    {
        ERRWRAP2(retval = cv::VideoCapture::waitAny(streams, readyIndex, timeoutNs));
        return Py_BuildValue("(NN)", pyopencv_from(retval), pyopencv_from(readyIndex));
    }

    return NULL;
}



// Tables (VideoCapture)

static PyGetSetDef pyopencv_VideoCapture_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_VideoCapture_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_VideoCapture
    PYOPENCV_EXTRA_METHODS_VideoCapture
#endif
    {"get", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_get, 0), "get(propId) -> retval\n.   @brief Returns the specified VideoCapture property\n.   \n.       @param propId Property identifier from cv::VideoCaptureProperties (eg. cv::CAP_PROP_POS_MSEC, cv::CAP_PROP_POS_FRAMES, ...)\n.       or one from @ref videoio_flags_others\n.       @return Value for the specified property. Value 0 is returned when querying a property that is\n.       not supported by the backend used by the VideoCapture instance.\n.   \n.       @note Reading / writing properties involves many layers. Some unexpected result might happens\n.       along this chain.\n.       @code{.txt}\n.       VideoCapture -> API Backend -> Operating System -> Device Driver -> Device Hardware\n.       @endcode\n.       The returned value might be different from what really used by the device or it could be encoded\n.       using device dependent rules (eg. steps or percentage). Effective behaviour depends from device\n.       driver and API Backend"},
    {"getBackendName", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_getBackendName, 0), "getBackendName() -> retval\n.   @brief Returns used backend API name\n.   \n.        @note Stream should be opened."},
    {"getExceptionMode", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_getExceptionMode, 0), "getExceptionMode() -> retval\n."},
    {"grab", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_grab, 0), "grab() -> retval\n.   @brief Grabs the next frame from video file or capturing device.\n.   \n.       @return `true` (non-zero) in the case of success.\n.   \n.       The method/function grabs the next frame from video file or camera and returns true (non-zero) in\n.       the case of success.\n.   \n.       The primary use of the function is in multi-camera environments, especially when the cameras do not\n.       have hardware synchronization. That is, you call VideoCapture::grab() for each camera and after that\n.       call the slower method VideoCapture::retrieve() to decode and get frame from each camera. This way\n.       the overhead on demosaicing or motion jpeg decompression etc. is eliminated and the retrieved frames\n.       from different cameras will be closer in time.\n.   \n.       Also, when a connected camera is multi-head (for example, a stereo camera or a Kinect device), the\n.       correct way of retrieving data from it is to call VideoCapture::grab() first and then call\n.       VideoCapture::retrieve() one or more times with different values of the channel parameter.\n.   \n.       @ref tutorial_kinect_openni"},
    {"isOpened", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_isOpened, 0), "isOpened() -> retval\n.   @brief Returns true if video capturing has been initialized already.\n.   \n.       If the previous call to VideoCapture constructor or VideoCapture::open() succeeded, the method returns\n.       true."},
    {"open", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_open, 0), "open(filename[, apiPreference]) -> retval\n.   @brief  Opens a video file or a capturing device or an IP video stream for video capturing.\n.   \n.       @overload\n.   \n.       Parameters are same as the constructor VideoCapture(const String& filename, int apiPreference = CAP_ANY)\n.       @return `true` if the file has been successfully opened\n.   \n.       The method first calls VideoCapture::release to close the already opened file or camera.\n\n\n\nopen(filename, apiPreference, params) -> retval\n.   @brief  Opens a video file or a capturing device or an IP video stream for video capturing with API Preference and parameters\n.   \n.       @overload\n.   \n.       The `params` parameter allows to specify extra parameters encoded as pairs `(paramId_1, paramValue_1, paramId_2, paramValue_2, ...)`.\n.       See cv::VideoCaptureProperties\n.   \n.       @return `true` if the file has been successfully opened\n.   \n.       The method first calls VideoCapture::release to close the already opened file or camera.\n\n\n\nopen(index[, apiPreference]) -> retval\n.   @brief  Opens a camera for video capturing\n.   \n.       @overload\n.   \n.       Parameters are same as the constructor VideoCapture(int index, int apiPreference = CAP_ANY)\n.       @return `true` if the camera has been successfully opened.\n.   \n.       The method first calls VideoCapture::release to close the already opened file or camera.\n\n\n\nopen(index, apiPreference, params) -> retval\n.   @brief  Opens a camera for video capturing with API Preference and parameters\n.   \n.       @overload\n.   \n.       The `params` parameter allows to specify extra parameters encoded as pairs `(paramId_1, paramValue_1, paramId_2, paramValue_2, ...)`.\n.       See cv::VideoCaptureProperties\n.   \n.       @return `true` if the camera has been successfully opened.\n.   \n.       The method first calls VideoCapture::release to close the already opened file or camera.\n\n\n\nopen(source, apiPreference, params) -> retval\n.   @brief Opens a video using data stream.\n.   \n.       @overload\n.   \n.       The `params` parameter allows to specify extra parameters encoded as pairs `(paramId_1, paramValue_1, paramId_2, paramValue_2, ...)`.\n.       See cv::VideoCaptureProperties\n.   \n.       @return `true` if the file has been successfully opened\n.   \n.       The method first calls VideoCapture::release to close the already opened file or camera."},
    {"read", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_read, 0), "read([, image]) -> retval, image\n.   @brief Grabs, decodes and returns the next video frame.\n.   \n.       @param [out] image the video frame is returned here. If no frames has been grabbed the image will be empty.\n.       @return `false` if no frames has been grabbed\n.   \n.       The method/function combines VideoCapture::grab() and VideoCapture::retrieve() in one call. This is the\n.       most convenient method for reading video files or capturing data from decode and returns the just\n.       grabbed frame. If no frames has been grabbed (camera has been disconnected, or there are no more\n.       frames in video file), the method returns false and the function returns empty image (with %cv::Mat, test it with Mat::empty()).\n.   \n.       @note In @ref videoio_c \"C API\", functions cvRetrieveFrame() and cv.RetrieveFrame() return image stored inside the video\n.       capturing structure. It is not allowed to modify or release the image! You can copy the frame using\n.       cvCloneImage and then do whatever you want with the copy."},
    {"release", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_release, 0), "release() -> None\n.   @brief Closes video file or capturing device.\n.   \n.       The method is automatically called by subsequent VideoCapture::open and by VideoCapture\n.       destructor.\n.   \n.       The C function also deallocates memory and clears \\*capture pointer."},
    {"retrieve", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_retrieve, 0), "retrieve([, image[, flag]]) -> retval, image\n.   @brief Decodes and returns the grabbed video frame.\n.   \n.       @param [out] image the video frame is returned here. If no frames has been grabbed the image will be empty.\n.       @param flag it could be a frame index or a driver specific flag\n.       @return `false` if no frames has been grabbed\n.   \n.       The method decodes and returns the just grabbed frame. If no frames has been grabbed\n.       (camera has been disconnected, or there are no more frames in video file), the method returns false\n.       and the function returns an empty image (with %cv::Mat, test it with Mat::empty()).\n.   \n.       @sa read()\n.   \n.       @note In @ref videoio_c \"C API\", functions cvRetrieveFrame() and cv.RetrieveFrame() return image stored inside the video\n.       capturing structure. It is not allowed to modify or release the image! You can copy the frame using\n.       cvCloneImage and then do whatever you want with the copy."},
    {"set", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_set, 0), "set(propId, value) -> retval\n.   @brief Sets a property in the VideoCapture.\n.   \n.       @param propId Property identifier from cv::VideoCaptureProperties (eg. cv::CAP_PROP_POS_MSEC, cv::CAP_PROP_POS_FRAMES, ...)\n.       or one from @ref videoio_flags_others\n.       @param value Value of the property.\n.       @return `true` if the property is supported by backend used by the VideoCapture instance.\n.       @note Even if it returns `true` this doesn't ensure that the property\n.       value has been accepted by the capture device. See note in VideoCapture::get()"},
    {"setExceptionMode", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_setExceptionMode, 0), "setExceptionMode(enable) -> None\n.   Switches exceptions mode\n.        *\n.        * methods raise exceptions if not successful instead of returning an error code"},
    {"waitAny", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoCapture_waitAny_static, METH_STATIC), "waitAny(streams[, timeoutNs]) -> retval, readyIndex\n.   @brief Wait for ready frames from VideoCapture.\n.   \n.       @param streams input video streams\n.       @param readyIndex stream indexes with grabbed frames (ready to use .retrieve() to fetch actual frame)\n.       @param timeoutNs number of nanoseconds (0 - infinite)\n.       @return `true` if streamReady is not empty\n.   \n.       @throws Exception %Exception on stream errors (check .isOpened() to filter out malformed streams) or VideoCapture type is not supported\n.   \n.       The primary use of the function is in multi-camera environments.\n.       The method fills the ready state vector, grabs video frame, if camera is ready.\n.   \n.       After this call use VideoCapture::retrieve() to decode and fetch frame data."},

    {NULL,          NULL}
};

// Converter (VideoCapture)

template<>
struct PyOpenCV_Converter< Ptr<cv::VideoCapture> >
{
    static PyObject* from(const Ptr<cv::VideoCapture>& r)
    {
        return pyopencv_VideoCapture_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::VideoCapture>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::VideoCapture> * dst_;
        if (pyopencv_VideoCapture_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::VideoCapture> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// VideoWriter (Generic)
//================================================================================

// GetSet (VideoWriter)



// Methods (VideoWriter)

static int pyopencv_cv_VideoWriter_VideoWriter(pyopencv_VideoWriter_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;

    pyPrepareArgumentConversionErrorsStorage(5);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::VideoWriter>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoWriter()));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_isColor = NULL;
    bool isColor=true;

    const char* keywords[] = { "filename", "fourcc", "fps", "frameSize", "isColor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:VideoWriter", (char**)keywords, &pyobj_filename, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_isColor) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_isColor, isColor, ArgInfo("isColor", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoWriter>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoWriter(filename, fourcc, fps, frameSize, isColor)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_isColor = NULL;
    bool isColor=true;

    const char* keywords[] = { "filename", "apiPreference", "fourcc", "fps", "frameSize", "isColor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:VideoWriter", (char**)keywords, &pyobj_filename, &pyobj_apiPreference, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_isColor) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_isColor, isColor, ArgInfo("isColor", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoWriter>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoWriter(filename, apiPreference, fourcc, fps, frameSize, isColor)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_params = NULL;
    vector_int params;

    const char* keywords[] = { "filename", "fourcc", "fps", "frameSize", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO:VideoWriter", (char**)keywords, &pyobj_filename, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoWriter>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoWriter(filename, fourcc, fps, frameSize, params)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_params = NULL;
    vector_int params;

    const char* keywords[] = { "filename", "apiPreference", "fourcc", "fps", "frameSize", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO:VideoWriter", (char**)keywords, &pyobj_filename, &pyobj_apiPreference, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        new (&(self->v)) Ptr<cv::VideoWriter>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::VideoWriter(filename, apiPreference, fourcc, fps, frameSize, params)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("VideoWriter");

    return -1;
}

static PyObject* pyopencv_cv_VideoWriter_fourcc_static(PyObject* self, PyObject* py_args, PyObject* kw)
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:VideoWriter.fourcc", (char**)keywords, &pyobj_c1, &pyobj_c2, &pyobj_c3, &pyobj_c4) &&
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

static PyObject* pyopencv_cv_VideoWriter_get(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);
    PyObject* pyobj_propId = NULL;
    int propId=0;
    double retval;

    const char* keywords[] = { "propId", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:VideoWriter.get", (char**)keywords, &pyobj_propId) &&
        pyopencv_to_safe(pyobj_propId, propId, ArgInfo("propId", 0)) )
    {
        ERRWRAP2(retval = _self_->get(propId));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_getBackendName(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getBackendName());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_isOpened(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isOpened());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_open(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_isColor = NULL;
    bool isColor=true;
    bool retval;

    const char* keywords[] = { "filename", "fourcc", "fps", "frameSize", "isColor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:VideoWriter.open", (char**)keywords, &pyobj_filename, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_isColor) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_isColor, isColor, ArgInfo("isColor", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, fourcc, fps, frameSize, isColor));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_isColor = NULL;
    bool isColor=true;
    bool retval;

    const char* keywords[] = { "filename", "apiPreference", "fourcc", "fps", "frameSize", "isColor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO|O:VideoWriter.open", (char**)keywords, &pyobj_filename, &pyobj_apiPreference, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_isColor) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_isColor, isColor, ArgInfo("isColor", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, apiPreference, fourcc, fps, frameSize, isColor));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_params = NULL;
    vector_int params;
    bool retval;

    const char* keywords[] = { "filename", "fourcc", "fps", "frameSize", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOO:VideoWriter.open", (char**)keywords, &pyobj_filename, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, fourcc, fps, frameSize, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_filename = NULL;
    String filename;
    PyObject* pyobj_apiPreference = NULL;
    int apiPreference=0;
    PyObject* pyobj_fourcc = NULL;
    int fourcc=0;
    PyObject* pyobj_fps = NULL;
    double fps=0;
    PyObject* pyobj_frameSize = NULL;
    Size frameSize;
    PyObject* pyobj_params = NULL;
    vector_int params;
    bool retval;

    const char* keywords[] = { "filename", "apiPreference", "fourcc", "fps", "frameSize", "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOOOO:VideoWriter.open", (char**)keywords, &pyobj_filename, &pyobj_apiPreference, &pyobj_fourcc, &pyobj_fps, &pyobj_frameSize, &pyobj_params) &&
        pyopencv_to_safe(pyobj_filename, filename, ArgInfo("filename", 4)) &&
        pyopencv_to_safe(pyobj_apiPreference, apiPreference, ArgInfo("apiPreference", 0)) &&
        pyopencv_to_safe(pyobj_fourcc, fourcc, ArgInfo("fourcc", 0)) &&
        pyopencv_to_safe(pyobj_fps, fps, ArgInfo("fps", 0)) &&
        pyopencv_to_safe(pyobj_frameSize, frameSize, ArgInfo("frameSize", 0)) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = _self_->open(filename, apiPreference, fourcc, fps, frameSize, params));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("open");

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_release(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->release());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_set(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);
    PyObject* pyobj_propId = NULL;
    int propId=0;
    PyObject* pyobj_value = NULL;
    double value=0;
    bool retval;

    const char* keywords[] = { "propId", "value", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:VideoWriter.set", (char**)keywords, &pyobj_propId, &pyobj_value) &&
        pyopencv_to_safe(pyobj_propId, propId, ArgInfo("propId", 0)) &&
        pyopencv_to_safe(pyobj_value, value, ArgInfo("value", 0)) )
    {
        ERRWRAP2(retval = _self_->set(propId, value));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_VideoWriter_write(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv;


    Ptr<cv::VideoWriter> * self1 = 0;
    if (!pyopencv_VideoWriter_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'VideoWriter' or its derivative)");
    Ptr<cv::VideoWriter> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;

    const char* keywords[] = { "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:VideoWriter.write", (char**)keywords, &pyobj_image) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) )
    {
        ERRWRAP2(_self_->write(image));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;

    const char* keywords[] = { "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:VideoWriter.write", (char**)keywords, &pyobj_image) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) )
    {
        ERRWRAP2(_self_->write(image));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("write");

    return NULL;
}



// Tables (VideoWriter)

static PyGetSetDef pyopencv_VideoWriter_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_VideoWriter_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_VideoWriter
    PYOPENCV_EXTRA_METHODS_VideoWriter
#endif
    {"fourcc", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_fourcc_static, METH_STATIC), "fourcc(c1, c2, c3, c4) -> retval\n.   @brief Concatenates 4 chars to a fourcc code\n.   \n.       @return a fourcc code\n.   \n.       This static method constructs the fourcc code of the codec to be used in the constructor\n.       VideoWriter::VideoWriter or VideoWriter::open."},
    {"get", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_get, 0), "get(propId) -> retval\n.   @brief Returns the specified VideoWriter property\n.   \n.        @param propId Property identifier from cv::VideoWriterProperties (eg. cv::VIDEOWRITER_PROP_QUALITY)\n.        or one of @ref videoio_flags_others\n.   \n.        @return Value for the specified property. Value 0 is returned when querying a property that is\n.        not supported by the backend used by the VideoWriter instance."},
    {"getBackendName", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_getBackendName, 0), "getBackendName() -> retval\n.   @brief Returns used backend API name\n.   \n.        @note Stream should be opened."},
    {"isOpened", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_isOpened, 0), "isOpened() -> retval\n.   @brief Returns true if video writer has been successfully initialized."},
    {"open", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_open, 0), "open(filename, fourcc, fps, frameSize[, isColor]) -> retval\n.   @brief Initializes or reinitializes video writer.\n.   \n.       The method opens video writer. Parameters are the same as in the constructor\n.       VideoWriter::VideoWriter.\n.       @return `true` if video writer has been successfully initialized\n.   \n.       The method first calls VideoWriter::release to close the already opened file.\n\n\n\nopen(filename, apiPreference, fourcc, fps, frameSize[, isColor]) -> retval\n.   @overload\n\n\n\nopen(filename, fourcc, fps, frameSize, params) -> retval\n.   @overload\n\n\n\nopen(filename, apiPreference, fourcc, fps, frameSize, params) -> retval\n.   @overload"},
    {"release", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_release, 0), "release() -> None\n.   @brief Closes the video writer.\n.   \n.       The method is automatically called by subsequent VideoWriter::open and by the VideoWriter\n.       destructor."},
    {"set", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_set, 0), "set(propId, value) -> retval\n.   @brief Sets a property in the VideoWriter.\n.   \n.        @param propId Property identifier from cv::VideoWriterProperties (eg. cv::VIDEOWRITER_PROP_QUALITY)\n.        or one of @ref videoio_flags_others\n.   \n.        @param value Value of the property.\n.        @return  `true` if the property is supported by the backend used by the VideoWriter instance."},
    {"write", CV_PY_FN_WITH_KW_(pyopencv_cv_VideoWriter_write, 0), "write(image) -> None\n.   @brief Writes the next video frame\n.   \n.       @param image The written frame. In general, color images are expected in BGR format.\n.   \n.       The function/method writes the specified image to video file. It must have the same size as has\n.       been specified when opening the video writer."},

    {NULL,          NULL}
};

// Converter (VideoWriter)

template<>
struct PyOpenCV_Converter< Ptr<cv::VideoWriter> >
{
    static PyObject* from(const Ptr<cv::VideoWriter>& r)
    {
        return pyopencv_VideoWriter_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::VideoWriter>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::VideoWriter> * dst_;
        if (pyopencv_VideoWriter_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::VideoWriter> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_BufferPool (Generic)
//================================================================================

// GetSet (cuda_BufferPool)



// Methods (cuda_BufferPool)

static int pyopencv_cv_cuda_cuda_BufferPool_BufferPool(pyopencv_cuda_BufferPool_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:BufferPool", (char**)keywords, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::BufferPool>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::BufferPool(stream)));
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_cuda_cuda_BufferPool_getAllocator(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::BufferPool> * self1 = 0;
    if (!pyopencv_cuda_BufferPool_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_BufferPool' or its derivative)");
    Ptr<cv::cuda::BufferPool> _self_ = *(self1);
    Ptr<GpuMat::Allocator> retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAllocator());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_BufferPool_getBuffer(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::BufferPool> * self1 = 0;
    if (!pyopencv_cuda_BufferPool_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_BufferPool' or its derivative)");
    Ptr<cv::cuda::BufferPool> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;
    GpuMat retval;

    const char* keywords[] = { "rows", "cols", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:cuda_BufferPool.getBuffer", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = _self_->getBuffer(rows, cols, type));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    GpuMat retval;

    const char* keywords[] = { "size", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_BufferPool.getBuffer", (char**)keywords, &pyobj_size, &pyobj_type) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(retval = _self_->getBuffer(size, type));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("getBuffer");

    return NULL;
}



// Tables (cuda_BufferPool)

static PyGetSetDef pyopencv_cuda_BufferPool_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_BufferPool_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_BufferPool
    PYOPENCV_EXTRA_METHODS_cuda_BufferPool
#endif
    {"getAllocator", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_BufferPool_getAllocator, 0), "getAllocator() -> retval\n."},
    {"getBuffer", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_BufferPool_getBuffer, 0), "getBuffer(rows, cols, type) -> retval\n.   \n\n\n\ngetBuffer(size, type) -> retval\n."},

    {NULL,          NULL}
};

// Converter (cuda_BufferPool)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::BufferPool> >
{
    static PyObject* from(const Ptr<cv::cuda::BufferPool>& r)
    {
        return pyopencv_cuda_BufferPool_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::BufferPool>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::BufferPool> * dst_;
        if (pyopencv_cuda_BufferPool_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::BufferPool> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_CLAHE (Generic)
//================================================================================

// GetSet (cuda_CLAHE)



// Methods (cuda_CLAHE)

static PyObject* pyopencv_cv_cuda_cuda_CLAHE_apply(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CLAHE> * self1 = 0;
    if (!pyopencv_cuda_CLAHE_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CLAHE' or its derivative)");
    Ptr<cv::cuda::CLAHE> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:cuda_CLAHE.apply", (char**)keywords, &pyobj_src, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->apply(src, dst, stream));
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

    const char* keywords[] = { "src", "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:cuda_CLAHE.apply", (char**)keywords, &pyobj_src, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->apply(src, dst, stream));
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

    const char* keywords[] = { "src", "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:cuda_CLAHE.apply", (char**)keywords, &pyobj_src, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->apply(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("apply");

    return NULL;
}



// Tables (cuda_CLAHE)

static PyGetSetDef pyopencv_cuda_CLAHE_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_CLAHE_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_CLAHE
    PYOPENCV_EXTRA_METHODS_cuda_CLAHE
#endif
    {"apply", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CLAHE_apply, 0), "apply(src, stream[, dst]) -> dst\n.   @brief Equalizes the histogram of a grayscale image using Contrast Limited Adaptive Histogram Equalization.\n.   \n.       @param src Source image with CV_8UC1 type.\n.       @param dst Destination image.\n.       @param stream Stream for the asynchronous version."},

    {NULL,          NULL}
};

// Converter (cuda_CLAHE)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::CLAHE> >
{
    static PyObject* from(const Ptr<cv::cuda::CLAHE>& r)
    {
        return pyopencv_cuda_CLAHE_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::CLAHE>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::CLAHE> * dst_;
        if (pyopencv_cuda_CLAHE_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::CLAHE> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_CannyEdgeDetector (Generic)
//================================================================================

// GetSet (cuda_CannyEdgeDetector)



// Methods (cuda_CannyEdgeDetector)

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_edges = NULL;
    Mat edges;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "edges", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_CannyEdgeDetector.detect", (char**)keywords, &pyobj_image, &pyobj_edges, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(image, edges, stream));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_edges = NULL;
    cuda::GpuMat edges;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "edges", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_CannyEdgeDetector.detect", (char**)keywords, &pyobj_image, &pyobj_edges, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(image, edges, stream));
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
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "dx", "dy", "edges", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cuda_CannyEdgeDetector.detect", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_edges, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(dx, dy, edges, stream));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dx = NULL;
    cuda::GpuMat dx;
    PyObject* pyobj_dy = NULL;
    cuda::GpuMat dy;
    PyObject* pyobj_edges = NULL;
    cuda::GpuMat edges;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "dx", "dy", "edges", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cuda_CannyEdgeDetector.detect", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_edges, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(dx, dy, edges, stream));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_edges = NULL;
    UMat edges;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "edges", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_CannyEdgeDetector.detect", (char**)keywords, &pyobj_image, &pyobj_edges, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(image, edges, stream));
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
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "dx", "dy", "edges", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cuda_CannyEdgeDetector.detect", (char**)keywords, &pyobj_dx, &pyobj_dy, &pyobj_edges, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_dx, dx, ArgInfo("dx", 0)) &&
        pyopencv_to_safe(pyobj_dy, dy, ArgInfo("dy", 0)) &&
        pyopencv_to_safe(pyobj_edges, edges, ArgInfo("edges", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(dx, dy, edges, stream));
        return pyopencv_from(edges);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_getAppertureSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getAppertureSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_getHighThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getHighThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_getL2Gradient(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getL2Gradient());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_getLowThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    double retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getLowThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_setAppertureSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    PyObject* pyobj_apperture_size = NULL;
    int apperture_size=0;

    const char* keywords[] = { "apperture_size", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_CannyEdgeDetector.setAppertureSize", (char**)keywords, &pyobj_apperture_size) &&
        pyopencv_to_safe(pyobj_apperture_size, apperture_size, ArgInfo("apperture_size", 0)) )
    {
        ERRWRAP2(_self_->setAppertureSize(apperture_size));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_setHighThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    PyObject* pyobj_high_thresh = NULL;
    double high_thresh=0;

    const char* keywords[] = { "high_thresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_CannyEdgeDetector.setHighThreshold", (char**)keywords, &pyobj_high_thresh) &&
        pyopencv_to_safe(pyobj_high_thresh, high_thresh, ArgInfo("high_thresh", 0)) )
    {
        ERRWRAP2(_self_->setHighThreshold(high_thresh));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_setL2Gradient(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=0;

    const char* keywords[] = { "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_CannyEdgeDetector.setL2Gradient", (char**)keywords, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(_self_->setL2Gradient(L2gradient));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CannyEdgeDetector_setLowThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CannyEdgeDetector> * self1 = 0;
    if (!pyopencv_cuda_CannyEdgeDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CannyEdgeDetector' or its derivative)");
    Ptr<cv::cuda::CannyEdgeDetector> _self_ = *(self1);
    PyObject* pyobj_low_thresh = NULL;
    double low_thresh=0;

    const char* keywords[] = { "low_thresh", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_CannyEdgeDetector.setLowThreshold", (char**)keywords, &pyobj_low_thresh) &&
        pyopencv_to_safe(pyobj_low_thresh, low_thresh, ArgInfo("low_thresh", 0)) )
    {
        ERRWRAP2(_self_->setLowThreshold(low_thresh));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_CannyEdgeDetector)

static PyGetSetDef pyopencv_cuda_CannyEdgeDetector_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_CannyEdgeDetector_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_CannyEdgeDetector
    PYOPENCV_EXTRA_METHODS_cuda_CannyEdgeDetector
#endif
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_detect, 0), "detect(image[, edges[, stream]]) -> edges\n.   @brief Finds edges in an image using the @cite Canny86 algorithm.\n.   \n.       @param image Single-channel 8-bit input image.\n.       @param edges Output edge map. It has the same size and type as image.\n.       @param stream Stream for the asynchronous version.\n\n\n\ndetect(dx, dy[, edges[, stream]]) -> edges\n.   @overload\n.       @param dx First derivative of image in the vertical direction. Support only CV_32S type.\n.       @param dy First derivative of image in the horizontal direction. Support only CV_32S type.\n.       @param edges Output edge map. It has the same size and type as image.\n.       @param stream Stream for the asynchronous version."},
    {"getAppertureSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_getAppertureSize, 0), "getAppertureSize() -> retval\n."},
    {"getHighThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_getHighThreshold, 0), "getHighThreshold() -> retval\n."},
    {"getL2Gradient", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_getL2Gradient, 0), "getL2Gradient() -> retval\n."},
    {"getLowThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_getLowThreshold, 0), "getLowThreshold() -> retval\n."},
    {"setAppertureSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_setAppertureSize, 0), "setAppertureSize(apperture_size) -> None\n."},
    {"setHighThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_setHighThreshold, 0), "setHighThreshold(high_thresh) -> None\n."},
    {"setL2Gradient", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_setL2Gradient, 0), "setL2Gradient(L2gradient) -> None\n."},
    {"setLowThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CannyEdgeDetector_setLowThreshold, 0), "setLowThreshold(low_thresh) -> None\n."},

    {NULL,          NULL}
};

// Converter (cuda_CannyEdgeDetector)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::CannyEdgeDetector> >
{
    static PyObject* from(const Ptr<cv::cuda::CannyEdgeDetector>& r)
    {
        return pyopencv_cuda_CannyEdgeDetector_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::CannyEdgeDetector>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::CannyEdgeDetector> * dst_;
        if (pyopencv_cuda_CannyEdgeDetector_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::CannyEdgeDetector> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_Convolution (Generic)
//================================================================================

// GetSet (cuda_Convolution)



// Methods (cuda_Convolution)

static PyObject* pyopencv_cv_cuda_cuda_Convolution_convolve(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Convolution> * self1 = 0;
    if (!pyopencv_cuda_Convolution_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Convolution' or its derivative)");
    Ptr<cv::cuda::Convolution> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_templ = NULL;
    Mat templ;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_ccorr = NULL;
    bool ccorr=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "templ", "result", "ccorr", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cuda_Convolution.convolve", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_result, &pyobj_ccorr, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_ccorr, ccorr, ArgInfo("ccorr", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->convolve(image, templ, result, ccorr, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_templ = NULL;
    cuda::GpuMat templ;
    PyObject* pyobj_result = NULL;
    cuda::GpuMat result;
    PyObject* pyobj_ccorr = NULL;
    bool ccorr=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "templ", "result", "ccorr", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cuda_Convolution.convolve", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_result, &pyobj_ccorr, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_ccorr, ccorr, ArgInfo("ccorr", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->convolve(image, templ, result, ccorr, stream));
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
    PyObject* pyobj_ccorr = NULL;
    bool ccorr=false;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "templ", "result", "ccorr", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OOO:cuda_Convolution.convolve", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_result, &pyobj_ccorr, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_ccorr, ccorr, ArgInfo("ccorr", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->convolve(image, templ, result, ccorr, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convolve");

    return NULL;
}



// Tables (cuda_Convolution)

static PyGetSetDef pyopencv_cuda_Convolution_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_Convolution_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_Convolution
    PYOPENCV_EXTRA_METHODS_cuda_Convolution
#endif
    {"convolve", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Convolution_convolve, 0), "convolve(image, templ[, result[, ccorr[, stream]]]) -> result\n.   @brief Computes a convolution (or cross-correlation) of two images.\n.   \n.       @param image Source image. Only CV_32FC1 images are supported for now.\n.       @param templ Template image. The size is not greater than the image size. The type is the same as\n.       image .\n.       @param result Result image. If image is *W x H* and templ is *w x h*, then result must be *W-w+1 x\n.       H-h+1*.\n.       @param ccorr Flags to evaluate cross-correlation instead of convolution.\n.       @param stream Stream for the asynchronous version."},

    {NULL,          NULL}
};

// Converter (cuda_Convolution)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::Convolution> >
{
    static PyObject* from(const Ptr<cv::cuda::Convolution>& r)
    {
        return pyopencv_cuda_Convolution_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::Convolution>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::Convolution> * dst_;
        if (pyopencv_cuda_Convolution_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::Convolution> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_CornernessCriteria (Generic)
//================================================================================

// GetSet (cuda_CornernessCriteria)



// Methods (cuda_CornernessCriteria)

static PyObject* pyopencv_cv_cuda_cuda_CornernessCriteria_compute(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CornernessCriteria> * self1 = 0;
    if (!pyopencv_cuda_CornernessCriteria_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CornernessCriteria' or its derivative)");
    Ptr<cv::cuda::CornernessCriteria> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_CornernessCriteria.compute", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->compute(src, dst, stream));
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_CornernessCriteria.compute", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->compute(src, dst, stream));
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_CornernessCriteria.compute", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->compute(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("compute");

    return NULL;
}



// Tables (cuda_CornernessCriteria)

static PyGetSetDef pyopencv_cuda_CornernessCriteria_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_CornernessCriteria_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_CornernessCriteria
    PYOPENCV_EXTRA_METHODS_cuda_CornernessCriteria
#endif
    {"compute", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CornernessCriteria_compute, 0), "compute(src[, dst[, stream]]) -> dst\n.   @brief Computes the cornerness criteria at each image pixel.\n.   \n.       @param src Source image.\n.       @param dst Destination image containing cornerness values. It will have the same size as src and\n.       CV_32FC1 type.\n.       @param stream Stream for the asynchronous version."},

    {NULL,          NULL}
};

// Converter (cuda_CornernessCriteria)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::CornernessCriteria> >
{
    static PyObject* from(const Ptr<cv::cuda::CornernessCriteria>& r)
    {
        return pyopencv_cuda_CornernessCriteria_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::CornernessCriteria>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::CornernessCriteria> * dst_;
        if (pyopencv_cuda_CornernessCriteria_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::CornernessCriteria> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_CornersDetector (Generic)
//================================================================================

// GetSet (cuda_CornersDetector)



// Methods (cuda_CornersDetector)

static PyObject* pyopencv_cv_cuda_cuda_CornersDetector_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CornersDetector> * self1 = 0;
    if (!pyopencv_cuda_CornersDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CornersDetector' or its derivative)");
    Ptr<cv::cuda::CornersDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_corners = NULL;
    Mat corners;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "corners", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_CornersDetector.detect", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(image, corners, mask, stream));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_corners = NULL;
    cuda::GpuMat corners;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "corners", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_CornersDetector.detect", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(image, corners, mask, stream));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_corners = NULL;
    UMat corners;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "corners", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_CornersDetector.detect", (char**)keywords, &pyobj_image, &pyobj_corners, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_corners, corners, ArgInfo("corners", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(image, corners, mask, stream));
        return pyopencv_from(corners);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CornersDetector_setMaxCorners(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CornersDetector> * self1 = 0;
    if (!pyopencv_cuda_CornersDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CornersDetector' or its derivative)");
    Ptr<cv::cuda::CornersDetector> _self_ = *(self1);
    PyObject* pyobj_maxCorners = NULL;
    int maxCorners=0;

    const char* keywords[] = { "maxCorners", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_CornersDetector.setMaxCorners", (char**)keywords, &pyobj_maxCorners) &&
        pyopencv_to_safe(pyobj_maxCorners, maxCorners, ArgInfo("maxCorners", 0)) )
    {
        ERRWRAP2(_self_->setMaxCorners(maxCorners));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_CornersDetector_setMinDistance(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::CornersDetector> * self1 = 0;
    if (!pyopencv_cuda_CornersDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_CornersDetector' or its derivative)");
    Ptr<cv::cuda::CornersDetector> _self_ = *(self1);
    PyObject* pyobj_minDistance = NULL;
    double minDistance=0;

    const char* keywords[] = { "minDistance", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_CornersDetector.setMinDistance", (char**)keywords, &pyobj_minDistance) &&
        pyopencv_to_safe(pyobj_minDistance, minDistance, ArgInfo("minDistance", 0)) )
    {
        ERRWRAP2(_self_->setMinDistance(minDistance));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_CornersDetector)

static PyGetSetDef pyopencv_cuda_CornersDetector_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_CornersDetector_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_CornersDetector
    PYOPENCV_EXTRA_METHODS_cuda_CornersDetector
#endif
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CornersDetector_detect, 0), "detect(image[, corners[, mask[, stream]]]) -> corners\n.   @brief Determines strong corners on an image.\n.   \n.       @param image Input 8-bit or floating-point 32-bit, single-channel image.\n.       @param corners Output vector of detected corners (1-row matrix with CV_32FC2 type with corners\n.       positions).\n.       @param mask Optional region of interest. If the image is not empty (it needs to have the type\n.       CV_8UC1 and the same size as image ), it specifies the region in which the corners are detected.\n.       @param stream Stream for the asynchronous version."},
    {"setMaxCorners", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CornersDetector_setMaxCorners, 0), "setMaxCorners(maxCorners) -> None\n."},
    {"setMinDistance", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_CornersDetector_setMinDistance, 0), "setMinDistance(minDistance) -> None\n."},

    {NULL,          NULL}
};

// Converter (cuda_CornersDetector)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::CornersDetector> >
{
    static PyObject* from(const Ptr<cv::cuda::CornersDetector>& r)
    {
        return pyopencv_cuda_CornersDetector_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::CornersDetector>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::CornersDetector> * dst_;
        if (pyopencv_cuda_CornersDetector_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::CornersDetector> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_DFT (Generic)
//================================================================================

// GetSet (cuda_DFT)



// Methods (cuda_DFT)

static PyObject* pyopencv_cv_cuda_cuda_DFT_compute(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DFT> * self1 = 0;
    if (!pyopencv_cuda_DFT_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DFT' or its derivative)");
    Ptr<cv::cuda::DFT> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_DFT.compute", (char**)keywords, &pyobj_image, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->compute(image, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_result = NULL;
    cuda::GpuMat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_DFT.compute", (char**)keywords, &pyobj_image, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->compute(image, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    PyObject* pyobj_result = NULL;
    UMat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_DFT.compute", (char**)keywords, &pyobj_image, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->compute(image, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("compute");

    return NULL;
}



// Tables (cuda_DFT)

static PyGetSetDef pyopencv_cuda_DFT_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_DFT_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_DFT
    PYOPENCV_EXTRA_METHODS_cuda_DFT
#endif
    {"compute", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DFT_compute, 0), "compute(image[, result[, stream]]) -> result\n.   @brief Computes an FFT of a given image.\n.   \n.       @param image Source image. Only CV_32FC1 images are supported for now.\n.       @param result Result image.\n.       @param stream Stream for the asynchronous version."},

    {NULL,          NULL}
};

// Converter (cuda_DFT)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::DFT> >
{
    static PyObject* from(const Ptr<cv::cuda::DFT>& r)
    {
        return pyopencv_cuda_DFT_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::DFT>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::DFT> * dst_;
        if (pyopencv_cuda_DFT_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::DFT> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_DeviceInfo (Generic)
//================================================================================

// GetSet (cuda_DeviceInfo)



// Methods (cuda_DeviceInfo)

static int pyopencv_cv_cuda_cuda_DeviceInfo_DeviceInfo(pyopencv_cuda_DeviceInfo_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(2);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::cuda::DeviceInfo>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::DeviceInfo()));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_device_id = NULL;
    int device_id=0;

    const char* keywords[] = { "device_id", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:DeviceInfo", (char**)keywords, &pyobj_device_id) &&
        pyopencv_to_safe(pyobj_device_id, device_id, ArgInfo("device_id", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::DeviceInfo>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::DeviceInfo(device_id)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("DeviceInfo");

    return -1;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_ECCEnabled(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->ECCEnabled());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_asyncEngineCount(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->asyncEngineCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_canMapHostMemory(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->canMapHostMemory());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_clockRate(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->clockRate());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_computeMode(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    DeviceInfo::ComputeMode retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->computeMode());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_concurrentKernels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->concurrentKernels());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_deviceID(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->deviceID());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_freeMemory(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->freeMemory());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_integrated(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->integrated());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_isCompatible(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isCompatible());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_kernelExecTimeoutEnabled(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->kernelExecTimeoutEnabled());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_l2CacheSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->l2CacheSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_majorVersion(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->majorVersion());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxGridSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxGridSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface1D(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurface1D());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface1DLayered(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurface1DLayered());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface2D(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurface2D());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface2DLayered(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurface2DLayered());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface3D(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurface3D());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurfaceCubemap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurfaceCubemap());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxSurfaceCubemapLayered(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSurfaceCubemapLayered());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1D(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture1D());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1DLayered(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture1DLayered());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1DLinear(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture1DLinear());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1DMipmap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture1DMipmap());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2D(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture2D());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DGather(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture2DGather());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DLayered(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture2DLayered());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DLinear(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture2DLinear());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DMipmap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture2DMipmap());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture3D(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTexture3D());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTextureCubemap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTextureCubemap());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxTextureCubemapLayered(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec2i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxTextureCubemapLayered());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxThreadsDim(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    Vec3i retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxThreadsDim());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxThreadsPerBlock(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxThreadsPerBlock());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_maxThreadsPerMultiProcessor(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxThreadsPerMultiProcessor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_memPitch(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->memPitch());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_memoryBusWidth(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->memoryBusWidth());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_memoryClockRate(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->memoryClockRate());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_minorVersion(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->minorVersion());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_multiProcessorCount(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->multiProcessorCount());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_pciBusID(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->pciBusID());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_pciDeviceID(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->pciDeviceID());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_pciDomainID(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->pciDomainID());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_queryMemory(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    PyObject* pyobj_totalMemory = NULL;
    size_t totalMemory=0;
    PyObject* pyobj_freeMemory = NULL;
    size_t freeMemory=0;

    const char* keywords[] = { "totalMemory", "freeMemory", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_DeviceInfo.queryMemory", (char**)keywords, &pyobj_totalMemory, &pyobj_freeMemory) &&
        pyopencv_to_safe(pyobj_totalMemory, totalMemory, ArgInfo("totalMemory", 0)) &&
        pyopencv_to_safe(pyobj_freeMemory, freeMemory, ArgInfo("freeMemory", 0)) )
    {
        ERRWRAP2(_self_->queryMemory(totalMemory, freeMemory));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_regsPerBlock(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->regsPerBlock());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_sharedMemPerBlock(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->sharedMemPerBlock());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_surfaceAlignment(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->surfaceAlignment());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_tccDriver(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->tccDriver());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_textureAlignment(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->textureAlignment());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_texturePitchAlignment(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->texturePitchAlignment());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_totalConstMem(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->totalConstMem());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_totalGlobalMem(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->totalGlobalMem());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_totalMemory(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->totalMemory());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_unifiedAddressing(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->unifiedAddressing());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_DeviceInfo_warpSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::DeviceInfo> * self1 = 0;
    if (!pyopencv_cuda_DeviceInfo_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_DeviceInfo' or its derivative)");
    Ptr<cv::cuda::DeviceInfo> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->warpSize());
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (cuda_DeviceInfo)

static PyGetSetDef pyopencv_cuda_DeviceInfo_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_DeviceInfo_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_DeviceInfo
    PYOPENCV_EXTRA_METHODS_cuda_DeviceInfo
#endif
    {"ECCEnabled", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_ECCEnabled, 0), "ECCEnabled() -> retval\n."},
    {"asyncEngineCount", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_asyncEngineCount, 0), "asyncEngineCount() -> retval\n."},
    {"canMapHostMemory", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_canMapHostMemory, 0), "canMapHostMemory() -> retval\n."},
    {"clockRate", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_clockRate, 0), "clockRate() -> retval\n."},
    {"computeMode", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_computeMode, 0), "computeMode() -> retval\n."},
    {"concurrentKernels", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_concurrentKernels, 0), "concurrentKernels() -> retval\n."},
    {"deviceID", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_deviceID, 0), "deviceID() -> retval\n.   @brief Returns system index of the CUDA device starting with 0."},
    {"freeMemory", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_freeMemory, 0), "freeMemory() -> retval\n."},
    {"integrated", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_integrated, 0), "integrated() -> retval\n."},
    {"isCompatible", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_isCompatible, 0), "isCompatible() -> retval\n.   @brief Checks the CUDA module and device compatibility.\n.   \n.       This function returns true if the CUDA module can be run on the specified device. Otherwise, it\n.       returns false ."},
    {"kernelExecTimeoutEnabled", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_kernelExecTimeoutEnabled, 0), "kernelExecTimeoutEnabled() -> retval\n."},
    {"l2CacheSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_l2CacheSize, 0), "l2CacheSize() -> retval\n."},
    {"majorVersion", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_majorVersion, 0), "majorVersion() -> retval\n."},
    {"maxGridSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxGridSize, 0), "maxGridSize() -> retval\n."},
    {"maxSurface1D", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface1D, 0), "maxSurface1D() -> retval\n."},
    {"maxSurface1DLayered", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface1DLayered, 0), "maxSurface1DLayered() -> retval\n."},
    {"maxSurface2D", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface2D, 0), "maxSurface2D() -> retval\n."},
    {"maxSurface2DLayered", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface2DLayered, 0), "maxSurface2DLayered() -> retval\n."},
    {"maxSurface3D", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurface3D, 0), "maxSurface3D() -> retval\n."},
    {"maxSurfaceCubemap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurfaceCubemap, 0), "maxSurfaceCubemap() -> retval\n."},
    {"maxSurfaceCubemapLayered", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxSurfaceCubemapLayered, 0), "maxSurfaceCubemapLayered() -> retval\n."},
    {"maxTexture1D", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1D, 0), "maxTexture1D() -> retval\n."},
    {"maxTexture1DLayered", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1DLayered, 0), "maxTexture1DLayered() -> retval\n."},
    {"maxTexture1DLinear", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1DLinear, 0), "maxTexture1DLinear() -> retval\n."},
    {"maxTexture1DMipmap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture1DMipmap, 0), "maxTexture1DMipmap() -> retval\n."},
    {"maxTexture2D", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2D, 0), "maxTexture2D() -> retval\n."},
    {"maxTexture2DGather", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DGather, 0), "maxTexture2DGather() -> retval\n."},
    {"maxTexture2DLayered", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DLayered, 0), "maxTexture2DLayered() -> retval\n."},
    {"maxTexture2DLinear", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DLinear, 0), "maxTexture2DLinear() -> retval\n."},
    {"maxTexture2DMipmap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture2DMipmap, 0), "maxTexture2DMipmap() -> retval\n."},
    {"maxTexture3D", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTexture3D, 0), "maxTexture3D() -> retval\n."},
    {"maxTextureCubemap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTextureCubemap, 0), "maxTextureCubemap() -> retval\n."},
    {"maxTextureCubemapLayered", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxTextureCubemapLayered, 0), "maxTextureCubemapLayered() -> retval\n."},
    {"maxThreadsDim", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxThreadsDim, 0), "maxThreadsDim() -> retval\n."},
    {"maxThreadsPerBlock", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxThreadsPerBlock, 0), "maxThreadsPerBlock() -> retval\n."},
    {"maxThreadsPerMultiProcessor", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_maxThreadsPerMultiProcessor, 0), "maxThreadsPerMultiProcessor() -> retval\n."},
    {"memPitch", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_memPitch, 0), "memPitch() -> retval\n."},
    {"memoryBusWidth", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_memoryBusWidth, 0), "memoryBusWidth() -> retval\n."},
    {"memoryClockRate", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_memoryClockRate, 0), "memoryClockRate() -> retval\n."},
    {"minorVersion", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_minorVersion, 0), "minorVersion() -> retval\n."},
    {"multiProcessorCount", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_multiProcessorCount, 0), "multiProcessorCount() -> retval\n."},
    {"pciBusID", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_pciBusID, 0), "pciBusID() -> retval\n."},
    {"pciDeviceID", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_pciDeviceID, 0), "pciDeviceID() -> retval\n."},
    {"pciDomainID", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_pciDomainID, 0), "pciDomainID() -> retval\n."},
    {"queryMemory", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_queryMemory, 0), "queryMemory(totalMemory, freeMemory) -> None\n."},
    {"regsPerBlock", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_regsPerBlock, 0), "regsPerBlock() -> retval\n."},
    {"sharedMemPerBlock", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_sharedMemPerBlock, 0), "sharedMemPerBlock() -> retval\n."},
    {"surfaceAlignment", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_surfaceAlignment, 0), "surfaceAlignment() -> retval\n."},
    {"tccDriver", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_tccDriver, 0), "tccDriver() -> retval\n."},
    {"textureAlignment", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_textureAlignment, 0), "textureAlignment() -> retval\n."},
    {"texturePitchAlignment", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_texturePitchAlignment, 0), "texturePitchAlignment() -> retval\n."},
    {"totalConstMem", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_totalConstMem, 0), "totalConstMem() -> retval\n."},
    {"totalGlobalMem", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_totalGlobalMem, 0), "totalGlobalMem() -> retval\n."},
    {"totalMemory", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_totalMemory, 0), "totalMemory() -> retval\n."},
    {"unifiedAddressing", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_unifiedAddressing, 0), "unifiedAddressing() -> retval\n."},
    {"warpSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_DeviceInfo_warpSize, 0), "warpSize() -> retval\n."},

    {NULL,          NULL}
};

// Converter (cuda_DeviceInfo)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::DeviceInfo> >
{
    static PyObject* from(const Ptr<cv::cuda::DeviceInfo>& r)
    {
        return pyopencv_cuda_DeviceInfo_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::DeviceInfo>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::DeviceInfo> * dst_;
        if (pyopencv_cuda_DeviceInfo_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::DeviceInfo> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_Event (Generic)
//================================================================================

// GetSet (cuda_Event)



// Methods (cuda_Event)

static int pyopencv_cv_cuda_cuda_Event_Event(pyopencv_cuda_Event_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_flags = NULL;
    Event_CreateFlags flags=Event::CreateFlags::DEFAULT;

    const char* keywords[] = { "flags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:Event", (char**)keywords, &pyobj_flags) &&
        pyopencv_to_safe(pyobj_flags, flags, ArgInfo("flags", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::Event>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::Event(flags)));
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_cuda_cuda_Event_elapsedTime_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_start = NULL;
    Event start;
    PyObject* pyobj_end = NULL;
    Event end;
    float retval;

    const char* keywords[] = { "start", "end", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_Event.elapsedTime", (char**)keywords, &pyobj_start, &pyobj_end) &&
        pyopencv_to_safe(pyobj_start, start, ArgInfo("start", 0)) &&
        pyopencv_to_safe(pyobj_end, end, ArgInfo("end", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::Event::elapsedTime(start, end));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_Event_queryIfComplete(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Event> * self1 = 0;
    if (!pyopencv_cuda_Event_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Event' or its derivative)");
    Ptr<cv::cuda::Event> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->queryIfComplete());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_Event_record(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Event> * self1 = 0;
    if (!pyopencv_cuda_Event_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Event' or its derivative)");
    Ptr<cv::cuda::Event> _self_ = *(self1);
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:cuda_Event.record", (char**)keywords, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->record(stream));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_Event_waitForCompletion(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Event> * self1 = 0;
    if (!pyopencv_cuda_Event_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Event' or its derivative)");
    Ptr<cv::cuda::Event> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->waitForCompletion());
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_Event)

static PyGetSetDef pyopencv_cuda_Event_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_Event_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_Event
    PYOPENCV_EXTRA_METHODS_cuda_Event
#endif
    {"elapsedTime", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Event_elapsedTime_static, METH_STATIC), "elapsedTime(start, end) -> retval\n."},
    {"queryIfComplete", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Event_queryIfComplete, 0), "queryIfComplete() -> retval\n."},
    {"record", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Event_record, 0), "record([, stream]) -> None\n."},
    {"waitForCompletion", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Event_waitForCompletion, 0), "waitForCompletion() -> None\n."},

    {NULL,          NULL}
};

// Converter (cuda_Event)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::Event> >
{
    static PyObject* from(const Ptr<cv::cuda::Event>& r)
    {
        return pyopencv_cuda_Event_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::Event>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::Event> * dst_;
        if (pyopencv_cuda_Event_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::Event> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_GpuData (Generic)
//================================================================================

// GetSet (cuda_GpuData)



// Methods (cuda_GpuData)



// Tables (cuda_GpuData)

static PyGetSetDef pyopencv_cuda_GpuData_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_GpuData_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_GpuData
    PYOPENCV_EXTRA_METHODS_cuda_GpuData
#endif

    {NULL,          NULL}
};

// Converter (cuda_GpuData)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::GpuData> >
{
    static PyObject* from(const Ptr<cv::cuda::GpuData>& r)
    {
        return pyopencv_cuda_GpuData_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::GpuData>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::GpuData> * dst_;
        if (pyopencv_cuda_GpuData_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::GpuData> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_GpuMat (Generic)
//================================================================================

// GetSet (cuda_GpuMat)


static PyObject* pyopencv_cuda_GpuMat_get_step(pyopencv_cuda_GpuMat_t* p, void *closure)
{
    return pyopencv_from(p->v->step);
}


// Methods (cuda_GpuMat)

static int pyopencv_cv_cuda_cuda_GpuMat_GpuMat(pyopencv_cuda_GpuMat_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(11);

    {
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:GpuMat", (char**)keywords, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(allocator)));
        return 0;
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
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "rows", "cols", "type", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:GpuMat", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(rows, cols, type, allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "size", "type", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:GpuMat", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(size, type, allocator)));
        return 0;
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
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "rows", "cols", "type", "s", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:GpuMat", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_s, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(rows, cols, type, s, allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "size", "type", "s", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:GpuMat", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_s, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(size, type, s, allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    GpuMat m;

    const char* keywords[] = { "m", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:GpuMat", (char**)keywords, &pyobj_m) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(m)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    GpuMat m;
    PyObject* pyobj_rowRange = NULL;
    Range rowRange;
    PyObject* pyobj_colRange = NULL;
    Range colRange;

    const char* keywords[] = { "m", "rowRange", "colRange", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:GpuMat", (char**)keywords, &pyobj_m, &pyobj_rowRange, &pyobj_colRange) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_rowRange, rowRange, ArgInfo("rowRange", 0)) &&
        pyopencv_to_safe(pyobj_colRange, colRange, ArgInfo("colRange", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(m, rowRange, colRange)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_m = NULL;
    GpuMat m;
    PyObject* pyobj_roi = NULL;
    Rect roi;

    const char* keywords[] = { "m", "roi", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:GpuMat", (char**)keywords, &pyobj_m, &pyobj_roi) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_roi, roi, ArgInfo("roi", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(m, roi)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    Mat arr;
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "arr", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:GpuMat", (char**)keywords, &pyobj_arr, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(arr, allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "arr", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:GpuMat", (char**)keywords, &pyobj_arr, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(arr, allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    UMat arr;
    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator=GpuMat::defaultAllocator();

    const char* keywords[] = { "arr", "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:GpuMat", (char**)keywords, &pyobj_arr, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::GpuMat>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::GpuMat(arr, allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("GpuMat");

    return -1;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_adjustROI(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_dtop = NULL;
    int dtop=0;
    PyObject* pyobj_dbottom = NULL;
    int dbottom=0;
    PyObject* pyobj_dleft = NULL;
    int dleft=0;
    PyObject* pyobj_dright = NULL;
    int dright=0;
    GpuMat retval;

    const char* keywords[] = { "dtop", "dbottom", "dleft", "dright", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO:cuda_GpuMat.adjustROI", (char**)keywords, &pyobj_dtop, &pyobj_dbottom, &pyobj_dleft, &pyobj_dright) &&
        pyopencv_to_safe(pyobj_dtop, dtop, ArgInfo("dtop", 0)) &&
        pyopencv_to_safe(pyobj_dbottom, dbottom, ArgInfo("dbottom", 0)) &&
        pyopencv_to_safe(pyobj_dleft, dleft, ArgInfo("dleft", 0)) &&
        pyopencv_to_safe(pyobj_dright, dright, ArgInfo("dright", 0)) )
    {
        ERRWRAP2(retval = _self_->adjustROI(dtop, dbottom, dleft, dright));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_assignTo(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_m = NULL;
    GpuMat m;
    PyObject* pyobj_type = NULL;
    int type=-1;

    const char* keywords[] = { "m", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.assignTo", (char**)keywords, &pyobj_m, &pyobj_type) &&
        pyopencv_to_safe(pyobj_m, m, ArgInfo("m", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(_self_->assignTo(m, type));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_channels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->channels());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_clone(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    GpuMat retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->clone());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_col(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_x = NULL;
    int x=0;
    GpuMat retval;

    const char* keywords[] = { "x", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.col", (char**)keywords, &pyobj_x) &&
        pyopencv_to_safe(pyobj_x, x, ArgInfo("x", 0)) )
    {
        ERRWRAP2(retval = _self_->col(x));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_colRange(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_startcol = NULL;
    int startcol=0;
    PyObject* pyobj_endcol = NULL;
    int endcol=0;
    GpuMat retval;

    const char* keywords[] = { "startcol", "endcol", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.colRange", (char**)keywords, &pyobj_startcol, &pyobj_endcol) &&
        pyopencv_to_safe(pyobj_startcol, startcol, ArgInfo("startcol", 0)) &&
        pyopencv_to_safe(pyobj_endcol, endcol, ArgInfo("endcol", 0)) )
    {
        ERRWRAP2(retval = _self_->colRange(startcol, endcol));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_r = NULL;
    Range r;
    GpuMat retval;

    const char* keywords[] = { "r", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.colRange", (char**)keywords, &pyobj_r) &&
        pyopencv_to_safe(pyobj_r, r, ArgInfo("r", 0)) )
    {
        ERRWRAP2(retval = _self_->colRange(r));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("colRange");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_convertTo(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;

    const char* keywords[] = { "rtype", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.convertTo", (char**)keywords, &pyobj_rtype, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rtype, rtype, ArgInfo("rtype", 0)) )
    {
        ERRWRAP2(_self_->convertTo(dst, rtype));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "rtype", "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:cuda_GpuMat.convertTo", (char**)keywords, &pyobj_rtype, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->convertTo(dst, rtype, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_alpha = NULL;
    double alpha=1.0;
    PyObject* pyobj_beta = NULL;
    double beta=0.0;

    const char* keywords[] = { "rtype", "dst", "alpha", "beta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_GpuMat.convertTo", (char**)keywords, &pyobj_rtype, &pyobj_dst, &pyobj_alpha, &pyobj_beta) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) )
    {
        ERRWRAP2(_self_->convertTo(dst, rtype, alpha, beta));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_rtype = NULL;
    int rtype=0;
    PyObject* pyobj_alpha = NULL;
    double alpha=0;
    PyObject* pyobj_beta = NULL;
    double beta=0;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "rtype", "alpha", "beta", "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOOO|O:cuda_GpuMat.convertTo", (char**)keywords, &pyobj_rtype, &pyobj_alpha, &pyobj_beta, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_rtype, rtype, ArgInfo("rtype", 0)) &&
        pyopencv_to_safe(pyobj_alpha, alpha, ArgInfo("alpha", 0)) &&
        pyopencv_to_safe(pyobj_beta, beta, ArgInfo("beta", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->convertTo(dst, rtype, alpha, beta, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("convertTo");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_copyTo(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(4);

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;

    const char* keywords[] = { "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:cuda_GpuMat.copyTo", (char**)keywords, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->copyTo(dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.copyTo", (char**)keywords, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->copyTo(dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_mask = NULL;
    GpuMat mask;

    const char* keywords[] = { "mask", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.copyTo", (char**)keywords, &pyobj_mask, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(_self_->copyTo(dst, mask));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    GpuMat dst;
    PyObject* pyobj_mask = NULL;
    GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "mask", "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:cuda_GpuMat.copyTo", (char**)keywords, &pyobj_mask, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->copyTo(dst, mask, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("copyTo");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_create(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "rows", "cols", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:cuda_GpuMat.create", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(_self_->create(rows, cols, type));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "size", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.create", (char**)keywords, &pyobj_size, &pyobj_type) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(_self_->create(size, type));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("create");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_cudaPtr(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    void* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->cudaPtr());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_defaultAllocator_static(PyObject* self, PyObject* py_args, PyObject* kw)
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

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_depth(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->depth());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_download(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;

    const char* keywords[] = { "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:cuda_GpuMat.download", (char**)keywords, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->download(dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;

    const char* keywords[] = { "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:cuda_GpuMat.download", (char**)keywords, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->download(dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.download", (char**)keywords, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->download(dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    cuda::GpuMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.download", (char**)keywords, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->download(dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;

    const char* keywords[] = { "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:cuda_GpuMat.download", (char**)keywords, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) )
    {
        ERRWRAP2(_self_->download(dst));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_dst = NULL;
    UMat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "stream", "dst", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.download", (char**)keywords, &pyobj_stream, &pyobj_dst) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->download(dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("download");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_elemSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->elemSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_elemSize1(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->elemSize1());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_empty(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->empty());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_getStdAllocator_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    GpuMat::Allocator* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = cv::cuda::GpuMat::getStdAllocator());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_isContinuous(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isContinuous());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_locateROI(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_wholeSize = NULL;
    Size wholeSize;
    PyObject* pyobj_ofs = NULL;
    Point ofs;

    const char* keywords[] = { "wholeSize", "ofs", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.locateROI", (char**)keywords, &pyobj_wholeSize, &pyobj_ofs) &&
        pyopencv_to_safe(pyobj_wholeSize, wholeSize, ArgInfo("wholeSize", 0)) &&
        pyopencv_to_safe(pyobj_ofs, ofs, ArgInfo("ofs", 0)) )
    {
        ERRWRAP2(_self_->locateROI(wholeSize, ofs));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_release(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->release());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_reshape(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_cn = NULL;
    int cn=0;
    PyObject* pyobj_rows = NULL;
    int rows=0;
    GpuMat retval;

    const char* keywords[] = { "cn", "rows", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_GpuMat.reshape", (char**)keywords, &pyobj_cn, &pyobj_rows) &&
        pyopencv_to_safe(pyobj_cn, cn, ArgInfo("cn", 0)) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) )
    {
        ERRWRAP2(retval = _self_->reshape(cn, rows));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_row(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_y = NULL;
    int y=0;
    GpuMat retval;

    const char* keywords[] = { "y", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.row", (char**)keywords, &pyobj_y) &&
        pyopencv_to_safe(pyobj_y, y, ArgInfo("y", 0)) )
    {
        ERRWRAP2(retval = _self_->row(y));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_rowRange(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_startrow = NULL;
    int startrow=0;
    PyObject* pyobj_endrow = NULL;
    int endrow=0;
    GpuMat retval;

    const char* keywords[] = { "startrow", "endrow", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.rowRange", (char**)keywords, &pyobj_startrow, &pyobj_endrow) &&
        pyopencv_to_safe(pyobj_startrow, startrow, ArgInfo("startrow", 0)) &&
        pyopencv_to_safe(pyobj_endrow, endrow, ArgInfo("endrow", 0)) )
    {
        ERRWRAP2(retval = _self_->rowRange(startrow, endrow));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_r = NULL;
    Range r;
    GpuMat retval;

    const char* keywords[] = { "r", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.rowRange", (char**)keywords, &pyobj_r) &&
        pyopencv_to_safe(pyobj_r, r, ArgInfo("r", 0)) )
    {
        ERRWRAP2(retval = _self_->rowRange(r));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("rowRange");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_setDefaultAllocator_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_allocator = NULL;
    GpuMat_Allocator* allocator;

    const char* keywords[] = { "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.setDefaultAllocator", (char**)keywords, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        ERRWRAP2(cv::cuda::GpuMat::setDefaultAllocator(allocator));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_setTo(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(8);

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    GpuMat retval;

    const char* keywords[] = { "s", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    GpuMat retval;

    const char* keywords[] = { "s", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, stream));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    GpuMat retval;

    const char* keywords[] = { "s", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    GpuMat retval;

    const char* keywords[] = { "s", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_mask = NULL;
    Mat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    GpuMat retval;

    const char* keywords[] = { "s", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, mask, stream));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_mask = NULL;
    cuda::GpuMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    GpuMat retval;

    const char* keywords[] = { "s", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, mask, stream));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    GpuMat retval;

    const char* keywords[] = { "s", "mask", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_mask) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, mask));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_s = NULL;
    Scalar s;
    PyObject* pyobj_mask = NULL;
    UMat mask;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();
    GpuMat retval;

    const char* keywords[] = { "s", "mask", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:cuda_GpuMat.setTo", (char**)keywords, &pyobj_s, &pyobj_mask, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_s, s, ArgInfo("s", 0)) &&
        pyopencv_to_safe(pyobj_mask, mask, ArgInfo("mask", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(retval = _self_->setTo(s, mask, stream));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("setTo");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_size(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    Size retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->size());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_step1(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->step1());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_swap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    PyObject* pyobj_mat = NULL;
    GpuMat mat;

    const char* keywords[] = { "mat", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.swap", (char**)keywords, &pyobj_mat) &&
        pyopencv_to_safe(pyobj_mat, mat, ArgInfo("mat", 0)) )
    {
        ERRWRAP2(_self_->swap(mat));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_type(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->type());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_updateContinuityFlag(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->updateContinuityFlag());
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_GpuMat_upload(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::GpuMat> * self1 = 0;
    if (!pyopencv_cuda_GpuMat_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_GpuMat' or its derivative)");
    Ptr<cv::cuda::GpuMat> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_arr = NULL;
    Mat arr;

    const char* keywords[] = { "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.upload", (char**)keywords, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) )
    {
        ERRWRAP2(_self_->upload(arr));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;

    const char* keywords[] = { "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.upload", (char**)keywords, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) )
    {
        ERRWRAP2(_self_->upload(arr));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    Mat arr;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "arr", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.upload", (char**)keywords, &pyobj_arr, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->upload(arr, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "arr", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.upload", (char**)keywords, &pyobj_arr, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->upload(arr, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    UMat arr;

    const char* keywords[] = { "arr", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_GpuMat.upload", (char**)keywords, &pyobj_arr) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) )
    {
        ERRWRAP2(_self_->upload(arr));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    UMat arr;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "arr", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_GpuMat.upload", (char**)keywords, &pyobj_arr, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->upload(arr, stream));
        Py_RETURN_NONE;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("upload");

    return NULL;
}



// Tables (cuda_GpuMat)

static PyGetSetDef pyopencv_cuda_GpuMat_getseters[] =
{
    {(char*)"step", (getter)pyopencv_cuda_GpuMat_get_step, NULL, (char*)"step", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_GpuMat_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_GpuMat
    PYOPENCV_EXTRA_METHODS_cuda_GpuMat
#endif
    {"adjustROI", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_adjustROI, 0), "adjustROI(dtop, dbottom, dleft, dright) -> retval\n."},
    {"assignTo", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_assignTo, 0), "assignTo(m[, type]) -> None\n."},
    {"channels", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_channels, 0), "channels() -> retval\n."},
    {"clone", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_clone, 0), "clone() -> retval\n."},
    {"col", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_col, 0), "col(x) -> retval\n."},
    {"colRange", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_colRange, 0), "colRange(startcol, endcol) -> retval\n.   \n\n\n\ncolRange(r) -> retval\n."},
    {"convertTo", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_convertTo, 0), "convertTo(rtype[, dst]) -> dst\n.   \n\n\n\nconvertTo(rtype, stream[, dst]) -> dst\n.   \n\n\n\nconvertTo(rtype[, dst[, alpha[, beta]]]) -> dst\n.   \n\n\n\nconvertTo(rtype, alpha, beta, stream[, dst]) -> dst\n."},
    {"copyTo", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_copyTo, 0), "copyTo([, dst]) -> dst\n.   \n\n\n\ncopyTo(stream[, dst]) -> dst\n.   \n\n\n\ncopyTo(mask[, dst]) -> dst\n.   \n\n\n\ncopyTo(mask, stream[, dst]) -> dst\n."},
    {"create", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_create, 0), "create(rows, cols, type) -> None\n.   \n\n\n\ncreate(size, type) -> None\n."},
    {"cudaPtr", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_cudaPtr, 0), "cudaPtr() -> retval\n."},
    {"defaultAllocator", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_defaultAllocator_static, METH_STATIC), "defaultAllocator() -> retval\n."},
    {"depth", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_depth, 0), "depth() -> retval\n."},
    {"download", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_download, 0), "download([, dst]) -> dst\n.   @brief Performs data download from GpuMat (Blocking call)\n.   \n.       This function copies data from device memory to host memory. As being a blocking call, it is\n.       guaranteed that the copy operation is finished when this function returns.\n\n\n\ndownload(stream[, dst]) -> dst\n.   @brief Performs data download from GpuMat (Non-Blocking call)\n.   \n.       This function copies data from device memory to host memory. As being a non-blocking call, this\n.       function may return even if the copy operation is not finished.\n.   \n.       The copy operation may be overlapped with operations in other non-default streams if \\p stream is\n.       not the default stream and \\p dst is HostMem allocated with HostMem::PAGE_LOCKED option."},
    {"elemSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_elemSize, 0), "elemSize() -> retval\n."},
    {"elemSize1", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_elemSize1, 0), "elemSize1() -> retval\n."},
    {"empty", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_empty, 0), "empty() -> retval\n."},
    {"getStdAllocator", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_getStdAllocator_static, METH_STATIC), "getStdAllocator() -> retval\n."},
    {"isContinuous", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_isContinuous, 0), "isContinuous() -> retval\n."},
    {"locateROI", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_locateROI, 0), "locateROI(wholeSize, ofs) -> None\n."},
    {"release", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_release, 0), "release() -> None\n."},
    {"reshape", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_reshape, 0), "reshape(cn[, rows]) -> retval\n."},
    {"row", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_row, 0), "row(y) -> retval\n."},
    {"rowRange", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_rowRange, 0), "rowRange(startrow, endrow) -> retval\n.   \n\n\n\nrowRange(r) -> retval\n."},
    {"setDefaultAllocator", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_setDefaultAllocator_static, METH_STATIC), "setDefaultAllocator(allocator) -> None\n."},
    {"setTo", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_setTo, 0), "setTo(s) -> retval\n.   \n\n\n\nsetTo(s, stream) -> retval\n.   \n\n\n\nsetTo(s, mask) -> retval\n.   \n\n\n\nsetTo(s, mask, stream) -> retval\n."},
    {"size", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_size, 0), "size() -> retval\n."},
    {"step1", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_step1, 0), "step1() -> retval\n."},
    {"swap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_swap, 0), "swap(mat) -> None\n."},
    {"type", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_type, 0), "type() -> retval\n."},
    {"updateContinuityFlag", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_updateContinuityFlag, 0), "updateContinuityFlag() -> None\n."},
    {"upload", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_GpuMat_upload, 0), "upload(arr) -> None\n.   @brief Performs data upload to GpuMat (Blocking call)\n.   \n.       This function copies data from host memory to device memory. As being a blocking call, it is\n.       guaranteed that the copy operation is finished when this function returns.\n\n\n\nupload(arr, stream) -> None\n.   @brief Performs data upload to GpuMat (Non-Blocking call)\n.   \n.       This function copies data from host memory to device memory. As being a non-blocking call, this\n.       function may return even if the copy operation is not finished.\n.   \n.       The copy operation may be overlapped with operations in other non-default streams if \\p stream is\n.       not the default stream and \\p dst is HostMem allocated with HostMem::PAGE_LOCKED option."},

    {NULL,          NULL}
};

// Converter (cuda_GpuMat)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::GpuMat> >
{
    static PyObject* from(const Ptr<cv::cuda::GpuMat>& r)
    {
        return pyopencv_cuda_GpuMat_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::GpuMat>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::GpuMat> * dst_;
        if (pyopencv_cuda_GpuMat_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::GpuMat> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_GpuMatND (Generic)
//================================================================================

// GetSet (cuda_GpuMatND)



// Methods (cuda_GpuMatND)



// Tables (cuda_GpuMatND)

static PyGetSetDef pyopencv_cuda_GpuMatND_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_GpuMatND_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_GpuMatND
    PYOPENCV_EXTRA_METHODS_cuda_GpuMatND
#endif

    {NULL,          NULL}
};

// Converter (cuda_GpuMatND)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::GpuMatND> >
{
    static PyObject* from(const Ptr<cv::cuda::GpuMatND>& r)
    {
        return pyopencv_cuda_GpuMatND_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::GpuMatND>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::GpuMatND> * dst_;
        if (pyopencv_cuda_GpuMatND_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::GpuMatND> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_GpuMat_Allocator (Generic)
//================================================================================

// GetSet (cuda_GpuMat_Allocator)



// Methods (cuda_GpuMat_Allocator)



// Tables (cuda_GpuMat_Allocator)

static PyGetSetDef pyopencv_cuda_GpuMat_Allocator_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_GpuMat_Allocator_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_GpuMat_Allocator
    PYOPENCV_EXTRA_METHODS_cuda_GpuMat_Allocator
#endif

    {NULL,          NULL}
};

// Converter (cuda_GpuMat_Allocator)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::GpuMat::Allocator> >
{
    static PyObject* from(const Ptr<cv::cuda::GpuMat::Allocator>& r)
    {
        return pyopencv_cuda_GpuMat_Allocator_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::GpuMat::Allocator>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::GpuMat::Allocator> * dst_;
        if (pyopencv_cuda_GpuMat_Allocator_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::GpuMat::Allocator> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_HostMem (Generic)
//================================================================================

// GetSet (cuda_HostMem)


static PyObject* pyopencv_cuda_HostMem_get_step(pyopencv_cuda_HostMem_t* p, void *closure)
{
    return pyopencv_from(p->v->step);
}


// Methods (cuda_HostMem)

static int pyopencv_cv_cuda_cuda_HostMem_HostMem(pyopencv_cuda_HostMem_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(6);

    {
    PyObject* pyobj_alloc_type = NULL;
    HostMem_AllocType alloc_type=HostMem::AllocType::PAGE_LOCKED;

    const char* keywords[] = { "alloc_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:HostMem", (char**)keywords, &pyobj_alloc_type) &&
        pyopencv_to_safe(pyobj_alloc_type, alloc_type, ArgInfo("alloc_type", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::HostMem>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::HostMem(alloc_type)));
        return 0;
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
    PyObject* pyobj_alloc_type = NULL;
    HostMem_AllocType alloc_type=HostMem::AllocType::PAGE_LOCKED;

    const char* keywords[] = { "rows", "cols", "type", "alloc_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:HostMem", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type, &pyobj_alloc_type) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_alloc_type, alloc_type, ArgInfo("alloc_type", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::HostMem>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::HostMem(rows, cols, type, alloc_type)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_size = NULL;
    Size size;
    PyObject* pyobj_type = NULL;
    int type=0;
    PyObject* pyobj_alloc_type = NULL;
    HostMem_AllocType alloc_type=HostMem::AllocType::PAGE_LOCKED;

    const char* keywords[] = { "size", "type", "alloc_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|O:HostMem", (char**)keywords, &pyobj_size, &pyobj_type, &pyobj_alloc_type) &&
        pyopencv_to_safe(pyobj_size, size, ArgInfo("size", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) &&
        pyopencv_to_safe(pyobj_alloc_type, alloc_type, ArgInfo("alloc_type", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::HostMem>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::HostMem(size, type, alloc_type)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    Mat arr;
    PyObject* pyobj_alloc_type = NULL;
    HostMem_AllocType alloc_type=HostMem::AllocType::PAGE_LOCKED;

    const char* keywords[] = { "arr", "alloc_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:HostMem", (char**)keywords, &pyobj_arr, &pyobj_alloc_type) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_alloc_type, alloc_type, ArgInfo("alloc_type", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::HostMem>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::HostMem(arr, alloc_type)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    cuda::GpuMat arr;
    PyObject* pyobj_alloc_type = NULL;
    HostMem_AllocType alloc_type=HostMem::AllocType::PAGE_LOCKED;

    const char* keywords[] = { "arr", "alloc_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:HostMem", (char**)keywords, &pyobj_arr, &pyobj_alloc_type) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_alloc_type, alloc_type, ArgInfo("alloc_type", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::HostMem>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::HostMem(arr, alloc_type)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_arr = NULL;
    UMat arr;
    PyObject* pyobj_alloc_type = NULL;
    HostMem_AllocType alloc_type=HostMem::AllocType::PAGE_LOCKED;

    const char* keywords[] = { "arr", "alloc_type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:HostMem", (char**)keywords, &pyobj_arr, &pyobj_alloc_type) &&
        pyopencv_to_safe(pyobj_arr, arr, ArgInfo("arr", 0)) &&
        pyopencv_to_safe(pyobj_alloc_type, alloc_type, ArgInfo("alloc_type", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::HostMem>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::HostMem(arr, alloc_type)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("HostMem");

    return -1;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_channels(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->channels());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_clone(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    HostMem retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->clone());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_create(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    PyObject* pyobj_rows = NULL;
    int rows=0;
    PyObject* pyobj_cols = NULL;
    int cols=0;
    PyObject* pyobj_type = NULL;
    int type=0;

    const char* keywords[] = { "rows", "cols", "type", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:cuda_HostMem.create", (char**)keywords, &pyobj_rows, &pyobj_cols, &pyobj_type) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) &&
        pyopencv_to_safe(pyobj_cols, cols, ArgInfo("cols", 0)) &&
        pyopencv_to_safe(pyobj_type, type, ArgInfo("type", 0)) )
    {
        ERRWRAP2(_self_->create(rows, cols, type));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_createMatHeader(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    Mat retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->createMatHeader());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_depth(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->depth());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_elemSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->elemSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_elemSize1(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->elemSize1());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_empty(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->empty());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_isContinuous(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isContinuous());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_reshape(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    PyObject* pyobj_cn = NULL;
    int cn=0;
    PyObject* pyobj_rows = NULL;
    int rows=0;
    HostMem retval;

    const char* keywords[] = { "cn", "rows", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|O:cuda_HostMem.reshape", (char**)keywords, &pyobj_cn, &pyobj_rows) &&
        pyopencv_to_safe(pyobj_cn, cn, ArgInfo("cn", 0)) &&
        pyopencv_to_safe(pyobj_rows, rows, ArgInfo("rows", 0)) )
    {
        ERRWRAP2(retval = _self_->reshape(cn, rows));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_size(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    Size retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->size());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_step1(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->step1());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_swap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    PyObject* pyobj_b = NULL;
    HostMem b;

    const char* keywords[] = { "b", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HostMem.swap", (char**)keywords, &pyobj_b) &&
        pyopencv_to_safe(pyobj_b, b, ArgInfo("b", 0)) )
    {
        ERRWRAP2(_self_->swap(b));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HostMem_type(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HostMem> * self1 = 0;
    if (!pyopencv_cuda_HostMem_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HostMem' or its derivative)");
    Ptr<cv::cuda::HostMem> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->type());
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (cuda_HostMem)

static PyGetSetDef pyopencv_cuda_HostMem_getseters[] =
{
    {(char*)"step", (getter)pyopencv_cuda_HostMem_get_step, NULL, (char*)"step", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_HostMem_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_HostMem
    PYOPENCV_EXTRA_METHODS_cuda_HostMem
#endif
    {"channels", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_channels, 0), "channels() -> retval\n."},
    {"clone", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_clone, 0), "clone() -> retval\n."},
    {"create", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_create, 0), "create(rows, cols, type) -> None\n."},
    {"createMatHeader", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_createMatHeader, 0), "createMatHeader() -> retval\n."},
    {"depth", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_depth, 0), "depth() -> retval\n."},
    {"elemSize", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_elemSize, 0), "elemSize() -> retval\n."},
    {"elemSize1", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_elemSize1, 0), "elemSize1() -> retval\n."},
    {"empty", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_empty, 0), "empty() -> retval\n."},
    {"isContinuous", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_isContinuous, 0), "isContinuous() -> retval\n.   @brief Maps CPU memory to GPU address space and creates the cuda::GpuMat header without reference counting\n.       for it.\n.   \n.       This can be done only if memory was allocated with the SHARED flag and if it is supported by the\n.       hardware. Laptops often share video and CPU memory, so address spaces can be mapped, which\n.       eliminates an extra copy."},
    {"reshape", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_reshape, 0), "reshape(cn[, rows]) -> retval\n."},
    {"size", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_size, 0), "size() -> retval\n."},
    {"step1", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_step1, 0), "step1() -> retval\n."},
    {"swap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_swap, 0), "swap(b) -> None\n."},
    {"type", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HostMem_type, 0), "type() -> retval\n."},

    {NULL,          NULL}
};

// Converter (cuda_HostMem)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::HostMem> >
{
    static PyObject* from(const Ptr<cv::cuda::HostMem>& r)
    {
        return pyopencv_cuda_HostMem_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::HostMem>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::HostMem> * dst_;
        if (pyopencv_cuda_HostMem_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::HostMem> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_HoughCirclesDetector (Generic)
//================================================================================

// GetSet (cuda_HoughCirclesDetector)



// Methods (cuda_HoughCirclesDetector)

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_circles = NULL;
    Mat circles;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "circles", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughCirclesDetector.detect", (char**)keywords, &pyobj_src, &pyobj_circles, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, circles, stream));
        return pyopencv_from(circles);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_circles = NULL;
    cuda::GpuMat circles;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "circles", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughCirclesDetector.detect", (char**)keywords, &pyobj_src, &pyobj_circles, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, circles, stream));
        return pyopencv_from(circles);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_circles = NULL;
    UMat circles;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "circles", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughCirclesDetector.detect", (char**)keywords, &pyobj_src, &pyobj_circles, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_circles, circles, ArgInfo("circles", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, circles, stream));
        return pyopencv_from(circles);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getCannyThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getCannyThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getDp(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getDp());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMaxCircles(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxCircles());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMaxRadius(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxRadius());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMinDist(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMinDist());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMinRadius(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMinRadius());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_getVotesThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getVotesThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setCannyThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_cannyThreshold = NULL;
    int cannyThreshold=0;

    const char* keywords[] = { "cannyThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setCannyThreshold", (char**)keywords, &pyobj_cannyThreshold) &&
        pyopencv_to_safe(pyobj_cannyThreshold, cannyThreshold, ArgInfo("cannyThreshold", 0)) )
    {
        ERRWRAP2(_self_->setCannyThreshold(cannyThreshold));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setDp(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_dp = NULL;
    float dp=0.f;

    const char* keywords[] = { "dp", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setDp", (char**)keywords, &pyobj_dp) &&
        pyopencv_to_safe(pyobj_dp, dp, ArgInfo("dp", 0)) )
    {
        ERRWRAP2(_self_->setDp(dp));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMaxCircles(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_maxCircles = NULL;
    int maxCircles=0;

    const char* keywords[] = { "maxCircles", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setMaxCircles", (char**)keywords, &pyobj_maxCircles) &&
        pyopencv_to_safe(pyobj_maxCircles, maxCircles, ArgInfo("maxCircles", 0)) )
    {
        ERRWRAP2(_self_->setMaxCircles(maxCircles));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMaxRadius(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_maxRadius = NULL;
    int maxRadius=0;

    const char* keywords[] = { "maxRadius", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setMaxRadius", (char**)keywords, &pyobj_maxRadius) &&
        pyopencv_to_safe(pyobj_maxRadius, maxRadius, ArgInfo("maxRadius", 0)) )
    {
        ERRWRAP2(_self_->setMaxRadius(maxRadius));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMinDist(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_minDist = NULL;
    float minDist=0.f;

    const char* keywords[] = { "minDist", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setMinDist", (char**)keywords, &pyobj_minDist) &&
        pyopencv_to_safe(pyobj_minDist, minDist, ArgInfo("minDist", 0)) )
    {
        ERRWRAP2(_self_->setMinDist(minDist));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMinRadius(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_minRadius = NULL;
    int minRadius=0;

    const char* keywords[] = { "minRadius", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setMinRadius", (char**)keywords, &pyobj_minRadius) &&
        pyopencv_to_safe(pyobj_minRadius, minRadius, ArgInfo("minRadius", 0)) )
    {
        ERRWRAP2(_self_->setMinRadius(minRadius));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughCirclesDetector_setVotesThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughCirclesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughCirclesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughCirclesDetector' or its derivative)");
    Ptr<cv::cuda::HoughCirclesDetector> _self_ = *(self1);
    PyObject* pyobj_votesThreshold = NULL;
    int votesThreshold=0;

    const char* keywords[] = { "votesThreshold", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughCirclesDetector.setVotesThreshold", (char**)keywords, &pyobj_votesThreshold) &&
        pyopencv_to_safe(pyobj_votesThreshold, votesThreshold, ArgInfo("votesThreshold", 0)) )
    {
        ERRWRAP2(_self_->setVotesThreshold(votesThreshold));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_HoughCirclesDetector)

static PyGetSetDef pyopencv_cuda_HoughCirclesDetector_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_HoughCirclesDetector_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_HoughCirclesDetector
    PYOPENCV_EXTRA_METHODS_cuda_HoughCirclesDetector
#endif
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_detect, 0), "detect(src[, circles[, stream]]) -> circles\n.   @brief Finds circles in a grayscale image using the Hough transform.\n.   \n.       @param src 8-bit, single-channel grayscale input image.\n.       @param circles Output vector of found circles. Each vector is encoded as a 3-element\n.       floating-point vector \\f$(x, y, radius)\\f$ .\n.       @param stream Stream for the asynchronous version.\n.   \n.       @sa HoughCircles"},
    {"getCannyThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getCannyThreshold, 0), "getCannyThreshold() -> retval\n."},
    {"getDp", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getDp, 0), "getDp() -> retval\n."},
    {"getMaxCircles", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMaxCircles, 0), "getMaxCircles() -> retval\n."},
    {"getMaxRadius", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMaxRadius, 0), "getMaxRadius() -> retval\n."},
    {"getMinDist", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMinDist, 0), "getMinDist() -> retval\n."},
    {"getMinRadius", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getMinRadius, 0), "getMinRadius() -> retval\n."},
    {"getVotesThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_getVotesThreshold, 0), "getVotesThreshold() -> retval\n."},
    {"setCannyThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setCannyThreshold, 0), "setCannyThreshold(cannyThreshold) -> None\n."},
    {"setDp", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setDp, 0), "setDp(dp) -> None\n."},
    {"setMaxCircles", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMaxCircles, 0), "setMaxCircles(maxCircles) -> None\n."},
    {"setMaxRadius", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMaxRadius, 0), "setMaxRadius(maxRadius) -> None\n."},
    {"setMinDist", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMinDist, 0), "setMinDist(minDist) -> None\n."},
    {"setMinRadius", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setMinRadius, 0), "setMinRadius(minRadius) -> None\n."},
    {"setVotesThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughCirclesDetector_setVotesThreshold, 0), "setVotesThreshold(votesThreshold) -> None\n."},

    {NULL,          NULL}
};

// Converter (cuda_HoughCirclesDetector)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::HoughCirclesDetector> >
{
    static PyObject* from(const Ptr<cv::cuda::HoughCirclesDetector>& r)
    {
        return pyopencv_cuda_HoughCirclesDetector_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::HoughCirclesDetector>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::HoughCirclesDetector> * dst_;
        if (pyopencv_cuda_HoughCirclesDetector_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::HoughCirclesDetector> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_HoughLinesDetector (Generic)
//================================================================================

// GetSet (cuda_HoughLinesDetector)



// Methods (cuda_HoughLinesDetector)

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lines", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughLinesDetector.detect", (char**)keywords, &pyobj_src, &pyobj_lines, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, lines, stream));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_lines = NULL;
    cuda::GpuMat lines;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lines", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughLinesDetector.detect", (char**)keywords, &pyobj_src, &pyobj_lines, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, lines, stream));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lines", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughLinesDetector.detect", (char**)keywords, &pyobj_src, &pyobj_lines, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, lines, stream));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_downloadResults(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_d_lines = NULL;
    Mat d_lines;
    PyObject* pyobj_h_lines = NULL;
    Mat h_lines;
    PyObject* pyobj_h_votes = NULL;
    Mat h_votes;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "d_lines", "h_lines", "h_votes", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_HoughLinesDetector.downloadResults", (char**)keywords, &pyobj_d_lines, &pyobj_h_lines, &pyobj_h_votes, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_d_lines, d_lines, ArgInfo("d_lines", 0)) &&
        pyopencv_to_safe(pyobj_h_lines, h_lines, ArgInfo("h_lines", 1)) &&
        pyopencv_to_safe(pyobj_h_votes, h_votes, ArgInfo("h_votes", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->downloadResults(d_lines, h_lines, h_votes, stream));
        return Py_BuildValue("(NN)", pyopencv_from(h_lines), pyopencv_from(h_votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_d_lines = NULL;
    cuda::GpuMat d_lines;
    PyObject* pyobj_h_lines = NULL;
    cuda::GpuMat h_lines;
    PyObject* pyobj_h_votes = NULL;
    cuda::GpuMat h_votes;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "d_lines", "h_lines", "h_votes", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_HoughLinesDetector.downloadResults", (char**)keywords, &pyobj_d_lines, &pyobj_h_lines, &pyobj_h_votes, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_d_lines, d_lines, ArgInfo("d_lines", 0)) &&
        pyopencv_to_safe(pyobj_h_lines, h_lines, ArgInfo("h_lines", 1)) &&
        pyopencv_to_safe(pyobj_h_votes, h_votes, ArgInfo("h_votes", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->downloadResults(d_lines, h_lines, h_votes, stream));
        return Py_BuildValue("(NN)", pyopencv_from(h_lines), pyopencv_from(h_votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_d_lines = NULL;
    UMat d_lines;
    PyObject* pyobj_h_lines = NULL;
    UMat h_lines;
    PyObject* pyobj_h_votes = NULL;
    UMat h_votes;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "d_lines", "h_lines", "h_votes", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OOO:cuda_HoughLinesDetector.downloadResults", (char**)keywords, &pyobj_d_lines, &pyobj_h_lines, &pyobj_h_votes, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_d_lines, d_lines, ArgInfo("d_lines", 0)) &&
        pyopencv_to_safe(pyobj_h_lines, h_lines, ArgInfo("h_lines", 1)) &&
        pyopencv_to_safe(pyobj_h_votes, h_votes, ArgInfo("h_votes", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->downloadResults(d_lines, h_lines, h_votes, stream));
        return Py_BuildValue("(NN)", pyopencv_from(h_lines), pyopencv_from(h_votes));
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("downloadResults");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_getDoSort(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getDoSort());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_getMaxLines(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxLines());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_getRho(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getRho());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_getTheta(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTheta());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_getThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_setDoSort(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    PyObject* pyobj_doSort = NULL;
    bool doSort=0;

    const char* keywords[] = { "doSort", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughLinesDetector.setDoSort", (char**)keywords, &pyobj_doSort) &&
        pyopencv_to_safe(pyobj_doSort, doSort, ArgInfo("doSort", 0)) )
    {
        ERRWRAP2(_self_->setDoSort(doSort));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_setMaxLines(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    PyObject* pyobj_maxLines = NULL;
    int maxLines=0;

    const char* keywords[] = { "maxLines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughLinesDetector.setMaxLines", (char**)keywords, &pyobj_maxLines) &&
        pyopencv_to_safe(pyobj_maxLines, maxLines, ArgInfo("maxLines", 0)) )
    {
        ERRWRAP2(_self_->setMaxLines(maxLines));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_setRho(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    PyObject* pyobj_rho = NULL;
    float rho=0.f;

    const char* keywords[] = { "rho", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughLinesDetector.setRho", (char**)keywords, &pyobj_rho) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) )
    {
        ERRWRAP2(_self_->setRho(rho));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_setTheta(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    PyObject* pyobj_theta = NULL;
    float theta=0.f;

    const char* keywords[] = { "theta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughLinesDetector.setTheta", (char**)keywords, &pyobj_theta) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) )
    {
        ERRWRAP2(_self_->setTheta(theta));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughLinesDetector_setThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughLinesDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughLinesDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughLinesDetector' or its derivative)");
    Ptr<cv::cuda::HoughLinesDetector> _self_ = *(self1);
    PyObject* pyobj_threshold = NULL;
    int threshold=0;

    const char* keywords[] = { "threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughLinesDetector.setThreshold", (char**)keywords, &pyobj_threshold) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) )
    {
        ERRWRAP2(_self_->setThreshold(threshold));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_HoughLinesDetector)

static PyGetSetDef pyopencv_cuda_HoughLinesDetector_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_HoughLinesDetector_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_HoughLinesDetector
    PYOPENCV_EXTRA_METHODS_cuda_HoughLinesDetector
#endif
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_detect, 0), "detect(src[, lines[, stream]]) -> lines\n.   @brief Finds lines in a binary image using the classical Hough transform.\n.   \n.       @param src 8-bit, single-channel binary source image.\n.       @param lines Output vector of lines. Each line is represented by a two-element vector\n.       \\f$(\\rho, \\theta)\\f$ . \\f$\\rho\\f$ is the distance from the coordinate origin \\f$(0,0)\\f$ (top-left corner of\n.       the image). \\f$\\theta\\f$ is the line rotation angle in radians (\n.       \\f$0 \\sim \\textrm{vertical line}, \\pi/2 \\sim \\textrm{horizontal line}\\f$ ).\n.       @param stream Stream for the asynchronous version.\n.   \n.       @sa HoughLines"},
    {"downloadResults", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_downloadResults, 0), "downloadResults(d_lines[, h_lines[, h_votes[, stream]]]) -> h_lines, h_votes\n.   @brief Downloads results from cuda::HoughLinesDetector::detect to host memory.\n.   \n.       @param d_lines Result of cuda::HoughLinesDetector::detect .\n.       @param h_lines Output host array.\n.       @param h_votes Optional output array for line's votes.\n.       @param stream Stream for the asynchronous version."},
    {"getDoSort", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_getDoSort, 0), "getDoSort() -> retval\n."},
    {"getMaxLines", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_getMaxLines, 0), "getMaxLines() -> retval\n."},
    {"getRho", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_getRho, 0), "getRho() -> retval\n."},
    {"getTheta", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_getTheta, 0), "getTheta() -> retval\n."},
    {"getThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_getThreshold, 0), "getThreshold() -> retval\n."},
    {"setDoSort", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_setDoSort, 0), "setDoSort(doSort) -> None\n."},
    {"setMaxLines", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_setMaxLines, 0), "setMaxLines(maxLines) -> None\n."},
    {"setRho", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_setRho, 0), "setRho(rho) -> None\n."},
    {"setTheta", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_setTheta, 0), "setTheta(theta) -> None\n."},
    {"setThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughLinesDetector_setThreshold, 0), "setThreshold(threshold) -> None\n."},

    {NULL,          NULL}
};

// Converter (cuda_HoughLinesDetector)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::HoughLinesDetector> >
{
    static PyObject* from(const Ptr<cv::cuda::HoughLinesDetector>& r)
    {
        return pyopencv_cuda_HoughLinesDetector_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::HoughLinesDetector>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::HoughLinesDetector> * dst_;
        if (pyopencv_cuda_HoughLinesDetector_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::HoughLinesDetector> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_HoughSegmentDetector (Generic)
//================================================================================

// GetSet (cuda_HoughSegmentDetector)



// Methods (cuda_HoughSegmentDetector)

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_detect(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_lines = NULL;
    Mat lines;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lines", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughSegmentDetector.detect", (char**)keywords, &pyobj_src, &pyobj_lines, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, lines, stream));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    cuda::GpuMat src;
    PyObject* pyobj_lines = NULL;
    cuda::GpuMat lines;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lines", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughSegmentDetector.detect", (char**)keywords, &pyobj_src, &pyobj_lines, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, lines, stream));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_src = NULL;
    UMat src;
    PyObject* pyobj_lines = NULL;
    UMat lines;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "lines", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_HoughSegmentDetector.detect", (char**)keywords, &pyobj_src, &pyobj_lines, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_lines, lines, ArgInfo("lines", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->detect(src, lines, stream));
        return pyopencv_from(lines);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("detect");

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_getMaxLineGap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxLineGap());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_getMaxLines(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMaxLines());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_getMinLineLength(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getMinLineLength());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_getRho(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getRho());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_getTheta(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getTheta());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_getThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getThreshold());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_setMaxLineGap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    PyObject* pyobj_maxLineGap = NULL;
    int maxLineGap=0;

    const char* keywords[] = { "maxLineGap", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughSegmentDetector.setMaxLineGap", (char**)keywords, &pyobj_maxLineGap) &&
        pyopencv_to_safe(pyobj_maxLineGap, maxLineGap, ArgInfo("maxLineGap", 0)) )
    {
        ERRWRAP2(_self_->setMaxLineGap(maxLineGap));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_setMaxLines(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    PyObject* pyobj_maxLines = NULL;
    int maxLines=0;

    const char* keywords[] = { "maxLines", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughSegmentDetector.setMaxLines", (char**)keywords, &pyobj_maxLines) &&
        pyopencv_to_safe(pyobj_maxLines, maxLines, ArgInfo("maxLines", 0)) )
    {
        ERRWRAP2(_self_->setMaxLines(maxLines));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_setMinLineLength(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    PyObject* pyobj_minLineLength = NULL;
    int minLineLength=0;

    const char* keywords[] = { "minLineLength", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughSegmentDetector.setMinLineLength", (char**)keywords, &pyobj_minLineLength) &&
        pyopencv_to_safe(pyobj_minLineLength, minLineLength, ArgInfo("minLineLength", 0)) )
    {
        ERRWRAP2(_self_->setMinLineLength(minLineLength));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_setRho(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    PyObject* pyobj_rho = NULL;
    float rho=0.f;

    const char* keywords[] = { "rho", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughSegmentDetector.setRho", (char**)keywords, &pyobj_rho) &&
        pyopencv_to_safe(pyobj_rho, rho, ArgInfo("rho", 0)) )
    {
        ERRWRAP2(_self_->setRho(rho));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_setTheta(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    PyObject* pyobj_theta = NULL;
    float theta=0.f;

    const char* keywords[] = { "theta", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughSegmentDetector.setTheta", (char**)keywords, &pyobj_theta) &&
        pyopencv_to_safe(pyobj_theta, theta, ArgInfo("theta", 0)) )
    {
        ERRWRAP2(_self_->setTheta(theta));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_HoughSegmentDetector_setThreshold(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::HoughSegmentDetector> * self1 = 0;
    if (!pyopencv_cuda_HoughSegmentDetector_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_HoughSegmentDetector' or its derivative)");
    Ptr<cv::cuda::HoughSegmentDetector> _self_ = *(self1);
    PyObject* pyobj_threshold = NULL;
    int threshold=0;

    const char* keywords[] = { "threshold", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_HoughSegmentDetector.setThreshold", (char**)keywords, &pyobj_threshold) &&
        pyopencv_to_safe(pyobj_threshold, threshold, ArgInfo("threshold", 0)) )
    {
        ERRWRAP2(_self_->setThreshold(threshold));
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_HoughSegmentDetector)

static PyGetSetDef pyopencv_cuda_HoughSegmentDetector_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_HoughSegmentDetector_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_HoughSegmentDetector
    PYOPENCV_EXTRA_METHODS_cuda_HoughSegmentDetector
#endif
    {"detect", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_detect, 0), "detect(src[, lines[, stream]]) -> lines\n.   @brief Finds line segments in a binary image using the probabilistic Hough transform.\n.   \n.       @param src 8-bit, single-channel binary source image.\n.       @param lines Output vector of lines. Each line is represented by a 4-element vector\n.       \\f$(x_1, y_1, x_2, y_2)\\f$ , where \\f$(x_1,y_1)\\f$ and \\f$(x_2, y_2)\\f$ are the ending points of each detected\n.       line segment.\n.       @param stream Stream for the asynchronous version.\n.   \n.       @sa HoughLinesP"},
    {"getMaxLineGap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_getMaxLineGap, 0), "getMaxLineGap() -> retval\n."},
    {"getMaxLines", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_getMaxLines, 0), "getMaxLines() -> retval\n."},
    {"getMinLineLength", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_getMinLineLength, 0), "getMinLineLength() -> retval\n."},
    {"getRho", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_getRho, 0), "getRho() -> retval\n."},
    {"getTheta", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_getTheta, 0), "getTheta() -> retval\n."},
    {"getThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_getThreshold, 0), "getThreshold() -> retval\n."},
    {"setMaxLineGap", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_setMaxLineGap, 0), "setMaxLineGap(maxLineGap) -> None\n."},
    {"setMaxLines", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_setMaxLines, 0), "setMaxLines(maxLines) -> None\n."},
    {"setMinLineLength", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_setMinLineLength, 0), "setMinLineLength(minLineLength) -> None\n."},
    {"setRho", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_setRho, 0), "setRho(rho) -> None\n."},
    {"setTheta", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_setTheta, 0), "setTheta(theta) -> None\n."},
    {"setThreshold", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_HoughSegmentDetector_setThreshold, 0), "setThreshold(threshold) -> None\n."},

    {NULL,          NULL}
};

// Converter (cuda_HoughSegmentDetector)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::HoughSegmentDetector> >
{
    static PyObject* from(const Ptr<cv::cuda::HoughSegmentDetector>& r)
    {
        return pyopencv_cuda_HoughSegmentDetector_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::HoughSegmentDetector>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::HoughSegmentDetector> * dst_;
        if (pyopencv_cuda_HoughSegmentDetector_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::HoughSegmentDetector> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_LookUpTable (Generic)
//================================================================================

// GetSet (cuda_LookUpTable)



// Methods (cuda_LookUpTable)

static PyObject* pyopencv_cv_cuda_cuda_LookUpTable_transform(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::LookUpTable> * self1 = 0;
    if (!pyopencv_cuda_LookUpTable_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_LookUpTable' or its derivative)");
    Ptr<cv::cuda::LookUpTable> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_src = NULL;
    Mat src;
    PyObject* pyobj_dst = NULL;
    Mat dst;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "src", "dst", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_LookUpTable.transform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->transform(src, dst, stream));
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_LookUpTable.transform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->transform(src, dst, stream));
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
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:cuda_LookUpTable.transform", (char**)keywords, &pyobj_src, &pyobj_dst, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_src, src, ArgInfo("src", 0)) &&
        pyopencv_to_safe(pyobj_dst, dst, ArgInfo("dst", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->transform(src, dst, stream));
        return pyopencv_from(dst);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("transform");

    return NULL;
}



// Tables (cuda_LookUpTable)

static PyGetSetDef pyopencv_cuda_LookUpTable_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_LookUpTable_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_LookUpTable
    PYOPENCV_EXTRA_METHODS_cuda_LookUpTable
#endif
    {"transform", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_LookUpTable_transform, 0), "transform(src[, dst[, stream]]) -> dst\n.   @brief Transforms the source matrix into the destination matrix using the given look-up table:\n.       dst(I) = lut(src(I)) .\n.   \n.       @param src Source matrix. CV_8UC1 and CV_8UC3 matrices are supported for now.\n.       @param dst Destination matrix.\n.       @param stream Stream for the asynchronous version."},

    {NULL,          NULL}
};

// Converter (cuda_LookUpTable)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::LookUpTable> >
{
    static PyObject* from(const Ptr<cv::cuda::LookUpTable>& r)
    {
        return pyopencv_cuda_LookUpTable_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::LookUpTable>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::LookUpTable> * dst_;
        if (pyopencv_cuda_LookUpTable_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::LookUpTable> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_Stream (Generic)
//================================================================================

// GetSet (cuda_Stream)



// Methods (cuda_Stream)

static int pyopencv_cv_cuda_cuda_Stream_Stream(pyopencv_cuda_Stream_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    pyPrepareArgumentConversionErrorsStorage(3);

    {

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        new (&(self->v)) Ptr<cv::cuda::Stream>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::Stream()));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_allocator = NULL;
    Ptr<GpuMat::Allocator> allocator;

    const char* keywords[] = { "allocator", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Stream", (char**)keywords, &pyobj_allocator) &&
        pyopencv_to_safe(pyobj_allocator, allocator, ArgInfo("allocator", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::Stream>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::Stream(allocator)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_cudaFlags = NULL;
    size_t cudaFlags=0;

    const char* keywords[] = { "cudaFlags", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:Stream", (char**)keywords, &pyobj_cudaFlags) &&
        pyopencv_to_safe(pyobj_cudaFlags, cudaFlags, ArgInfo("cudaFlags", 0)) )
    {
        new (&(self->v)) Ptr<cv::cuda::Stream>(); // init Ptr with placement new
        if(self) ERRWRAP2(self->v.reset(new cv::cuda::Stream(cudaFlags)));
        return 0;
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("Stream");

    return -1;
}

static PyObject* pyopencv_cv_cuda_cuda_Stream_Null_static(PyObject* self, PyObject* py_args, PyObject* kw)
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

static PyObject* pyopencv_cv_cuda_cuda_Stream_cudaPtr(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Stream> * self1 = 0;
    if (!pyopencv_cuda_Stream_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Stream' or its derivative)");
    Ptr<cv::cuda::Stream> _self_ = *(self1);
    void* retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->cudaPtr());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_Stream_queryIfComplete(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Stream> * self1 = 0;
    if (!pyopencv_cuda_Stream_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Stream' or its derivative)");
    Ptr<cv::cuda::Stream> _self_ = *(self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->queryIfComplete());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_Stream_waitEvent(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Stream> * self1 = 0;
    if (!pyopencv_cuda_Stream_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Stream' or its derivative)");
    Ptr<cv::cuda::Stream> _self_ = *(self1);
    PyObject* pyobj_event = NULL;
    Event event;

    const char* keywords[] = { "event", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:cuda_Stream.waitEvent", (char**)keywords, &pyobj_event) &&
        pyopencv_to_safe(pyobj_event, event, ArgInfo("event", 0)) )
    {
        ERRWRAP2(_self_->waitEvent(event));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_Stream_waitForCompletion(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::Stream> * self1 = 0;
    if (!pyopencv_cuda_Stream_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_Stream' or its derivative)");
    Ptr<cv::cuda::Stream> _self_ = *(self1);

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(_self_->waitForCompletion());
        Py_RETURN_NONE;
    }

    return NULL;
}



// Tables (cuda_Stream)

static PyGetSetDef pyopencv_cuda_Stream_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_Stream_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_Stream
    PYOPENCV_EXTRA_METHODS_cuda_Stream
#endif
    {"Null", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Stream_Null_static, METH_STATIC), "Null() -> retval\n.   @brief Adds a callback to be called on the host after all currently enqueued items in the stream have\n.       completed.\n.   \n.       @note Callbacks must not make any CUDA API calls. Callbacks must not perform any synchronization\n.       that may depend on outstanding device work or other callbacks that are not mandated to run earlier.\n.       Callbacks without a mandated order (in independent streams) execute in undefined order and may be\n.       serialized."},
    {"cudaPtr", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Stream_cudaPtr, 0), "cudaPtr() -> retval\n."},
    {"queryIfComplete", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Stream_queryIfComplete, 0), "queryIfComplete() -> retval\n.   @brief Returns true if the current stream queue is finished. Otherwise, it returns false."},
    {"waitEvent", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Stream_waitEvent, 0), "waitEvent(event) -> None\n.   @brief Makes a compute stream wait on an event."},
    {"waitForCompletion", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_Stream_waitForCompletion, 0), "waitForCompletion() -> None\n.   @brief Blocks the current CPU thread until all operations in the stream are complete."},

    {NULL,          NULL}
};

// Converter (cuda_Stream)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::Stream> >
{
    static PyObject* from(const Ptr<cv::cuda::Stream>& r)
    {
        return pyopencv_cuda_Stream_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::Stream>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::Stream> * dst_;
        if (pyopencv_cuda_Stream_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::Stream> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_TargetArchs (Generic)
//================================================================================

// GetSet (cuda_TargetArchs)



// Methods (cuda_TargetArchs)

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_has_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.has", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::has(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_hasBin_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.hasBin", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasBin(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrGreater_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.hasEqualOrGreater", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreater(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrGreaterBin_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.hasEqualOrGreaterBin", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreaterBin(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrGreaterPtx_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.hasEqualOrGreaterPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrGreaterPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrLessPtx_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.hasEqualOrLessPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasEqualOrLessPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_cuda_cuda_TargetArchs_hasPtx_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;

    PyObject* pyobj_major = NULL;
    int major=0;
    PyObject* pyobj_minor = NULL;
    int minor=0;
    bool retval;

    const char* keywords[] = { "major", "minor", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO:cuda_TargetArchs.hasPtx", (char**)keywords, &pyobj_major, &pyobj_minor) &&
        pyopencv_to_safe(pyobj_major, major, ArgInfo("major", 0)) &&
        pyopencv_to_safe(pyobj_minor, minor, ArgInfo("minor", 0)) )
    {
        ERRWRAP2(retval = cv::cuda::TargetArchs::hasPtx(major, minor));
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (cuda_TargetArchs)

static PyGetSetDef pyopencv_cuda_TargetArchs_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_TargetArchs_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_TargetArchs
    PYOPENCV_EXTRA_METHODS_cuda_TargetArchs
#endif
    {"has", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_has_static, METH_STATIC), "has(major, minor) -> retval\n.   @brief There is a set of methods to check whether the module contains intermediate (PTX) or binary CUDA\n.       code for the given architecture(s):\n.   \n.       @param major Major compute capability version.\n.       @param minor Minor compute capability version."},
    {"hasBin", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_hasBin_static, METH_STATIC), "hasBin(major, minor) -> retval\n."},
    {"hasEqualOrGreater", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrGreater_static, METH_STATIC), "hasEqualOrGreater(major, minor) -> retval\n."},
    {"hasEqualOrGreaterBin", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrGreaterBin_static, METH_STATIC), "hasEqualOrGreaterBin(major, minor) -> retval\n."},
    {"hasEqualOrGreaterPtx", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrGreaterPtx_static, METH_STATIC), "hasEqualOrGreaterPtx(major, minor) -> retval\n."},
    {"hasEqualOrLessPtx", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_hasEqualOrLessPtx_static, METH_STATIC), "hasEqualOrLessPtx(major, minor) -> retval\n."},
    {"hasPtx", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TargetArchs_hasPtx_static, METH_STATIC), "hasPtx(major, minor) -> retval\n."},

    {NULL,          NULL}
};

// Converter (cuda_TargetArchs)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::TargetArchs> >
{
    static PyObject* from(const Ptr<cv::cuda::TargetArchs>& r)
    {
        return pyopencv_cuda_TargetArchs_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::TargetArchs>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::TargetArchs> * dst_;
        if (pyopencv_cuda_TargetArchs_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::TargetArchs> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// cuda_TemplateMatching (Generic)
//================================================================================

// GetSet (cuda_TemplateMatching)



// Methods (cuda_TemplateMatching)

static PyObject* pyopencv_cv_cuda_cuda_TemplateMatching_match(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::cuda;


    Ptr<cv::cuda::TemplateMatching> * self1 = 0;
    if (!pyopencv_cuda_TemplateMatching_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'cuda_TemplateMatching' or its derivative)");
    Ptr<cv::cuda::TemplateMatching> _self_ = *(self1);
    pyPrepareArgumentConversionErrorsStorage(3);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    PyObject* pyobj_templ = NULL;
    Mat templ;
    PyObject* pyobj_result = NULL;
    Mat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "templ", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cuda_TemplateMatching.match", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->match(image, templ, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    cuda::GpuMat image;
    PyObject* pyobj_templ = NULL;
    cuda::GpuMat templ;
    PyObject* pyobj_result = NULL;
    cuda::GpuMat result;
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "templ", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cuda_TemplateMatching.match", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->match(image, templ, result, stream));
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
    PyObject* pyobj_stream = NULL;
    Stream stream=Stream::Null();

    const char* keywords[] = { "image", "templ", "result", "stream", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:cuda_TemplateMatching.match", (char**)keywords, &pyobj_image, &pyobj_templ, &pyobj_result, &pyobj_stream) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) &&
        pyopencv_to_safe(pyobj_templ, templ, ArgInfo("templ", 0)) &&
        pyopencv_to_safe(pyobj_result, result, ArgInfo("result", 1)) &&
        pyopencv_to_safe(pyobj_stream, stream, ArgInfo("stream", 0)) )
    {
        ERRWRAP2(_self_->match(image, templ, result, stream));
        return pyopencv_from(result);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("match");

    return NULL;
}



// Tables (cuda_TemplateMatching)

static PyGetSetDef pyopencv_cuda_TemplateMatching_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_cuda_TemplateMatching_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_cuda_TemplateMatching
    PYOPENCV_EXTRA_METHODS_cuda_TemplateMatching
#endif
    {"match", CV_PY_FN_WITH_KW_(pyopencv_cv_cuda_cuda_TemplateMatching_match, 0), "match(image, templ[, result[, stream]]) -> result\n.   @brief Computes a proximity map for a raster template and an image where the template is searched for.\n.   \n.       @param image Source image.\n.       @param templ Template image with the size and type the same as image .\n.       @param result Map containing comparison results ( CV_32FC1 ). If image is *W x H* and templ is *w\n.       x h*, then result must be *W-w+1 x H-h+1*.\n.       @param stream Stream for the asynchronous version."},

    {NULL,          NULL}
};

// Converter (cuda_TemplateMatching)

template<>
struct PyOpenCV_Converter< Ptr<cv::cuda::TemplateMatching> >
{
    static PyObject* from(const Ptr<cv::cuda::TemplateMatching>& r)
    {
        return pyopencv_cuda_TemplateMatching_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::cuda::TemplateMatching>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::cuda::TemplateMatching> * dst_;
        if (pyopencv_cuda_TemplateMatching_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::cuda::TemplateMatching> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// ocl_Device (Generic)
//================================================================================

// GetSet (ocl_Device)



// Methods (ocl_Device)

static int pyopencv_cv_ocl_ocl_Device_Device(pyopencv_ocl_Device_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::ocl::Device());
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_OpenCLVersion(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->OpenCLVersion());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_OpenCL_C_Version(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->OpenCL_C_Version());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_addressBits(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->addressBits());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_available(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->available());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_compilerAvailable(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->compilerAvailable());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_deviceVersionMajor(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->deviceVersionMajor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_deviceVersionMinor(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->deviceVersionMinor());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_doubleFPConfig(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->doubleFPConfig());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_driverVersion(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->driverVersion());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_endianLittle(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->endianLittle());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_errorCorrectionSupport(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->errorCorrectionSupport());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_executionCapabilities(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->executionCapabilities());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_extensions(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->extensions());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_getDefault_static(PyObject* self, PyObject* py_args, PyObject* kw)
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

static PyObject* pyopencv_cv_ocl_ocl_Device_globalMemCacheLineSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->globalMemCacheLineSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_globalMemCacheSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->globalMemCacheSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_globalMemCacheType(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->globalMemCacheType());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_globalMemSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->globalMemSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_halfFPConfig(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->halfFPConfig());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_hasFP16(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->hasFP16());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_hasFP64(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->hasFP64());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_hostUnifiedMemory(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->hostUnifiedMemory());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_image2DMaxHeight(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->image2DMaxHeight());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_image2DMaxWidth(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->image2DMaxWidth());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_image3DMaxDepth(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->image3DMaxDepth());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_image3DMaxHeight(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->image3DMaxHeight());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_image3DMaxWidth(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->image3DMaxWidth());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_imageFromBufferSupport(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->imageFromBufferSupport());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_imageMaxArraySize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->imageMaxArraySize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_imageMaxBufferSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->imageMaxBufferSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_imageSupport(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->imageSupport());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_intelSubgroupsSupport(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->intelSubgroupsSupport());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_isAMD(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isAMD());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_isExtensionSupported(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    PyObject* pyobj_extensionName = NULL;
    String extensionName;
    bool retval;

    const char* keywords[] = { "extensionName", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:ocl_Device.isExtensionSupported", (char**)keywords, &pyobj_extensionName) &&
        pyopencv_to_safe(pyobj_extensionName, extensionName, ArgInfo("extensionName", 0)) )
    {
        ERRWRAP2(retval = _self_->isExtensionSupported(extensionName));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_isIntel(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isIntel());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_isNVidia(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->isNVidia());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_linkerAvailable(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    bool retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->linkerAvailable());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_localMemSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->localMemSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_localMemType(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->localMemType());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxClockFrequency(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxClockFrequency());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxComputeUnits(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxComputeUnits());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxConstantArgs(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxConstantArgs());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxConstantBufferSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxConstantBufferSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxMemAllocSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxMemAllocSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxParameterSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxParameterSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxReadImageArgs(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxReadImageArgs());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxSamplers(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxSamplers());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxWorkGroupSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxWorkGroupSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxWorkItemDims(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxWorkItemDims());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_maxWriteImageArgs(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->maxWriteImageArgs());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_memBaseAddrAlign(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->memBaseAddrAlign());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_name(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->name());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthChar(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthChar());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthDouble(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthDouble());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthFloat(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthFloat());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthHalf(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthHalf());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthInt(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthInt());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthLong(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthLong());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_nativeVectorWidthShort(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->nativeVectorWidthShort());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthChar(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthChar());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthDouble(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthDouble());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthFloat(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthFloat());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthHalf(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthHalf());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthInt(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthInt());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthLong(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthLong());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_preferredVectorWidthShort(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->preferredVectorWidthShort());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_printfBufferSize(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->printfBufferSize());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_profilingTimerResolution(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    size_t retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->profilingTimerResolution());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_singleFPConfig(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->singleFPConfig());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_type(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->type());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_vendorID(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->vendorID());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_vendorName(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->vendorName());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_ocl_ocl_Device_version(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::ocl;


    cv::ocl::Device * self1 = 0;
    if (!pyopencv_ocl_Device_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'ocl_Device' or its derivative)");
    cv::ocl::Device* _self_ = (self1);
    String retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->version());
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (ocl_Device)

static PyGetSetDef pyopencv_ocl_Device_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_ocl_Device_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_ocl_Device
    PYOPENCV_EXTRA_METHODS_ocl_Device
#endif
    {"OpenCLVersion", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_OpenCLVersion, 0), "OpenCLVersion() -> retval\n."},
    {"OpenCL_C_Version", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_OpenCL_C_Version, 0), "OpenCL_C_Version() -> retval\n."},
    {"addressBits", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_addressBits, 0), "addressBits() -> retval\n."},
    {"available", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_available, 0), "available() -> retval\n."},
    {"compilerAvailable", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_compilerAvailable, 0), "compilerAvailable() -> retval\n."},
    {"deviceVersionMajor", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_deviceVersionMajor, 0), "deviceVersionMajor() -> retval\n."},
    {"deviceVersionMinor", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_deviceVersionMinor, 0), "deviceVersionMinor() -> retval\n."},
    {"doubleFPConfig", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_doubleFPConfig, 0), "doubleFPConfig() -> retval\n."},
    {"driverVersion", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_driverVersion, 0), "driverVersion() -> retval\n."},
    {"endianLittle", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_endianLittle, 0), "endianLittle() -> retval\n."},
    {"errorCorrectionSupport", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_errorCorrectionSupport, 0), "errorCorrectionSupport() -> retval\n."},
    {"executionCapabilities", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_executionCapabilities, 0), "executionCapabilities() -> retval\n."},
    {"extensions", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_extensions, 0), "extensions() -> retval\n."},
    {"getDefault", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_getDefault_static, METH_STATIC), "getDefault() -> retval\n."},
    {"globalMemCacheLineSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_globalMemCacheLineSize, 0), "globalMemCacheLineSize() -> retval\n."},
    {"globalMemCacheSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_globalMemCacheSize, 0), "globalMemCacheSize() -> retval\n."},
    {"globalMemCacheType", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_globalMemCacheType, 0), "globalMemCacheType() -> retval\n."},
    {"globalMemSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_globalMemSize, 0), "globalMemSize() -> retval\n."},
    {"halfFPConfig", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_halfFPConfig, 0), "halfFPConfig() -> retval\n."},
    {"hasFP16", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_hasFP16, 0), "hasFP16() -> retval\n."},
    {"hasFP64", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_hasFP64, 0), "hasFP64() -> retval\n."},
    {"hostUnifiedMemory", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_hostUnifiedMemory, 0), "hostUnifiedMemory() -> retval\n."},
    {"image2DMaxHeight", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_image2DMaxHeight, 0), "image2DMaxHeight() -> retval\n."},
    {"image2DMaxWidth", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_image2DMaxWidth, 0), "image2DMaxWidth() -> retval\n."},
    {"image3DMaxDepth", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_image3DMaxDepth, 0), "image3DMaxDepth() -> retval\n."},
    {"image3DMaxHeight", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_image3DMaxHeight, 0), "image3DMaxHeight() -> retval\n."},
    {"image3DMaxWidth", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_image3DMaxWidth, 0), "image3DMaxWidth() -> retval\n."},
    {"imageFromBufferSupport", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_imageFromBufferSupport, 0), "imageFromBufferSupport() -> retval\n."},
    {"imageMaxArraySize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_imageMaxArraySize, 0), "imageMaxArraySize() -> retval\n."},
    {"imageMaxBufferSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_imageMaxBufferSize, 0), "imageMaxBufferSize() -> retval\n."},
    {"imageSupport", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_imageSupport, 0), "imageSupport() -> retval\n."},
    {"intelSubgroupsSupport", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_intelSubgroupsSupport, 0), "intelSubgroupsSupport() -> retval\n."},
    {"isAMD", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_isAMD, 0), "isAMD() -> retval\n."},
    {"isExtensionSupported", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_isExtensionSupported, 0), "isExtensionSupported(extensionName) -> retval\n."},
    {"isIntel", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_isIntel, 0), "isIntel() -> retval\n."},
    {"isNVidia", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_isNVidia, 0), "isNVidia() -> retval\n."},
    {"linkerAvailable", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_linkerAvailable, 0), "linkerAvailable() -> retval\n."},
    {"localMemSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_localMemSize, 0), "localMemSize() -> retval\n."},
    {"localMemType", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_localMemType, 0), "localMemType() -> retval\n."},
    {"maxClockFrequency", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxClockFrequency, 0), "maxClockFrequency() -> retval\n."},
    {"maxComputeUnits", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxComputeUnits, 0), "maxComputeUnits() -> retval\n."},
    {"maxConstantArgs", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxConstantArgs, 0), "maxConstantArgs() -> retval\n."},
    {"maxConstantBufferSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxConstantBufferSize, 0), "maxConstantBufferSize() -> retval\n."},
    {"maxMemAllocSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxMemAllocSize, 0), "maxMemAllocSize() -> retval\n."},
    {"maxParameterSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxParameterSize, 0), "maxParameterSize() -> retval\n."},
    {"maxReadImageArgs", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxReadImageArgs, 0), "maxReadImageArgs() -> retval\n."},
    {"maxSamplers", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxSamplers, 0), "maxSamplers() -> retval\n."},
    {"maxWorkGroupSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxWorkGroupSize, 0), "maxWorkGroupSize() -> retval\n."},
    {"maxWorkItemDims", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxWorkItemDims, 0), "maxWorkItemDims() -> retval\n."},
    {"maxWriteImageArgs", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_maxWriteImageArgs, 0), "maxWriteImageArgs() -> retval\n."},
    {"memBaseAddrAlign", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_memBaseAddrAlign, 0), "memBaseAddrAlign() -> retval\n."},
    {"name", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_name, 0), "name() -> retval\n."},
    {"nativeVectorWidthChar", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthChar, 0), "nativeVectorWidthChar() -> retval\n."},
    {"nativeVectorWidthDouble", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthDouble, 0), "nativeVectorWidthDouble() -> retval\n."},
    {"nativeVectorWidthFloat", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthFloat, 0), "nativeVectorWidthFloat() -> retval\n."},
    {"nativeVectorWidthHalf", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthHalf, 0), "nativeVectorWidthHalf() -> retval\n."},
    {"nativeVectorWidthInt", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthInt, 0), "nativeVectorWidthInt() -> retval\n."},
    {"nativeVectorWidthLong", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthLong, 0), "nativeVectorWidthLong() -> retval\n."},
    {"nativeVectorWidthShort", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_nativeVectorWidthShort, 0), "nativeVectorWidthShort() -> retval\n."},
    {"preferredVectorWidthChar", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthChar, 0), "preferredVectorWidthChar() -> retval\n."},
    {"preferredVectorWidthDouble", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthDouble, 0), "preferredVectorWidthDouble() -> retval\n."},
    {"preferredVectorWidthFloat", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthFloat, 0), "preferredVectorWidthFloat() -> retval\n."},
    {"preferredVectorWidthHalf", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthHalf, 0), "preferredVectorWidthHalf() -> retval\n."},
    {"preferredVectorWidthInt", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthInt, 0), "preferredVectorWidthInt() -> retval\n."},
    {"preferredVectorWidthLong", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthLong, 0), "preferredVectorWidthLong() -> retval\n."},
    {"preferredVectorWidthShort", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_preferredVectorWidthShort, 0), "preferredVectorWidthShort() -> retval\n."},
    {"printfBufferSize", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_printfBufferSize, 0), "printfBufferSize() -> retval\n."},
    {"profilingTimerResolution", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_profilingTimerResolution, 0), "profilingTimerResolution() -> retval\n."},
    {"singleFPConfig", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_singleFPConfig, 0), "singleFPConfig() -> retval\n."},
    {"type", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_type, 0), "type() -> retval\n."},
    {"vendorID", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_vendorID, 0), "vendorID() -> retval\n."},
    {"vendorName", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_vendorName, 0), "vendorName() -> retval\n."},
    {"version", CV_PY_FN_WITH_KW_(pyopencv_cv_ocl_ocl_Device_version, 0), "version() -> retval\n."},

    {NULL,          NULL}
};

// Converter (ocl_Device)

template<>
struct PyOpenCV_Converter< cv::ocl::Device >
{
    static PyObject* from(const cv::ocl::Device& r)
    {
        return pyopencv_ocl_Device_Instance(r);
    }
    static bool to(PyObject* src, cv::ocl::Device& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::ocl::Device * dst_;
        if (pyopencv_ocl_Device_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::ocl::Device for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// ocl_OpenCLExecutionContext (Generic)
//================================================================================

// GetSet (ocl_OpenCLExecutionContext)



// Methods (ocl_OpenCLExecutionContext)



// Tables (ocl_OpenCLExecutionContext)

static PyGetSetDef pyopencv_ocl_OpenCLExecutionContext_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_ocl_OpenCLExecutionContext_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_ocl_OpenCLExecutionContext
    PYOPENCV_EXTRA_METHODS_ocl_OpenCLExecutionContext
#endif

    {NULL,          NULL}
};

// Converter (ocl_OpenCLExecutionContext)

template<>
struct PyOpenCV_Converter< Ptr<cv::ocl::OpenCLExecutionContext> >
{
    static PyObject* from(const Ptr<cv::ocl::OpenCLExecutionContext>& r)
    {
        return pyopencv_ocl_OpenCLExecutionContext_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::ocl::OpenCLExecutionContext>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::ocl::OpenCLExecutionContext> * dst_;
        if (pyopencv_ocl_OpenCLExecutionContext_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::ocl::OpenCLExecutionContext> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// segmentation_IntelligentScissorsMB (Generic)
//================================================================================

// GetSet (segmentation_IntelligentScissorsMB)



// Methods (segmentation_IntelligentScissorsMB)

static int pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_IntelligentScissorsMB(pyopencv_segmentation_IntelligentScissorsMB_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::segmentation::IntelligentScissorsMB());
        return 0;
    }

    return -1;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_applyImage(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_image = NULL;
    Mat image;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:segmentation_IntelligentScissorsMB.applyImage", (char**)keywords, &pyobj_image) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) )
    {
        ERRWRAP2(retval = _self_->applyImage(image));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_image = NULL;
    UMat image;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:segmentation_IntelligentScissorsMB.applyImage", (char**)keywords, &pyobj_image) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) )
    {
        ERRWRAP2(retval = _self_->applyImage(image));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("applyImage");

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_applyImageFeatures(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_non_edge = NULL;
    Mat non_edge;
    PyObject* pyobj_gradient_direction = NULL;
    Mat gradient_direction;
    PyObject* pyobj_gradient_magnitude = NULL;
    Mat gradient_magnitude;
    PyObject* pyobj_image = NULL;
    Mat image;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "non_edge", "gradient_direction", "gradient_magnitude", "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:segmentation_IntelligentScissorsMB.applyImageFeatures", (char**)keywords, &pyobj_non_edge, &pyobj_gradient_direction, &pyobj_gradient_magnitude, &pyobj_image) &&
        pyopencv_to_safe(pyobj_non_edge, non_edge, ArgInfo("non_edge", 0)) &&
        pyopencv_to_safe(pyobj_gradient_direction, gradient_direction, ArgInfo("gradient_direction", 0)) &&
        pyopencv_to_safe(pyobj_gradient_magnitude, gradient_magnitude, ArgInfo("gradient_magnitude", 0)) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) )
    {
        ERRWRAP2(retval = _self_->applyImageFeatures(non_edge, gradient_direction, gradient_magnitude, image));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_non_edge = NULL;
    UMat non_edge;
    PyObject* pyobj_gradient_direction = NULL;
    UMat gradient_direction;
    PyObject* pyobj_gradient_magnitude = NULL;
    UMat gradient_magnitude;
    PyObject* pyobj_image = NULL;
    UMat image;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "non_edge", "gradient_direction", "gradient_magnitude", "image", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO|O:segmentation_IntelligentScissorsMB.applyImageFeatures", (char**)keywords, &pyobj_non_edge, &pyobj_gradient_direction, &pyobj_gradient_magnitude, &pyobj_image) &&
        pyopencv_to_safe(pyobj_non_edge, non_edge, ArgInfo("non_edge", 0)) &&
        pyopencv_to_safe(pyobj_gradient_direction, gradient_direction, ArgInfo("gradient_direction", 0)) &&
        pyopencv_to_safe(pyobj_gradient_magnitude, gradient_magnitude, ArgInfo("gradient_magnitude", 0)) &&
        pyopencv_to_safe(pyobj_image, image, ArgInfo("image", 0)) )
    {
        ERRWRAP2(retval = _self_->applyImageFeatures(non_edge, gradient_direction, gradient_magnitude, image));
        return pyopencv_from(retval);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("applyImageFeatures");

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_buildMap(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    PyObject* pyobj_sourcePt = NULL;
    Point sourcePt;

    const char* keywords[] = { "sourcePt", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O:segmentation_IntelligentScissorsMB.buildMap", (char**)keywords, &pyobj_sourcePt) &&
        pyopencv_to_safe(pyobj_sourcePt, sourcePt, ArgInfo("sourcePt", 0)) )
    {
        ERRWRAP2(_self_->buildMap(sourcePt));
        Py_RETURN_NONE;
    }

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_getContour(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    pyPrepareArgumentConversionErrorsStorage(2);

    {
    PyObject* pyobj_targetPt = NULL;
    Point targetPt;
    PyObject* pyobj_contour = NULL;
    Mat contour;
    PyObject* pyobj_backward = NULL;
    bool backward=false;

    const char* keywords[] = { "targetPt", "contour", "backward", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:segmentation_IntelligentScissorsMB.getContour", (char**)keywords, &pyobj_targetPt, &pyobj_contour, &pyobj_backward) &&
        pyopencv_to_safe(pyobj_targetPt, targetPt, ArgInfo("targetPt", 0)) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 1)) &&
        pyopencv_to_safe(pyobj_backward, backward, ArgInfo("backward", 0)) )
    {
        ERRWRAP2(_self_->getContour(targetPt, contour, backward));
        return pyopencv_from(contour);
    }


        pyPopulateArgumentConversionErrors();
    }
    

    {
    PyObject* pyobj_targetPt = NULL;
    Point targetPt;
    PyObject* pyobj_contour = NULL;
    UMat contour;
    PyObject* pyobj_backward = NULL;
    bool backward=false;

    const char* keywords[] = { "targetPt", "contour", "backward", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "O|OO:segmentation_IntelligentScissorsMB.getContour", (char**)keywords, &pyobj_targetPt, &pyobj_contour, &pyobj_backward) &&
        pyopencv_to_safe(pyobj_targetPt, targetPt, ArgInfo("targetPt", 0)) &&
        pyopencv_to_safe(pyobj_contour, contour, ArgInfo("contour", 1)) &&
        pyopencv_to_safe(pyobj_backward, backward, ArgInfo("backward", 0)) )
    {
        ERRWRAP2(_self_->getContour(targetPt, contour, backward));
        return pyopencv_from(contour);
    }


        pyPopulateArgumentConversionErrors();
    }
    pyRaiseCVOverloadException("getContour");

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setEdgeFeatureCannyParameters(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    PyObject* pyobj_threshold1 = NULL;
    double threshold1=0;
    PyObject* pyobj_threshold2 = NULL;
    double threshold2=0;
    PyObject* pyobj_apertureSize = NULL;
    int apertureSize=3;
    PyObject* pyobj_L2gradient = NULL;
    bool L2gradient=false;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "threshold1", "threshold2", "apertureSize", "L2gradient", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OO|OO:segmentation_IntelligentScissorsMB.setEdgeFeatureCannyParameters", (char**)keywords, &pyobj_threshold1, &pyobj_threshold2, &pyobj_apertureSize, &pyobj_L2gradient) &&
        pyopencv_to_safe(pyobj_threshold1, threshold1, ArgInfo("threshold1", 0)) &&
        pyopencv_to_safe(pyobj_threshold2, threshold2, ArgInfo("threshold2", 0)) &&
        pyopencv_to_safe(pyobj_apertureSize, apertureSize, ArgInfo("apertureSize", 0)) &&
        pyopencv_to_safe(pyobj_L2gradient, L2gradient, ArgInfo("L2gradient", 0)) )
    {
        ERRWRAP2(retval = _self_->setEdgeFeatureCannyParameters(threshold1, threshold2, apertureSize, L2gradient));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setEdgeFeatureZeroCrossingParameters(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    PyObject* pyobj_gradient_magnitude_min_value = NULL;
    float gradient_magnitude_min_value=0.0f;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "gradient_magnitude_min_value", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:segmentation_IntelligentScissorsMB.setEdgeFeatureZeroCrossingParameters", (char**)keywords, &pyobj_gradient_magnitude_min_value) &&
        pyopencv_to_safe(pyobj_gradient_magnitude_min_value, gradient_magnitude_min_value, ArgInfo("gradient_magnitude_min_value", 0)) )
    {
        ERRWRAP2(retval = _self_->setEdgeFeatureZeroCrossingParameters(gradient_magnitude_min_value));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setGradientMagnitudeMaxLimit(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    PyObject* pyobj_gradient_magnitude_threshold_max = NULL;
    float gradient_magnitude_threshold_max=0.0f;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "gradient_magnitude_threshold_max", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:segmentation_IntelligentScissorsMB.setGradientMagnitudeMaxLimit", (char**)keywords, &pyobj_gradient_magnitude_threshold_max) &&
        pyopencv_to_safe(pyobj_gradient_magnitude_threshold_max, gradient_magnitude_threshold_max, ArgInfo("gradient_magnitude_threshold_max", 0)) )
    {
        ERRWRAP2(retval = _self_->setGradientMagnitudeMaxLimit(gradient_magnitude_threshold_max));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setWeights(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::segmentation;


    cv::segmentation::IntelligentScissorsMB * self1 = 0;
    if (!pyopencv_segmentation_IntelligentScissorsMB_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'segmentation_IntelligentScissorsMB' or its derivative)");
    cv::segmentation::IntelligentScissorsMB* _self_ = (self1);
    PyObject* pyobj_weight_non_edge = NULL;
    float weight_non_edge=0.f;
    PyObject* pyobj_weight_gradient_direction = NULL;
    float weight_gradient_direction=0.f;
    PyObject* pyobj_weight_gradient_magnitude = NULL;
    float weight_gradient_magnitude=0.f;
    IntelligentScissorsMB retval;

    const char* keywords[] = { "weight_non_edge", "weight_gradient_direction", "weight_gradient_magnitude", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "OOO:segmentation_IntelligentScissorsMB.setWeights", (char**)keywords, &pyobj_weight_non_edge, &pyobj_weight_gradient_direction, &pyobj_weight_gradient_magnitude) &&
        pyopencv_to_safe(pyobj_weight_non_edge, weight_non_edge, ArgInfo("weight_non_edge", 0)) &&
        pyopencv_to_safe(pyobj_weight_gradient_direction, weight_gradient_direction, ArgInfo("weight_gradient_direction", 0)) &&
        pyopencv_to_safe(pyobj_weight_gradient_magnitude, weight_gradient_magnitude, ArgInfo("weight_gradient_magnitude", 0)) )
    {
        ERRWRAP2(retval = _self_->setWeights(weight_non_edge, weight_gradient_direction, weight_gradient_magnitude));
        return pyopencv_from(retval);
    }

    return NULL;
}



// Tables (segmentation_IntelligentScissorsMB)

static PyGetSetDef pyopencv_segmentation_IntelligentScissorsMB_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_segmentation_IntelligentScissorsMB_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_segmentation_IntelligentScissorsMB
    PYOPENCV_EXTRA_METHODS_segmentation_IntelligentScissorsMB
#endif
    {"applyImage", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_applyImage, 0), "applyImage(image) -> retval\n.   @brief Specify input image and extract image features\n.        *\n.        * @param image input image. Type is #CV_8UC1 / #CV_8UC3"},
    {"applyImageFeatures", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_applyImageFeatures, 0), "applyImageFeatures(non_edge, gradient_direction, gradient_magnitude[, image]) -> retval\n.   @brief Specify custom features of input image\n.        *\n.        * Customized advanced variant of applyImage() call.\n.        *\n.        * @param non_edge Specify cost of non-edge pixels. Type is CV_8UC1. Expected values are `{0, 1}`.\n.        * @param gradient_direction Specify gradient direction feature. Type is CV_32FC2. Values are expected to be normalized: `x^2 + y^2 == 1`\n.        * @param gradient_magnitude Specify cost of gradient magnitude function: Type is CV_32FC1. Values should be in range `[0, 1]`.\n.        * @param image **Optional parameter**. Must be specified if subset of features is specified (non-specified features are calculated internally)"},
    {"buildMap", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_buildMap, 0), "buildMap(sourcePt) -> None\n.   @brief Prepares a map of optimal paths for the given source point on the image\n.        *\n.        * @note applyImage() / applyImageFeatures() must be called before this call\n.        *\n.        * @param sourcePt The source point used to find the paths"},
    {"getContour", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_getContour, 0), "getContour(targetPt[, contour[, backward]]) -> contour\n.   @brief Extracts optimal contour for the given target point on the image\n.        *\n.        * @note buildMap() must be called before this call\n.        *\n.        * @param targetPt The target point\n.        * @param[out] contour The list of pixels which contains optimal path between the source and the target points of the image. Type is CV_32SC2 (compatible with `std::vector<Point>`)\n.        * @param backward Flag to indicate reverse order of retrieved pixels (use \"true\" value to fetch points from the target to the source point)"},
    {"setEdgeFeatureCannyParameters", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setEdgeFeatureCannyParameters, 0), "setEdgeFeatureCannyParameters(threshold1, threshold2[, apertureSize[, L2gradient]]) -> retval\n.   @brief Switch edge feature extractor to use Canny edge detector\n.        *\n.        * @note \"Laplacian Zero-Crossing\" feature extractor is used by default (following to original article)\n.        *\n.        * @sa Canny"},
    {"setEdgeFeatureZeroCrossingParameters", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setEdgeFeatureZeroCrossingParameters, 0), "setEdgeFeatureZeroCrossingParameters([, gradient_magnitude_min_value]) -> retval\n.   @brief Switch to \"Laplacian Zero-Crossing\" edge feature extractor and specify its parameters\n.        *\n.        * This feature extractor is used by default according to article.\n.        *\n.        * Implementation has additional filtering for regions with low-amplitude noise.\n.        * This filtering is enabled through parameter of minimal gradient amplitude (use some small value 4, 8, 16).\n.        *\n.        * @note Current implementation of this feature extractor is based on processing of grayscale images (color image is converted to grayscale image first).\n.        *\n.        * @note Canny edge detector is a bit slower, but provides better results (especially on color images): use setEdgeFeatureCannyParameters().\n.        *\n.        * @param gradient_magnitude_min_value Minimal gradient magnitude value for edge pixels (default: 0, check is disabled)"},
    {"setGradientMagnitudeMaxLimit", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setGradientMagnitudeMaxLimit, 0), "setGradientMagnitudeMaxLimit([, gradient_magnitude_threshold_max]) -> retval\n.   @brief Specify gradient magnitude max value threshold\n.        *\n.        * Zero limit value is used to disable gradient magnitude thresholding (default behavior, as described in original article).\n.        * Otherwize pixels with `gradient magnitude >= threshold` have zero cost.\n.        *\n.        * @note Thresholding should be used for images with irregular regions (to avoid stuck on parameters from high-contract areas, like embedded logos).\n.        *\n.        * @param gradient_magnitude_threshold_max Specify gradient magnitude max value threshold (default: 0, disabled)"},
    {"setWeights", CV_PY_FN_WITH_KW_(pyopencv_cv_segmentation_segmentation_IntelligentScissorsMB_setWeights, 0), "setWeights(weight_non_edge, weight_gradient_direction, weight_gradient_magnitude) -> retval\n.   @brief Specify weights of feature functions\n.        *\n.        * Consider keeping weights normalized (sum of weights equals to 1.0)\n.        * Discrete dynamic programming (DP) goal is minimization of costs between pixels.\n.        *\n.        * @param weight_non_edge Specify cost of non-edge pixels (default: 0.43f)\n.        * @param weight_gradient_direction Specify cost of gradient direction function (default: 0.43f)\n.        * @param weight_gradient_magnitude Specify cost of gradient magnitude function (default: 0.14f)"},

    {NULL,          NULL}
};

// Converter (segmentation_IntelligentScissorsMB)

template<>
struct PyOpenCV_Converter< cv::segmentation::IntelligentScissorsMB >
{
    static PyObject* from(const cv::segmentation::IntelligentScissorsMB& r)
    {
        return pyopencv_segmentation_IntelligentScissorsMB_Instance(r);
    }
    static bool to(PyObject* src, cv::segmentation::IntelligentScissorsMB& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::segmentation::IntelligentScissorsMB * dst_;
        if (pyopencv_segmentation_IntelligentScissorsMB_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::segmentation::IntelligentScissorsMB for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// utils_ClassWithKeywordProperties (Generic)
//================================================================================

// GetSet (utils_ClassWithKeywordProperties)


static PyObject* pyopencv_utils_ClassWithKeywordProperties_get_except(pyopencv_utils_ClassWithKeywordProperties_t* p, void *closure)
{
    return pyopencv_from(p->v.except);
}

static PyObject* pyopencv_utils_ClassWithKeywordProperties_get_lambda(pyopencv_utils_ClassWithKeywordProperties_t* p, void *closure)
{
    return pyopencv_from(p->v.lambda);
}

static int pyopencv_utils_ClassWithKeywordProperties_set_lambda(pyopencv_utils_ClassWithKeywordProperties_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the lambda attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.lambda, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (utils_ClassWithKeywordProperties)

static int pyopencv_cv_utils_utils_ClassWithKeywordProperties_ClassWithKeywordProperties(pyopencv_utils_ClassWithKeywordProperties_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils;

    PyObject* pyobj_lambda_arg = NULL;
    int lambda_arg=24;
    PyObject* pyobj_except_arg = NULL;
    int except_arg=42;

    const char* keywords[] = { "lambda_arg", "except_arg", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:ClassWithKeywordProperties", (char**)keywords, &pyobj_lambda_arg, &pyobj_except_arg) &&
        pyopencv_to_safe(pyobj_lambda_arg, lambda_arg, ArgInfo("lambda_arg", 0)) &&
        pyopencv_to_safe(pyobj_except_arg, except_arg, ArgInfo("except_arg", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::utils::ClassWithKeywordProperties(lambda_arg, except_arg));
        return 0;
    }

    return -1;
}



// Tables (utils_ClassWithKeywordProperties)

static PyGetSetDef pyopencv_utils_ClassWithKeywordProperties_getseters[] =
{
    {(char*)"except_", (getter)pyopencv_utils_ClassWithKeywordProperties_get_except, NULL, (char*)"except_", NULL},
    {(char*)"lambda_", (getter)pyopencv_utils_ClassWithKeywordProperties_get_lambda, (setter)pyopencv_utils_ClassWithKeywordProperties_set_lambda, (char*)"lambda_", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_utils_ClassWithKeywordProperties_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_utils_ClassWithKeywordProperties
    PYOPENCV_EXTRA_METHODS_utils_ClassWithKeywordProperties
#endif

    {NULL,          NULL}
};

// Converter (utils_ClassWithKeywordProperties)

template<>
struct PyOpenCV_Converter< cv::utils::ClassWithKeywordProperties >
{
    static PyObject* from(const cv::utils::ClassWithKeywordProperties& r)
    {
        return pyopencv_utils_ClassWithKeywordProperties_Instance(r);
    }
    static bool to(PyObject* src, cv::utils::ClassWithKeywordProperties& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::utils::ClassWithKeywordProperties * dst_;
        if (pyopencv_utils_ClassWithKeywordProperties_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::utils::ClassWithKeywordProperties for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// utils_FunctionParams (Map)
//================================================================================
static bool pyopencv_to(PyObject* src, cv::utils::FunctionParams& dst, const ArgInfo& info)
{
    PyObject* tmp;
    bool ok;

    if( PyMapping_HasKeyString(src, (char*)"lambda") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"lambda");
        ok = tmp && pyopencv_to_safe(tmp, dst.lambda, ArgInfo("lambda", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    if( PyMapping_HasKeyString(src, (char*)"sigma") )
    {
        tmp = PyMapping_GetItemString(src, (char*)"sigma");
        ok = tmp && pyopencv_to_safe(tmp, dst.sigma, ArgInfo("sigma", 0));
        Py_DECREF(tmp);
        if(!ok) return false;
    }
    return true;
}

template<> bool pyopencv_to(PyObject* src, cv::utils::FunctionParams& dst, const ArgInfo& info);

//================================================================================
// utils_nested_OriginalClassName (Generic)
//================================================================================

// GetSet (utils_nested_OriginalClassName)



// Methods (utils_nested_OriginalClassName)

static PyObject* pyopencv_cv_utils_nested_utils_nested_OriginalClassName_create_static(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    PyObject* pyobj_params = NULL;
    OriginalClassName_Params params=OriginalClassName::Params();
    Ptr<OriginalClassName> retval;

    const char* keywords[] = { "params", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|O:utils_nested_ExportClassName.create", (char**)keywords, &pyobj_params) &&
        pyopencv_to_safe(pyobj_params, params, ArgInfo("params", 0)) )
    {
        ERRWRAP2(retval = cv::utils::nested::OriginalClassName::create(params));
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_utils_nested_OriginalClassName_getFloatParam(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;


    Ptr<cv::utils::nested::OriginalClassName> * self1 = 0;
    if (!pyopencv_utils_nested_OriginalClassName_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'utils_nested_OriginalClassName' or its derivative)");
    Ptr<cv::utils::nested::OriginalClassName> _self_ = *(self1);
    float retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getFloatParam());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_utils_nested_OriginalClassName_getIntParam(PyObject* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;


    Ptr<cv::utils::nested::OriginalClassName> * self1 = 0;
    if (!pyopencv_utils_nested_OriginalClassName_getp(self, self1))
        return failmsgp("Incorrect type of self (must be 'utils_nested_OriginalClassName' or its derivative)");
    Ptr<cv::utils::nested::OriginalClassName> _self_ = *(self1);
    int retval;

    if(PyObject_Size(py_args) == 0 && (!kw || PyObject_Size(kw) == 0))
    {
        ERRWRAP2(retval = _self_->getIntParam());
        return pyopencv_from(retval);
    }

    return NULL;
}

static PyObject* pyopencv_cv_utils_nested_utils_nested_OriginalClassName_originalName_static(PyObject* self, PyObject* py_args, PyObject* kw)
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



// Tables (utils_nested_OriginalClassName)

static PyGetSetDef pyopencv_utils_nested_OriginalClassName_getseters[] =
{
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_utils_nested_OriginalClassName_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_utils_nested_OriginalClassName
    PYOPENCV_EXTRA_METHODS_utils_nested_OriginalClassName
#endif
    {"create", CV_PY_FN_WITH_KW_(pyopencv_cv_utils_nested_utils_nested_OriginalClassName_create_static, METH_STATIC), "create([, params]) -> retval\n."},
    {"getFloatParam", CV_PY_FN_WITH_KW_(pyopencv_cv_utils_nested_utils_nested_OriginalClassName_getFloatParam, 0), "getFloatParam() -> retval\n."},
    {"getIntParam", CV_PY_FN_WITH_KW_(pyopencv_cv_utils_nested_utils_nested_OriginalClassName_getIntParam, 0), "getIntParam() -> retval\n."},
    {"originalName", CV_PY_FN_WITH_KW_(pyopencv_cv_utils_nested_utils_nested_OriginalClassName_originalName_static, METH_STATIC), "originalName() -> retval\n."},

    {NULL,          NULL}
};

// Converter (utils_nested_OriginalClassName)

template<>
struct PyOpenCV_Converter< Ptr<cv::utils::nested::OriginalClassName> >
{
    static PyObject* from(const Ptr<cv::utils::nested::OriginalClassName>& r)
    {
        return pyopencv_utils_nested_OriginalClassName_Instance(r);
    }
    static bool to(PyObject* src, Ptr<cv::utils::nested::OriginalClassName>& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        Ptr<cv::utils::nested::OriginalClassName> * dst_;
        if (pyopencv_utils_nested_OriginalClassName_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected Ptr<cv::utils::nested::OriginalClassName> for argument '%s'", info.name);
        return false;
    }
};

//================================================================================
// utils_nested_OriginalClassName_Params (Generic)
//================================================================================

// GetSet (utils_nested_OriginalClassName_Params)


static PyObject* pyopencv_utils_nested_OriginalClassName_Params_get_float_value(pyopencv_utils_nested_OriginalClassName_Params_t* p, void *closure)
{
    return pyopencv_from(p->v.float_value);
}

static int pyopencv_utils_nested_OriginalClassName_Params_set_float_value(pyopencv_utils_nested_OriginalClassName_Params_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the float_value attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.float_value, ArgInfo("value", 0)) ? 0 : -1;
}

static PyObject* pyopencv_utils_nested_OriginalClassName_Params_get_int_value(pyopencv_utils_nested_OriginalClassName_Params_t* p, void *closure)
{
    return pyopencv_from(p->v.int_value);
}

static int pyopencv_utils_nested_OriginalClassName_Params_set_int_value(pyopencv_utils_nested_OriginalClassName_Params_t* p, PyObject *value, void *closure)
{
    if (!value)
    {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the int_value attribute");
        return -1;
    }
    return pyopencv_to_safe(value, p->v.int_value, ArgInfo("value", 0)) ? 0 : -1;
}


// Methods (utils_nested_OriginalClassName_Params)

static int pyopencv_cv_utils_nested_utils_nested_OriginalClassName_Params_OriginalClassName_Params(pyopencv_utils_nested_OriginalClassName_Params_t* self, PyObject* py_args, PyObject* kw)
{
    using namespace cv::utils::nested;

    PyObject* pyobj_int_param = NULL;
    int int_param=123;
    PyObject* pyobj_float_param = NULL;
    float float_param=3.5f;

    const char* keywords[] = { "int_param", "float_param", NULL };
    if( PyArg_ParseTupleAndKeywords(py_args, kw, "|OO:OriginalClassName_Params", (char**)keywords, &pyobj_int_param, &pyobj_float_param) &&
        pyopencv_to_safe(pyobj_int_param, int_param, ArgInfo("int_param", 0)) &&
        pyopencv_to_safe(pyobj_float_param, float_param, ArgInfo("float_param", 0)) )
    {
        if(self) ERRWRAP2(new (&(self->v)) cv::utils::nested::OriginalClassName::Params(int_param, float_param));
        return 0;
    }

    return -1;
}



// Tables (utils_nested_OriginalClassName_Params)

static PyGetSetDef pyopencv_utils_nested_OriginalClassName_Params_getseters[] =
{
    {(char*)"float_value", (getter)pyopencv_utils_nested_OriginalClassName_Params_get_float_value, (setter)pyopencv_utils_nested_OriginalClassName_Params_set_float_value, (char*)"float_value", NULL},
    {(char*)"int_value", (getter)pyopencv_utils_nested_OriginalClassName_Params_get_int_value, (setter)pyopencv_utils_nested_OriginalClassName_Params_set_int_value, (char*)"int_value", NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef pyopencv_utils_nested_OriginalClassName_Params_methods[] =
{
#ifdef PYOPENCV_EXTRA_METHODS_utils_nested_OriginalClassName_Params
    PYOPENCV_EXTRA_METHODS_utils_nested_OriginalClassName_Params
#endif

    {NULL,          NULL}
};

// Converter (utils_nested_OriginalClassName_Params)

template<>
struct PyOpenCV_Converter< cv::utils::nested::OriginalClassName::Params >
{
    static PyObject* from(const cv::utils::nested::OriginalClassName::Params& r)
    {
        return pyopencv_utils_nested_OriginalClassName_Params_Instance(r);
    }
    static bool to(PyObject* src, cv::utils::nested::OriginalClassName::Params& dst, const ArgInfo& info)
    {
        if(!src || src == Py_None)
            return true;
        cv::utils::nested::OriginalClassName::Params * dst_;
        if (pyopencv_utils_nested_OriginalClassName_Params_getp(src, dst_))
        {
            dst = *dst_;
            return true;
        }
        
        failmsg("Expected cv::utils::nested::OriginalClassName::Params for argument '%s'", info.name);
        return false;
    }
};

