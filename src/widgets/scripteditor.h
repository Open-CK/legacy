#ifndef SCRIPTEDITOR_H
#define SCRIPTEDITOR_H

#include <QPlainTextEdit>

class QSyntaxHighlighter;
class ScriptEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    ScriptEditor(QWidget* parent = Q_NULLPTR);
    ScriptEditor(const ScriptEditor&) = default;
    ScriptEditor& operator=(const ScriptEditor&) = default;
    ~ScriptEditor() = default;

protected:
    void resizeEvent(QResizeEvent* ev);

public slots:
    void on_scriptIndexChanged(int index);

private slots:
    void on_blockCountChanged(int);
    void on_updateRequest(const QRect& rect, int dy);

private:
    class LineNumberWidget : public QWidget
    {
    public:
        LineNumberWidget(ScriptEditor* editor);

        QSize sizeHint() const;
    protected:
        void paintEvent(QPaintEvent* ev);

    private:
        ScriptEditor* scriptEditor{ nullptr };
    };

    // Line numbering.
    LineNumberWidget* lineNumberWidget{ nullptr };
    void paintLineNumbers(QPaintEvent* ev);
    int getLineNumberAreaWidth() const;
    static const quint32 LINENUMBER_PADDING = 5;

    // Highlighter.
    QSyntaxHighlighter* syntaxHighlighter{ nullptr };
};

#endif