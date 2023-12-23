#ifndef FORM_H
#define FORM_H

#include <QMainWindow>

#include "ui_Form.h"

#include "api/Feedback.h"
#include "api/DobotMove.h"
#include "api/Dashboard.h"

using namespace Dobot;

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class QTimer;

class Form : public QWidget
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void signalConnectState(bool);
    void signalPrintLog(QString strLog);
    void signalSetBtnText(QPushButton* pBtn, QString strTxt);

private slots:
    void slotTimeoutReadFeedback();

    void on_btnConnect_clicked();

    void on_btnEnable_clicked();

    void on_btnReset_clicked();

    void on_clearError_clicked();

    void on_btnConfirmSpeed_clicked();

    void on_btnConfirmDO_clicked();

    void on_btnMovJ_clicked();

    void on_btnMovL_clicked();

    void on_btnJointMovJ_clicked();

    void slotOnBtnMoveJog();
    void slotOnBtnStopMoveJog();

private:
    void Connect();
    void Disconnect();

    void PrintLog(QString strLog);
    void DoMoveJog(QString str);
    void DoStopMoveJog();
    void ShowDataResult();
    void ParseWarn();

private:
    Ui::Form *ui;
    QTimer* m_pTimerReader;

    CFeedback m_Feedback;
    CDobotMove m_DobotMove;
    CDashboard m_Dashboard;
};
#endif // FORM_H
