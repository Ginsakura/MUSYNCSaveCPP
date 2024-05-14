# ͬ������������ Steam�� �浵�������� C++�ع���
MUSYNX Steam Client Savefile Decode & Analyze Tool C++ Version

[down_svg]: https://img.shields.io/github/downloads/ginsakura/MUSYNCSaveCPP/total?label=All%20Downloads
[all_release]: https://github.com/Ginsakura/MUSYNCSaveCPP/releases
[commit_svg]: https://img.shields.io/github/commit-activity/t/ginsakura/MUSYNCSaveCPP?label=All%20Commits
[commit]: https://github.com/Ginsakura/MUSYNCSaveCPP/commits
[license_svg]: https://img.shields.io/github/license/ginsakura/MUSYNCSaveCPP?label=License
[![All releases][down_svg]][all_release]
[![All commit activity (branch)][commit_svg]][commit]
[![License][license_svg]](./LICENSE)

[latest_prerelease_svg]: https://img.shields.io/github/v/release/ginsakura/MUSYNCSaveCPP?display_name=release&label=Latest%20PreRelease&include_prereleases
[all_tags]: https://github.com/Ginsakura/MUSYNCSaveCPP/tags
[![Latest tag][latest_prerelease_svg]][all_tags]

[latest_release_svg]: https://img.shields.io/github/v/release/ginsakura/MUSYNCSaveCPP?display_name=release&label=Latest%20Release
[release]: https://github.com/Ginsakura/MUSYNCSaveCPP/releases/latest
[![latest release][latest_release_svg]][release]

## How to use

1. [English (English, `en-us`) v1.2.6 rc2](How_to_use.en.md)
2. [�������� (Simplified Chinese, `zh-Hans`) v1.2.6 rc2](How_to_use.zh.md)

## ����չʾ

<details>
<summary>����չʾ</summary>

![��ҳ��](./ReadmeResources/main.png "��ҳ��")
![score-diffҳ��](./ReadmeResources/score-diff.png "score-diffҳ��")
![HitDelayҳ��](./ReadmeResources/HitDelay.png "HitDelayҳ��")
![HitAnalyze-Pie&Barҳ��](./ReadmeResources/HitAnalyze-Pie&Bar.png "HitAnalyze-Pie&Barҳ��")
![HitAnalyze-Lineҳ��](./ReadmeResources/HitAnalyze-Line.png "HitAnalyze-Lineҳ��")
![AllHitAnalyze-Pieҳ��](./ReadmeResources/AllHitAnalyze.png "AllHitAnalyzeҳ��")
![AvgAcc-SYNC.Rate�ع����ҳ��](./ReadmeResources/AvgAcc-SYNC.Rate.png "AvgAcc-SYNC.Rate�ع����")

</details>

## �ƻ�
### δ���ļƻ�
- [ ] �ṩȫ�����а���ʾ���� (��Ҫ����SteamAPI)
- [ ] ���ṩһ���ĵ�����ʾʹ�÷��� (��д��,������)
- [ ] ʹ���ļ�����ָ���ļ����ķ�ʽ�Զ�������UI
### ����ɵļƻ�
- [x] һ����ȡ�ϴ�����������
- [x] ʹ��GitHub Action workflowʵ���Զ��ַ�
- [x] ���Ű�SongName.json
- [x] ���������ؼ��غ󱣳�λ�ò���
- [x] ����cmd����
- [x] ����Windows��Դ������һ��ʹ���б�������������
- [x] ���߼���������Ϊ`ExtraFunction.cfg`�����ļ�

## Release�汾˵��
NoConsole�汾Ϊû��������ʾ�����棬�ʺ�����ʹ��

WithConsole�汾Ϊ��������ʾ�����棬�ʺϳ���bugʱ���ٶ�λ�������ص��Լ�ԭ��

## ���ܿ���ģ��
<details>
<summary>���Ʋ������</summary>

��`./musync_data/ExtraFunction.cfg`�ļ�������/���ö�Ӧ����

|               ������              |     Ĭ��ֵ    | ֵ���� |                                ����˵��                                |
|-----------------------------------|---------------|--------|------------------------------------------------------------------------|
| `EnableAcc-Sync`                  |false          |boolean |�Ƿ�����Acc-Synxͼ��                                                    |
| `DisableCheckUpdate`              |false          |boolean |�Ƿ���ø��¼��                                                        |
| `EnableAnalyzeWhenStarting`       |false          |boolean |�Ƿ�����ÿ������ʱ����ɨ��浵�ļ�                                      |
| `EnableDLLInjection`              |false          |boolean |�Ƿ�����DLLע���Կ���`�߼�����`                                         |
| `SystemDPI`                       |`�Զ���ȡ`     |string  |��ȡϵͳDPI, �ṩDPI��������(δʵ��)                                    |
| `EnableDonutChartinHitDelay`      |false          |boolean |�Ƿ��ڵ�������ͳ������ʾ�����ӳٻ���ͼ                                  |
| `EnableDonutChartinAllHitAnalyze` |false          |boolean |�Ƿ���ȫ��ͳ������ʾ�����ӳٻ���ͼ                                      |
| `EnablePDFofCyanExact`            |false          |boolean |�Ƿ���ȫ��ͳ������ʾ��CyanExact����̬�ֲ����                           |
| `EnableNarrowDelayInterval`       |true           |boolean |�Ƿ��ڵ�������ͳ����ʹ�ø���խ�Ļ�������������ƽ��ƫ��ֵ(Delay)<br>[true=45ms,false=90ms]|
| `ConsoleAlpha`                    |75             |int     |��������Ϸ�������̨���ڵĲ�͸����<br>(ȡֵ��Χ[0,100],100Ϊ��ȫ��͸��,������ȡֵ��30����)|
| `ConsoleFont`                     |'ϼ���Ŀ��ȿ�' |string  |��������Ϸ�������̨���ڵ�����                                          |
| `ConsoleFontSize`                 |36             |int     |��������Ϸ�������̨���ڵ��ֺ�                                          |
| `MainExecPath`                    |`�Զ���ȡ`     |string  |��������Ϸ�������������ڵ�·��                                          |
| `ChangeConsoleStyle`              |false          |boolean |�Ƿ������Զ�����������Ϸ�������̨������ʽ                              |
| `EnableFramelessWindow`           |false          |boolean |�Ƿ������ޱ߿򴰿���ʽ(δ���)                                          |
| `TransparentColor`                |'#FFFFFF'      |string<br>boolean |����͸��ɫ(��������ʽ)<br>����Ϊfalse��Ϊ�ر�͸��ɫ           |
| `DefaultKeys`                     |false          |boolean |`�߼�����`��Ĭ��`����`����                                              |
| `DefaultDiffcute`                 |0              |int     |`�߼�����`��Ĭ��`�Ѷ�`����                                              |

</details>

### �߼����ܼ��
�����������Ϸ�ͻ������޸�,�����ʹ��

*** $\color{Red}{ ע�ⱸ�� ע�ⱸ�� ע�ⱸ�� }$ ***

$\color{Red}{�����о����Ƿ�ʹ��,ʹ�ù����г����κ�����}$
$\color{Red}{����Ը�,�����߸Ų�����}$

HitDelayģ���÷�:����DLLע���,�ڱ�����Ϸ�����״���������ʱ���һ��cmd���� $\color{Red}{����رոô���}$

- `HitDelayFix.dll` �������޸Ĺ��Ŀͻ����ļ�,ԭʼ�ļ�Ϊ`./MUSYNX_Data/Managed/Assembly-CSharp.dll`.
- `HitDelayLine.py` ���ڶ�ȡ`./musync_data/HitDelay.log`�еĻ�����Ϣ���ɿ��ӻ����ݱ�,�������ṩ����ͳ����Ϣ.
    - `AvgDelay` ƽ�������ӳ�,�����л����ƽ��ֵ,�ܹ�һ���̶�����ʾ��Ϸ�ӳ�Ӧ�õ�������ֵ(�����нϴ�ƫ��,�����ο�).
    ������Ϸ���ж�������+010ms,AvgDelay��ֵΪ-5ms,��ô��Ӧ����Ϸ���ж���������5ms,���Ǿ�����Ҫ�����������β���.
    - `AllKeys` �����д���note����Ŀ.
    - `AvgAcc` ƽ������ƫ��,�����л���ľ���ֵ��ƽ��ֵ,��ֵ��Ϊ����.
    ��ֵ��Ӧ������ǰ���汾���������Key��ʱ���ľ�׼��,��ֵ������������Ľ���ɼ���һ���Ĺ���:

    ��ֵԽС,��˵���������Խ��׼,(�ڸ�ֵС��45msʱ������)��ֵ�ͻ�Խ��.

## ������־
<!--
### Version 
#### PreRelease 
1. ����
    1. xxx
2. �޸�
    1. xxx
3. �Ż�
    1. xxx
-->
### Version 0.0.1
1. ����
    1. ��ʼ����Ŀ������

## ���������`����`�Դ浵�ļ�����`д`����