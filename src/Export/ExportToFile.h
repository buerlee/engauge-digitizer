#ifndef EXPORT_TO_FILE_H
#define EXPORT_TO_FILE_H

#include <QStringList>

class Document;
class DocumentModelExport;
class QTextStream;
class Transformation;

/// Strategy class for exporting to a file. This strategy is external to the Document class so that class is simpler.
class ExportToFile
{
public:
  /// Single constructor.
  ExportToFile();

  /// Export Document points according to the settings. The DocumentModelExport inside the Document is ignored so
  /// DlgSettingsExport can supply its own DocumentModelExport when previewing what would be exported.
  void exportToFile (const DocumentModelExport &modelExport,
                     const Document &document,
                     const Transformation &transformation,
                     QTextStream &str) const;

private:
  QStringList curvesToInclude (const DocumentModelExport &modelExport,
                               const QStringList &curvesGraphsNames) const;
  void exportToFileAllPerLine (const DocumentModelExport &modelExport,
                               const Document &document,
                               const QStringList &curvesIncluded,
                               const Transformation &transformation,
                               QTextStream &str) const;
  void exportToFileOnePerLine (const DocumentModelExport &modelExport,
                               const Document &document,
                               const QStringList &curvesIncluded,
                               const Transformation &transformation,
                               QTextStream &str) const;
};

#endif // EXPORT_TO_FILE_H
