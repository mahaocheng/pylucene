/*
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <jni.h>
#include "JCCEnv.h"
#include "java/lang/Object.h"
#include "java/lang/Class.h"
#include "java/lang/Integer.h"

namespace java {
    namespace lang {

        enum {
            mid__init_,
            mid_intValue,
            max_mid
        };

        Class *Integer::class$ = NULL;
        jmethodID *Integer::_mids = NULL;
        
        jclass Integer::initializeClass(bool getOnly)
        {
            if (getOnly)
                return (jclass) (class$ == NULL ? NULL : class$->this$);
            if (!class$)
            {
                jclass cls = env->findClass("java/lang/Integer");

                _mids = new jmethodID[max_mid];
                _mids[mid__init_] = env->getMethodID(cls, "<init>", "(I)V");
                _mids[mid_intValue] =
                    env->getMethodID(cls, "intValue", "()I");

                class$ = (Class *) new JObject(cls);
            }

            return (jclass) class$->this$;
        }

        Integer::Integer(jint n) : Object(env->newObject(initializeClass, &_mids, mid__init_, n)) {
        }

        jint Integer::intValue() const
        {
            return env->callIntMethod(this$, _mids[mid_intValue]);
        }
    }
}


#include "structmember.h"
#include "functions.h"
#include "macros.h"

namespace java {
    namespace lang {

        static PyMethodDef t_Integer__methods_[] = {
            { NULL, NULL, 0, NULL }
        };

        DECLARE_TYPE(Integer, t_Integer, Object, java::lang::Integer,
                     abstract_init, 0, 0, 0, 0, 0);
    }
}
