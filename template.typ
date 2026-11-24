#let identity = toml("identity.toml")

#let ruled(body) = box(
  width: 100%,
  stroke: (bottom: 0.5pt),
  inset: (bottom: 3pt, x: 2pt),
  body,
)

#let note(body) = text(size: 9pt, style: "italic", body)

#let signature-row(label, name) = grid(
  columns: (34mm, 25mm, 30mm, 1fr),
  column-gutter: 5mm,
  row-gutter: 2pt,
  align: (left + bottom, center + bottom, center + bottom, center + bottom),
  label, ruled[~], ruled[~], ruled(name),
  [], note[подпись], note[дата], note[инициалы и фамилия],
)

#let title-page(
  kind,
  number,
  title,
  discipline,
  institute,
  specialty,
  department,
  student,
  group,
  cipher,
  teacher,
  city,
  year,
) = page(
  numbering: none,
  margin: (top: 25mm, bottom: 25mm, left: 30mm, right: 15mm),
)[
  #set par(first-line-indent: 0pt, justify: false, leading: 0.65em, spacing: 0.65em)
  #set text(size: 14pt)
  #align(center)[
    #image("assets/logo.png", width: 22mm)
    #v(4mm)
    #text(size: 11pt)[МИНИСТЕРСТВО НАУКИ И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ]
    #v(2mm)
    #text(size: 10pt)[
      ФЕДЕРАЛЬНОЕ ГОСУДАРСТВЕННОЕ БЮДЖЕТНОЕ ОБРАЗОВАТЕЛЬНОЕ УЧРЕЖДЕНИЕ \
      ВЫСШЕГО ОБРАЗОВАНИЯ \
      «МИРЭА – РОССИЙСКИЙ ТЕХНОЛОГИЧЕСКИЙ УНИВЕРСИТЕТ» \
      РТУ МИРЭА
    ]
  ]
  #v(6mm)
  #grid(
    columns: (auto, 1fr),
    column-gutter: 3mm,
    row-gutter: 6mm,
    align: bottom,
    [*Институт*], ruled(institute),
    [*Специальность (направление):*], ruled(specialty),
    [*Кафедра:*], ruled(department),
    [*Дисциплина:*], ruled[«#discipline»],
  )
  #v(8mm)
  #align(center, text(size: 16pt)[#kind #if number != none [№ #number] \ на тему:])
  #v(2mm)
  #block(
    width: 100%,
    stroke: (bottom: 0.5pt),
    inset: (bottom: 4pt),
    align(center, text(size: 16pt, title)),
  )
  #block(width: 100%, height: 1.4em, stroke: (bottom: 0.5pt))
  #v(14mm)
  #signature-row[Студент:][#student]
  #v(6mm)
  #grid(
    columns: (auto, 1fr, auto, 1fr),
    column-gutter: 5mm,
    align: bottom,
    [Группа:], ruled[#group], [Шифр:], ruled[#cipher],
  )
  #v(6mm)
  #signature-row[Преподаватель:][#text(size: 11pt, teacher)]
  #v(1fr)
  #align(center)[*#city #year г.*]
]

#let report(
  title: "",
  number: none,
  kind: "Практическая работа",
  discipline: "Объектно-ориентированное программирование",
  institute: identity.institute,
  specialty: identity.specialty,
  department: identity.department,
  student: identity.student,
  group: identity.group,
  cipher: identity.cipher,
  teacher: identity.teacher,
  city: "Москва",
  year: datetime.today().year(),
  body,
) = {
  let full-title = kind + (if number != none { " " + str(number) } else { "" }) + ". " + title
  set document(title: full-title, author: student)
  set page(paper: "a4", margin: (top: 20mm, bottom: 20mm, left: 30mm, right: 15mm))
  set text(font: ("Liberation Serif", "DejaVu Serif"), size: 14pt, lang: "ru")
  set par(justify: true, leading: 1em, spacing: 1em, first-line-indent: (amount: 1.25cm, all: true))

  title-page(
    kind, number, title, discipline, institute, specialty, department,
    student, group, cipher, teacher, city, year,
  )

  set page(numbering: "1", number-align: center)
  set heading(numbering: "1.1")
  show heading: set block(above: 1.5em, below: 1em)
  show heading.where(level: 1): set text(size: 16pt)
  show heading.where(level: 1): it => {
    pagebreak(weak: true)
    it
  }

  set figure.caption(separator: [ – ])
  show figure.caption: set text(size: 12pt)
  show figure.caption: set par(first-line-indent: 0pt)
  show figure: set block(above: 1.5em, below: 1.5em)
  show figure.where(kind: raw): set block(breakable: true)

  set table(stroke: 0.5pt)
  show table.cell: set par(first-line-indent: 0pt, justify: false, leading: 0.65em)
  show table.cell.where(y: 0): strong
  show list: set par(first-line-indent: 0pt)
  show enum: set par(first-line-indent: 0pt)

  show raw: set text(font: ("JetBrains Mono", "JetBrainsMono NF", "DejaVu Sans Mono"))
  show raw.where(block: false): set text(size: 12pt)
  show raw.where(block: false): it => box(it)
  show raw.where(block: true): it => block(
    width: 100%,
    fill: luma(247),
    stroke: 0.5pt + luma(190),
    inset: 8pt,
    radius: 2pt,
    {
      set text(size: 10pt)
      set par(leading: 0.55em, first-line-indent: 0pt)
      show raw.line: l => {
        box(width: 1.6em, align(right, text(fill: luma(140), str(l.number))))
        h(0.8em)
        l
      }
      it
    },
  )

  body
}

#let listing(code, caption) = figure(
  code,
  caption: figure.caption(position: top, caption),
  kind: raw,
  supplement: [Листинг],
)

#let screenshot(img, caption) = figure(
  img,
  caption: caption,
  kind: image,
  supplement: [Рисунок],
)

#let tbl(body, caption) = figure(
  body,
  caption: figure.caption(position: top, caption),
  kind: table,
  supplement: [Таблица],
)
