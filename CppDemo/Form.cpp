#include "Form.h"

#include <QTimer>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDateTime>
#include <QDir>

#include "api/ErrorInfoHelper.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);

    CDobotClient::InitNet();

    m_pTimerReader = new QTimer(this);
    m_pTimerReader->setInterval(100);
    connect(m_pTimerReader, &QTimer::timeout, this, &Form::slotTimeoutReadFeedback);

    connect(this, &Form::signalPrintLog, this, [this](QString str){
        static int iLineCount = 0;
        if (iLineCount > 50)
        {
            iLineCount = 0;
            ui->textEditLog->clear();
        }
        ++iLineCount;
        ui->textEditLog->append(str);
    });
    connect(this, &Form::signalSetBtnText, this, [](QPushButton* pBtn, QString strTxt){
        pBtn->setText(strTxt);
    });
    connect(this, &Form::signalConnectState, this, [this](bool bConnected){
        ui->boxDashboard->setEnabled(bConnected);
        ui->boxMoveFunction->setEnabled(bConnected);
        ui->boxFeedback->setEnabled(bConnected);
        if (bConnected)
            m_pTimerReader->start();
        else
            m_pTimerReader->stop();
    });

    connect(ui->btn6AxisJ1M, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ1M, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ2M, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ2M, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ3M, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ3M, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ4M, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ4M, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ5M, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ5M, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ6M, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ6M, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);

    connect(ui->btn6AxisJ1P, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ1P, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ2P, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ2P, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ3P, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ3P, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ4P, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ4P, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ5P, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ5P, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisJ6P, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisJ6P, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);

    connect(ui->btn6AxisXM, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisXM, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisYM, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisYM, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisZM, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisZM, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisRXM, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisRXM, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisRYM, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisRYM, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisRZM, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisRZM, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);

    connect(ui->btn6AxisXP, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisXP, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisYP, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisYP, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisZP, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisZP, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisRXP, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisRXP, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisRYP, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisRYP, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);
    connect(ui->btn6AxisRZP, &QPushButton::pressed, this, &Form::slotOnBtnMoveJog);
    connect(ui->btn6AxisRZP, &QPushButton::released, this, &Form::slotOnBtnStopMoveJog);

    ui->boxDashboard->setEnabled(false);
    ui->boxMoveFunction->setEnabled(false);
    ui->boxFeedback->setEnabled(false);

    QString strPath = qApp->applicationDirPath() + QDir::separator();
    CErrorInfoHelper::ParseControllerJsonFile(QString(strPath+ "alarm_controller.json").toStdString());
    CErrorInfoHelper::ParseServoJsonFile(QString(strPath + "alarm_servo.json").toStdString());
}

Form::~Form()
{
    CDobotClient::UinitNet();

    delete ui;
}

void Form::PrintLog(QString strLog)
{
    emit signalPrintLog(strLog);
}

void Form::on_btnConnect_clicked()
{
    if (ui->btnConnect->text().compare("Disconnect")==0)
    {
        Disconnect();
        return;
    }
    Connect();
}

void Form::Connect()
{
    QString strIp = ui->lineEditIP->text();
    unsigned short iPortDashboard = ui->lineEditDashPort->text().toUShort();
    unsigned short iPortMove = ui->lineEditMovePort->text().toUShort();
    unsigned short iPortFeedback = ui->lineEditFeedbackPort->text().toUShort();

    PrintLog("Connecting...");
    std::thread thd([=]{
        if (!m_Dashboard.Connect(strIp.toStdString(), iPortDashboard))
        {
            PrintLog(QString::asprintf("Connect %s:%hu Fail!!", strIp.toStdString().c_str(), iPortDashboard));
            return;
        }
        if (!m_DobotMove.Connect(strIp.toStdString(), iPortMove))
        {
            PrintLog(QString::asprintf("Connect %s:%hu Fail!!", strIp.toStdString().c_str(), iPortMove));
            return;
        }
        if (!m_Feedback.Connect(strIp.toStdString(), iPortFeedback))
        {
            PrintLog(QString::asprintf("Connect %s:%hu Fail!!", strIp.toStdString().c_str(), iPortFeedback));
            return;
        }
        PrintLog("Connect Success!!!");

        emit signalSetBtnText(ui->btnConnect,QString("Disconnect"));
        emit signalConnectState(true);
    });
    thd.detach();
}

void Form::Disconnect()
{
    std::thread thd([this]{
        emit signalConnectState(false);
        m_Feedback.Disconnect();
        m_DobotMove.Disconnect();
        m_Dashboard.Disconnect();
        PrintLog("Disconnect success!!!");
        emit signalSetBtnText(ui->btnConnect,QString("Connect"));
    });
    thd.detach();
}

void Form::on_btnEnable_clicked()
{
    bool bEnable = ui->btnEnable->text().compare("Enable")==0;
    PrintLog(QString::asprintf("send to %s:%hu: %s()", m_Dashboard.GetIp().c_str(),
                               m_Dashboard.GetPort(), bEnable? "EnableRobot" : "DisableRobot"));
    std::thread thd([=]{
        std::string ret = bEnable ? m_Dashboard.EnableRobot() : m_Dashboard.DisableRobot();
        bool bOk = ret.find("0")==0;
        if (bOk)
        {
            emit signalSetBtnText(ui->btnEnable,QString(bEnable?"Disable":"Enable"));
        }
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_Dashboard.GetIp().c_str(),
                                   m_Dashboard.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_btnReset_clicked()
{
    PrintLog(QString::asprintf("send to %s:%hu: ResetRobot()", m_Dashboard.GetIp().c_str(), m_Dashboard.GetPort()));
    std::thread thd([this]{
        std::string ret = m_Dashboard.ResetRobot();
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_Dashboard.GetIp().c_str(),
                                   m_Dashboard.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_clearError_clicked()
{
    PrintLog(QString::asprintf("send to %s:%hu: ClearError()", m_Dashboard.GetIp().c_str(), m_Dashboard.GetPort()));
    std::thread thd([this]{
        std::string ret = m_Dashboard.ClearError();
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_Dashboard.GetIp().c_str(),
                                   m_Dashboard.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_btnConfirmSpeed_clicked()
{
    int iValue = ui->spinBox->value();
    PrintLog(QString::asprintf("send to %s:%hu: SpeedFactor(%d)", m_Dashboard.GetIp().c_str(), m_Dashboard.GetPort(),iValue));
    std::thread thd([=]{
        std::string ret = m_Dashboard.SpeedFactor(iValue);
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_Dashboard.GetIp().c_str(),
                                   m_Dashboard.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_btnConfirmDO_clicked()
{
    int idx = ui->editIndex->text().toInt();
    bool bIsOn = ui->comboBoxStatus->currentText().compare("ON",Qt::CaseInsensitive)==0;
    PrintLog(QString::asprintf("send to %s:%hu: DigitalOutputs(%d,%s)", m_Dashboard.GetIp().c_str(),
                               m_Dashboard.GetPort(),idx,bIsOn?"on":"off"));
    std::thread thd([=]{
        std::string ret = m_Dashboard.DigitalOutputs(idx, bIsOn);
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_Dashboard.GetIp().c_str(),
                                   m_Dashboard.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_btnMovJ_clicked()
{
    CDescartesPoint pt;
    pt.x = ui->lineEditX->text().toDouble();
    pt.y = ui->lineEditY->text().toDouble();
    pt.z = ui->lineEditZ->text().toDouble();
    pt.rx = ui->lineEditRX->text().toDouble();
    pt.ry = ui->lineEditRY->text().toDouble();
    pt.rz = ui->lineEditRZ->text().toDouble();

    PrintLog(QString::asprintf("send to %s:%hu: MovJ(%s)", m_DobotMove.GetIp().c_str(),
                               m_DobotMove.GetPort(),pt.ToString().c_str()));
    std::thread thd([=]{
        std::string ret = m_DobotMove.MovJ(pt);
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_DobotMove.GetIp().c_str(),
                                   m_DobotMove.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_btnMovL_clicked()
{
    CDescartesPoint pt;
    pt.x = ui->lineEditX->text().toDouble();
    pt.y = ui->lineEditY->text().toDouble();
    pt.z = ui->lineEditZ->text().toDouble();
    pt.rx = ui->lineEditRX->text().toDouble();
    pt.ry = ui->lineEditRY->text().toDouble();
    pt.rz = ui->lineEditRZ->text().toDouble();

    PrintLog(QString::asprintf("send to %s:%hu: MovL(%s)", m_DobotMove.GetIp().c_str(),
                               m_DobotMove.GetPort(),pt.ToString().c_str()));
    std::thread thd([=]{
        std::string ret = m_DobotMove.MovL(pt);
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_DobotMove.GetIp().c_str(),
                                   m_DobotMove.GetPort(), ret.c_str()));
    });
    thd.detach();
}


void Form::on_btnJointMovJ_clicked()
{
    CJointPoint pt;
    pt.j1 = ui->lineEditJ1->text().toDouble();
    pt.j2 = ui->lineEditJ2->text().toDouble();
    pt.j3 = ui->lineEditJ3->text().toDouble();
    pt.j4 = ui->lineEditJ4->text().toDouble();
    pt.j5 = ui->lineEditJ5->text().toDouble();
    pt.j6 = ui->lineEditJ6->text().toDouble();

    PrintLog(QString::asprintf("send to %s:%hu: JointMovJ(%s)", m_DobotMove.GetIp().c_str(),
                               m_DobotMove.GetPort(),pt.ToString().c_str()));
    std::thread thd([=]{
        std::string ret = m_DobotMove.JointMovJ(pt);
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_DobotMove.GetIp().c_str(),
                                   m_DobotMove.GetPort(), ret.c_str()));
    });
    thd.detach();
}

void Form::slotOnBtnMoveJog()
{
    QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
    if (!pBtn) return;
    DoMoveJog(pBtn->text());
}

void Form::slotOnBtnStopMoveJog()
{
    QPushButton* pBtn = qobject_cast<QPushButton*>(sender());
    if (!pBtn) return;
    DoStopMoveJog();
}

void Form::DoMoveJog(QString str)
{
    PrintLog(QString::asprintf("send to %s:%hu: MoveJog(%s)", m_DobotMove.GetIp().c_str(),
                               m_DobotMove.GetPort(),str.toStdString().c_str()));
    std::thread thd([=]{
        std::string ret = m_DobotMove.MoveJog(str.toStdString());
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_DobotMove.GetIp().c_str(),
                                   m_DobotMove.GetPort(), ret.c_str()));
    });
    thd.detach();
}

void Form::DoStopMoveJog()
{
    PrintLog(QString::asprintf("send to %s:%hu: MoveJog()", m_DobotMove.GetIp().c_str(),
                               m_DobotMove.GetPort()));
    std::thread thd([=]{
        std::string ret = m_DobotMove.MoveJog("");
        PrintLog(QString::asprintf("Receive From %s:%hu: %s", m_DobotMove.GetIp().c_str(),
                                   m_DobotMove.GetPort(), ret.c_str()));
    });
    thd.detach();
}

void Form::slotTimeoutReadFeedback()
{
    if (!m_Feedback.IsDataHasRead())
    {
        return;
    }
    m_Feedback.SetDataHasRead(false);
    ShowDataResult();
}

void Form::ShowDataResult()
{
    ui->labCurrentSpeedRatio->setText(QString::asprintf("Current Speed Ratio:%.2f%%",m_Feedback.GetFeedbackData().SpeedScaling));
    ui->labRobotMode->setText(QString::asprintf("Robot Mode:%s", m_Feedback.ConvertRobotMode().c_str()));

    ui->dbBoxJ1->setValue(m_Feedback.GetFeedbackData().QActual[0]);
    ui->dbBoxJ2->setValue(m_Feedback.GetFeedbackData().QActual[1]);
    ui->dbBoxJ3->setValue(m_Feedback.GetFeedbackData().QActual[2]);
    ui->dbBoxJ4->setValue(m_Feedback.GetFeedbackData().QActual[3]);
    ui->dbBoxJ5->setValue(m_Feedback.GetFeedbackData().QActual[4]);
    ui->dbBoxJ6->setValue(m_Feedback.GetFeedbackData().QActual[5]);

    ui->dbBoxX->setValue(m_Feedback.GetFeedbackData().ToolVectorActual[0]);
    ui->dbBoxY->setValue(m_Feedback.GetFeedbackData().ToolVectorActual[1]);
    ui->dbBoxZ->setValue(m_Feedback.GetFeedbackData().ToolVectorActual[2]);
    ui->dbBoxA->setValue(m_Feedback.GetFeedbackData().ToolVectorActual[3]);
    ui->dbBoxB->setValue(m_Feedback.GetFeedbackData().ToolVectorActual[4]);
    ui->dbBoxC->setValue(m_Feedback.GetFeedbackData().ToolVectorActual[5]);

    QString strValue = QString::number(m_Feedback.GetFeedbackData().DigitalInputs,2).rightJustified(64,'0');
    ui->labDI->setText(QString::asprintf("Digital Inputs:%s", strValue.toStdString().c_str()));

    strValue = QString::number(m_Feedback.GetFeedbackData().DigitalOutputs,2).rightJustified(64,'0');
    ui->labDO->setText(QString::asprintf("Digital Inputs:%s",strValue.toStdString().c_str()));

    ParseWarn();
}

void Form::ParseWarn()
{
    if (m_Feedback.GetFeedbackData().RobotMode != 9) return;

    //strResult=ErrorID,{[[id,...,id], [id], [id], [id], [id], [id], [id]]},GetErrorID()
    std::string strResult = m_Dashboard.GetErrorID();
    if (strResult.find("0")!=0) return;

    //截取第一个{}内容
    size_t iBegPos = strResult.find('{');
    if (iBegPos == std::string::npos) return;
    size_t iEndPos = strResult.find('}', iBegPos + 1);
    if (iEndPos <= iBegPos) return;
    strResult = strResult.substr(iBegPos + 1, iEndPos - iBegPos - 1);
    if (strResult.empty()) return;

    //剩余7组[]，第1组是控制器报警，其他6组是伺服报警
    QString strShowTxt;
    QJsonDocument doc = QJsonDocument::fromJson(QByteArray(strResult.c_str(), strResult.size()));
    do{
        if (!doc.isArray()) break;
        QJsonArray arrWarn = doc.array();
        for (int i = 0; i < arrWarn.size(); ++i)
        {
            if (!arrWarn[i].isArray()) continue;

            QJsonArray arr = arrWarn[i].toArray();
            for (int j = 0; j < arr.size(); ++j)
            {
                bool bFind = false;
                CErrorInfoBean bean;
                if (0 == i)
                {//控制器报警
                    bFind = CErrorInfoHelper::FindController(arr[j].toInt(), bean);
                }
                else
                {//伺服报警
                    bFind = CErrorInfoHelper::FindServo(arr[j].toInt(), bean);
                }
                if (bFind)
                {
                    strShowTxt.append(QString::asprintf("ID:%d\r\n",bean.id));
                    strShowTxt.append(QString::asprintf("Type:%s\r\n",bean.Type.c_str()));
                    strShowTxt.append(QString::asprintf("Level:%d\r\n",bean.level));
                    strShowTxt.append(QString::asprintf("Solution:%s\r\n",bean.en.solution.c_str()));
                }
            }
        }
    }while(false);

    if (!strShowTxt.isEmpty())
    {
        static int iLineCount = 0;
        if (iLineCount > 50)
        {
            ui->textEditErrorInfo->clear();
            iLineCount = 0;
        }
        ++iLineCount;
        QString strTime = QString("Time Stamp: ") + QDateTime::currentDateTime().toLocalTime().toString("yyyy-MM-dd HH:mm:ss");
        ui->textEditErrorInfo->append(strTime);
        ui->textEditErrorInfo->append(strShowTxt);
    }
}
