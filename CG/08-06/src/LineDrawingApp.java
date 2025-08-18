
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.util.ArrayList;
import java.util.List;

public class LineDrawingApp extends JFrame {
    private DrawingPanel drawingPanel;
    private JButton clearButton, exportButton;
    private JRadioButton simpleAlgorithm, bresenhamAlgorithm, compareMode;
    private JCheckBox showAnimation, showDetails;
    private JLabel statusLabel, lineThicknessLabel;
    private JTextArea detailsArea;
    private JSpinner lineThicknessSpinner;
    private Point startPoint, endPoint;
    private boolean isDrawing = false;
    private Timer animationTimer;
    private List<Point> currentPixels;
    private int currentPixelIndex;
    private String currentAlgorithm = "Bresenham";
    private ComparisonWindow comparisonWindow;

    public LineDrawingApp() {
        setTitle("Algoritmos de Desenho de Linha - Bresenham vs Simples");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());
        
        // Definir tamanho máximo de 800x600 pixels
        setMaximumSize(new Dimension(800, 600));
        setPreferredSize(new Dimension(800, 600));
        setResizable(true);

        initializeComponents();
        setupLayout();
        setupEventHandlers();

        pack();
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void initializeComponents() {
        // Panel de desenho
        drawingPanel = new DrawingPanel();
        drawingPanel.setPreferredSize(new Dimension(500, 350));
        drawingPanel.setBackground(Color.WHITE);

        // Botões de controle
        clearButton = new JButton("Limpar Tela");
        exportButton = new JButton("Exportar Imagem");

        // Radio buttons para algoritmos
        simpleAlgorithm = new JRadioButton("Algoritmo Simples");
        bresenhamAlgorithm = new JRadioButton("Bresenham", true);
        compareMode = new JRadioButton("Comparar Ambos");

        ButtonGroup algorithmGroup = new ButtonGroup();
        algorithmGroup.add(simpleAlgorithm);
        algorithmGroup.add(bresenhamAlgorithm);
        algorithmGroup.add(compareMode);

        // Checkboxes para opções
        showAnimation = new JCheckBox("Mostrar Animação", true);
        showDetails = new JCheckBox("Mostrar Detalhes", true);

        // Controle para espessura da linha
        lineThicknessLabel = new JLabel("Espessura da Linha:");
        SpinnerNumberModel thicknessModel = new SpinnerNumberModel(5, 1, 20, 1);
        lineThicknessSpinner = new JSpinner(thicknessModel);

        // Labels e área de texto
        statusLabel = new JLabel("Clique para definir o ponto inicial da linha");
        detailsArea = new JTextArea(10, 30);
        detailsArea.setEditable(false);
        detailsArea.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 12));
    }

    private void setupLayout() {
        // Panel principal de desenho
        add(drawingPanel, BorderLayout.CENTER);

        // Panel de controles à esquerda
        JPanel controlPanel = new JPanel();
        controlPanel.setLayout(new BoxLayout(controlPanel, BoxLayout.Y_AXIS));
        controlPanel.setBorder(BorderFactory.createTitledBorder("Controles"));

        // Algoritmos
        JPanel algorithmPanel = new JPanel();
        algorithmPanel.setLayout(new BoxLayout(algorithmPanel, BoxLayout.Y_AXIS));
        algorithmPanel.setBorder(BorderFactory.createTitledBorder("Algoritmo"));
        algorithmPanel.add(simpleAlgorithm);
        algorithmPanel.add(bresenhamAlgorithm);
        algorithmPanel.add(compareMode);

        // Opções
        JPanel optionsPanel = new JPanel();
        optionsPanel.setLayout(new BoxLayout(optionsPanel, BoxLayout.Y_AXIS));
        optionsPanel.setBorder(BorderFactory.createTitledBorder("Opções"));
        optionsPanel.add(showAnimation);
        optionsPanel.add(showDetails);
        
        // Controle de espessura da linha
        JPanel thicknessPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        thicknessPanel.add(lineThicknessLabel);
        thicknessPanel.add(lineThicknessSpinner);
        optionsPanel.add(thicknessPanel);

        // Botões
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new BoxLayout(buttonPanel, BoxLayout.Y_AXIS));
        buttonPanel.add(clearButton);
        buttonPanel.add(Box.createVerticalStrut(10));
        buttonPanel.add(exportButton);

        controlPanel.add(algorithmPanel);
        controlPanel.add(Box.createVerticalStrut(10));
        controlPanel.add(optionsPanel);
        controlPanel.add(Box.createVerticalStrut(10));
        controlPanel.add(buttonPanel);

        add(controlPanel, BorderLayout.WEST);

        // Panel inferior com status e detalhes
        JPanel bottomPanel = new JPanel(new BorderLayout());
        bottomPanel.add(statusLabel, BorderLayout.NORTH);

        JScrollPane scrollPane = new JScrollPane(detailsArea);
        scrollPane.setPreferredSize(new Dimension(800, 120));
        bottomPanel.add(scrollPane, BorderLayout.CENTER);

        add(bottomPanel, BorderLayout.SOUTH);
    }

    private void setupEventHandlers() {
        // Mouse listeners para o panel de desenho
        drawingPanel.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                // Parar qualquer animação em andamento
                if (animationTimer != null && animationTimer.isRunning()) {
                    animationTimer.stop();
                }
                
                if (!isDrawing) {
                    // Resetar estado para nova linha
                    startPoint = e.getPoint();
                    endPoint = null;
                    statusLabel.setText("Ponto inicial: (" + startPoint.x + ", " + startPoint.y + "). Clique para definir o ponto final.");
                    drawingPanel.setStartPoint(startPoint);
                    drawingPanel.setCurrentPixel(null); // Limpar pixel atual
                    drawingPanel.repaint();
                } else {
                    endPoint = e.getPoint();
                    statusLabel.setText("Desenhando linha de (" + startPoint.x + ", " + startPoint.y + ") para (" + endPoint.x + ", " + endPoint.y + ")");
                    drawLine();
                }
                isDrawing = !isDrawing;
            }
        });

        // Listeners para botões
        clearButton.addActionListener(_ -> clearCanvas());
        exportButton.addActionListener(_ -> exportImage());

        // Listener para espessura da linha
        lineThicknessSpinner.addChangeListener(_ -> {
            int thickness = (Integer) lineThicknessSpinner.getValue();
            drawingPanel.setLineThickness(thickness);
            if (comparisonWindow != null) {
                comparisonWindow.setLineThickness(thickness);
            }
            drawingPanel.repaint();
        });

        // Listeners para radio buttons
        ActionListener algorithmListener = _ -> {
            if (simpleAlgorithm.isSelected()) {
                currentAlgorithm = "Simples";
                closeComparisonWindow();
            } else if (bresenhamAlgorithm.isSelected()) {
                currentAlgorithm = "Bresenham";
                closeComparisonWindow();
            } else {
                currentAlgorithm = "Comparar";
                openComparisonWindow();
            }
        };

        simpleAlgorithm.addActionListener(algorithmListener);
        bresenhamAlgorithm.addActionListener(algorithmListener);
        compareMode.addActionListener(algorithmListener);
    }

    private void drawLine() {
        if (startPoint == null || endPoint == null) return;

        // Parar qualquer animação em andamento
        if (animationTimer != null && animationTimer.isRunning()) {
            animationTimer.stop();
        }

        drawingPanel.clearPixels();
        drawingPanel.setCurrentPixel(null); // Limpar pixel atual
        detailsArea.setText("");

        if (currentAlgorithm.equals("Comparar")) {
            // A comparação será feita na janela separada
            statusLabel.setText("Use a janela de comparação para desenhar linhas.");
            isDrawing = false;
            return;
        } else {
            List<Point> pixels = currentAlgorithm.equals("Bresenham") ? 
                bresenhamLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y) :
                simpleLine(startPoint.x, startPoint.y, endPoint.x, endPoint.y);

            if (showAnimation.isSelected()) {
                animateLineDrawing(pixels, currentAlgorithm.equals("Bresenham") ? Color.BLUE : Color.RED);
            } else {
                drawingPanel.addPixels(pixels, currentAlgorithm.equals("Bresenham") ? Color.BLUE : Color.RED);
                drawingPanel.repaint();
                // Resetar estado quando animação está desativada
                statusLabel.setText("Linha concluída! Clique para desenhar nova linha.");
                isDrawing = false;
            }
        }
    }

    private List<Point> bresenhamLine(int x0, int y0, int x1, int y1) {
        List<Point> pixels = new ArrayList<>();
        StringBuilder details = new StringBuilder();

        int dx = Math.abs(x1 - x0);
        int dy = Math.abs(y1 - y0);
        int sx = x0 < x1 ? 1 : -1;
        int sy = y0 < y1 ? 1 : -1;
        int err = dx - dy;

        details.append("Algoritmo de Bresenham:\n");
        details.append("dx = ").append(dx).append(", dy = ").append(dy).append("\n");
        details.append("sx = ").append(sx).append(", sy = ").append(sy).append("\n");
        details.append("err inicial = ").append(err).append("\n\n");

        int x = x0, y = y0;
        int step = 0;

        while (true) {
            pixels.add(new Point(x, y));
            details.append("Passo ").append(++step).append(": (").append(x).append(", ").append(y).append(")");

            if (x == x1 && y == y1) break;

            int e2 = 2 * err;
            details.append(", e2 = ").append(e2);

            if (e2 > -dy) {
                err -= dy;
                x += sx;
                details.append(", decisão: E (East)");
            }
            if (e2 < dx) {
                err += dx;
                y += sy;
                details.append(", decisão: NE (North-East)");
            }
            details.append(", novo err = ").append(err).append("\n");
        }

        if (showDetails.isSelected()) {
            detailsArea.setText(details.toString());
        }

        return pixels;
    }

    private List<Point> simpleLine(int x0, int y0, int x1, int y1) {
        List<Point> pixels = new ArrayList<>();
        StringBuilder details = new StringBuilder();

        details.append("Algoritmo Simples (dy/dx):\n");

        int dx = Math.abs(x1 - x0);
        int dy = Math.abs(y1 - y0);

        if (dx == 0) { // Linha vertical
            int startY = Math.min(y0, y1);
            int endY = Math.max(y0, y1);
            for (int y = startY; y <= endY; y++) {
                pixels.add(new Point(x0, y));
            }
            details.append("Linha vertical de y=").append(startY).append(" até y=").append(endY).append("\n");
        } else if (dy == 0) { // Linha horizontal
            int startX = Math.min(x0, x1);
            int endX = Math.max(x0, x1);
            for (int x = startX; x <= endX; x++) {
                pixels.add(new Point(x, y0));
            }
            details.append("Linha horizontal de x=").append(startX).append(" até x=").append(endX).append("\n");
        } else {
            double slope = (double)(y1 - y0) / (x1 - x0);
            details.append("Inclinação = ").append(String.format("%.3f", slope)).append("\n");

            if (Math.abs(slope) <= 1) {
                // Iterar sobre X
                int startX = Math.min(x0, x1);
                int endX = Math.max(x0, x1);
                int baseY = (startX == x0) ? y0 : y1;
                int baseX = (startX == x0) ? x0 : x1;

                for (int x = startX; x <= endX; x++) {
                    int y = (int) Math.round(baseY + slope * (x - baseX));
                    pixels.add(new Point(x, y));
                    details.append("x=").append(x).append(", y=").append(y).append("\n");
                }
            } else {
                // Iterar sobre Y
                int startY = Math.min(y0, y1);
                int endY = Math.max(y0, y1);
                int baseX = (startY == y0) ? x0 : x1;
                int baseY = (startY == y0) ? y0 : y1;
                double invSlope = 1.0 / slope;

                for (int y = startY; y <= endY; y++) {
                    int x = (int) Math.round(baseX + invSlope * (y - baseY));
                    pixels.add(new Point(x, y));
                    details.append("y=").append(y).append(", x=").append(x).append("\n");
                }
            }
        }

        if (showDetails.isSelected()) {
            detailsArea.setText(details.toString());
        }

        return pixels;
    }

    private void animateLineDrawing(List<Point> pixels, Color color) {
        currentPixels = pixels;
        currentPixelIndex = 0;

        animationTimer = new Timer(50, _ -> {
            if (currentPixelIndex < currentPixels.size()) {
                drawingPanel.addPixel(currentPixels.get(currentPixelIndex), color);
                drawingPanel.setCurrentPixel(currentPixels.get(currentPixelIndex));
                drawingPanel.repaint();
                currentPixelIndex++;
            } else {
                animationTimer.stop();
                drawingPanel.setCurrentPixel(null);
                statusLabel.setText("Linha concluída! Clique para desenhar nova linha.");
                isDrawing = false;
            }
        });

        animationTimer.start();
    }

    private void clearCanvas() {
        // Parar qualquer animação em andamento
        if (animationTimer != null && animationTimer.isRunning()) {
            animationTimer.stop();
        }
        
        drawingPanel.clearAll();
        drawingPanel.repaint();
        detailsArea.setText("");
        statusLabel.setText("Tela limpa. Clique para definir o ponto inicial da linha.");
        isDrawing = false;
        startPoint = null;
        endPoint = null;
        currentPixels = null;
        currentPixelIndex = 0;
    }

    private void exportImage() {
        BufferedImage image = new BufferedImage(drawingPanel.getWidth(), drawingPanel.getHeight(), BufferedImage.TYPE_INT_RGB);
        Graphics2D g2d = image.createGraphics();
        drawingPanel.paint(g2d);
        g2d.dispose();

        JFileChooser fileChooser = new JFileChooser();
        fileChooser.setSelectedFile(new File("linha_desenho.png"));

        if (fileChooser.showSaveDialog(this) == JFileChooser.APPROVE_OPTION) {
            try {
                ImageIO.write(image, "PNG", fileChooser.getSelectedFile());
                JOptionPane.showMessageDialog(this, "Imagem exportada com sucesso!");
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(this, "Erro ao exportar imagem: " + ex.getMessage());
            }
        }
    }

    private void openComparisonWindow() {
        if (comparisonWindow == null || !comparisonWindow.isVisible()) {
            comparisonWindow = new ComparisonWindow();
            comparisonWindow.setLineThickness((Integer) lineThicknessSpinner.getValue());
            comparisonWindow.setVisible(true);
        }
    }

    private void closeComparisonWindow() {
        if (comparisonWindow != null && comparisonWindow.isVisible()) {
            comparisonWindow.dispose();
            comparisonWindow = null;
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            new LineDrawingApp();
        });
    }
}