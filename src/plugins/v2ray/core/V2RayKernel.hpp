#pragma once

#include "QvPlugin/Handlers/KernelHandler.hpp"

class QProcess;
class APIWorker;

const inline KernelId v2ray_kernel_id{ u"v2ray_kernel"_qs };

class V2RayKernel : public Qv2rayPlugin::Kernel::PluginKernel
{
    Q_OBJECT
  public:
    V2RayKernel();
    ~V2RayKernel();

  public:
    virtual void SetConnectionSettings(const QMap<Qv2rayPlugin::Kernel::KernelOptionFlags, QVariant> &, const IOConnectionSettings &) override{};
    virtual void SetProfileContent(const ProfileContent &) override;
    virtual bool PrepareConfigurations() override;
    virtual void Start() override;
    virtual bool Stop() override;
    virtual KernelId GetKernelId() const override
    {
        return v2ray_kernel_id;
    }

  signals:
    void OnCrashed(const QString &);
    void OnLog(const QString &);
    void OnStatsAvailable(StatisticsObject);

  private:
    std::optional<QString> ValidateConfig(const QString &path);

  private:
    ProfileContent profile;
    APIWorker *apiWorker;
    QProcess *vProcess;
    bool apiEnabled;
    bool kernelStarted = false;
    QMap<QString, QString> tagProtocolMap;
    QString configFilePath;
};
