#if false
using UnityEngine;
using UniRx;
using static Expm.ExStep;
using Step = Expm.Step;

namespace du.Test {

    public interface ITestCode {
        void OnAwake();
        void OnStart();
        void OnUpdate();
    }
    public abstract class AbsTestCode : ITestCode {
        public virtual void OnAwake() {}
        public virtual void OnStart() {}
        public virtual void OnUpdate() {}
    }

    public class TestCodeCalledByAppMgr : AbsTestCode {

        public override void OnAwake() {
            LLog.Boot.Log("TestCodeCalledByAppMgr on start.");

            // string log = "";
            // LLog.Debug.Log(log);

        }

    }

}

#endif
