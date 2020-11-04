#if false
using UnityEngine;


namespace du.Test {

    public class LayerdLogMgr : MonoBehaviour {
        [SerializeField] bool m_isLogEnable = true;

        [SerializeField] bool m_llog  = true;

        [SerializeField] bool m_boot  = true;
        [SerializeField] bool m_dutil = true;
        [SerializeField] bool m_debug = true;
        [SerializeField] bool m_audio = true;
        [SerializeField] bool m_misc  = true;

        [SerializeField] bool m_iaBoot   = true;
        [SerializeField] bool m_iAct     = true;
        [SerializeField] bool m_expLog   = true;
        [SerializeField] bool m_mainBoot = true;
        [SerializeField] bool m_mainMem  = true;
        [SerializeField] bool m_expm     = true;

        public void InitializeLLog() {
            LayeredLog.Initialize(m_isLogEnable);
            LayeredLog.SetActive("LLOG" , m_llog );

            LayeredLog.SetActive("BOOT" , m_boot );
            LayeredLog.SetActive("dUTIL", m_dutil);
            LayeredLog.SetActive("DEBUG", m_debug);
            LayeredLog.SetActive("AUDIO", m_audio);
            LayeredLog.SetActive("MISC" , m_misc );

            LayeredLog.SetActive("IA:BOOT", m_iaBoot);
            LayeredLog.SetActive("IA:IACT", m_iAct);
            LayeredLog.SetActive("EXPLOG", m_expLog);
            LayeredLog.SetActive("MAIN:BOOT", m_mainBoot);
            LayeredLog.SetActive("MAIN:MEM", m_mainMem);
            LayeredLog.SetActive("EXPM", m_expLog);
        }
    }

}
#endif
